/*
 *	insert an element in an array
 * main.c
 *
 *  Created on: Sep 6, 2020
 *      Author: Hossam Magdy
 */

#include <stdio.h>

int main(){
	int i,x,n,arr[100],y;
	printf("Number of elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		fflush(stdin);
	}
	for(i=0;i<n;i++){
			printf("%d ",arr[i]);
			fflush(stdout);
		}
	printf("\nenter the element to be inserted: ");
	fflush(stdout);
	scanf("%d",&x);
	fflush(stdin);
	printf("enter the location : ");
	fflush(stdout);
	scanf("%d",&y);
	fflush(stdin);
	arr[y-1]=x;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
