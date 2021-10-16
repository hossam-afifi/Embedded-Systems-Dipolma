/*
 * reverse a sentence by using recursion
 * main.c
 *
 *  Created on: Sep 17, 2020
 *      Author: Hossam Magdy
 */



#include <stdio.h>
#include<string.h>

int j = 0;

void reverse(char arr1[], int y, int len) {
	char temp;
	if(y >= len/2) {
		temp = arr1[j];
		arr1[j++] = arr1[y];
		arr1[y--] = temp;
		reverse(arr1, y, len);
	}
	//printf("\n%s",arr1);
}

int main() {
	char arr[20];
	int x;
	printf("enter a sentence: ");
	fflush(stdout);
	gets(arr);
	x=strlen(arr);
	reverse(arr, x - 1, x);
	printf("%s",arr);
	return 0;
}
