/*
 *
 * search an element in array
 * main.c
 *
 *  Created on: Sep 6, 2020
 *      Author: Hossam Magdy
 */


#include <stdio.h>
#include <stdlib.h>

int main(){
	int arr[100],i,n,x;
	printf("enter no of elements:");
	fflush(stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		fflush(stdin);

	}
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
		fflush(stdout);
	}
	printf("\nenter the elements to be searched: ");
	fflush(stdout);
	scanf("%d",&x);
	for(i=0;i<n;i++){
		if(arr[i]==x){
			printf("number found at the location= %d",i+1);
			return 0;// exit(0);
		}

	}
		printf("number is not found %d",i);
		return 0;
}
/*
 * if(i<n)
 * printf(found %d,i)
 * else
 * printf(not found)
 */
