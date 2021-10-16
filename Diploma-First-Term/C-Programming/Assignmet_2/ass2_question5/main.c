/*
 *
 * main.c
 *
 *  Created on: Sep 6, 2020
 *      Author: Hossam Magdy
 */

#include <stdio.h>
#include "string.h"

int main(){
	int i,c,r=0,col=0;
	int a[10][10],temp[10][10];
	printf("enter rows and column of matrix : ");
	fflush(stdout);
	scanf("%d %d",&r,&col);
	for(i=0;i<r;i++) {
		for(c=0;c<col;c++) {
			printf("element a%d%d:",i+1,c+1);
			fflush(stdout);
			scanf("%d", &a[i][c]);
			//a[i][c] = x;
		}
	}
	printf("\r\n");

	printf("Enter of matrix:\n");
	for(i=0;i<r;i++){
		for(c=0;c<col;c++){
			printf("%d ",a[i][c]);
		}
		printf("\r\n");
	}
	printf("Transpose of Matrix:\n");
	for(i=0;i<r;i++){
		for(c=0;c<col;c++){
			temp[c][i]=a[i][c];
		}

	}
	for(i=0;i<col;i++){
		for(c=0;c<r;c++){
			printf("%d ",temp[i][c]);
		}
		printf("\n\n");
	}
	return 0;
}




