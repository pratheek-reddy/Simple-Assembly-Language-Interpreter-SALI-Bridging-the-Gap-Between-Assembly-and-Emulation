#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include <unordered_map>

class Instruction
{
    protected:
        string printString;
        string argtype;
    public:
        virtual void execute() = 0;
        virtual string get() = 0;
        void print();

};

class Hardware{
    public:
        static Instruction* program_memory[128];
        static string data_memory[128];
        static int A;
        static int B;
        static int PC;
        static int ZB;
        static int OF;
        static unordered_map<string, string*> symbol_table;
        

       // Hardware(){}

       static Instruction* get_program(int i)
       {
        return program_memory[i];
       }
       static void set_program(int i,Instruction* x)
       {
        program_memory[i]=x;
       }
    


};

