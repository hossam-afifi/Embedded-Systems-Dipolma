/*
 * main.c
 *
 *  Created on: Nov 7, 2020
 *      Author: Hossam Magdy
 */

#include <stdio.h>

int main(){
	int i;
	char *ab;
	char arr[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N',
		          'O','P','Q','R','S','T','U','V','M','X','Y','Z'};
	ab=arr;
	for(i=0;i<27;i++,ab++){
		printf(" %c",*ab);
	}
	return 0;
}
