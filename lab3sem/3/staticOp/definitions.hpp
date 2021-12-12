#ifndef SET_ST
#define SET_ST
#include <iostream>
#include <limits>

void menuPrint();
int choice(int max, const char* msg);

namespace def{

    template <class T>
    void getNum(T &a){
        std::cin >> a;
        while(!std::cin.good()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            std::cout << "Wrong input! Try again: ";
            std::cin >> a;
        }
    }

    class Set{
        private:
            static const int maxPower = 100;
            int power;
            int set[maxPower]{};
        public:
            Set(int power = 0);
            Set(int power, const int* nums);
            int getPower() const{return power;};
            int getElemByIndex(int i) const {return set[i];};

            Set& Add(int value);
            Set Diff(Set& subtrahend) const noexcept;
            Set Intersection(Set& second) const noexcept;
            Set Union(Set& second) const noexcept;
            friend std::istream& Input(std::istream& istrm, std::ostream& ostrm, Set& tmp);
            friend std::ostream& print(std::ostream& strm, Set& tmp) noexcept;
            friend Set operator - (const Set& minuend, const Set& subtrahend) noexcept;
            friend Set operator * (const Set& first, const Set& secondOperand) noexcept;
            friend Set operator + (const Set& first, const Set& secondOperand) noexcept;
            friend std::ostream& operator << (std::ostream& strm, Set& tmp) noexcept;
            friend std::istream& operator >> (std::istream& strm, Set& tmp);
            bool Isin(int numLookFor) const noexcept; //check for elem in set
    };

}

#endif
