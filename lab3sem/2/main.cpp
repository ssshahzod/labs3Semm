//Booth Lemniscate class

#include <iostream>
#include "definitions.hpp"


int main(){
    Lemniscatus::BoothLemniscate a;
    Lemniscatus::Point tmp;
    std::string types[] = {"Elliptical type.", "Special case (c = 0): lemniscate of Bernoulli.",
                           "Hyperbolic type.", "Special case (c = 2m^2): 2 circles."};
    char* str = new char[50];
    double ang, m, c;
    int fl, ch = 0;
    menuPrint();
    do{
        ch = choice(6);
        if(ch == 1){
            std::cout << "Input new x, y, M and C parameters to continue or press ctrl+D to exit: "
            << std::endl;
            std::cout << "Input x coordinate: ";
            getNum(tmp.cordX);
            std::cout << "\nInput y coordinate: ";
            getNum(tmp.cordY);
            a.setP(tmp);
            std::cout << "\nInput m parameter (m > 0): ";
            getNum(m);
            a.setM(m);
            std::cout << "\nInput c parameter: ";
            getNum(c);
            a.setC(c);
        }

        else if(ch == 2){
            std::cout << "Area: " << a.area() << std::endl;
        }
        else if(ch == 3){
            std::cout << "Type of the curve: " << types[a.curveType()] << std::endl;
        }
        else if(ch == 4){
            std::cout << "Coefficients: " << "A: " << a.coef().cordX
                      << " B: " << a.coef().cordY << std::endl;
        }
        else if(ch == 5){
            std::cout << "Input angle to count distance: " << std::endl;
            getNum(ang);
            std::cout << "Distance: " << a.centerDistance(ang) << std::endl;
        }
        else if(ch == 6) {
            std::cout << "Your curve is: ";
            a.frml(str, 50);
            std::cout << str;
        }
        else
            continue;
    }while(ch);
    delete [] str;
    return 0;

}

void menuPrint(){
    std::cout << "Booths lemniscate program. "
                 "(x^2 + y^2)^2 - (2M^2 + C)x^2 + (2M^2 - C)y^2 = 0" << std::endl;
    std::cout << "0.Exit.\n"
                 "1.Input lemniscate.\n"
                 "2.Get area.\n"
                 "3.Get curve type.\n"
                 "4.Get curve coefficients.\n"
                 "5.Get distance to center from angle.\n"
                 "6.Get formula.\n";
}

template <class T>
int getNum(T &a){
    std::cin >> a;
    while(!std::cin.good()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        std::cout << "Wrong input! Try again: ";
        std::cin >> a;
    }
    return 1;
}


int choice(int max){
    int x;
    do{
        std::cout << "Make your choice: ";
        getNum(x);
    }while(x < 0 || x > max);
    return x;
}