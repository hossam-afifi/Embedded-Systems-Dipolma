/*
 * check a character is alphabet or not
 * main.c
 *
 *  Created on: Aug 29, 2020
 *      Author: Hossam Magdy
 */
#include <stdio.h>

int main(){
	char x;
	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c",&x);
	if(x=='*'||	x=='/'	||	x=='+'	||	x=='-'	||	x=='='	||	x=='%')
		printf("%c is not an alphabet.\n",x);
	else
		printf("%c is an alphabet.\n",x);
	return 0;
}

