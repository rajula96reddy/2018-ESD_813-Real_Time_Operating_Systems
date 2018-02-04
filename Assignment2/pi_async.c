#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <wiringPi.h>

#define INT_PIN 0 //Interrupt Pin
#define READ_PIN_1 1 //Read pin
#define READ_PIN_2 2 //Read pin
#define READ_PIN_3 3 //Read pin
#define READ_PIN_4 4 //Read pin

void main()
{
	wiringPiSetup(); //setup the library
	pinMode (INT_PIN, INPUT); //set mode of pin_0
	pinMode (READ_PIN_1, INPUT); //set mode of pin_1
	pinMode (READ_PIN_2, INPUT); //set mode of pin_2
	pinMode (READ_PIN_3, INPUT); //set mode of pin_3
	pinMode (READ_PIN_4, INPUT); //set mode of pin_4
	int pin_value_1_prev, pin_value_1;
	int pin_value_2_prev, pin_value_2;
	int pin_value_3_prev, pin_value_3;
	int pin_value_4_prev, pin_value_4;

  while(1) //waiting for an interrupt
	{
		pin_value_1 = digitalRead(READ_PIN_1); //Read pin 1 value
		pin_value_2 = digitalRead(READ_PIN_2); //Read pin 2 value
		pin_value_3 = digitalRead(READ_PIN_3); //Read pin 3 value
		pin_value_4 = digitalRead(READ_PIN_4); //Read pin 4 value
		usleep(100);
		pin_value_1_prev = digitalRead(READ_PIN_1); //Read pin 1 value
		pin_value_2_prev = digitalRead(READ_PIN_2); //Read pin 2 value
		pin_value_3_prev = digitalRead(READ_PIN_3); //Read pin 3 value
		pin_value_4_prev = digitalRead(READ_PIN_4); //Read pin 4 value
		if( pin_value_1 != pin_value_1_prev || pin_value_2 != pin_value_2_prev || pin_value_3 != pin_value_3_prev || pin_value_4 != pin_value_4_prev)
		{
			printf("Value of Pin 1 (wrt wiringPi) is %d\n", pin_value_1); //Print pin 1 value
			printf("Value of Pin 2 (wrt wiringPi) is %d\n", pin_value_2); //Print pin 2 value
			printf("Value of Pin 3 (wrt wiringPi) is %d\n", pin_value_3); //Print pin 3 value
			printf("Value of Pin 4 (wrt wiringPi) is %d\n", pin_value_4); //Print pin 4 value
		}
	}
}
