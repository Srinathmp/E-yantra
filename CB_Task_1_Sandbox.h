/*
Team ID: #3353
Author List: Pavan Harish,Srinath MP,Sujay Krishna B,V R Shravan Kumar
FileName:
Theme: Construct O Bot
Functions: forward_wls(),left_turn_wls(void),right_turn_wls(void),e_shape(void),Task_1_1(void),Task_1_2(void),correction(void),forcurve(),correction1(void).
Global Variables: None
*/








#include "CB_Task_1_Predef.h"
extern unsigned int color_sensor_pulse_count;

void forward_wls(unsigned char node); //This function is used to help the Robot to move forward.
void left_turn_wls(void);//This function is used to help the Robot detect the line on the left and aids to turn the Robot left.
void right_turn_wls(void);//This function is used to help the Robot detect the line on the rigth and aids to turn the Robot right.
void e_shape(void); // This function is the part of the assignment and make the Robot trace the path of the 'e'.
void Task_1_1(void);//This function is invoked for the Robot to trace the path given in Task 1.1
void Task_1_2(void);//This function is invoked for the Robot to execute the Task assigned in Task 1.2
void correction(void); //This function is used to help the Robot stay in the path and not deviate from it.
void forcurve(unsigned char node); // This function used to help the Robot traverse the path which is curved.
void correction1(void); //This function is used to align the robot in the black line
