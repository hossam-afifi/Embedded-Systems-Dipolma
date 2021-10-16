/*
 * main.c
 *
 *  Created on: Oct 10, 2020
 *      Author: Hossam Magdy
 */

#include <stdio.h>
#include <string.h>

struct sstudent{
	char name[50];
	float mark;
	int number;
};
//struct sstudent x;

struct sstudent* data(struct sstudent *x){	//struct sstudent data(struct sstudent &x)

	printf("\ndisplaying information \n");
	printf("name:%s\n",x->name);
	printf("roll number:%d",x->number);
	printf("\nmark:%.2f", x->mark);

	return x;
}

int main (){
	struct sstudent f;
	struct sstudent* z;
	printf("enter information of student \n");
	printf("enter name:");
	fflush(stdout);
	scanf("%s",f.name); //gets(x.name)
	printf("enter roll number:");
	fflush(stdout);
	scanf("%d",&f.number);
	printf("enter mark:");
	fflush(stdout);
	scanf("%f",&f.mark);

	z = data(&f);

	return 0;
}
