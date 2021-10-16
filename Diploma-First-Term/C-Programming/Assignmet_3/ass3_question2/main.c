/*
 * factorial of number by using recursion
 * main.c
 *
 *  Created on: Sep 17, 2020
 *      Author: Hossam Magdy
 */


#include<stdio.h>
int fact=1;
int factorial(int y){
	if(y==0)
		return 0;
	fact=fact*y;
	if(y==1)
		printf("factorial= %d",fact);
	--y;
	factorial(y);

	return 1;
}
int main(){
	int x;
	printf("enter an positive integer:");
	fflush(stdout);
	scanf("%d",&x);
	factorial(x);
	return 0;
}
