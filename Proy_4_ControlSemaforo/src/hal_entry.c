/* HAL-only entry function */
#include "hal_data.h"

#define LED_STATUS(LED,ON_OFF)  g_ioport.p_api->pinWrite((LED), (ON_OFF))
#define delayTime(time)         R_BSP_SoftwareDelay((time), bsp_delay_units);/* Delay */

const bsp_delay_units_t bsp_delay_units = BSP_DELAY_UNITS_MILLISECONDS;     /* Define the units to be used with the software delay function */                                                 /* Calculate the delay in terms of bsp_delay_units */

uint8_t CarWantsToPass = 0;
uint8_t PersonWantsToPass = 0;

void hal_entry(void)
{
    g_external_irq10.p_api->open(g_external_irq10.p_ctrl,g_external_irq10.p_cfg);
    g_external_irq11.p_api->open(g_external_irq11.p_ctrl,g_external_irq11.p_cfg);

    while(1){
        FunctionLogic();
    }
}

void FunctionLogic(void){
    if(PersonWantsToPass == 1){
        changeToRED(PERSONA);
        PersonWantsToPass = 0;
    }
    else if(CarWantsToPass == 1){
        changeToRED(AUTOMOVIL);
        CarWantsToPass = 0;
    }
    else{
        LED_STATUS(GREEN_LED, LED_ON);
        LED_STATUS(RED_LED,LED_OFF);
        LED_STATUS(YELLOW_LED,LED_OFF);
    }
}

void changeToRED(SOURCE source){

    blinkLED(VERDE);
    blinkLED(AMARILLO);
    LED_STATUS(RED_LED, LED_ON);

    switch (source) {
        case PERSONA:
            delayTime(personDelay); LED_STATUS(RED_LED,LED_OFF);
            break;
        case AUTOMOVIL:
            delayTime(carDelay); LED_STATUS(RED_LED,LED_OFF);
            break;
        default:
            /*Nothing to do*/
            break;
    }
}

void blinkLED(COLOR LED){
    uint8_t cycles =0;
    switch (LED) {
        case VERDE:
            for (cycles=0; cycles<CICLOS; cycles++){
                LED_STATUS(GREEN_LED,LED_ON); delayTime(200);
                LED_STATUS(GREEN_LED,LED_OFF);delayTime(200);
            }
            break;
        case AMARILLO:
            for (cycles=0; cycles<CICLOS; cycles++){
                LED_STATUS(YELLOW_LED,LED_ON); delayTime(200);
                LED_STATUS(YELLOW_LED,LED_OFF);delayTime(200);
            }
            break;
        case ROJO:
            for (cycles=0; cycles<CICLOS; cycles++){
                LED_STATUS(RED_LED,LED_ON); delayTime(200);
                LED_STATUS(RED_LED,LED_OFF);delayTime(200);
            }
            break;
        default:
            /* nothing to do */
            break;
    }
}

void button_callback_SW4(external_irq_callback_args_t *args){
    (void)args;
    CarWantsToPass = 1;
}

void button_callback_SW5(external_irq_callback_args_t *args){
    (void)args;
    PersonWantsToPass = 1;
}
