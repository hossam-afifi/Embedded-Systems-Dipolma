/*
 * products integer numbers
 * main.c
 *
 *  Created on: Sep 5, 2020
 *      Author: Hossam Magdy
 */

#include <stdio.h>

int main (){
	int result=1,num,i,n;
	printf("enter numbers of integer:");
	fflush(stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("enter num%d:",i);
		fflush(stdout);
		scanf("%d",&num);
		if(num==0)
			continue;
		result*=num;
	}
	printf("product=%d",result);
	return 0;
}
