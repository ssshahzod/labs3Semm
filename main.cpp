#include <iostream>
#include <cstring>
#include "table.h"

class string{
    private:
        size_t size;
        char* str;
    public:
        explicit string(size_t s = 0) : size(s) {str = nullptr; getStat();};
        void setS(const char* st){str = new char[size]; std::strcpy(str, st);};
        void getStat(){std::cout << "String made\n";};
        [[nodiscard]] size_t getSize() const{return size;};
        void printS(){std::cout << str;};
};

int main(){
    const char* s = "Just a little string\n";
    const char* s2 = "Another little string\n";
    Table<int, int, string> tmp(9);

    string tm(strlen(s));
    tm.setS(s);
    Iterator it = tmp.begin();
    Node<int, int, string> node;
    node.xkey = 1;
    node.ykey = 2;
    node.info = &tm;


    std::cout << "FIRST string: ";

 }

