/*
Team ID: #3353
Author List: Pavan Harish,Srinath MP,Sujay Krishna B,V R Shravan Kumar
FileName:Sandbox.cpp
Theme: Construct O Bot
Functions: forward_wls(),left_turn_wls(void),right_turn_wls(void),e_shape(void),Task_1_1(void),Task_1_2(void),correction(void),forcurve(),correction1(void),zigzag(void),zebra(void).
Global Variables: None
*/


//You are allowed to define your own function to fulfill the requirement of tasks
//Dont change the name of following functions

#include "CB_Task_1_Sandbox.h"


/*
*
* Function Name: forward_wls
* Input: node
* Output: void
* Logic: Uses white line sensors to go forward by the number of nodes specified
* Example Call: forward_wls(2); //Goes forward by two nodes
*
*/
void forward_wls(unsigned char node)      //This function is used to help the Robot to move forward.The variables used in the function are left,right and center to detect the line based on the direction of the line.
{

	unsigned char lefts, centres, rights;


	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);



	int i = (int)node;
	for (int a = 0; a < i; a++)
	{

		int b = 1;
		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);
		if (lefts == 255 && rights == 255 && centres == 255)
		{

			forward();
			velocity(200, 200);
			_delay_ms(350);

		}
		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);
		_delay_ms(10);



		while (!(lefts == 255 && rights == 255 && centres == 255))
		{


			forward();
			velocity(200, 200);


			correction();


			lefts = ADC_Conversion(1);
			centres = ADC_Conversion(2);
			rights = ADC_Conversion(3);
			_delay_ms(10);


		}
		printf("%d %d %d\n", lefts, rights, centres);
	}



	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);

	//printf("%d %d %d", lefts, rights, centres);
}




/*
* Function Name: left_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn left until black line is encountered
* Example Call: left_turn_wls(); //Turns right until black line is encountered
*
*/
void left_turn_wls(void)           //This function is used to help the Robot detect the line on the left and aids to turn the Robot left.
{
	unsigned lefts, rights, centres;
	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);

	while (centres == 255)
	{
		forward();
		velocity(100, 135);

		_delay_ms(450);

		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);
	}



	while (centres != 255)
	{
		//printf("%d %d %d\n", lefts, centres, rights);
		//printf("entering right block");
		left();
		centres = ADC_Conversion(2);
	}

}







/*
*
* Function Name: right_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn right until black line is encountered
* Example Call: right_turn_wls(); //Turns right until black line is encountered
*/
void right_turn_wls(void)               //This function is used to help the Robot detect the line on the rigth and aids to turn the Robot right.
{
	unsigned lefts, rights, centres;
	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);

	while (centres == 255)
	{



		forward();
		velocity(135, 100);

		_delay_ms(450);

		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);
	}



	while (centres != 255)
	{
		//printf("%d %d %d\n", lefts, centres, rights);
		//printf("entering right block");
		right();
		centres = ADC_Conversion(2);
	}

}

/*
*
* Function Name: e_shape
* Input: void
* Output: void
* Logic: Use this function to make the robot trace a e shape path on the arena
* Example Call: e_shape();
*/
void e_shape(void)               // This function is the part of the assignment and make the Robot trace the path of the 'e'.
{
	unsigned lefts, rights, centre;
	lefts = ADC_Conversion(1);
	centre = ADC_Conversion(2);
	rights = ADC_Conversion(3);



	forward_wls(1);
	right_turn_wls();
	forward_wls(2);
	right_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);








}


/*
*
* Function Name: Task_1_1
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.1 logic
* Example Call: Task_1_1();
*/
void Task_1_1(void)             //This function is invoked for the Robot to trace the path given in Task 1.1
{
	forward_wls(1);
	right_turn_wls();
	forward_wls(4);
	left_turn_wls();
	forcurve(1);
	left_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls(1);
	right_turn_wls();
	zebra();
	right_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls(1);


}

/*
*
* Function Name: Task_1_2
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.2 logic
* Example Call: Task_1_2();
*/
void Task_1_2(void)          //This function is invoked for the Robot to execute the Task assigned in Task 1.2
{
	forward();
	_delay_ms(5000);
	right();
	left();
	forward();
	_delay_ms(2000);
	//write your task 1.2 logic here
}



