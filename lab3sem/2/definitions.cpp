#include <iostream>
#include "definitions.hpp"


namespace Lemniscatus{
    BoothLemniscate::BoothLemniscate(double m, double c) :center(0,0){
        if (m <= 0)
            throw std::logic_error("Incorrect M parameter!");
        M = m;
        C = c;
    }

    BoothLemniscate::BoothLemniscate(const Point &p0, double m, double c) : center(p0){
        if (m <= 0)
            throw std::logic_error("Incorrect M parameter!");
        M = m;
        C = c;
    }

    BoothLemniscate::BoothLemniscate(double x0, double y0, double m, double c) :center(x0, y0){
        if (m <= 0)
            throw std::logic_error("Incorrect M parameter!");
        M = m;
        C = c;
    }

    BoothLemniscate &BoothLemniscate::setM(double m){
        if(m <= 0)
            throw std::logic_error("Incorrect value!");
        M = m;
        return *this;
    }

    BoothLemniscate &BoothLemniscate::setC(double c){
        C = c;
        return *this;
    }

    int BoothLemniscate::curveType() const{
        enum type{Elliptical_type = 0, LemnOfBernoulli, Hyperbolic, Circles};
        if (C > 2*M*M)
            return Elliptical_type;
        else if(C == 0)
            return LemnOfBernoulli;
        else if(C < 2*M*M)
            return Hyperbolic;
        else
            return Circles;
    }

    double BoothLemniscate::area() const{
        //area depends on the type of the curve
        double par = 2*M*M;
        double a = par + C;
        if(C > par)
            return (3.14159 * C);

        else if(C < par){
            double b = par - C;
            return ((a - b)/2 * atan(sqrt(a)/sqrt(b)) + (sqrt(a)*sqrt(b))/2);
        }
        else if(C == par){
            if(center.cordX < 0)
                return (center.cordX * (-1) * 2*M);
            else
                return (center.cordX * 2*M);
        }
        else
            return 2*M*M;

    }

    Point BoothLemniscate::coef() const{
        //point.cordX - "a" param, point.cordY - "b" param
        double par = 2*M*M;
        Point res;
        if(C == 0)
            res.cordX = par;

        else if(C > par){
            res.cordX = sqrt(par + C);
            res.cordY = sqrt(C - par);
        }
        else if(C < par){
            res.cordX = sqrt(par + C);
            res.cordY = sqrt(par - C);
        }
        else
            res.cordX = 2*M;

        return res;
    }

    double BoothLemniscate::centerDistance(double angle) const{
        double par = 2*M*M;
        double a = par + C, b;
        if(C > par){
            b = C - par;
            return (sqrt(a*pow(cos(angle), 2) + b*pow(sin(angle),2)));
        }
        else if(C == 0)
            return (sqrt(a*cos(2*angle)));

        else if(C < par){
            b = par - C;
            return (sqrt(a*pow(cos(angle), 2) - b*pow(sin(angle), 2)));
        }
        else
            return(sqrt(2*par*pow(cos(angle), 2)));

    }

    void BoothLemniscate::frml(char* destin_array, size_t arsize) const { //formula: r^2 = a^2cos^2A +- b^2sin^2A ////without new
        char tmp[] = "r^2 =  (cosA)^2   (sinA)^2\n";
        size_t len = strlen(tmp);
        char* res = destin_array;
        double a = 2*M*M + C, b = C - 2*M*M;
        size_t size = 20;
        bool sign = false;
        if(b < 0){
            sign = true;
            b *= -1;
        }
        char num[size];
        sprintf(num, "%.2f", a);
        len += strlen(num);
        sprintf(num, "%.2f", b);
        len += strlen(num);
        if(arsize < len || destin_array == nullptr)
            throw std::length_error("Not enough size of the array!\n");
        sprintf(res, "%s", "r^2 = ");
        size = strlen(res);
        sprintf(res + size, "%.2f%s", a, "(cosA)^2");
        size = strlen(res);
        if(b == 0){
            sprintf(res + size, "%s", "\n");
            return;
        }
        if(sign)
            sprintf(res + size, "%s ", " -");
        else
            sprintf(res + size, "%s ", " +");
        size = strlen(res);
        sprintf(res + size, "%.2f%s", b, "(sinA)^2\n");
    }

}




