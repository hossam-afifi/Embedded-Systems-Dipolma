/*
 * power of number by using recursion
 * main.c
 *
 *  Created on: Sep 17, 2020
 *      Author: Hossam Magdy
 */

#include <stdio.h>

int count=1;

int power(int x,int y){
	if(count<y){
		++count;
		return x*power(x,y);
	}
	else
		return x;
}

int main(){
	int a,b;
	printf("enter base number: ");
	fflush(stdout);
	scanf("%d",&a);
	printf("enter power number(positive number): ");
	fflush(stdout);
	scanf("%d",&b);
	printf("%d^%d= %d",a,b,power(a,b));

	return 0;
}

