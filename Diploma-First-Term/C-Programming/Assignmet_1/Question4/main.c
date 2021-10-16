/*
 * check number is positive or negative
 * main.c
 *
 *  Created on: Aug 29, 2020
 *      Author: Hossam Magdy
 */

#include <stdio.h>

int main() {
	float x;
	printf("Enter Number: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%f",&x);
	if(x>0)
		printf("%f is Positive.\n",x);
	else if(x<0)
		printf("%f is Negative.\n",x);
	else
		printf("You Enter Zero \n");

	return 0;
}
