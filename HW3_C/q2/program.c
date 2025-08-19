#include <stdio.h>
#include "headers.h"

  int main(){
    int x=284119;
    printf("The number: %d in Binary is:\n",x);
    printBits(x);
    
    int y=16;
    printf("\nWe loop the number: %d , %d Bits and got:\n",x,y);
    printBits(loopBits(x,y));
    
    
    char str[]={"61646678"};
    printf("\nThe arrays of '%s' in Bits is:\n",str);
    printBits(ChangeCharArrayToNum(str));
    
    return 0;
  }
  
  
  
  void printBits(unsigned int num){//2.1
      
    for(int i=31;i>=0;i--)//start at 31,the most significant bit, to 0.
    { 
      unsigned int bit=(num & (1<<i))!=0;//the !=0 will change numbers greater the 1 to 1, and if 0 will put 0.
      printf("%u",bit);//%u print unsigned integer.
    }  
    
    printf("\n");
 
  }
  
  
  
  unsigned int loopBits(unsigned int a,int n){//2.2
    return (a<<n) | (a>>(32-n));
    //a<<n will move the bits in a ,n times left.
    //a>>(32-n) will move the bits in a ,32-n times right. 
    // '|' will do the OR logic to the values in (a<<n),(a>>(32-n)).
    //and that will make sure that we loop a ,n bits.
  }
  
  
   
  unsigned int ChangeCharArrayToNum(char str[]) {
    unsigned int result=0;

    for (int i=7;i>=0;i--) 
    {      
        int digit=str[7-i]-'0';   //'0'=48     
        result =result | digit<<(i*4);//i*4 will always put the num in the 7-i position  to the most left postion it need to be.
    }

    return result;
}

  
