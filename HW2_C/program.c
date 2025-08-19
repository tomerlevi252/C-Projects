#include <stdio.h>
#include <stdarg.h>
#include "headers.h"


  int main(){
    int arr0[]={-2,1,-3,4,-1,2,1,-5,4};
    int arr1[]={2,8,14,-9,5,6,2,19,4};
    int arr2[]={8,5,2,4};
    int arr3[]={1,1,1,2,2,4,5};
    int arr4[]={3,4,1,2,5};
    int A[]={1,-12,0,-42};
    int B[]={1,-3};
   
    //for q3
    q3(arr0,sizeof(arr0)/sizeof(int));
    
    //for q4
    q4(9,-2,1,-3,4,-1,2,1,-5,4);
  
    //for q5 ,booly=1(true) else booly=0(false).  
    int booly=q5(arr1,sizeof(arr1)/sizeof(int),arr2,sizeof(arr2)/sizeof(int));     
    printf("%d\n",(booly>0)?1:0);
    
    //for q6
    q6(A,sizeof(A)/sizeof(int),B,sizeof(B)/sizeof(int));    
    
    //for q7    
    printf("%d\n",q7(arr3,sizeof(arr3)/sizeof(int)));
      
    //for q8    
    q8(arr1,sizeof(arr1)/sizeof(int));
     
    //to print q8 doing    
    printArray(arr1,sizeof(arr1)/sizeof(int));      
                   
    //for q9 
    q9(arr4,sizeof(arr4)/sizeof(int));
    
    //to print q9 doing
    printArray(arr4,sizeof(arr4)/sizeof(int));
    return 0;
  }
  


  void q3(int arr[],int n){
    int max_sum=arr[0];
    int current_sum=arr[0];
    int start=0;    
    int temp_start=0;
    int end=0;
    
    for(int i=1;i<n;i++){
      if(current_sum+arr[i]<arr[i])
      {
        current_sum=arr[i];
        temp_start=i;
      }
      else
        current_sum+=arr[i];
      
      if(current_sum>max_sum)
      {
        max_sum=current_sum;
        start=temp_start;
        end=i;    
      }
    }
    printf("SubArray of max sum: ");
    for(int i=start;i<=end;i++)
      printf("%d ",arr[i]);
    
    printf("\nMax sum of q3:%d\n",max_sum);
      
  }
 
 

  void q4(int length,...){
    
    va_list param;
    va_start(param,length);
    
    int current_sum=0;
    int max_sum=0;
    int num;
    int start=0;    
    int temp_start=0;
    int end=0;    
        
    for(int i=0;i<length;i++)
    {
      num=va_arg(param,int);
      
      if(current_sum+num<num)
      {
        current_sum=num;
        temp_start=i;  
      }
      else
        current_sum+=num;
      
      if(current_sum>max_sum)
      {
        max_sum=current_sum;
        start=temp_start;
        end=i;
      }      
    }
    
    va_end(param);
    
    //restart the ellipsis
    va_start(param,length);
    
    //skip the number before start;
    for(int i=0;i<start;i++)    
      va_arg(param,int);
    
    printf("SubArray of max sum: ");
    for(int i=start;i<=end;i++)
      printf("%d ",va_arg(param,int));
    printf("\nMax sum of q4:%d\n",max_sum);
            
  }
  
  
  
  int q5(int arr1[],int n1,int arr2[],int n2){
    if(n1==0 || n2==0)return 0;
    
    if(arr1[n1-1]==arr2[n2-1])
      return q5(arr1,n1-1,arr2,n2-1)+1;
    
    else 
    {
      return q5(arr1,n1-1,arr2,n2);
      return q5(arr1,n1,arr2,n2-1);
    }
    
  }
  
  
  
  void q6(int A[],int sizeA,int B[],int sizeB){
    
    int degreeA=sizeA-1;
    int degreeB=sizeB-1;
    
    int Q[sizeA];
    int R[sizeA];
    
    for(int i=0;i<=degreeA;i++)
    {
      Q[i]=0;
      R[i]=A[i];
    }
    
    for(int i=degreeA;i>=degreeB;i--)
    {
      if(R[i]!=0) 
      {
        Q[i-degreeB]=R[i]/B[degreeB];
        
        for(int j=0;j<=degreeB;j++)
          R[i-j]-=Q[i-degreeB]*B[degreeB-j];       
      }
    }
    
    printf("Qutient: ");
    for(int i=0;i<degreeA-degreeB+1;i++)
      printf("%d ",Q[i]);
      
    printf("\n");  
    
    printf("Remainder: ");
    for(int i=degreeB;i<=degreeA;i++)
      printf("%d ",R[i]);
      
    printf("\n");
       
  }  

  
  
  int q7(const int arr[],int n){   
    if(n==1)return 1;
    if(n==2){
      if(arr[0]<=arr[1])
        return 1;
      else return 0;
    }
    q7(arr,n-1);
    
  }  
 
 
 
  void q8Helper(int arr[],int n){
    //if only 1 number then it sorted.
    if(n<2) return;
    
    //if first > second , switch places.
    if(arr[0]>arr[1])
    {
      int temp=arr[0];
      arr[0]=arr[1];
      arr[1]=temp;
    }
    
    //recursive call for the rest of the array.
    q8Helper(arr+1,n-1);  
    
  }
  
  
  
  void q8(int arr[],int n){
    if(n<2)return;
    
    //do the first recursive call.
    q8Helper(arr,n);
    
    //do the second recursive calls.
    q8(arr,n-1);
   
  }
  
   
   
  void q9(int arr[],int n){
    if(n<2)return;
    
    int indexMin=min(arr,n);
    int indexMax=max(arr,n);
        
    swap(arr,indexMin);
    
    if(indexMax==0) 
      indexMax=indexMin;
    
    swap(arr+1,indexMax-1);
      
    q9(arr+2,n-2);      
  }



  //function helper for q9
  void swap(int arr[],int index){
    int temp=arr[0];
    arr[0]=arr[index];
    arr[index]=temp;
  }
  


  //function helper for q9 
  int min(int arr[],int n){
    int min=arr[0];
    int index=0;
    for(int i=1;i<n;i++){
      if(min>arr[i]){
        min=arr[i];
        index=i;
      }
    }
    return index;
  }



  //function helper for q9
  int max(int arr[],int n){
    int max=arr[0];
    int index=0;
    for(int i=1;i<n;i++){
      if(max<arr[i]){
        max=arr[i];
        index=i;
      }
    }
    return index;
  }  
  
 
  
  void printArray(int arr[],int n){
    for(int i=0;i<n;i++)
    { 
      if(i==n-1) printf("%d\n",arr[i]);
       
      else printf("%d,",arr[i]);
    }

  }
  
  
  
  
  
  
  
  
  
  
  
