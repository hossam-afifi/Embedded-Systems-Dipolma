/*
 * solve lab
 * main.c
 *
 *  Created on: Aug 30, 2020
 *      Author: Hossam Magdy
 */

#include <stdio.h>

int main(){
	for(int i=0;i<=9;i++){
		for(int x=i;x<=9;x++)
			printf("%d ",x);
		printf("\n");
	}
	return 0;
}
