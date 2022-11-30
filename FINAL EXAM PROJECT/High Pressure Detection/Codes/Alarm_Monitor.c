/*
 ============================================================================
 File Name        : High Pressure Detection
 Author           : Andrew Nasser
 Description      : alarm_monitor.c
 ============================================================================
 */
#include "Headers.h"

void High_Pressure_Detected(){
	Set_Alarm_actuator(ON);
	Delay(1000);
	Set_Alarm_actuator(OFF);

}
