/*
 * main.c
 *
 *  Created on: Oct 11, 2020
 *      Author: Hossam Magdy
 */


#include <stdio.h>

struct sdistance{
	int feet;
	float inch;
};

struct sdistance *Add(struct sdistance* x , struct sdistance* y){
	struct sdistance g;
	struct sdistance *sum = &g;
	sum->feet= x->feet + y->feet;
	sum->inch= x->inch + y->inch;
	if(sum->inch>12.0){
		sum->inch= sum->inch - 12.0;
		++sum->feet;
	}
	printf("\nsum of distance=%d\'-%.2f\"",sum->feet,sum->inch);
	return sum;
}

int main(){
	struct sdistance d,f;
	struct sdistance *z;
	printf("enter information for 1st distance\n");
	printf("enter feet:");
	fflush(stdout);
	scanf("%d",&d.feet);
	printf("enter inch:");
	fflush(stdout);
	scanf("%f",&d.inch);
	printf("\nenter information for 2st distance\n");
	printf("enter feet:");
	fflush(stdout);
	scanf("%d",&f.feet);
	printf("enter inch:");
	fflush(stdout);
	scanf("%f",&f.inch);
	z= Add(&d,&f);
	return 0;
}
