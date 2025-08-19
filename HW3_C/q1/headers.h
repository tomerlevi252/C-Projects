#define MAX_GEN 11
#define MAX_ROW 10
#define MAX_COLUMN 10

void change(int a[][MAX_ROW][MAX_COLUMN], int gen, int row, int column,int nrow,int ncolumn);
int countNeighbors(int a[][MAX_ROW][MAX_COLUMN],int gen,int row,int column,int nrow,int ncolumn);
void printArray(int a[][MAX_ROW][MAX_COLUMN],int gen,int row,int column);
