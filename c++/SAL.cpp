

#include "SAL.h"
#include <cstring>
#include <iostream>

using namespace std;

class Instruction {
protected:
    virtual void execute() = 0;

    string printString;
    string argtype;
public:
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
        cout << "HI"  << endl;
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
        cout << "HI" << endl;
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
        cout << "HI"  << endl;
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
        cout << "HI"  << endl;
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
        cout << "HI"  << endl;
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
        cout << "HI"  << endl;
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
        cout << "HI"  << endl;
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
        cout << "HI"  << endl;
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
        cout << "HI"  << endl;
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
        cout << "HI"  << endl;
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
        cout << "HI"  << endl;
    }
    string get() {
        return "dummy";
    }
};

int main()
{
    DEC* dec1 = new DEC("DEC object");
    LDA* lda1 = new LDA("LDA object");
    LDB* ldb1 = new LDB("LDB object");
    LDI* ldi1 = new LDI("LDI object");
    STR* str1 = new STR("STR object");
    XCH* xch1 = new XCH();
    JMP* jmp1 = new JMP("JMP object");
    JZS* jzs1 = new JZS("JZS object");
    JVS* jvs1 = new JVS("JVS object");
    ADD* add = new ADD();
    HLT* hlt = new HLT();

    cout << dec1->get() << endl;
    dec1->execute();
    cout << lda1->get() << endl;
    lda1->execute();
    cout << ldb1->get() << endl;
    ldb1->execute();
    cout << ldi1->get() << endl;
    ldi1->execute();
    cout << str1->get() << endl;
    str1->execute();
    cout << xch1->get() << endl;
    xch1->execute();
    cout << jmp1->get() << endl;
    jmp1->execute();
    cout << jzs1->get() << endl;
    jzs1->execute();
    cout << jvs1->get() << endl;
    jvs1->execute();
    cout << add->get() << endl;
    add->execute();
    cout << hlt->get() << endl;
    hlt->execute();
    return 0;
}