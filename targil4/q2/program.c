#include <stdio.h>
#include <string.h>
#include "headers.h"

  int main(){
  
    int a[]={2,7,6,4,1};
    
    double b[]={12.5,2.7,3.0,5.5,5.9,1.0};
    
    char c[][5]={"abc","xy","ac"};
    
    char *d[]={"abc","xy","ac"};

    
   // sortInt (a ,sizeof(a)/sizeof(a[0]));  // dont need it for the problem 
   // sortDouble(b ,sizeof(b)/sizeof(b[0])); // dont need it for the problem
    
    printf("before the sort:\n");
    printArray(a ,sizeof(a)/sizeof(a[0]) ,sizeof(a[0]) ,printInt);
    printArray(b ,sizeof(b)/sizeof(b[0]) ,sizeof(b[0]) ,printDouble);
    printArray(c ,sizeof(c)/sizeof(c[0]) ,sizeof(c[0]) ,printString);
    printArray(d ,sizeof(d)/sizeof(d[0]) ,sizeof(d[0]) ,printStringPointer);
    
    printf("\n");
    
    sort(a , sizeof(a)/sizeof(a[0]) , sizeof(a[0]) , compareInt );
    sort(b , sizeof(b)/sizeof(b[0]) , sizeof(b[0]) , compareDouble );
    sort(c , sizeof(c)/sizeof(c[0]) , sizeof(c[0]) , compareChar );
    sort(d , sizeof(d)/sizeof(d[0]) , sizeof(d[0]) , comapreCharPointer );
    
    printf("after the sort:\n");    
    printArray(a ,sizeof(a)/sizeof(a[0]) ,sizeof(a[0]) ,printInt);
    printArray(b ,sizeof(b)/sizeof(b[0]) ,sizeof(b[0]) ,printDouble);
    printArray(c ,sizeof(c)/sizeof(c[0]) ,sizeof(c[0]) ,printString);
    printArray(d ,sizeof(d)/sizeof(d[0]) ,sizeof(d[0]) ,printStringPointer);
       
    return 0;
  }
  
  //arr --> the pointer of the array.
  //size --> the size of the array.
  //type --> the type of the array.
  //func --> the pointer to the comparison function that was given.
  void sort(void *arr ,int size ,int type ,int (*func)(void *,void *)){
        
    for(int i=0;i<size-1;i++)    
      for(int j=0;j<size-1;j++)
      {
        if(func((char*)arr+j*type ,(char*)arr+(j+1)*type))//if(1) works.
        {
          for(int k=0;k<type;k++)//need this for to swap all the bytes.
          {
            char temp=*((char*)arr+j*type+k);
            *((char*)arr+j*type+k) = *((char*)arr+(j+1)*type+k);
            *((char*)arr+(j+1)*type+k) = temp;
          }
        }          
      }
  }
  
  
  int compareInt(void * a1,void * a2){
  
    if(*(int*)a1 > *(int*)a2)return 1;//switch
    return 0;//dont switch  
    
  }



  int compareDouble(void * a1,void * a2){
  
    if(*(double*)a1 > *(double*)a2)return 1;//switch
    return 0;//dont switch  
 
  }  
  
  
  
  int compareChar(void * a1,void * a2){
    return strcmp((char*)a1,(char*)a2);
  } 
  
  
  
  int comapreCharPointer(void * a1,void * a2){
    return strcmp(*(char**)a1,*(char**)a2);
    
  }
   
   
       
  void sortInt(int arr[],int size){
    
    for(int i=0;i<size-1;i++)
      for(int j=0;j<size-1;j++)
        if(arr[j]>arr[j+1])
        {
          int temp=arr[j];
          arr[j]=arr[j+1];
          arr[j+1]=temp;
        }       
  }  
  
  
  
  void sortDouble(double arr[],int size){
    
    for(int i=0;i<size-1;i++)
      for(int j=0;j<size-1;j++)
        if(arr[j]>arr[j+1])
        {
          double temp=arr[j];
          arr[j]=arr[j+1];
          arr[j+1]=temp;
        }       
  }   
  
  
  
  //all the prints type.
  void printArray(void *arr,int size,int move,void (*func)(void *)){
    
    for(int i=0;i<size;i++)
    {
      func((char*)arr+move*i);
      if(i<size-1)
        printf(",");  
    }
    
    printf("\n");
  }
  
  
  
  void printInt(void *arr){   
    printf("%d",*(int*)arr);        
  }



  void printDouble(void *arr){   
    printf("%f",*(double*)arr);         
  }
  
  
  
  void printChar(void *arr){   
    printf("%c",*(char*)arr);         
  }
  
  
  
  void printString(void *arr){   
    printf("%s",(char*)arr);          
  }
  
  
  
  void printStringPointer(void *arr){
    printf("%s",*(char**)arr);
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
