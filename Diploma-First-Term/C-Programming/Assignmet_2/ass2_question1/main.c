/*
 * 	 find average number
 * main.c
 *
 *  Created on: Sep 5, 2020
 *      Author: Hossam Magdy
 */

#include <stdio.h>
int main(){
	float sum=0.0,number,average;
	int i,n;
	printf("maximum no. of inputs\n");
	fflush(stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		printf("enter num%d:",i);
		fflush(stdout);
		scanf("%f",&number);
		if(number<0.0)
			break;
	sum=sum+number;
	}
	average =sum/(i-1);
	printf("Average=%.2f\n",average);
	return 0;
}
