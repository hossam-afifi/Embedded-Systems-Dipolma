#include "driver.h"
#include "alarm_monitor.h"



void Set_Alarm_On(){
	
	RESET_BIT(GPIOA_ODR,13); // reset alarm pin 13
}
void Set_Alarm_Off(){
	
	SET_BIT(GPIOA_ODR,13); // set alarm pin 13
	
}