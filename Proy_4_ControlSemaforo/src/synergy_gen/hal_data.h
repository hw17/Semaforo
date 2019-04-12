/* generated HAL header file - do not edit */
#ifndef HAL_DATA_H_
#define HAL_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "common_data.h"
#include "r_icu.h"
#include "r_external_irq_api.h"
#ifdef __cplusplus
extern "C"
{
#endif
/* External IRQ on ICU Instance. */
extern const external_irq_instance_t g_external_irq11;
#ifndef button_callback_SW4
void button_callback_SW4(external_irq_callback_args_t *p_args);
#endif
/* External IRQ on ICU Instance. */
extern const external_irq_instance_t g_external_irq10;
#ifndef button_callback_SW5
void button_callback_SW5(external_irq_callback_args_t *p_args);
#endif

#define LED_ON      IOPORT_LEVEL_LOW
#define LED_OFF     IOPORT_LEVEL_HIGH

#define GREEN_LED   IOPORT_PORT_06_PIN_00
#define RED_LED     IOPORT_PORT_06_PIN_01
#define YELLOW_LED  IOPORT_PORT_06_PIN_02

#define CICLOS      5U
#define carDelay    1000U /*miliseconds*/
#define personDelay 2000U /*miliseconds*/

typedef enum {
    VERDE,
    ROJO,
    AMARILLO
}COLOR;
typedef enum{
    PERSONA,
    AUTOMOVIL
}SOURCE;

void hal_entry(void);
void FunctionLogic(void);
void changeToRED(SOURCE source);
void blinkLED(uint8_t LED);
void g_hal_init(void);
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* HAL_DATA_H_ */
