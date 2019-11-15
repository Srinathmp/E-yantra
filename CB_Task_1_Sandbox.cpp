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
/*
void forward_wls(unsigned char node)
{
	unsigned char lefts, centres, rights;
	
	
	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);
	printf("%d %d %d\n", lefts, centres, rights);
	while (rights!=255) {
		forward();
		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);
		
		//printf("%d %d %d\n",lefts, centres, rights);	
	}
	soft_right();
	_delay_ms(100);
	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);
	
	
	printf("%d %d %d\n", lefts, centres, rights);
	while (rights!=255) {
		soft_right();
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);
		lefts = ADC_Conversion(1);
	}
	printf("%d %d %d", lefts,centres, rights);
	while (rights != 0 || lefts != 0 || centres != 0) {
		forward();
		if (rights > centres) {
			while (rights > centres) {
				soft_right();
				lefts = ADC_Conversion(1);
				centres = ADC_Conversion(2);
				rights = ADC_Conversion(3);
			}

		}
		if (lefts > centres) {
			while (lefts > centres) {
				soft_left();
				lefts = ADC_Conversion(1);
				centres = ADC_Conversion(2);
				rights = ADC_Conversion(3);
			}
		}
		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);


	}
	printf("%d %d %d", lefts, centres, rights);



	
	
	

	

	
	
	
}
*/
/*
*
* Function Name: left_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn left until black line is encountered
* Example Call: left_turn_wls(); //Turns right until black line is encountered
*
*/
void left_turn_wls(void)
{
	unsigned char lefts, centres, rights;


	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);
	printf("%d %d %d\n", lefts, centres, rights);
	
	while (centres != 255) {
		left();
		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);
		//printf("%d %d %d\n", lefts, centres, rights);
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
	unsigned char lefts, centres, rights;


	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);
	printf("%d %d %d\n", lefts, centres, rights);
	
	while (rights != 255) {
		right();
		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);
		//printf("%d %d %d\n", lefts, centres, rights);
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
	unsigned char lefts, centres, rights;

	int cnt=1;
	lefts = ADC_Conversion(1);
	centres = ADC_Conversion(2);
	rights = ADC_Conversion(3);
	printf("%d %d %d\n", lefts, centres, rights);
	while (centres== 255) {
		forward();
		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);

	}
	right_turn_wls();
	printf("%d %d %d", lefts, centres, rights);
	
	while (cnt<=1200) {
		forward();
		
		if (rights > centres) {
			while (rights > centres) {
				soft_right();
				lefts = ADC_Conversion(1);
				centres = ADC_Conversion(2);
				rights = ADC_Conversion(3);
			}

		}
		if (lefts > centres) {
			while (lefts > centres) {
				soft_left();
				lefts = ADC_Conversion(1);
				centres = ADC_Conversion(2);
				rights = ADC_Conversion(3);
			}

		}
		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);
		
		if (lefts ==0 && centres ==0 && rights == 0) {
			
			
			cnt += 1;
			
			
		}
		printf("%d\n", cnt);
	}
	left_turn_wls();
	while (1) {
		forward();
		if (rights > centres) {
			while (rights > centres) {
				soft_right();
				lefts = ADC_Conversion(1);
				centres = ADC_Conversion(2);
				rights = ADC_Conversion(3);
			}

		}
		if (lefts > centres) {
			while (lefts > centres) {
				soft_left();
				lefts = ADC_Conversion(1);
				centres = ADC_Conversion(2);
				rights = ADC_Conversion(3);
			}
		}
		lefts = ADC_Conversion(1);
		centres = ADC_Conversion(2);
		rights = ADC_Conversion(3);
		


	}
	
	printf("%d %d %d", lefts, centres, rights);
	
	
		// Write your task 1.1 Logic here
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
	//write your task 1.2 logic here
}