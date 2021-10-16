/*
 * main.c
 *
 *  Created on: Nov 7, 2020
 *      Author: Hossam Magdy
 */
#include <stdio.h>
int main(){
	int m=29;
	int *ab;
	printf("address of m: %p\n",&m);
	printf("value of m: %d\n",m);
	ab=&m;
	printf("address of ab: %p\n",ab);
	printf("value of ab: %d\n",*ab);
	*ab=34; //m=34
	printf("The value of m assigned to 34 now\n");
	printf("address of ab: %p\n",ab);
	printf("value of ab: %d\n",*ab);
	*ab=7; //m=7
	printf("The value of m assigned to 7 now\n");
	printf("address of m: %p\n",&m);
	printf("value of m: %d\n",m);
	return 0;
}
