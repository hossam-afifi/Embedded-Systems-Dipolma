/*
main.c
 *
 *	code check number is even or odd
 *
 *  Created on: Aug 29, 2020
 *      Author: Hossam Magdy
 */

#include <stdio.h>

int main(){
	int x;
	printf(" Enter an integer you want to check: ");
	fflush(stdout);
	scanf("%d",&x);
	if(x % 2 == 0)
		printf("%d is even. ",x);
	else
		printf("%d is odd. ",x);
	return 0;
}

