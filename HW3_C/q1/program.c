#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers.h"

#define MAX_GEN 11//max gen is 10 because in question he want to have the gen we give + how much we want to make.
#define MAX_ROW 10
#define MAX_COLUMN 10

typedef enum {dead=0,alive=1} state;

  int main(){
    int gen,row,column;
    int temp;
    
    temp=scanf("%d",&row);  
    if(temp!=1)
    {
      printf("ERROR, Value not numeric.\n");
      return 1;
    }
    if(row>10 || row<0)
    {
      printf("ERROR, Exceeding the maximum range of Rows.\n");
      return 1;      
    }
    
    temp=scanf("%d",&column);     
    if(temp!=1)
    {
      printf("ERROR, Value not numeric.\n");
      return 1;
    }  
    if(column>10 || column<0)
    {
      printf("ERROR, Exceeding the maximum range of Columns.\n");
      return 1;      
    }
       
    temp=scanf("%d",&gen);
    if(temp!=1)
    {
      printf("ERROR, Value not numeric.\n");
      return 1;
    }
    if(gen>10 || gen<0)
    {
      printf("ERROR, Exceeding the maximum range of Generations.\n");
      return 1;      
    }     
      
                        
    int arr[MAX_GEN][MAX_ROW][MAX_COLUMN]={0};//reset arr.
    
    for(int i=0;i<row;i++)//get zero gen.
      for(int j=0;j<column;j++)
      {
        temp=scanf("%d",&arr[0][i][j]);
        if(temp!=1 || (arr[0][i][j]!=1 && arr[0][i][j]!=0))
        {
          printf("ERROR, Value not numeric.\n");      
          return 1;
        } 
      }


    for(int g=0;g<gen+1;g++)//make the rest of the gens.
      for(int i=0;i<row;i++)     
        for(int j=0;j<column;j++)       
          change(arr,g,i,j,row,column);
  
  
    printArray(arr,gen+1,row,column);//print all the gens.
      
    return 0;
  }
  
  
   
  void change(int a[][MAX_ROW][MAX_COLUMN], int gen, int row, int column,int nrow,int ncolumn){
    int count=countNeighbors(a,gen,row,column,nrow,ncolumn);
    
    if(gen<MAX_GEN-1)
    {
      if(a[gen][row][column]==alive) //current gen.
      {
        if(count>3 || count<2)
          a[gen+1][row][column]=dead;//not alive next gen.
        else a[gen+1][row][column]=alive;//alive next gen.
      }
        
      else if(count==3)
        a[gen+1][row][column]=alive;//alive next gen.
        
    }
  }
  
  
  
  int countNeighbors(int a[][MAX_ROW][MAX_COLUMN],int gen,int row,int column,int nrow,int ncolumn){
    int count=0;
    
    if(row>0 && a[gen][row-1][column]==alive) //up
      count++;
      
    if(row<nrow-1 && a[gen][row+1][column]==alive)//down     
      count++;
      
    if(row>0 && column>0 && a[gen][row-1][column-1]==alive)//up left
      count++;
      
    if(row>0 && column<ncolumn-1 && a[gen][row-1][column+1]==alive)//up right
      count++;
      
    if(column>0 && a[gen][row][column-1]==alive)//left 
      count++;
        
    if(column<ncolumn-1 && a[gen][row][column+1]==alive)//right
      count++;
      
   if(row<nrow-1 && column>0 && a[gen][row+1][column-1]==alive)//down left
      count++;
      
   if(row<nrow-1 && column<ncolumn-1 && a[gen][row+1][column+1]==alive)//down right
      count++;
    
    return count;
  }
  
  
  
  void printArray(int a[][MAX_ROW][MAX_COLUMN],int gen,int row,int column){
 
    for(int g=0;g<gen;g++)
    {
      printf("Gen %d:\n",g);
      for(int i=0;i<row;i++)
      {
        printf("{");
        for(int j=0;j<column;j++)
        {
          if(j!=column-1)
            printf("%d,",a[g][i][j]);
          else printf("%d}\n",a[g][i][j]);
        }
      }
      printf("\n");
    }   
  }
 
