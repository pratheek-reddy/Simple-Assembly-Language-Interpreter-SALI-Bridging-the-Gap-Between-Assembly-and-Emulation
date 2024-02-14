#Super class for instructions with abstract method-execute
class Instruction
  attr_accessor :opcode,:argtype

  def execute
  end
end

#Below are each instruction class and definition of execute methods
class DEC < Instruction

  def initialize(argtype)
    @argtype = argtype
    @opcode = "DEC"
  end

  def execute
    Memory.add_symbol(@argtype,Memory.get_pc+128)
    Memory.set_pc(Memory.get_pc+1)
  end

end

class LDA < Instruction

  def initialize(argtype)
    @argtype = argtype
    @opcode = "LDA"
  end

  def execute
    Memory.set_A(Memory.get_memory(Memory.get_symbol(@argtype)).to_i)
    Memory.set_pc(Memory.get_pc+1)
  end

end

class LDB < Instruction

  def initialize(argtype)
    @argtype = argtype
    @opcode = "LDB"
  end

  def execute
    Memory.set_B(Memory.get_memory(Memory.get_symbol(@argtype)).to_i)
    Memory.set_pc(Memory.get_pc+1)
  end

end

class LDI < Instruction

  def initialize(argtype)
    @argtype = argtype
    @opcode = "LDI"
  end

  def execute
    Memory.set_A(@argtype.to_i)
    Memory.set_pc(Memory.get_pc+1)
  end

end

class STR < Instruction

  def initialize(argtype)
    @argtype = argtype
    @opcode = "STR"
  end

  def execute
    Memory.add_memory(Memory.get_A,Memory.get_symbol(@argtype).to_i)
    Memory.set_pc(Memory.get_pc+1)
  end

end

class XCH < Instruction

  def initialize
    @argtype = nil
    @opcode = "XCH"
  end
  def execute
    a = Memory.get_A
    b = Memory.get_B
    Memory.set_A(b)
    Memory.set_B(a)
    Memory.set_pc(Memory.get_pc+1)
  end

end

class JMP < Instruction

  def initialize(argtype)
    @argtype = argtype
    @opcode = "JMP"
  end

  def execute
    Memory.set_pc(argtype.to_i)
  end

end

class JZS < Instruction

  def initialize(argtype)
    @argtype = argtype
    @opcode = "JZS"
  end
  def execute
    if(Memory.get_ZR==1)
      Memory.set_pc(argtype.to_i)
    else
      Memory.set_pc(Memory.get_pc+1)
    end
  end

end

class JVS < Instruction

  def initialize(argtype)
    @argtype = argtype
    @opcode = "JVS"
  end
  def execute
    if(Memory.get_OF==1)
      Memory.set_pc(argtype.to_i)
    else
      Memory.set_pc(Memory.get_pc+1)
    end
  end

end

class ADD < Instruction

  def initialize(argtype)
    @argtype = nil
    @opcode = "ADD"
  end
  def execute
    a = Memory.get_A
    b = Memory.get_B
    a = a+b
    if a == 0

      Memory.set_ZR(1)
    end

    if a > 2147483647 || a < -2147483648
      a = a < 0 ? -2147483648: 2147483647
      Memory.set_OF(1)
    end
    Memory.set_A(a)
    puts("Register A is #{a}")
    Memory.set_pc(Memory.get_pc+1)
  end

end

class HLT < Instruction

  def initialize
    @argtype = nil
    @opcode = "HLT"
  end

  def execute
    Execution.set_instr_count(1001)
  end

end
