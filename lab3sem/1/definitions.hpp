namespace Definitions{

typedef struct Node{
    int col;
    int val;
} Node;

typedef struct Column{
    int rowLenght;
    Node *row;
} Column;



int getInt(const char* msg, int m);
void matInput(Column *arr, int rows, int columns);
void matInputAlt(Column *arr, int rows, int columns);
void matOutput(Column *arr, int rows, int columns, const char* msg, int mode);
Column* matClear(Column *arr, int rows);
Column* newMatrix(Column* arr, int rows, int(*func)(int));
int reverseNum(int num);

}
