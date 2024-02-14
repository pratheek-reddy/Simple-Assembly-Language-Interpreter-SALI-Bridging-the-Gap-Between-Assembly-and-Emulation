
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

class Instruction {
protected:
    

    string printString;
    string argtype;
public:
    virtual void execute() = 0;
    virtual string get() = 0;
    void print() {
        cout << "Zero = " << endl;
        cout << "Overflow = " << endl;
        cout << "Register A = " << endl;
        cout << "Register B = " << endl;

    }
};

class DEC : public Instruction {
public:
    DEC(string argdata) {
        printString = "DEC";
        argtype = argdata;

    }
    void execute() {
        cout << "HI DEC"  << endl;
    }
    string get() {
        return argtype;
    }
};

class LDA : public Instruction {
public:
    LDA(string argdata) {
        printString = "LDA";
        argtype = argdata;

    }
    void execute() {
        cout << "HI LDA" << endl;
    }
    string get() {
        return argtype;
    }
};

class LDB : public Instruction {
public:
    LDB(string argdata) {
        printString = "LDB";
        argtype = argdata;

    }
    void execute() {
        cout << "HI LDB"  << endl;
    }
    string get() {
        return argtype;
    }
};

class LDI : public Instruction {
public:
    LDI(string argdata) {
        printString = "LDI";
        argtype = argdata;

    }
    void execute() {
        cout << "HI LDI"  << endl;
    }
    string get() {
        return argtype;
    }
};

class STR : public Instruction {
public:
    STR(string argdata) {
        printString = "STR";
        argtype = argdata;

    }
    void execute() {
        cout << "HI STR"  << endl;
    }
    string get() {
        return argtype;
    }
};

class XCH : public Instruction {
public:
    XCH() {
        printString = "XCH";
    }
    void execute() {
        cout << "HI XCH"  << endl;
    }
    string get() {
        return "dummy";
    }
};

class JMP : public Instruction {
public:
    JMP(string argdata) {
        printString = "JMP";
        argtype = argdata;

    }
    void execute() {
        cout << "HI JMP"  << endl;
    }
    string get() {
        return argtype;
    }
};

class JZS : public Instruction {
public:
    JZS(string argdata) {
        printString = "JZS";
        argtype = argdata;

    }
    void execute() {
        cout << "HI JZS"  << endl;
    }
    string get() {
        return argtype;
    }
};

class JVS : public Instruction {
public:
    JVS(string argdata) {
        printString = "JVS";
        argtype = argdata;

    }
    void execute() {
        cout << "HI JVS"  << endl;
    }
    string get() {
        return argtype;
    }
};

class ADD : public Instruction {
public:
    ADD() {
        printString = "ADD";
    }
    void execute() {
        cout << "HI ADD"  << endl;
    }
    string get() {
        return "dummy";
    }
};

class HLT : public Instruction {
public:
    HLT() {
        printString = "HLT";
    }
    void execute() {
        cout << "HI HLT"  << endl;
    }
    string get() {
        return "dummy";
    }
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

        Hardware(){}

    


};

class ALI{
    


};

int main()
{
    Hardware* h = new Hardware();
    std::ifstream file;
    file.open("input.txt");
    if(!file.is_open())
    {
    cout<<"Unable to open the file."<<endl;
    return 0;
    }
    
    string line;
    string lines[128];
    int i=0;
    while(getline(file, line))
    {
        string Inst;
        string data;
        stringstream X(line);

        getline(X,Inst,' ');
        getline(X,data,' ');

        if(Inst=="DEC")
        {
            DEC* dec1 = new DEC(data);
            Instruction* x =dec1;
            h->program_memory[i]=x;
            h->symbol_table[data] = &h->data_memory[i];
            
        }
        else if(Inst=="LDA")
        {
            LDA* lda1 = new LDA(data);
            Instruction* x =lda1;
            h->program_memory[i]=x;
            h->data_memory[i]=data;

        }
        else if(Inst=="LDB")
        {
            LDB* ldb1 = new LDB(data);
            Instruction* x =ldb1;
            h->program_memory[i]=x;
            h->data_memory[i]=data;

        }
        else if(Inst=="LDI")
        {
            LDI* ldi1 = new LDI(data);
            Instruction* x =ldi1;
            h->program_memory[i]=x;
            h->data_memory[i]=data;
        }
        else if(Inst=="STR")
        {
            STR* str1 = new STR(data);
            Instruction* x =str1;
            h->program_memory[i]=x;
            h->data_memory[i]=data;
            
        }
        else if(Inst=="XCH")
        {
            XCH* xch1 = new XCH();
            Instruction* x =xch1;
            h->program_memory[i]=x;
        }
        else if(Inst=="JMP")
        {
            JMP* jmp1 = new JMP(data);
            Instruction* x =jmp1;
            h->program_memory[i]=x;
            h->data_memory[i]=data;
        }
        else if(Inst=="JZS")
        {
            JZS* jzs1 = new JZS(data);
            Instruction* x =jzs1;
            h->program_memory[i]=x;
            h->data_memory[i]=data;
        }
        else if(Inst=="JVS")
        {
            JVS* jvs1 = new JVS(data);
            Instruction* x = jvs1;
            h->program_memory[i]=x;
            h->data_memory[i]=data;
        }
        else if(Inst=="ADD")
        {
            ADD* add1 = new ADD();
            Instruction* x = add1;
            h->program_memory[i]=x;
        }
        else if(Inst=="HLT")
        {
            HLT* hlt1 = new HLT();
            Instruction* x = hlt1;
            h->program_memory[i]=x;
        }
        i++;

    }





    
    // DEC* dec1 = new DEC("DEC object");
    // Instruction* x =dec1;
    // x->execute();

    // Instruction* program_memory[128];
    // program_memory[0]=x;

    // Instruction* y = program_memory[0];

    // y->execute();

    
    // LDA* lda1 = new LDA("LDA object");
    // LDB* ldb1 = new LDB("LDB object");
    // LDI* ldi1 = new LDI("LDI object");
    // STR* str1 = new STR("STR object");
    // XCH* xch1 = new XCH();
    // JMP* jmp1 = new JMP("JMP object");
    // JZS* jzs1 = new JZS("JZS object");
    // JVS* jvs1 = new JVS("JVS object");
    // ADD* add = new ADD();
    // HLT* hlt = new HLT();

    // cout << dec1->get() << endl;
    // dec1->execute();
    // cout << lda1->get() << endl;
    // lda1->execute();
    // cout << ldb1->get() << endl;
    // ldb1->execute();
    // cout << ldi1->get() << endl;
    // ldi1->execute();
    // cout << str1->get() << endl;
    // str1->execute();
    // cout << xch1->get() << endl;
    // xch1->execute();
    // cout << jmp1->get() << endl;
    // jmp1->execute();
    // cout << jzs1->get() << endl;
    // jzs1->execute();
    // cout << jvs1->get() << endl;
    // jvs1->execute();
    // cout << add->get() << endl;
    // add->execute();
    // cout << hlt->get() << endl;
    // hlt->execute();
    return 0;
}