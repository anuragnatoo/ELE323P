#include "tm4c123gh6pm.h"
int main()
{
  *((unsigned int *)0x400FE608)=0x20U;
  *((unsigned int *)0x40025400)=0x0EU;
  *((unsigned int *)0x4002551C)=0x0EU;
  
  while(1){
  *((unsigned int *)0x400253FC)=0x02;
  for(int i=0;i<100000;i++){
  
  }
  *((unsigned int *)0x400253FC)=0x08;
  for(int i=0;i<100000;i++){
  }

}

}