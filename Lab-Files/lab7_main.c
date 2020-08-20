#include <stdint.h> 
#include "tm4c123gh6pm.h"
#define WHITE 0x0EU
#define PURPLE 0x06U
#define BLUE 0x04U
#define GREEN 0x08U
#define YELLOW 0x0AU
#define RED 0x02U
#define CYAN 0x0CU
#define BLACK 0x00U
#define PressCode1 0x00U
#define PressCode2 0x00U
#define LeftButton *((unsigned int*)0x40025040)
#define RightButton *((unsigned int*)0x40025004)
int main()
{
  int buttonPressed = 0;
  int buttonPresseddir = 0;
  int counter = 0;
  int counterdir = 0;
  // Enable Peripheral Clocks
  *((volatile unsigned long *)0x400FE640) |= 2;       // enable clock to PWM1
  *((volatile unsigned long *)0x400FE608) |= 0x20;
  *((volatile unsigned long *)0x400FE608) |= 0x02; // enable clock to PORTF
  *((volatile unsigned long *)0x400FE060) &= ~0x00100000; // no pre-divide for PWM clock  
  *((volatile unsigned long *)0x4002900C) |= 0x80;
  // Enable port PF2 for PWM1 M1PWM7      
  *((volatile unsigned long *)0x40025420) = 0x08;   // PF2 uses alternate function
  *((volatile unsigned long *)0x4002552C) |= 0x00005000; 
  *((volatile unsigned long *)0x40025400) = 0x08;     // pin digital
  *((volatile unsigned long *)0x4002551C) = 0x08;     // pin digital  
  *((volatile unsigned long *)0x40005400) |= 0x0C;
  *((volatile unsigned long *)0x4000551C) |= 0x0C;
  *((volatile unsigned long *)0x400053FC) |= 0x08;     // pin digital 
    
    
  *((volatile unsigned long *)0x40029100) = 0;            // stop counter  
  *((volatile unsigned long *)0x40029124) = 0x0000008C;  // M1PWM6 output set when reload,            // start timer  
  *((volatile unsigned long *)0x40029110) = 16000;       // set load value for 1kHz (16MHz/16000)  
  *((volatile unsigned long *)0x40029118) = 15999;       // set duty cycle to min  
  *((volatile unsigned long *)0x40029100) = 1;            // start timer  
  *((volatile unsigned long *)0x40029008) = 0x80;        // start PWM1 ch7 
  *((unsigned int*)0x400FE608)=0x20U;
  *((unsigned int*)0x40025400)=0x0EU;
  *((unsigned int*)0x4002551C)=0x1FU;
  *((unsigned int*)0x40025524)=0xFFU;
  *((unsigned int*)0x40025510)=0x11U;
  *((unsigned int*)0x40025520)=0x4C4F434BU;

  *((unsigned int*)0x400FE608)=0x20U;
  *((unsigned int*)0x40025400)=0x0EU;
  *((unsigned int*)0x4002551C)=0x1FU;
  *((unsigned int*)0x40025524)=0xFFU;
  *((unsigned int*)0x40025510)=0x11U;
  *((unsigned int*)0x40025520)=0x4C4F434BU;

  *((volatile unsigned long *)0x400053FC) = 0x04;          //port a3
  while(1)
  { 
    if (*((unsigned int *)0x40025040) == 0 && counter == 0 && buttonPressed == 0){
      //*((unsigned int *)0x40025038) = 0x04U;
      *((volatile unsigned long *)0x400290D8) = 4800;
      buttonPressed = 1;
      //delay(1);
      counter++;
    }
    else if (*((unsigned int *)0x40025040) == 0 && counter == 1 && buttonPressed==0){
      //*((unsigned int *)0x40025038) = 0x08U;
      *((volatile unsigned long *)0x400290D8) = 9600;
      buttonPressed = 1;
      //delay(1);
      counter++;
    }
    else if (*((unsigned int *)0x40025040) == 0 && counter == 2 && buttonPressed==0){
      //*((unsigned int *)0x40025038) = 0x02U;
      *((volatile unsigned long *)0x400290D8) = 15999;
      buttonPressed = 1;
      //delay(1);
      counter++;
    }
    else if (*((unsigned int *)0x40025040) == 0 && counter == 3 && buttonPressed==0){
      //*((unsigned int *)0x40025038) = 0x02U;
      *((volatile unsigned long *)0x400290D8) = 0;
      buttonPressed = 1;
      //delay(1);
      counter++;
    }
    else if(buttonPressed==1 && *((unsigned int *)0x40025040) != 0)
    {
      
      buttonPressed = 0;
      if (counter == 4){
        counter = 0;
      //delay(1);
	//counter++;
      }
      
    }

     
  if(*((unsigned int *)0x40025004) == 0 && counterdir == 0 && buttonPresseddir==0){
        buttonPresseddir = 1;
        *((volatile unsigned long *)0x400053FC) &= ~0x04;          //port a2
        *((volatile unsigned long *)0x400053FC) |= 0x08;            //port a2
        counterdir++;
      }
      else if(*((unsigned int *)0x40025004) == 0 && counterdir == 1 && buttonPresseddir==0){
        buttonPresseddir = 1;
        *((volatile unsigned long *)0x400053FC) &= ~0x08;          //port a2
        *((volatile unsigned long *)0x400053FC) |= 0x04;          //port a3
        counterdir++;
      }
      else if (buttonPresseddir==1 && *((unsigned int *)0x40025004) != 0){
        buttonPresseddir = 0;
        if(counterdir == 2){
          counterdir=0;
        }
      }

  }
}