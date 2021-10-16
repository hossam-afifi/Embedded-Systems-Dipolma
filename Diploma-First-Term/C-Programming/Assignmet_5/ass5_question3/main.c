/*
 * main.c
 *
 *  Created on: Nov 7, 2020
 *      Author: Hossam Magdy
 */
#include <stdio.h>
#include "string.h"

int main(){
	int i,x;
	char arr[50]; //="hossam magdy";
	char arr2[50];
	char *ptr;
	printf("Input a string:");
	fflush(stdout);
	scanf("%s",arr);
	x=strlen(arr);
	ptr=&arr[x-1];
	for(i=0;i<strlen(arr);i++,ptr--){
		arr2[i]=*ptr;
	}
	arr2[i]='\0';
	printf("Reverse of the string is:%s",arr2);
	return 0;
}
