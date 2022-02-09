/*
 ============================================================================
 Name        : student_mangment.c
 Author      : Hossam Magdy
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "FIFO.h"

int main(void) {
	fifo_buff queue;
	fifo_buff* fifo = &queue;
	int choice =0;
	if((FIFO_init(fifo,student,100)) == FIFO_No_ERROR)

	DPRINTF("Welcome to the Student Management System\n");
// infinite loop
	while(1)
	{
		DPRINTF("====================================================\n");
		DPRINTF("Choice The Task that you want to perform\n");
		DPRINTF("1) Add the Student Details Manually\n");
		DPRINTF("2) Add the Student Details From Text File\n");
		DPRINTF("3) Find the Student Details by Roll Number\n");
		DPRINTF("4) Find the Student Details by First Name\n");
		DPRINTF("5) Find the Student Details by Course ID\n");
		DPRINTF("6) Find the Total number of Students\n");
		DPRINTF("7) Delete the Student Details by Roll Number\n");
		DPRINTF("8) Update the Student Details by Roll Number\n");
		DPRINTF("9) Show all information\n");
		DPRINTF("10) exit\n");
		DPRINTF("====================================================\n");
		DPRINTF("Enter your option: ");
		scanf("%d",&choice);

		switch (choice) {
		case 1:
			Add_studentManual(fifo);
			break;
		case 2:
			Add_studentFile(fifo);
			break;
		case 3:
			F_roll(fifo);
			break;
		case 4:
			F_firstName(fifo);
			break;
		case 5:
			F_courseid(fifo);
			break;
		case 6:
			F_countStudent(fifo);
			break;
		case 7:
			Delete_student(fifo);
			break;
		case 8:
			update_student(fifo);
			break;
		case 9:
			show_students(fifo);
			break;
		case 10:
			f_exit();
			break;
		default:
			DPRINTF("wrong choice option\n");
			break;
		}

	}

	return 0;
}
