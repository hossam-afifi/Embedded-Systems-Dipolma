/*
 *  find frequency of characters in string
 *
 * main.c
 *
 *  Created on: Sep 7, 2020
 *      Author: Hossam Magdy
 */


#include <stdio.h>

int main() {
	char arr[100],c;
	int i=0,count=0;
	printf("enter a string : ");
	fflush(stdout);
	gets(arr);
	fflush(stdout);
	printf("enter a character to find frequency :");
	fflush(stdout);
	scanf("%c",&c);
	while(arr[i]!='\0'){
		if(c==arr[i])
			count++;
		i++;
	}
	printf("frequency of %c = %d",c,count);

	return 0;
}

