/*
 *	find prime numbers between two number
 * main.c
 *
 *  Created on: Sep 16, 2020
 *      Author: Hossam Magdy
 */


#include <stdio.h>

int prime(int x);

int main() {
	int f,z,i;
	printf("enter two number(intervals): ");
	fflush(stdout);
	scanf("%d %d",&f,&z);
	for(i=f+1;i<=z;i++){
		if(prime(i))
			printf("%d ",i);
	}

	return 0;
}
int prime(int x){
	int y,i;
	for(i=2;i<x;i++){
		y=x%i;
		if(y==0)
			return 0;
	}
	return 1;
}
