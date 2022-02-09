/*
 * FIFO.h
 *
 *  Created on: Jan 8, 2022
 *      Author: amagd
 */

#ifndef FIFO_H_
#define FIFO_H_
#include <stdio.h>
#include "string.h"
#include "stdlib.h"

#define TRUE  1
#define FALSE 0
#define ROW   2
#define Column   20

typedef unsigned char u8;
typedef unsigned int   u32;
typedef unsigned short u16;

#define DPRINTF(...)    {   fflush(stdin); fflush(stdout); \
	                          printf(__VA_ARGS__);       \
	                          fflush(stdin); fflush(stdout); }

typedef struct Sstudent  {
	char fname[50];
	char lname[50];
	u16 roll;
	u32 cid[5];
	float GPA;
} student_info;

student_info student[55];

typedef struct {
	u32 length;
	u32 count;
	student_info *head;
	student_info *tail;
	student_info *base;
}fifo_buff;


typedef enum{
	FIFO_ERROR,
	FIFO_No_ERROR,
	FIFO_EMPTY,
	FIFO_FULL,
	FIFO_NULL
}fifo_status;

/*APIs Function*/
fifo_status FIFO_init(fifo_buff*fifo,student_info * buf, u32 length);
fifo_status Add_studentManual(fifo_buff* fifo );
fifo_status Add_studentFile(fifo_buff* fifo );
fifo_status F_roll(fifo_buff* fifo );
fifo_status F_firstName(fifo_buff* fifo );
fifo_status F_countStudent(fifo_buff* fifo );
fifo_status F_courseid(fifo_buff* fifo );
fifo_status update_student(fifo_buff* fifo );
fifo_status show_students(fifo_buff* fifo );
void f_exit();
fifo_status FIFO_full(fifo_buff* fifo );
fifo_status FIFO_empty(fifo_buff* fifo );
fifo_status Delete_student(fifo_buff* fifo );
char F_checkRoll(int data,fifo_buff *fifo);
char F_checkname(char name_student[ROW][Column],fifo_buff* fifo );


#endif /* FIFO_H_ */
