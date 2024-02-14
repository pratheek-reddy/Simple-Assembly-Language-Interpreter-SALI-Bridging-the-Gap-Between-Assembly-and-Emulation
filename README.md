# Simple Assembly Language Interpreter (SALI)

Welcome to the Simple Assembly Language Interpreter (SALI) project! SALI is a virtual machine designed to interpret programs written in Simple Assembly Language (SAL). This README file provides an overview of the SALI project, including its purpose, functionality, and usage instructions.

## Purpose
The purpose of the SALI project is to provide a platform for executing programs written in a simple assembly language. SALI interprets SAL programs and executes them on a virtual machine, emulating the behavior of a physical computer with memory, registers, and a program counter.

## Components
SALI consists of the following main components:
1. Memory: A 32-bit, word-addressable memory capable of storing both program source code and data.
2. Accumulator: A 32-bit register used for arithmetic operations.
3. Additional Register: A second 32-bit register available for storing data.
4. Program Counter (PC): An 8-bit register that holds the address of the next instruction to be executed.
5. Zero-Result Bit: Indicates whether the last ADD instruction produced a zero result.
6. Overflow Bit: Indicates whether an ADD instruction produced an overflow.

## Instruction Set
SALI supports the following instructions:
- DEC symbol: Declares a symbolic variable in the data memory.
- LDA symbol: Loads the content of a symbolic variable into the accumulator.
- LDB symbol: Loads the content of a symbolic variable into the additional register.
- LDI value: Loads an integer value into the accumulator.
- STR symbol: Stores the content of the accumulator into the data memory at the address of the symbol.
- XCH: Exchanges the content of registers A and B.
- JMP number: Transfers control to the instruction at the specified address in program memory.
- JZS number: Transfers control if the zero-result bit is set.
- JVS number: Transfers control if the overflow bit is set.
- ADD: Adds the content of registers A and B.
- HLT: Terminates program execution.

## Usage
To use SALI, follow these steps:
1. Compile the SALI source code in C++ (`main.cpp`) or Ruby (`main.rb`) using the respective compilers.
2. Run SALI and follow the prompts to input the name of the SAL program file.
3. Execute SAL programs line by line using the 's' command or all at once until a halt instruction is encountered using the 'a' command.
4. Use the 'q' command to quit the SALI command loop.



