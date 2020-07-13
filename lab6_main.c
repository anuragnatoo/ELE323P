#include "tm4c123gh6pm.h"
unsigned char uart_inchar(void)
{
  while((*((volatile unsigned long *)0x4000D018)&0x0010) != 0);// wait until RXFE is 0
  return((unsigned char)(*((volatile unsigned long *)0x4000D000)&0xFF));
}
// UART Initialization
void uart_init()
{   
  *((volatile unsigned long *)0x400FE104) |= 0x00000002;  // activate UART1
  *((volatile unsigned long *)0x400FE108) |= 0x00000004;  // activate port C
  *((volatile unsigned long *)0x4000D030) &= ~0x00000001;    // disable UART
  *((volatile unsigned long *)0x4000D024) = 43;     // IBRD = int(80,000,000/(16*115,200)) = int(43.40278)
  *((volatile unsigned long *)0x4000D028) = 26;     // FBRD = round(0.40278 * 64) = 26
  *((volatile unsigned long *)0x4000D02C) = 0x00000070;  // 8 bit, no parity bits, one stop, FIFOs
  *((volatile unsigned long *)0x4000D030) |= 0x00000001;     // enable UART
  *((volatile unsigned long *)0x40006420) |= 0x30;    // enable alt funct on PC5-4
  *((volatile unsigned long *)0x4000651C) |= 0x30;      // configure PC5-4 as UART1
  *((volatile unsigned long *)0x4000652C) = (GPIO_PORTC_PCTL_R&0xFF00FFFF)+0x00220000;
  *((volatile unsigned long *)0x40006528) &= ~0x30;   // disable analog on PC5-4
}

void uart_outchar(unsigned char data)
{
  while((*((volatile unsigned long *)0x4000D018)&0x0020) != 0);      // wait until TXFF is 0
  *((volatile unsigned long *)0x4000D000) = data;
}
unsigned char uart_incharnonblocking(void)
{
  if((*((volatile unsigned long *)0x4000D018)&0x00000010) == 0)
  {
    return((unsigned char)(*((volatile unsigned long *)0x4000D000)&0xFF));
  }
  else
  {
    return 0;
  }
}
const long colorwheel[8] = {0x02,0x0A,0x08,0x0C,0x04,0x06,0x0E,0x00};
//  red, yellow, green, light blue, blue, purple,  white,  dark
int main(void){
  unsigned long SW1,SW2;
  long prevSW1 = 0;        // previous value of SW1
  long prevSW2 = 0;        // previous value of SW2
  unsigned char inColor;   // color value from other microcontroller
  unsigned char color = 0; // this microcontroller's color value
  //SSI_CC_CS_SYSPLL = 80;       // set system clock to 80 MHz
  //SysTick_Init();          // initialize SysTick
  *((volatile unsigned long *)0x400FE618)|= (1<<0); //Enable the UART0 module
  *((volatile unsigned long *)0x400FE608) |= (1<<0); //enable clock to PORTA
  uart_init();             // initialize UART
  *((volatile unsigned long *)0x4002551C)=(1<<1)|(1<<2)|(1<<3); //Enable digital on PF1 PF2 PF3
  *((volatile unsigned long *)0x40025400)=(1<<1)|(1<<2)|(1<<3)|(1<<4)|1; //Enable digital output on PF1 PF2 PF3
  *((volatile unsigned long *)0x400253FC) = ~((1<<1)|(1<<2)|(1<<3)); //Disable digital output on PF1 PF2 PF3           // initialize buttons and LEDs on Port F

  while(1){
    SW1 = *((volatile unsigned long *)0x400253FC)&0x10; // Read SW1
    if((SW1 == 0) && prevSW1){    // falling of SW1?
      color = (color+1)&0x07;     // step to next color
    }

    prevSW1 = SW1; // current value of SW1
    SW2 = *((volatile unsigned long *)0x400253FC)&0x01; // Read SW2

    if((SW2 == 0) && prevSW2){    // falling of SW2?
      uart_outchar(color+0x30);   // send color as '0' - '7'
    }

    prevSW2 = SW2; // current value of SW2
    inColor = uart_incharnonblocking();
    if(inColor){ // new data have come in from the UART??
      color = inColor&0x07;     // update this computer's color
    }

    *((volatile unsigned long *)0x400253FC) = colorwheel[color];  // update LEDs

    //SysTick_Wait10ms(2);        // debounce switch
  }
}


