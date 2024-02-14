require './instruction.rb'

#to input the source code file
puts "Enter file name to execute in the current directory:"
file_name = gets.chomp()

instr_arr = IO.readlines(file_name)

#memory class to for memory and registers
class Memory

  @@memory = Array.new(256)
  @@symbol_table = Hash.new

  @@A = 0
  @@B = 0
  @@pc = 0
  @@ZR = 0
  @@OF = 0

  #Below are the getter and setter methods for memory and all registers

  def Memory.add_memory (obj, index)
    @@memory[index] = obj
  end
  def Memory.get_memory (index)

    @@memory[index]
  end
  def Memory.set_instr_count (value)
    @@instr_count = value
  end
  def Memory.get_instr_count
    @@instr_count
  end
  def Memory.add_symbol (key,value)
    @@symbol_table.store(key, value)
  end
  def Memory.get_symbol (key)
    @@symbol_table[key]
  end
  def Memory.set_A (value)
    @@A = value
  end
  def Memory.get_A
    @@A
  end
  def Memory.set_B (value)
    @@B = value
  end
  def Memory.get_B
    @@B
  end
  def Memory.set_pc (value)
    @@pc = value
  end
  def Memory.get_pc
    @@pc
  end
  def Memory.set_ZR (value)
    @@ZR = value
  end
  def Memory.get_ZR
    @@ZR
  end
  def Memory.set_OF (value)
    @@OF = value
  end
  def Memory.get_OF
    @@OF
  end

  #print the values of registers and symbols
  def Memory.print
    puts "Register A = #{@@A}"
    puts "Register B = #{@@B}"
    puts "Zero Result bit = #{@@ZR}"
    puts "Over flow bit = #{@@OF}"
    puts "PC = #{@@pc}"

    @@symbol_table.each do |key,value|
      puts "#{key}: #{@@memory[value]}"
    end

  end


end

#execution class to execute the commands
class Execution
  @@instr_count = 0
  @@instr_no =0

  #method to parse the source code and create instruction instances and store it in memory
  def Execution.parse_code(instr_arr)
    i=0
    @@instr_no = instr_arr.length()
    instr_arr.each do |line|

      line = line.split(" ")
      case line[0]
      when /^DEC/
        dec = DEC.new(line[1])
        Memory.add_memory(dec,i)
      when /^LDA/
        lda = LDA.new(line[1])
        Memory.add_memory(lda,i)
        Memory.add_memory(line[1],i+128)
      when /^LDB/
        ldb = LDB.new(line[1])
        Memory.add_memory(ldb,i)
        Memory.add_memory(line[1],i+128)
      when /^LDI/
        ldi = LDI.new(line[1])
        Memory.add_memory(ldi,i)
        Memory.add_memory(line[1],i+128)
      when /^STR/
        str = STR.new(line[1])
        Memory.add_memory(str,i)
        Memory.add_memory(line[1],i+128)
      when /^XCH/
        xch = XCH.new
        Memory.add_memory(xch,i)

      when /^JMP/
        jmp = JMP.new(line[1])
        Memory.add_memory(jmp,i)
        Memory.add_memory(line[1],i+128)
      when /^JZS/
        jzs = JZS.new(line[1])
        Memory.add_memory(jzs,i)
        Memory.add_memory(line[1],i+128)
      when /^JVS/
        jvs = JVS.new(line[1])
        Memory.add_memory(jvs,i)
        Memory.add_memory(line[1],i+128)
      when /^ADD/
        add = ADD.new(line[1])
        Memory.add_memory(add,i)
        Memory.add_memory(line[1],i+128)
      when /^HLT/
        hlt = HLT.new
        Memory.add_memory(hlt,i)
      end
      i = i + 1
    end


  end

  #method to execute s command
  def Execution.s_command
    Execution.command_exec
    @@instr_count = @@instr_count+1
  end

  #method to execute a command
  def Execution.a_command

    while @@instr_count<=1000
      puts(@@instr_count)
      Execution.command_exec
      @@instr_count = @@instr_count+1
    end

  end

  #method to execute q command
  def Execution.q_command
    exit
  end

  def Execution.command_exec
    i_instance = Memory.get_memory(Memory.get_pc)
    i_instance.execute
  end
  def Execution.set_instr_count (value)
    @@instr_count = value
  end
end


Execution.parse_code(instr_arr)
Memory.set_pc(0)

while(true) #this while loop runs infinitely until q is given as input command

  puts "Enter command:"
  command = gets.chomp()

  case command
  when /^s/
    Execution.s_command
    Memory.print
    i_instance = Memory.get_memory(Memory.get_pc)
    puts "Next Instruction is: #{i_instance.opcode} #{i_instance.argtype}"
  when /^a/
    Execution.a_command
    Memory.print
  when /^q/
    Memory.print
    Execution.q_command
  else
    puts "Try again"
  end

end
