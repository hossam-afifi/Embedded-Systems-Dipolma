/*
 * main.c
 *
 *  Created on: Oct 11, 2020
 *      Author: Hossam Magdy
 */


#include <stdio.h>

#define PI 3.142857143
#define area PI*(r)*(r)

int main (){
	int r;
	printf("enter the radius: ");
	fflush(stdout);
	scanf("%d",&r);
	printf("Area=%.2f",area);

	return 0;
}
