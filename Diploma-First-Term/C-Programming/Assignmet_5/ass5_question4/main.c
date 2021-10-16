/*
 * main.c
 *
 *  Created on: Nov 13, 2020
 *      Author: Hossam Magdy
 */
#include <stdio.h>
#include "string.h"
int main(){
	int i,j,s=0,*ptr1,arr[15],arr2[15];
	int *ptr[15];
	printf("Input the number of elements to store in the array (max 15) :");
	fflush(stdout);
	scanf("%d",&j);
	for(i=0;i<j;i++)
		ptr[i] = &arr[i];
	if(j>15)
		j=15;
	printf("Input %d number of elements in the array :\n",j);
		fflush(stdout);
	for(i=0;i<j;i++){
		scanf("%d",ptr[i]);
		arr[i]=*ptr[i];
	}
	for(i=0;i<j;i++)
		printf("element - %d : %d\n",i+1,arr[i]);
	ptr1=arr2;
	printf("The elements of array in reverse order are :\n");
	for(i=j-1;i>=0;i--){
		*ptr1=arr[i];
		arr2[s]=*ptr1;
		printf("element - %d : %d\n",i+1,arr2[s]);
	}

	return 0;
}
