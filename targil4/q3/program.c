#include <stdio.h>
#include "headers.h"


  int main(){
  
    int A[]={5,-5,14,5,2};
    
    int B[]={3,6,11};
    
    int C[]={4,1,-3,4};
    
    int D[]={6,2,7,1,8,2};
    
    int E[]={2,15};
    
    int F[]={3,4,-2};
    
    int *All[]={A,B,C,D,E,F,NULL};
    
    transpose(All); 

    return 0;
  }
  
   
  
  void transpose(int *all[]) {

    int **tempAllPointer=all;
 
    int maxColumns=0;

    while(*tempAllPointer!=NULL) 
    {
      int *currentRow = *tempAllPointer;
      int rowSize = *currentRow; 
      
      if(rowSize > maxColumns)      
        maxColumns = rowSize;
      
      tempAllPointer++;
    }


    for(int i=0;i<maxColumns;i++)
    {
      tempAllPointer = all;
      
      while(*tempAllPointer != NULL)
        {
          int *currentRow = *tempAllPointer;
          int rowSize = *currentRow;
          
          if (i < rowSize-1) 
            printf("%4d",*(currentRow+i+1));
          else
            printf("    ");
        
          tempAllPointer++;
        }
      printf("\n"); 
    }
  }
  
  
  
  
  
  
  
  
  
  
  
