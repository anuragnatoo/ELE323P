#include <stdint.h>
#include "tm4c123gh6pm.h"
void delayMs(int n);
void brightness();
int main(void){
/* Enable Peripheral Clocks */
while(1)
{
SYSCTL_RCGCPWM_R |= 2; /* enable clock to PWM1 */
SYSCTL_RCGCGPIO_R |= 0x20; /* enable clock to PORTF */
SYSCTL_RCC_R &= ~0x00100000; /* no pre-divide for PWM clock */
/* Enable port PF2 for PWM1 M1PWM7 */
GPIO_PORTF_AFSEL_R = 0x04; /* PF2 uses alternate function */
GPIO_PORTF_PCTL_R |= 0x000000500;
GPIO_PORTF_DEN_R = 0x04; /* pin digital */
PWM1_3_CTL_R = 0; /* stop counter */
PWM1_3_GENA_R = 0x0000008C; /* M1PWM6 output set when reload, */
/* clear when match PWMCMPA */
PWM1_3_LOAD_R = 16000; /* set load value for 1kHz (16MHz/16000) */
PWM1_3_CMPA_R = 15999; /* set duty cycle to min */
PWM1_3_CTL_R = 1; /* start timer */
PWM1_ENABLE_R = 0x40; /* start PWM1 ch7 */
brightness();
/* Enable port PF2 for PWM1 M1PWM7 */
GPIO_PORTF_AFSEL_R = 0x08; /* PF2 uses alternate function */
GPIO_PORTF_PCTL_R |= 0x000005000;
GPIO_PORTF_DEN_R = 0x02; /* pin digital */
PWM1_3_CTL_R = 0; /* stop counter */
PWM1_3_GENB_R = 0x0000008C; /* M1PWM6 output set when reload, */
/* clear when match PWMCMPA */
PWM1_3_LOAD_R = 16000; /* set load value for 1kHz (16MHz/16000) */
PWM1_3_CMPA_R = 15999; /* set duty cycle to min */
PWM1_3_CTL_R = 1; /* start timer */
PWM1_ENABLE_R = 0x80; /* start PWM1 ch7 */
brightness();
GPIO_PORTF_AFSEL_R = 0x08; /* PF2 uses alternate function */
GPIO_PORTF_PCTL_R |= 0x000005000;
GPIO_PORTF_DEN_R = 0x08; /* pin digital */
PWM1_3_CTL_R = 0; /* stop counter */
PWM1_3_GENB_R = 0x0000008C; /* M1PWM6 output set when reload, */
/* clear when match PWMCMPA */
PWM1_3_LOAD_R = 16000; /* set load value for 1kHz (16MHz/16000) */
PWM1_3_CMPA_R = 15999; /* set duty cycle to min */
PWM1_3_CTL_R = 1; /* start timer */
PWM1_ENABLE_R = 0x80; /* start PWM1 ch7 */
brightness();
}
}
/* delay n milliseconds (16 MHz CPU clock) */
void delayMs(int n){
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3180; j++)
{} /* do nothing for 1 ms */
}
void brightness()
{
int x = 15999;
for(;;) {  
x = x - 50;
if (x <= 0)
break;
PWM1_3_CMPA_R = x;
delayMs(20);
}
for(;;){
x = x + 50;
if (x>=15999)
break;
PWM1_3_CMPA_R = x;
delayMs(20);
}
}
