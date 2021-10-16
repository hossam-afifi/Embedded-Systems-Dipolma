/*
 * 	reverse string without using library
 * main.c
 *
 *  Created on: Sep 7, 2020
 *      Author: Hossam Magdy
 */
#include <stdio.h>
#include <string.h>

int main(){
	char arr[100];
	char arr2[100];
	int i,count=0;
	printf("enter a string : ");
	fflush(stdout);
	gets(arr);
	for(i=strlen(arr);i>=0;i--){
		arr2[count]=arr[i-1]; //arr2[strlen-i]
		count++;
	}
	arr[count+1]='\0';
		printf("reverse string is : %s",arr2);
	return 0;
}

