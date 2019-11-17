
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
void forward_wls(unsigned char node)
{

	unsigned char lefts, centres, rights;


	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);



	printf("%d %d %d\n", lefts, centres, rights);
	int i = (int)node;
	for (int a = 0; a < i; a++)
	{


		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);
		if (lefts == 255 && rights == 255 && centres == 255)
		{
			forward();
		    velocity(150,150);
			_delay_ms(400);
		}

		while (!(lefts == 255 && rights == 255 && centres == 255))
		{


			forward();
			velocity(150, 150);

			correction();

			lefts = ADC_Conversion(1);
			centres = ADC_Conversion(2);
			rights = ADC_Conversion(3);


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
void left_turn_wls(void)
{
	unsigned lefts, rights, centres;


	forward();
	velocity(100, 100);

	_delay_ms(550);
	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);



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
void right_turn_wls(void)
{
	unsigned lefts, rights, centres;


	forward();
	velocity(100, 100);

	_delay_ms(550);
	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);



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
void e_shape(void)
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
void Task_1_1(void)
{
	forward_wls(1);
	right_turn_wls();
	forward_wls(5);
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
}

/*
*
* Function Name: Task_1_2
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.2 logic
* Example Call: Task_1_2();
*/
void Task_1_2(void)
{
	forward();
	_delay_ms(5000);
	right();
	left();
	forward();
	_delay_ms(2000);
	//write your task 1.2 logic here
}


void correction(void)
{
	unsigned lefts, rights, centres;

	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);


	if (rights > centres)
	{
		while (rights > centres)
		{

			velocity(150, 90);
			lefts = ADC_Conversion(1);
			centres = ADC_Conversion(2);
			rights = ADC_Conversion(3);
			//printf("right is greater");

			//printf("%d %d %d\n", lefts, centres, rights);
		}

	}
	if (lefts > centres) {
		while (lefts > centres) {

			velocity(90, 150);



			lefts = ADC_Conversion(1);
			centres = ADC_Conversion(2);
			rights = ADC_Conversion(3);
			//printf("left is greater");
			//printf("%d %d %d\n", lefts, centres, rights);
		}


	}


}
void forcurve(unsigned char node)
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

		while (!(lefts == 255 && rights ==255 && centres == 255))
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

			printf("%d %d %d\n", lefts, rights, centres);


		}
		printf("%d %d %d\n", lefts, rights, centres);

	



	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);

	//printf("%d %d %d", lefts, rights, centres);
}
void correction1(void)
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
		    printf("right is greater");

		     printf("%d %d %d\n", lefts, centres, rights);
		}

	}
	if (lefts >centres) {
		while (lefts >centres) {

			left();



			lefts = ADC_Conversion(1);
			centres = ADC_Conversion(2);
			rights = ADC_Conversion(3);
			//printf("left is greater");
			//printf("%d %d %d\n", lefts, centres, rights);
		}


	}
}

