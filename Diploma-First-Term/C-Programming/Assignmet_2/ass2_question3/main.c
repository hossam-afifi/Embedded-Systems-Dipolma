/*
 *  multidimensional array in c
 * main.c
 *
 *  Created on: Sep 6, 2020
 *      Author: Hossam Magdy
 */

#include <stdio.h>

int main (){
	float arr1[3][3];
	float arr2[3][3];
	int i,j;
	printf("enter of 1st matrix\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("enter a[%d][%d]:",i+1,j+1);
			fflush(stdout);
			scanf("%f",&arr1[i][j]);
		}
	}
	printf("enter of 2st matrix\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("enter a[%d][%d]:",i+1,j+1);
			fflush(stdout);
			scanf("%f",&arr2[i][j]);
		}
	}
	printf("Sum of Matrix:\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%.1f \t",arr1[i][j]+arr2[i][j]);
			if(j==1)
				printf("\n");


		}
	}


	return 0;
}

