#ifndef DEFINITIONS_H
#define DEFINITIONS_H
#include "gtest/gtest.h"
#include <cmath>

void menuPrint();
template <class T> int getNum(T &a);
int choice(int max);

namespace Lemniscatus{

    struct Point{
        double cordX, cordY;
        Point(double cordx0 = 0, double cordy0 = 0) :cordX(cordx0), cordY(cordy0){}
    };

    class BoothLemniscate{
        private:
            Point center;
            double M, C; //curve parameters. M > 0, C - has no boundaries
        public:
            //constructors
            BoothLemniscate(double M = 1, double C = 1);
            BoothLemniscate(const Point &p0, double M = 1, double C = 1);
            BoothLemniscate(double x0, double y0, double M, double C);

            //setters
            BoothLemniscate &setP(const Point &p0){ center = p0; return *this;}
            BoothLemniscate &setM(double m);
            BoothLemniscate &setC(double c);

            //getters
            Point getP() const{ return center;};
            double getM() const { return M;};
            double getC() const { return C;};
            
            //other methods
            int curveType() const;
            double area() const;
            Point coef() const; //Point type is used to return both coefficients at once ///
            double centerDistance(double angle) const;
            void frml(char* destin_array, size_t arsize) const;

    };
}

#endif