/*
 * main.c
 *
 *  Created on: Aug 29, 2020
 *      Author: Hossam Magdy
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long binarynum = 0;

int fact(void);
long decimalToBinary(void);
int power(void);
int main(){
	char x;
	float a,b;
	float result;
	long h,t;
	int m;
	const char divrest = '%';

	printf("Enter operator either w(welcome) + or - or * or divide or %c or factorial(f) or"
			"h (hex decimal) or b(binary) or (p)power e(exit) :\n", divrest);
	fflush(stdout);
	fflush(stdin);
	scanf("%c", &x);
	if(x!='f' && x!='&' && x!='b' && x!='B'  && x!='h' && x!='p' && x!='q'&& x!='e'&& x!='w' ){
		printf("Enter two value: ");
		fflush(stdout);
		scanf("%f %f", &a, &b);
	}
	switch(x){
	case 'w':
		printf("welcome Hossam Magdy");
		break;
	case '+':{
		result=a+b;
		printf("result=%f\n",result);
	}break;
	case '-':{
		result=a-b;
		printf("result=%f\n",result);
	}break;
	case '*':{
		result=a*b;
		printf("result=%f\n",result);
	}break;
	case '/':{
		result=a/b;
		printf("result=%f\n",result);
	}break;
	case '%':{
		result=((int)a) % ((int)b);
		printf("result=%f\n",result);
	}break;
	case 'f':{
		result=fact();
		printf("result=%f\n",result);
	}
	break;
	case 'B':
	case 'b':
	{
		decimalToBinary();
	}
	break;
	case 'h':
	case 'H':
	{	printf("enter number: ");
	fflush(stdout);
	scanf("%d",&m);
	fflush(stdout);
	printf("number hex is: %0x\n",m);
	}
	break;
	case '&':
	{
		t=decimalToBinary();
		h=decimalToBinary();
	}
	break;
	case 'e':
	{
		printf("Good Bye");
	}
	break;
	case 'p':
		result=power();
		printf("result=%d\n",(int)result);

		break;
	default:
		printf("Error!!!\n");
		break;
	}
	if(x=='b' || x=='B' || x=='&') {
		long g;
		g = binarynum;
		if(x=='&'){
			printf("%ld &% ld = %ld\n", t, h, t & h);
			fflush(stdout);
			exit(0);
		}
		printf("binary number is: %ld\n", g);
		fflush(stdout);
	}

	//printf("result=%f\n",result);
	return 0;
}

int fact(void){
	int sum=1,n,i;
	printf("enter number of factorial:");
	fflush(stdout);
	scanf("%d", &n);
	for( i=1;i<=n;i++){
		sum *= i;
	}
	return sum;
}
long decimalToBinary(void)
{
	int decimalnum;
	int rem, temp = 1;
	binarynum = 0;
	printf("Enter a Decimal Number: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &decimalnum);
	while (decimalnum!=0)
	{
		rem = decimalnum % 2;
		decimalnum = decimalnum / 2;
		binarynum = binarynum + rem*temp;
		temp = temp * 10;
	}
	//printf("Equivalent Binary Number is: %ld", decimalToBinary(decimalnum));
	return binarynum;
}
int power(void){
	int p,n,i,u=1;
	printf("enter number of power:");
	fflush(stdout);
	scanf("%d",&n);
	printf("enter number:");
	fflush(stdout);
	scanf("%d",&p);
	for(i=1;i<=n;i++)
		u=u*p;
	return u;
}
	//power function
				/*double n,m;
				printf("enter number of power:");
				fflush(stdout);
				scanf("%lf",&m);
				printf("enter number:");
				fflush(stdout);
				scanf("%lf",&n);
				result=pow(n, m);
				printf("result=%d\n",(int)result); */
