//
// Created by cronion on 18.11.2021.
//

#ifndef INC_4TH_UTIL_H
#define INC_4TH_UTIL_H
#include <iostream>
#include <iterator>


template<class T>
class Iterator;

template<class T>
class array
{
public:
    array(): arr(new T*[0]), ar_size(0){arr[0] = nullptr;};

    explicit array(size_t sz): ar_size(sz), arr(new T*[sz]){
        for(int i = 0; i < sz; i++){
            arr[i] = nullptr;
        }
    }

    array(const array& inarr){
        delete inarr;
        ar_size = inarr->sz;
        inarr = new T*[ar_size];
        std::copy(inarr.arr, inarr.arr + ar_size, inarr);
    }

    ~array(){
        delete[] arr;
    }

    Iterator<T> begin(){
        return Iterator<T>(*arr);
    }

    Iterator<T> end(){
        return Iterator<T>(*(arr + ar_size));
    }

    bool isEmpty(size_t idx){
        return (arr[idx]);
    }

    T* operator [](size_t idx){
        return (arr[idx]);
    }

    void inputObj(size_t x, T* var){
        if(arr[x] == nullptr)
            arr[x] = var;
    }

    [[nodiscard]]size_t size() const{
        return ar_size;
    }

private:
    T** arr;
    size_t ar_size;
};

template<class T>
class Iterator
{
public:
    explicit Iterator(T* curr):current(curr){}

    Iterator& operator =(const Iterator& other){
        if (this != &other)
        {
            current = other.current;
        }
        return *this;
    }


    Iterator& operator ++(){
        current++;
        return *this;
    }

    Iterator operator ++(int i){
        Iterator tmp(current);
        ++current;
        return tmp;
    }

    T& operator *(){
        return **current;
    }

    T* operator ->(){
        return current;
    }

    bool operator ==(const Iterator& other) const{
        return current == other.current;
    }

    bool operator !=(const Iterator& other){
        return !(*this == other);
    }


private:
    T* current;
};


#endif //INC_4TH_UTIL_H
