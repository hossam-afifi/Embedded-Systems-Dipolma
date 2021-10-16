/*
 * main.c
 *	find a larg number among three number
 *  Created on: Aug 29, 2020
 *      Author: Hossam Magdy
 */

#include <stdio.h>

int main (){
	float x,y,z,max;
	printf("enter three numbers: ");
	fflush(stdout);
	scanf("%f %f %f",&x,&y,&z);
	max=(x > y) ? x : y;
	if(max > z)
	printf("Largest number:%f",max);
	else
		printf("Largest number:%f",z);
	return 0;
}
