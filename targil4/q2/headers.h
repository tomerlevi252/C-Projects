void sortInt(int arr[],int size);
void sortDouble(double arr[],int size);
void sort(void *arr ,int size ,int type ,int (*func)(void *,void *));
int compareInt(void * a1,void * a2);
int compareDouble(void * a1,void * a2);
int compareChar(void * a1,void * a2);
int comapreCharPointer(void * a1,void * a2);


void printArray(void *arr,int size,int move,void (*func)(void *));
void printInt(void *arr);
void printDouble(void *arr);
void printChar(void *arr);
void printString(void *arr);
void printStringPointer(void *arr);
