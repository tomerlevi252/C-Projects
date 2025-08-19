#include <stdio.h>
#include "headers.h"
#include <string.h>

  int main (){
    
    char * arrP1[] = {"father" ,"mother" ,NULL};
    char * arrP2[] = {"sister" ,"brother" ,"grandfather" ,NULL};
    char * arrP3[] = {"grandmother" ,NULL};
    char * arrP4[] = {"uncle" ,"aunt",NULL};
    char ** arrPP[] = {arrP1 ,arrP2 ,arrP3 ,arrP4 ,NULL};
  
    printAllStrings(arrPP);    
    Sort(arrPP);   
    printAllStrings(arrPP);   
    printf("%s\n", maxLengthString (arrPP));

   return 0;  
  }
  
  
  
  //return the longest array of all the arrays.
  char* maxLengthString(char ***arrPP){
  
    char *max="";
    int maxLen=0;
    
    for(int i=0;arrPP[i]!=NULL;i++)
    {
      for(int j=0;arrPP[i][j]!=NULL;j++)
      {
        int tempLen=strlen(arrPP[i][j]);
        if(tempLen>maxLen)
        {
          maxLen=tempLen;
          max=arrPP[i][j];
        }            
      }      
    }
    return max;    
  }  
 
 
  
  //sort the arrays.
  void Sort(char ***arrPP) { 
    int counter=countMaxSize(arrPP)-1;
    char *temp[counter];
    int c=0;
    
    //fill the temp array with the strings.
    for(int i=0;arrPP[i]!=NULL;i++)
    {
      for(int j=0;arrPP[i][j]!=NULL;j++)
      {
        temp[c]=arrPP[i][j];
        c++;
      }
    }
    
    //Bubble sort.
    bubbleSort(temp,counter);
 

    //organize the arrPP alphabetically.
    c=0;
    for(int i=0;arrPP[i]!=NULL;i++)  
      for(int j=0;arrPP[i][j]!=NULL;j++)      
        arrPP[i][j]=temp[c++];
            
  }
    
  void bubbleSort(char *arr[],int size){
  
    for(int i=0;i<size;i++)  
      for(int j=0;j<size-i;j++)
      {
         
        if(arr[j][0]==arr[j+1][0])
        {
          for(int k=1;k<sizeof(**arr);k++)
          {
            if(arr[j][k]>arr[j+1][k])
              {
                char * temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
              }
          }
        } 
                
        else if(arr[j][0]>arr[j+1][0])
        {
          char * temp=arr[j];
          arr[j]=arr[j+1];
          arr[j+1]=temp;
        }  
      }  
  } 
 
 
 
 
  
  //print all arrays.
  void printAllStrings(char ***arrPP){
    
    for(int i=0;arrPP[i]!=NULL;i++)
      for(int j=0;arrPP[i][j]!=NULL;j++)
        printf("%s\n",arrPP[i][j]);
        
   printf("\n");

  }
  
  
   
  //return the max size of all the arrays combine.  
  int countMaxSize(char ***arrPP){
    int count=0;
    
    for(int i=0;arrPP[i]!=NULL;i++)    
      for(int j=0;arrPP[i][j]!=NULL;j++)
        count++;
  
    return count;
  }
  
  
  
  
  
  
  
  
  

