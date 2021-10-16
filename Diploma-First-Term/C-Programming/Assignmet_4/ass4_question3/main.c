/*
 * main.c
 *
 *  Created on: Oct 11, 2020
 *      Author: Hossam Magdy
 */


#include <stdio.h>

struct scomplex{
	float real,imag;
};
//struct scomplex g;

struct scomplex add(struct scomplex *x,struct scomplex *y){  //struct scomplex *add
	struct scomplex sum;   //struct scomplex *sum=&g;

	sum.real = x->real + y->real;
	sum.imag = x->imag + y->imag;

	return sum;
}



int main (){
	struct scomplex x,y;
	struct scomplex z;  //struct scomplex *z;

	printf("for 1st complex number\n");
	printf("enter real number and imaginary respectively:");
	fflush(stdout);
	scanf("%f %f",&x.real,&x.imag);
	printf("for 2st complex number\n");
	printf("enter real number and imaginary respectively:");
	fflush(stdout);
	scanf("%f %f",&y.real,&y.imag);
	z=add(&x,&y);
	printf("sum=%.1f+%.1fi",z.real,z.imag);

	return 0;
}
