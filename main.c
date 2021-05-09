//*********************************************************************************************
// Laboratorio 6
// Helder Ovalle
// 18349
//*********************************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "driverlib/gpio.c"
#include "driverlib/gpio.h"
#include "driverlib/debug.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.c"
#include "driverlib/sysctl.h"

uint32_t segundos = 0 ;

int main(void)
{
    SysCtlClockSet ( SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ ) ;
    SysCtlPeripheralEnable ( SYSCTL_PERIPH_GPIOF ) ;
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE , GPIO_PIN_4 ) ;
    GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_4, GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPU ) ;
    GPIOPinTypeGPIOOutput (GPIO_PORTF_BASE,GPIO_PIN_1) ;//led rojo
    GPIOPinTypeGPIOOutput (GPIO_PORTF_BASE, GPIO_PIN_2) ;//led azul
    GPIOPinTypeGPIOOutput (GPIO_PORTF_BASE, GPIO_PIN_3) ;//led verde

    segundos = SysCtlClockGet() / 3 ;
    while(1){
        if((GPIOPinRead (GPIO_PORTF_BASE,GPIO_PIN_4 ) & 0x16)==0){
        while((GPIOPinRead (GPIO_PORTF_BASE,GPIO_PIN_4 ) & 0x16)==0){}
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x08);
        SysCtlDelay (segundos) ;
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x00);
        SysCtlDelay (segundos) ;
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x08);
        SysCtlDelay (segundos) ;
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x00);
        SysCtlDelay (segundos) ;
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x08);
        SysCtlDelay (segundos) ;
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x00);
        SysCtlDelay (segundos) ;
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x08);
        SysCtlDelay (segundos) ;
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x00);
        SysCtlDelay (segundos) ;
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x0A);
        SysCtlDelay (segundos) ;
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x00);
        SysCtlDelay (segundos) ;
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x02);
    }
    }
}
