/*
 * factorial code
 * main.c
 *
 *  Created on: Aug 29, 2020
 *      Author: Hossam Magdy
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
	int fact=1,n;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d",&n);
	while(n<0){
				printf("Error!!! Factorial of negative number dose not exist.\n");
				exit(0);
	}
	for(int i=1;i<=n;i++)
		fact*=i;
	printf("Factorial=%d\n",fact);

	return 0;
}
