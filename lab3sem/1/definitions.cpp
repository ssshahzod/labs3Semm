#include <iostream>
#include "definitions.hpp"

namespace Definitions{

    int getInt(const char* msg, int m){
	    while(true){
		    std::cout << msg;
		    int val;
		    std::cin >> val;

		    if(std::cin.fail()){
			    std::cin.clear();
			    std::cin.ignore(10000, '\n');
	        }
		    else{
		        if(m == -1 || (val >= 0 && val <= m))
		            return val;
		        else
                    continue;
		    }

	    }
    }


    void matInput(Column *arr, int rows, int columns){
        int tmp, size, k;
        auto *tempAr = new Node[columns];
        for(int i = 0; i < columns; i++)
            tempAr[i].col = tempAr[i].val = 0;

        for (int i = 0; i < rows; i++){
            k = 0;
            std::cout << "Input items for line #" << (i + 1) << ":" << std::endl;
            size = columns;
            for(int j = 0; j < columns; j++){
                if((tmp = getInt("", -1)) == 0){
                    size--;
                    tempAr[j].col = columns + 1;
                }
                else{
                    tempAr[j].col = j;
                    tempAr[j].val = tmp;
                }
            }
            arr[i].rowLenght = size;
            if(size == 0){
                arr[i].row = nullptr;
                continue;
            }
            else
                arr[i].row = new Node[size];

            for(int j = 0; j < columns; j++){
                if(tempAr[j].col == columns + 1)
                    continue;

                arr[i].row[k].col = tempAr[j].col;
                arr[i].row[k].val = tempAr[j].val;
                tempAr[j].col = tempAr[j].val = 0;
                k++;
            }
        }
        delete[] tempAr;
    }

    void matInputAlt(Column *arr, int rows, int columns){
        int line, col, val, tmp;
        Node* tempAr;
        for (int i = 0; i < rows; i++){
            arr[i].rowLenght = 0;
        }
        std::cout << "Input items (enter \"0\" in any field to end input):" << std::endl;
        while(true){
            if((line = getInt("Input line number:", rows)) == 0 ||
            (col = getInt("Input column number:", columns)) == 0 ||
            (val = getInt("Input value:", -1)) == 0){
                break;
            }
            else{
                tmp = arr[line - 1].rowLenght;
                if(tmp == 0){
                    arr[line - 1].row = new Node[1];
                    arr[line - 1].row[0].col = col - 1;
                    arr[line - 1].row[0].val = val;
                }
                else{
                    tempAr = (Node*)std::realloc(arr[line - 1].row, sizeof(Node) * tmp + 1);
                    if(tempAr != nullptr){
                        arr[line - 1].row = tempAr;
                        arr[line - 1].row[tmp].val = val;
                        arr[line - 1].row[tmp].col = col - 1;
                    }
                    else{
                       delete[] arr[line - 1].row;
                       arr[line - 1].rowLenght = 0;
                       std::cout << "Memory allocation error!" << std::endl;
                       break;
                    }
                }
                arr[line - 1].rowLenght += 1;
            }
            std::cout << std::endl;
        }

    }

    int reverseNum(int num){
        int rem, reverse = 0;
        if(num < 0)
            num *= -1;
        while(num > 0){
            rem = num % 10;
            reverse = reverse * 10 + rem;
            num /= 10;
        }
        return reverse;
    }

    Column* newMatrix(Column* arr, int rows, int(*func)(int)){
        auto res = new Column[rows];
        for(int i = 0; i < rows; i++){
            res[i].rowLenght = arr[i].rowLenght;
            if(res[i].rowLenght == 0)
                res[i].row = nullptr;
            else
                res[i].row = new Node[arr[i].rowLenght];
            for(int j = 0; j < res[i].rowLenght; j++){
                res[i].row[j].val = func(arr[i].row[j].val);
                res[i].row[j].col = arr[i].row[j].col;
            }
        }
        return res;
    }

    void matOutput(Column *arr, int rows, int columns, const char* msg, int mode){
        std::cout << msg << std::endl;
        int tmp;
        if(mode == 1) {
            for (int i = 0; i < rows; i++) {
                tmp = 0;
                if (arr[i].rowLenght == 0) {
                    for (int j = 0; j < columns; j++)
                        std::cout << "0" << " ";
                    std::cout << std::endl;
                    continue;
                }
                for (int j = 0; j < columns; j++) {
                    if (tmp < arr[i].rowLenght && j == arr[i].row[tmp].col) {
                        std::cout << arr[i].row[tmp].val << " ";
                        tmp++;
                    } else
                        std::cout << "0" << " ";

                }
                std::cout << std::endl;
            }
        }
        else if(mode == 2){
            std::cout << "Output format: (line, column, value).\n";
            for (int i = 0; i < rows; i++) {
                tmp = 0;
                if (arr[i].rowLenght == 0) {
                    continue;
                }
                for (int j = 0; j < columns; j++) {
                    if (tmp < arr[i].rowLenght && j == arr[i].row[tmp].col) {
                        std::cout << "(" << i + 1 << "," << j + 1<< ") " << arr[i].row[tmp].val << " ";
                        tmp++;
                    }
                }
                std::cout << std::endl;
            }
        }
    }

    Column* matClear(Column *arr, int rows){
        for(int i = 0; i < rows; i++)
            if(arr[i].rowLenght != 0)
                delete[] arr[i].row;

        delete[] arr;
        return nullptr;
    }

}