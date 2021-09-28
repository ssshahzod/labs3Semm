//Booth Lemniscate class

#include <iostream>
#include "definitions.hpp"


int main(){
    Lemniscatus::BoothLemniscate a(4, 5, 6, 10);
    Lemniscatus::Point tmp;
    std::string types[] = {"Elliptical type.", "Special case (c = 0): lemniscate of Bernoulli.",
                           "Hyperbolic type.", "Special case (c = 2m^2): 2 circles."};
    char* str;
    double ang, m, c;
    int fl = 1;
    while(fl){
        std::cout << "Your curve is: ";
        str = a.frml();
        std::cout << str;
        delete [] str;
        std::cout << "Area: " << a.area() << std::endl;
        std::cout << "Type of the curve: " << types[a.curveType()] << std::endl;
        std::cout << "Coefficients: " << "A: " << a.coef().cordX
                                        << " B: " << a.coef().cordY << std::endl;
        int exval = 1;
        while(exval){
            std::cout << "Input angle to count distance: " << std::endl;
            std::cin >> ang;
            exval = std::cin.good();
            if(!exval){
                continue;
            }
            std::cout << "Distance: " << a.centerDistance(ang) << std::endl;
        }

        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Input new x, y, M and C parameters to continue or press ctrl+D to exit: "
                        << std::endl;
        std::cin >> tmp.cordX >> tmp.cordY >> m >> c;
        if(std::cin.good()){
            a.setC(c);
            a.setM(m);
            a.setP(tmp);
        }
        else
            fl = 0;
    }
    return 0;

}