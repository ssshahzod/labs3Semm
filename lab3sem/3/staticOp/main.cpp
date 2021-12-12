#include <iostream>
#include "definitions.hpp"

int main(){
    int num, ch, index = 0, size, var;
    def::Set sets[100], tmp;
    menuPrint();
    do{
        std::cout << "You entered: " << index << " sets" << std::endl;
        ch = choice(8, "Make your choice: ");
        if(ch == 1){
            std::cout << "Input size of the set: ";
            def::getNum(num);
            try{
                sets[index] = def::Set(num);
                index++;
            }
            catch(const std::exception &msg){
                std::cout << msg.what() << std::endl;
            }
        }
        else if(ch == 2){
            def::Set temp;
            Input(std::cin, std::cout, temp);
            sets[index] = temp;
            index++;
        }
        else if(ch == 3){
            size = choice(index, "Choose set to input elem in: ");
            std::cout << "Input elem: ";
            def::getNum(var);
            sets[size - 1].Add(var);
            std::cout << sets[size];
        }
        else if(ch == 4){
            size = choice(index, "Choose first set to interesct: ");
            var = choice(index, "Choose second set: ");
            tmp = sets[size - 1] * sets[var - 1];
            std::cout << "Your result: ";
            std::cout << tmp;
        }
        else if(ch == 5){
            size = choice(index, "Choose set to subtract from: ");
            var = choice(index, "Choose set to subtract what: ");
            tmp = sets[size - 1] - sets[var - 1];
            std::cout << "Your result: ";
            std::cout << tmp;
        }
        else if(ch == 6) {
            size = choice(index, "Choose first set to unite: ");
            var = choice(index, "Choose second set: ");
            tmp = sets[size - 1] + sets[var - 1];
            std::cout << "Your result: ";
            std::cout << tmp;
        }
        else if(ch == 7){
            size = choice(index, "Input num of array to print: ");
            std::cout << sets[size - 1];
        }
        else if(ch == 8){
            size = choice(index, "Choose set to work with: ");
            std::cout << "Input elem to search: ";
            def::getNum(num);
            if(sets[size - 1].Isin(num)){
                std::cout << "Elem: " << num << " is in the set." << std::endl;
            }
            else
                std::cout << "Elem was not found." << std::endl;
        }
        else
            continue;
    }while(ch);

    return 1;
}


void menuPrint(){
    std::cout << "Integer set class program." << std::endl;
    std::cout << "0.Exit.\n"
                 "1.Generate random set.\n"
                 "2.Input set.\n"
                 "3.Add elem in set.\n"
                 "4.Intersection of sets.\n"
                 "5.Difference of sets.\n"
                 "6.Union of sets.\n"
                 "7.Output set.\n"
                 "8.Check set for elem.\n";
}


int choice(int max, const char* msg){
    int x;
    do{
        std::cout << msg;
        def::getNum(x);
    }while(x < 0 || x > max);
    return x;
}