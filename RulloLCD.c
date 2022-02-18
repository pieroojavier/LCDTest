//=== INCLUDES =============================================================================
#include "FreeRTOSConfig.h"             // ARM.FreeRTOS::RTOS:Config
#include "FreeRTOS.h"   
#include "task.h"                       // ARM.FreeRTOS::RTOS:Core
#include "timer.h"
#include "event_groups.h"               // ARM.FreeRTOS::RTOS:Event Groups
#include <stdio.h>
#include "Led.h"
#include "Arduino.h"
#include "Ultrasuoni.h"
#include "Puls.h"
#include "LCD.h"
#include "RulloLCD.h"

EventGroupHandle_t xServo;

void LCDInit(void){
	LCDInitialization();
	LCDDisplayString((uint8_t *)"B0 N0");

	xTaskCreate(vTaskConteggio, /* Pointer to the function that implements the task.              */
	"UltrasuoniTestTask",    /* Text name for the task.  This is to facilitate debugging only. */
	50,    /* Stack depth in words.                */
	NULL,  /* We are not using the task parameter. */
	1,     /* This task will run at priority 1.    */
	NULL); /* We are not using the task handle.    */
}

void LCDTest(void){
	xTaskCreate(vTaskPuls, /* Pointer to the function that implements the task.              */
	"UltrasuoniTestTask",    /* Text name for the task.  This is to facilitate debugging only. */
	50,    /* Stack depth in words.                */
	NULL,  /* We are not using the task parameter. */
	1,     /* This task will run at priority 1.    */
	NULL); /* We are not using the task handle.    */
	
	xServo=xEventGroupCreate();	
}

void vTaskConteggio(void * pvParameters){
	static int pacchi_b=0;
	static int pacchi_n=0;
	char conteggio[8];
	EventBits_t var;
	const EventBits_t xBitsToWait = EVENT_SMISTASX | EVENT_SMISTADX;
	
	while(1){
		var=xEventGroupWaitBits(xServo, xBitsToWait, pdTRUE, pdFALSE, portMAX_DELAY);
		if(var==EVENT_SMISTASX){
			pacchi_b++; 
			LedVerdeToggle();
		}
		if(var==EVENT_SMISTADX){
			pacchi_n++;
			LedRossoToggle();
		}
		sprintf(conteggio,"B%dN%d",pacchi_b,pacchi_n);
		LCDClear();
		LCDDisplayString((uint8_t *)conteggio);
	}
}

void vTaskPuls(void * pvParameters){
	char colore;
	while(1){
		if(SwLeftClick()){
			xEventGroupSetBits(xServo,EVENT_SMISTASX);
		}
		if(SwRightClick())
			xEventGroupSetBits(xServo,EVENT_SMISTADX);
		}
	}