void correction(void)       //This function is used to help the Robot stay in the path and not deviate from it.
{
	unsigned lefts, rights, centres;

	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);


	if (rights > centres)
	{
		while (rights > centres)
		{

			velocity(120, 10);
			lefts = ADC_Conversion(1);
			centres = ADC_Conversion(2);
			rights = ADC_Conversion(3);

			//printf("right is greater");

			//printf("%d %d %d\n", lefts, centres, rights);
		}

	}
	if (lefts > centres) {
		while (lefts > centres) {

			velocity(10, 120);



			lefts = ADC_Conversion(1);
			centres = ADC_Conversion(2);
			rights = ADC_Conversion(3);

			//printf("left is greater");
			//printf("%d %d %d\n", lefts, centres, rights);
		}


	}


}
void forcurve(unsigned char node)      // This function used to help the Robot traverse the path which is curved.
{
	unsigned char lefts, centres, rights;


	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);




	printf("%d %d %d\n", lefts, centres, rights);




	/*if (lefts == 0 && centres == 0 && rights == 0)
	{
		while (centres != 255)
		{
			soft_left();
			lefts = ADC_Conversion(1);
			centres = ADC_Conversion(2);
			rights = ADC_Conversion(3);
		}
	}*/

	while (!(lefts == 255 && rights == 255 && centres == 255))
	{


		forward();
		velocity(90, 90);

		correction1();
		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);
		/*if (lefts == 0 && centres == 0 && rights == 0)
		{
			while (centres != 255)
			{
				soft_left();
				lefts = ADC_Conversion(1);
				centres = ADC_Conversion(2);
				rights = ADC_Conversion(3);
			}
		} */

		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);

		//printf("%d %d %d\n", lefts, rights, centres);


	}
	printf("%d %d %d\n", lefts, rights, centres);





	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);

	//printf("%d %d %d", lefts, rights, centres);
}
void correction1(void)          //This function helps the Robot to align in the curved region of the path.
{
	unsigned lefts, rights, centres;

	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);


	if (rights > centres)

	{
		printf(" At turning %d %d %d\n", lefts, centres, rights);
		while (rights > centres)
		{

			velocity(80, 0);
			lefts = ADC_Conversion(1);
			centres = ADC_Conversion(2);
			rights = ADC_Conversion(3);

		}

	}
	if (lefts > centres) {
		while (lefts > centres) {

			left();



			lefts = ADC_Conversion(1);
			centres = ADC_Conversion(2);
			rights = ADC_Conversion(3);
			//printf("left is greater");
			//printf("%d %d %d\n", lefts, centres, rights);
		}


	}
}
void zigzag()  //This function is used to aid the Robot in moving along the zigzag region of the path.
{
	unsigned lefts, rights, centres;

	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);
	_delay_ms(10);
	while (!(lefts == 255 && rights == 255 && centres == 255))
	{
		//correction();
		while (!(lefts == 0 && rights == 0 && centres == 0))
		{

			forward();
			velocity(150, 150);
			correction();
			lefts = ADC_Conversion(1);
			centres = ADC_Conversion(2);
			rights = ADC_Conversion(3);
			_delay_ms(10);

		}


		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);
		_delay_ms(10);

		if (lefts == 0 && rights == 0 && centres == 0)
		{
			//velocity(0, 100);
			left();
			_delay_ms(100);
			//velocity(0, 0);



		}
		correction();
		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);
		_delay_ms(10);

		while (lefts == 0 && rights == 0 && centres == 0)
		{
			right();

			lefts = ADC_Conversion(1);
			centres = ADC_Conversion(2);
			rights = ADC_Conversion(3);
			_delay_ms(10);

		}

		correction();
		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);
		_delay_ms(10);

	}
}
void zebra(void)     //This function is used to allow the Robot to traverse along the zebra crossing just before the goal.
{
	unsigned char lefts, rights, centres;

	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);
	/*
	while (!(centres != 255 && lefts == 255 && rights == 255))
	{
		forward();
		velocity(200, 200);
		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);
		_delay_ms(10);
	}
	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);
	_delay_ms(10);
	while (!(centres == 255 && lefts != 255 && rights != 255))
	{
		forward();
		velocity(200, 200);
		velocity(200, 200);
		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);
		_delay_ms(10);
	}*/
	while (!(centres == 255 && lefts == 255 && rights == 255))
	{
		forward();
		velocity(200, 200);
		velocity(200, 200);
		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);
		_delay_ms(10);
	}



}