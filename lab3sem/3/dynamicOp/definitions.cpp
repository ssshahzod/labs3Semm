#include "definitions.hpp"
#include <iostream>



namespace def{
    Set::Set(int pow){
        if(pow < 0)
            throw std::out_of_range("Incorrect size!\n");
        int *location;
        power = pow;
        set = nullptr;
        if(pow){
            set = new char[pow * 4];
            for(int i = 0; i < pow; i++){
                location = getAddrByIndex(i);
                *location = i;
            }
        }
    }

    Set::Set(int pow, const int* nums){
        int *location, num;
        if(pow < 0)
            throw std::out_of_range("Incorrect size!\n");
        power = pow;
        set = new char[pow * 4];
        for(int i = 0; i < pow; i++){
            location = (int*)(&set[i * 4]);
            *location = std::numeric_limits<int>::max();
        }
        for(int i = 0; i < pow; i++){
            if(!Isin(nums[i])){
                num = nums[i];
                location = (int*)(&set[i * 4]);
                *location = num;
            }
            else
                throw std::logic_error("Array has same elements!\n");
        }

    }

    Set::Set(const Set& tmp){
        int *location;
        power = tmp.getPower();
        set = new char[power * 4];
        for (int i = 0; i < power; i++){
            location = (int*)(&set[i * 4]);
            *location = tmp.getElemByIndex(i);
        }
    }

    int Set::getElemByIndex(int i) const {
        int *location;
        location = (int*)(&set[i * 4]);
        int res = *location;
        return res;

    }

    Set& Set::Add(int value) {
        int *location;
        if(Isin(value))
            throw std::logic_error("Repeating value!\n");
        char *tmp = new char[(power + 1) * 4];
        if(power){
            memcpy(tmp, set, (power) * 4);
            delete [] set;
        }
        location = (int*)(&tmp[(power) * 4]);
        *location = value;
        set = tmp;
        power++;
        return *this;
    }

    void Set::Diff(const Set &subtrahend, Set& tmp) noexcept{
        for(int i = 0; i < power; i++){
            if(!subtrahend.Isin(getElemByIndex(i))){
                tmp.Add(getElemByIndex(i));
            }
        }
    }

    void Set::Intersection(const Set &second, Set& tmp) noexcept{
        for(int i = 0; i < power; i++){
            if(second.Isin(getElemByIndex(i))){
                tmp.Add(getElemByIndex(i));
            }
        }
    }

    void Set::Union(const Set& second, Set& tmp) noexcept{
        for(int i = 0; i < power; i++)
            tmp.Add(getElemByIndex(i));
        for(int i = 0; i < second.power; i++)
            if(!tmp.Isin(second.getElemByIndex(i)))
                tmp.Add(second.getElemByIndex(i));
    }

    std::ostream& print(std::ostream& strm, Set& tmp) noexcept{ ///
        if(tmp.getPower() == 0)
            strm << "Set is empty!";
        else{
            strm << "Set: ";
            for(int i = 0; i < tmp.getPower(); i++){
                if(i % 10 == 0)
                    strm << "\n";
                strm << tmp.getElemByIndex(i) << " ";
            }
        }
        strm << std::endl;
        return strm;
    }

    std::istream& Input(std::istream& istrm, std::ostream& ostrm, Set& tmp){ ///
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
        }while(size < 0);
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
                tmp.Add(num);

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

    Set& Set::operator= (Set&& tmp) noexcept{
        if(this == &tmp)
            return *this;

        power = tmp.getPower();
        delete [] set;
        set = tmp.set;
        tmp.power = 0;
        tmp.set = nullptr;
        return *this;
    }

    std::istream& operator >> (std::istream& istrm, Set& tmp){
        int size = 0, num, val;
        istrm >> size;d
        if(!istrm.good() || size < 0){
            istrm.setstate(std::ios::failbit);
            return istrm;
        }
        if(size > 0){
            for(int i = 0; i < size; i++){
                istrm >> num;
                if(!istrm.good()){
                    istrm.setstate(std::ios::failbit);
                    return istrm;
                }
                val = tmp.Isin(num);
                if(val){
                    istrm.setstate(std::ios::failbit);
                    return istrm;
                }
                tmp.Add(num);

            }
        }
        return istrm;
    }

    std::ostream& operator << (std::ostream& strm, Set& tmp)  noexcept{
        if(tmp.power == 0)
            strm << "Set is empty!";
        else{
            strm << "Set: ";
            for(int i = 0; i < tmp.getPower(); i++){
                if(i % 10 == 0)
                    strm << "\n";
                strm << tmp.getElemByIndex(i) << " ";
            }
        }
        strm << std::endl;
        return strm;
    }

    bool Set::Isin(int numLookFor) const noexcept{
        int * location, num;
        if(set){
            for(int i = 0; i < power; i++){
                location = (int*)(&set[i * 4]);
                num = *location;
                if(num == numLookFor){
                    return true;
                }
            }
        }
        return false;
    }


}