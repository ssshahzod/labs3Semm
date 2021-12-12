#include "definitions.hpp"
#include <iostream>



namespace def{
    Set::Set(int pow){
        if(pow > maxPower || pow < 0)
            throw std::out_of_range("Incorrect size!\n");
        int num;
        power = pow;
        for(int i = 0; i < pow; i++){
            num = rand();
            while(Isin(num))
                num++;
            set[i] = num;
        }
        for(int i = pow; i < maxPower; i++){
            set[i] = std::numeric_limits<int>::max();
        }
    }

    Set::Set(int pow, const int* nums){
        if(pow > maxPower || pow < 0)
            throw std::out_of_range("Incorrect size!\n");

        for(auto& i : set){
            i = std::numeric_limits<int>::max();
        }
        power = pow;

        for(int i = 0; i < pow; i++){
            if(!Isin(nums[i]))
                set[i] = nums[i];
            else
                throw std::logic_error("Array has same elements!\n");
        }

    }

    Set& Set::Add(int value) {
        if(power + 1 == maxPower)
            throw std::out_of_range("Set overflow!\n");
        if(Isin(value))
            throw std::logic_error("Repeating value!\n");
        set[power] = value;
        power++;
        return *this;
    }

    Set Set::Diff(Set &subtrahend) const noexcept{ 
        Set tmp;
        for(int i = 0; i < power; i++){
            if(!subtrahend.Isin(set[i])){
                tmp.Add(set[i]);
            }
        }
        return tmp;
    }

    Set Set::Intersection(Set &second) const noexcept{
        Set tmp;
        for(int i = 0; i < power; i++){
            if(second.Isin(set[i]))
                tmp.Add(set[i]);
        }
        return tmp;
    }

    Set Set::Union(Set& second) const noexcept{
        Set tmp;
        for(int i = 0; i < power; i++)
            tmp.Add(set[i]);
        for(int i = 0; i < second.power; i++)
            if(!tmp.Isin(second.set[i]))
                tmp.Add(second.set[i]);
        return tmp;
    }

    std::ostream& print(std::ostream& strm, Set& tmp) noexcept{
        if(tmp.getPower() == 0)
            strm << "Set is empty!";
        else{
            strm << "Set: ";
            for(int i = 0; i < tmp.getPower(); i ++){
                if(i % 10 == 0)
                    strm << "\n";
                strm << tmp.getElemByIndex(i)<< " ";
            }
        }
        strm << std::endl;
        return strm;
    }

    std::istream& Input(std::istream& istrm, std::ostream& ostrm, Set& tmp){ //cout -
        int size, num, val;
        do{
            ostrm << "Input size of the set: ";
            istrm >> size;
            while(!istrm.good()){
                istrm.clear();
                istrm.ignore(std::numeric_limits<int>::max(), '\n');
                ostrm << "Wrong input! Try again: ";
                istrm >> size;
            }
        }while(size > tmp.maxPower || size < 0);
        tmp.power = size;
        if(size){
            ostrm << "Input elems of the set: ";
            for(int i = 0; i < size; i++){
                istrm >> num;
                while(!istrm.good()){
                    istrm.clear();
                    istrm.ignore(std::numeric_limits<int>::max(), '\n');
                    ostrm << "Wrong input! Try again: ";
                    istrm >> size;
                }
                val = tmp.Isin(num);
                if(val)
                    throw std::logic_error("Elem already in the set!\n");
                tmp.set[i] = num;

            }
        }
        return istrm;
    }

    Set operator - (const Set& minuend, const Set& subtrahend) noexcept{
        Set tmp;
        for(int i = 0; i < minuend.getPower(); i++){
            if(!subtrahend.Isin(minuend.getElemByIndex(i))){
                tmp.Add(minuend.getElemByIndex(i));
            }
        }
        return tmp;
    }

    Set operator * (const Set& first, const Set& second) noexcept{
        Set tmp;
        for(int i = 0; i < first.getPower(); i++){
            if(second.Isin(first.getElemByIndex(i)))
                tmp.Add(first.getElemByIndex(i));

        }
        return tmp;
    }

    Set operator + (const Set& first, const Set& second) noexcept{
        Set tmp;
        int var;
        for(int i = 0; i < first.getPower(); i++)
            tmp.Add(first.getElemByIndex(i));
        for(int i = 0; i < second.getPower(); i++){
            var = second.getElemByIndex(i);
            if(!tmp.Isin(var))
                tmp.Add(var);
        }
        return tmp;
    }

    std::istream& operator >> (std::istream& strm, Set& tmp){ //std cout
        int size, num, val;
        do{
            std::cout << "Enter number of elems in set: ";
            getNum(size);
        }while(size > tmp.maxPower || size < 0);
        tmp.power = size;
        if(size){
            std::cout << "Enter elements: ";
            for(int i = 0; i < size; i++){
                getNum(num);
                val = tmp.Isin(num);
                if(val)
                    strm.setstate(std::ios::failbit);
                tmp.set[i] = num;

            }
        }
        return strm;
    }

    std::ostream& operator << (std::ostream& strm, Set& tmp)  noexcept{
        if(tmp.power == 0)
            strm << "Set is empty!";
        else{
            strm << "Set: ";
            for(int i = 0; i < tmp.power; i ++){
                if(i % 10 == 0)
                    strm << "\n";
                strm << tmp.set[i] << " ";
            }
        }
        strm << std::endl;
        return strm;
    }

    bool Set::Isin(int numLookFor) const noexcept{
        for(int i = 0; i < power; i++){
            if(set[i] == numLookFor){
                return true;
            }
        }
        return false;
    }

}
