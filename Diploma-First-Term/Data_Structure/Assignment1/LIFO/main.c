/*
 * main.c
 *
 *  Created on: Sep 4, 2021
 *      Author: amagd
 */

#include "stdio.h"
#include "LIFO.h"


//int max_num(int x,int y);
uinit_32 buffer_1[5];
uinit_32 temp=0;
int main (){
LIFO_bus_t Uart_lifo;
LIFO_init(&Uart_lifo,buffer_1,5);
for (int i = 0; i < 8; i++) {
	if(LIFO_Push_item(&Uart_lifo,i) == LIFO_NO_ERROR)
		printf("uart_lifo push(%d):%d\n",i,i);
	else
		printf("LIFO_Push_item(%d) is Failed\n",i);
}
printf("################################\n");
for (int i = 0; i < 8; i++) {
	if(LIFO_Pull_item(&Uart_lifo,&temp) == LIFO_NO_ERROR)
		printf("uart_lifo pull:%d\n",temp);
	else
		printf("LIFO_Push_item(%d) is Failed\n",i);
}

	return 0;
}

/*

int max_num(int x,int y){

	if(x>y)
		return x;
	else
		return y;

}

*/
/*
	unsigned int arr[SIZE]={1,2,2,3,3,3,4,4},COUNT_1=0,COUNT_2=0; //COUNT_3=0; //count_1
	unsigned int *ptr = arr;
	printf("enter number of element: \n");
	fflush(stdout);

	for(int i=0;i<SIZE;i++){
		scanf("%d",&arr[i]);
	}

	printf("number of elements are :\n");
	for(int i=0;i<SIZE;i++){
		printf("%d\t",arr[i]);
	}

	printf("\n");
	printf("#############################\n");
	printf("print elements of array pointer\n");
	for(int i=0;i<SIZE;i++){
		printf("%d\t",*ptr++);
	}

	printf("\n");

	ptr = arr;
	COUNT_1 = arr[0];
	for(int i=0;i<SIZE-1;i++){
		if( arr[i+1] == *ptr) {
			COUNT_1 = *ptr;
			count++;
			ptr++;

		}
		else if( arr[i+1] < *ptr) {
			COUNT_2 = *ptr;
			count=1;
		}

		else
			ptr++;

		int y = max_num(COUNT_1,COUNT_2);


	}

	printf("\nbig number is :%d",COUNT_1);
 */







