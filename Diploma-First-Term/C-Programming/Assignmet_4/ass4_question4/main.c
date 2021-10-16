/*
 * main.c
 *
 *  Created on: Oct 11, 2020
 *      Author: Hossam Magdy
 */

#include <stdio.h>
#include <stdio.h>

struct sstudent{
	char name[50];
	float mark;
	int number;
};
//struct sstudent f;
struct sstudent data(){
struct sstudent f[50];
int i;
printf("enter information of students\n");
for(i=0;i<10;i++){
	printf("enter roll number:%d\n",i+1);
	printf("enter name:");
	fflush(stdout);
	scanf("%s",f[i].name);
	//gets(f[i].name);
	printf("enter mark:");
	fflush(stdout);
	scanf("%f",&f[i].mark);
}
printf("\ndisplaying information of students\n");
for(i=0;i<10;i++){
	printf("roll number:%d\n",i+1);
	printf("name:%s\n",f[i].name);
	printf("mark:%.2f\n", f[i].mark);
}
	return *f;
}
int main (){
	data();
	return 0;
}
