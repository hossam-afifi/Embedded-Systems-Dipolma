/*
 * main.c
 *
 *  Created on: Oct 11, 2020
 *      Author: Hossam Magdy
 */




#include <stdio.h>

union job {
	char name[32];
	int worker_no;
	float salary;
}u;
struct job1{
	char name[32];
	int worker_no;
	float salary;
}s;

int main (){
	printf("size of union =%d\n",sizeof(u));
	printf("size of structure =%d",sizeof(s));
	return 0;
}

