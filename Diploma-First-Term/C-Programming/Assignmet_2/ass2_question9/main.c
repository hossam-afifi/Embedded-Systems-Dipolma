/*
 *
 * find the length of string
 * main.c
 *
 *  Created on: Sep 7, 2020
 *      Author: Hossam Magdy
 */


#include <stdio.h>

int main(){
	char arr[100];
	int i=0;
	printf("enter a string : ");
	fflush(stdout);
	gets(arr);
	while(arr[i]!='\0')
		i++;
	printf("Length of string : %d",i);
	return 0;
}
/*
 * using sting library
 * define #include <string.h>
 *  char arr[100]
 *	printf("enter a string : ");
 *	fflush(stdout);
 *	gets(arr);
 *	printf("Length of string : %d",strlen(arr));
 *
 */
