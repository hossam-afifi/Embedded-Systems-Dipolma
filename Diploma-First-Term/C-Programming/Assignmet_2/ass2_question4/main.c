/*
 *  find average numbers of array
 * main.c
 *
 *  Created on: Sep 6, 2020
 *      Author: Hossam Magdy
 */

#include <stdio.h>

int main (){
	float arr[50];
	float aver=0;
	int i,n;
	printf("enter the numbers of data: ");
	fflush(stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("%d.enter number: ",i+1);
		fflush(stdout);
		scanf("%f",&arr[i]);
		aver+=arr[i];
	}
	aver=aver/n;
	printf("Average = %.2f",aver);

	return 0;
}
