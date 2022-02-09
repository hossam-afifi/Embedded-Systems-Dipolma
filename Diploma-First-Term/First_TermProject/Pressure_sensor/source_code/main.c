
//#include "driver.h"
#include "alarm_monitor.h"
#include "pressure_sensor.h"


int main (){
	GPIO_INITIALIZATION();
	int pressure_val;
	while (1)
	{
		pressure_val = getPressureVal();
		
		/*max bar is 20, if pressure_val >20 alarm on for time delay (500ms) and off*/
		if(pressure_val > 20) {
			Set_Alarm_On();  // alarm on
		    Delay(1000); // time delay		   
		} /*end if condation bracket*/
		
		/*pressure_val <= 20 bar alarm is off */
		else {
			Set_Alarm_Off(); // alarm off
			Delay(1000);
		} /*end else bracket*/
		
		//Implement your Design 
	}
return 0;
}
