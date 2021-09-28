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
        /*
        0 -> "Elliptical type."
        1 -> "Special case (c = 0): lemniscate of Bernoulli."
        2 -> "Hyperbolic type."
        3 -> "Special case (c = 2m^2): 2 circles."
         */
        if (C > 2*M*M)
            return 0;
        else if(C == 0)
            return 1;
        else if(C < 2*M*M)
            return 2;
        else
            return 3;
    }

    double BoothLemniscate::area(){
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

    Point BoothLemniscate::coef(){
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

    double BoothLemniscate::centerDistance(double angle) {
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

    char* BoothLemniscate::frml() const { //formula: r^2 = a^2cos^2A +- b^2sin^2A
        char tmp[] = "r^2 =  (cosA)^2   (sinA)^2\n";
        size_t len = strlen(tmp);
        double a = 0, b = 0;
        size_t size = 20;
        bool sign = false;
        a = 2*M*M + C;
        b = C - 2*M*M;
        if(b < 0){
            sign = true;
            b *= -1;
        }
        char num[size];
        sprintf(num, "%.2f", a);
        len += strlen(num);
        sprintf(num, "%.2f", b);
        len += strlen(num);
        char* res = new char[len];
        sprintf(res, "%s", "r^2 = ");
        size = strlen(res);
        sprintf(res + size, "%.2f%s", a, "(cosA)^2 ");
        size = strlen(res);
        if(sign)
            sprintf(res + size, "%s ", "-");
        else
            sprintf(res + size, "%s ", "+");
        size = strlen(res);
        sprintf(res + size, "%.2f%s", b, "(sinA)^2\n");
        return res;
    }

}




