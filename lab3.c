#include "tm4c123gh6pm.h"
int main()
{
  void delay();
*((volatile unsigned int*)0x400FE608)=0x04;
*((volatile unsigned int*)0x40006400)=0xF0;
*((volatile unsigned int*)0x4000651C)=0xF0;

while(1)
{
*((volatile unsigned int*)0x40006040)=~(0x01);
*((volatile unsigned int*)0x40006080)=~(0x02);
*((volatile unsigned int*)0x40006100)=~(0x04);
*((volatile unsigned int*)0x40006200)=~(0x08);
delay();
*((volatile unsigned int*)0x40006040)=~(0x01);
*((volatile unsigned int*)0x40006080)=~(0x02);
*((volatile unsigned int*)0x40006100)=~(0x04);
*((volatile unsigned int*)0x40006200)=0x08;
delay();
*((volatile unsigned int*)0x40006040)=~(0x01);
*((volatile unsigned int*)0x40006080)=~(0x02);
*((volatile unsigned int*)0x40006100)=0x04;
*((volatile unsigned int*)0x40006200)=~(0x08);
delay();
*((volatile unsigned int*)0x40006040)=~(0x01);
*((volatile unsigned int*)0x40006080)=~(0x02);
*((volatile unsigned int*)0x40006100)=0x04;
*((volatile unsigned int*)0x40006200)=0x08;
delay();
*((volatile unsigned int*)0x40006040)=~(0x01);
*((volatile unsigned int*)0x40006080)=0x02;
*((volatile unsigned int*)0x40006100)=~(0x04);
*((volatile unsigned int*)0x40006200)=~(0x08);
delay();
*((volatile unsigned int*)0x40006040)=~(0x01);
*((volatile unsigned int*)0x40006080)=0x02;
*((volatile unsigned int*)0x40006100)=~(0x04);
*((volatile unsigned int*)0x40006200)=0x08;
delay();
*((volatile unsigned int*)0x40006040)=~(0x01);
*((volatile unsigned int*)0x40006080)=0x02;
*((volatile unsigned int*)0x40006100)=0x04;
*((volatile unsigned int*)0x40006200)=~(0x08);
delay();
*((volatile unsigned int*)0x40006040)=~(0x01);
*((volatile unsigned int*)0x40006080)=0x02;
*((volatile unsigned int*)0x40006100)=0x04;
*((volatile unsigned int*)0x40006200)=0x08;
delay();
*((volatile unsigned int*)0x40006040)=0x01;
*((volatile unsigned int*)0x40006080)=~(0x02);
*((volatile unsigned int*)0x40006100)=~(0x04);
*((volatile unsigned int*)0x40006200)=~(0x08);
delay();
*((volatile unsigned int*)0x40006040)=0x01;
*((volatile unsigned int*)0x40006080)=~(0x02);
*((volatile unsigned int*)0x40006100)=~(0x04);
*((volatile unsigned int*)0x40006200)=0x08;
delay();
*((volatile unsigned int*)0x40006040)=0x01;
*((volatile unsigned int*)0x40006080)=~(0x02);
*((volatile unsigned int*)0x40006100)=0x04;
*((volatile unsigned int*)0x40006200)=~(0x08);
delay();
*((volatile unsigned int*)0x40006040)=0x01;
*((volatile unsigned int*)0x40006080)=~(0x02);
*((volatile unsigned int*)0x40006100)=0x04;
*((volatile unsigned int*)0x40006200)=0x08;
delay();
*((volatile unsigned int*)0x40006040)=0x01;
*((volatile unsigned int*)0x40006080)=0x02;
*((volatile unsigned int*)0x40006100)=~(0x04);
*((volatile unsigned int*)0x40006200)=~(0x08);
delay();
*((volatile unsigned int*)0x40006040)=0x01;
*((volatile unsigned int*)0x40006080)=0x02;
*((volatile unsigned int*)0x40006100)=~(0x04);
*((volatile unsigned int*)0x40006200)=0x08;
delay();
*((volatile unsigned int*)0x40006040)=0x01;
*((volatile unsigned int*)0x40006080)=0x02;
*((volatile unsigned int*)0x40006100)=0x04;
*((volatile unsigned int*)0x40006200)=~(0x08);
delay();
*((volatile unsigned int*)0x40006040)=0x01;
*((volatile unsigned int*)0x40006080)=0x02;
*((volatile unsigned int*)0x40006100)=0x04;
*((volatile unsigned int*)0x40006200)=0x08;
delay();
}
return 0;
}

void delay(){
  int volatile counter = 0;
  while(counter<900000)
    ++counter;
}
