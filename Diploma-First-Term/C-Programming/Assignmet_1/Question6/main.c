/*
 * calculate sum to natural number
 * main.c
 *
 *  Created on: Aug 29, 2020
 *      Author: Hossam Magdy
 */

#include <stdio.h>

int main (){
	int sum=0,n;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		sum+=i;
	}
	printf("sum=%d\n",sum);
	return 0;
}

