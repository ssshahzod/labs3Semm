#include <iostream>
#include "definitions.hpp"


int main(){
    int ch; //choose input/output style
    int lines = Definitions::getInt("Input number of lines in matrix: ", -1);
    int columns = Definitions::getInt("Input number of columns: ", -1);

    auto* column = new Definitions::Column[lines];
    Definitions::Column* res;
    do {
        ch = Definitions::getInt("Choose input style:\n"
                                 "1. With \"0\" elements.\n"
                                 "2. Without \"0\" elements.\n", -1);
    }while(ch != 1 && ch != 2);
    if(ch == 1)
        Definitions::matInput(column, lines, columns);
    else
        Definitions::matInputAlt(column, lines, columns);

    res = Definitions::newMatrix(column, lines, Definitions::reverseNum);
    std::cout << "End of the input!\n";
    do {
        ch = Definitions::getInt("Choose output style:\n"
                                 "1. With \"0\" elements.\n"
                                 "2. Without \"0\" elements.\n", -1);
    }while(ch != 1 && ch != 2);
    Definitions::matOutput(column, lines, columns, "Input matrix: ",ch);
    std::cout << std::endl;
    Definitions::matOutput(res, lines, columns, "Result matrix (numbers reversed): ", ch);
    Definitions::matClear(column, lines);
    Definitions::matClear(res, lines);

  return 0;
}
