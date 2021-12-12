#ifndef SET_ST
#define SET_ST
#include <iostream>
#include <limits>
#include <cstring>

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
            int power;
            char *set;
        public://
            explicit Set(int power = 0);
            Set(int power, const int* nums);
            Set(const Set& tmp);
            int getPower() const{return power;};
            int getElemByIndex(int i) const;
            int* getAddrByIndex(int i) const{return (int*)(&set[i * 4]);};
            void deleteSet(){delete [] set; power = 0; set = nullptr;};

            Set& Add(int value);
            void Diff(const Set& subtrahend, Set& tmp) noexcept;
            void Intersection(const Set& second, Set& tmp) noexcept;
            void Union(const Set& second, Set& tmp) noexcept;
            friend std::istream& Input(std::istream& istrm, std::ostream& ostrm, Set& tmp);
            friend std::ostream& print(std::ostream& strm, Set& tmp) noexcept;
            friend Set operator - (const Set& minuend, const Set& subtrahend) noexcept;
            friend Set operator * (const Set& first, const Set& secondOperand) noexcept;
            friend Set operator + (const Set& first, const Set& secondOperand) noexcept;
            Set& operator = (Set&& tmp) noexcept;
            friend std::ostream& operator << (std::ostream& strm, Set& tmp) noexcept;
            friend std::istream& operator >> (std::istream& strm, Set& tmp);
            bool Isin(int numLookFor) const noexcept; //check for elem in set
    };

}

#endif