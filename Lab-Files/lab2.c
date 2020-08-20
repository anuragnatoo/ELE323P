#include "tm4c123gh6pm.h"
#include "time.h"
int main()
{
  int flag=0;
  int count=0;
*((unsigned int *)0x400FE608)=0x20U;
*((unsigned int *)0x40025400)=0x0EU;
*((unsigned int *)0x4002551C)=0x1FU;
*((unsigned int *)0x40025524)=0xFF;
*((unsigned int *)0x40025510)=0x10;
while(1)
{
if(*((unsigned int *)0x40025040)==0 && flag==0) {
  flag=1;
  if(count==0)
    *((unsigned int *)0x40025038)=0x04;
  else if(count==1)
    *((unsigned int *)0x40025038)=0x08;
  else if(count==2)
    *((unsigned int *)0x40025038)=0x02;
  
  count = (count+1)%3;
}
else if(flag==1 && *((unsigned int *)0x40025040)!=0)
 flag=0;
}
}