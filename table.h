#ifndef TABLE_H
#define TABLE_H


#include <iostream>
#include <iterator>
#include <math.h>

template<typename key1, typename key2, class data>
struct Node{
    key1 xkey;
    key2 ykey;
    data* info;
    bool isTaken;
};

template<typename key1, typename key2, class data>
class Iterator;

template<typename key1, typename key2, class data>
class Table
{
public:
    enum containerErrors{
        no_error = 100,
        cell_is_taken,
    };
    explicit Table(size_t table_size){
        size = table_size;
        fill = 0;
        width = static_cast<size_t>(sqrt(table_size));
        arr = new Node<key1, key2, data>[table_size];
        for(size_t i = 0; i < table_size; i++){
            arr[i].data = nullptr;
            arr[i].isTaken = false;
        }
    }

    Iterator<key1, key2, data> begin(){
        return Iterator<key1, key2, data>(arr[0], this);
    }

    Iterator<key1, key2, data> end(){
        return Iterator<key1, key2, data>(arr[size], this);
    }

    [[nodiscard]]size_t get_size() const{
        return size;
    }

    [[nodiscard]]size_t fullness() const{
        return fill;
    }

    [[nodiscard]]size_t get_width() const{
        return width;
    }

    int inputObject(Node<key1, key2, data>* tmp){
        size_t pos = (tmp->ykey * width) + tmp->xkey;
        if(arr[pos].isTaken){
            return cell_is_taken;
        }
        else{
            arr[pos] = tmp;
            /*arr[pos].data = tmp;
            arr[pos].isTaken = true;
            arr[pos].xkey = tmp->xkey;*/
        }
    }

private:
    Node<key1, key2, data>* arr;
    size_t size;
    size_t width;
    size_t fill;
};

template<typename key1, typename key2, class data>
class Iterator
{
public:
    Iterator(Node<key1, key2, data>* curr, Table<key1, key2, data>* table):current(curr), table(table){}

    Node<key1, key2, data>& operator++(){
        current++;
        return *current;
    }

    Node<key1, key2, data>* operator*(){
        return current;
    }

    bool operator !=(const Iterator& other){
        return !(*this == other);
    }

    bool operator ==(const Iterator& other){
        return (*this == other);
    }

private:
    Node<key1, key2, data>* current;
    Table<key1, key2, data>* table;
};


#endif