//Potentiometer
#include "tm4c123gh6pm.h"
int main(){
volatile int result;
*((volatile unsigned int *)0x400FE608)=(1<<4)|(1<<5); /* clock gating portE*/
*((volatile unsigned int *)0x400FE638)|=1; /* analog clock gating */
*((volatile unsigned int *)0x40025400)=0xFFU; /* portF direction register*/
*((volatile unsigned int *)0x4002551C)=0xFFU; /* portF digital function register*/
GPIO_PORTE_AFSEL_R |= 8; /* enable alternate function */
GPIO_PORTE_DIR_R &= ~8; /* disable digital function */
GPIO_PORTE_AMSEL_R |= 8; /* enable analog function */
ADC0_ACTSS_R &= ~8; /* disable SS3 during configuration */
ADC0_EMUX_R &= ~0xF000; /* software trigger conversion */
ADC0_SSMUX3_R = 0; /* get input from channel 0 */
ADC0_SSCTL3_R |= 6; /* take one sample at a time, set flag at 1st sample */
ADC0_ACTSS_R |= 8; /* enable ADC0 sequencer 3 */
while(1) {
ADC0_PSSI_R |= 8; /* start a conversion sequence 3 */
if((ADC0_RIS_R & 8) == 0) /* wait for conversion complete */
{
  result = ADC0_SSFIFO3_R; /* read conversion result */
  if(result<2000)
  {
     GPIO_PORTF_DATA_R = 0x00   ;
  }
  else if(2000<= result && result<3000)
  {
    GPIO_PORTF_DATA_R = 0x02;
  }
  else if(3000<= result && result<4000)
  {
     GPIO_PORTF_DATA_R = 0x04;
  }
  else if(result>4000)
  {
    GPIO_PORTF_DATA_R = 0x08;
  }
 
}
ADC0_ISC_R = 8; /* clear completion flag */
}
return 0;
}
