/*
 * FIFO.c
 *
 *  Created on: Jan 8, 2022
 *      Author: Hossam Magdy
 */


#include "FIFO.h"

/*make malloc for buf and fifo*/
fifo_status FIFO_init(fifo_buff*fifo,student_info * buf, u32 length){
	if(buf == 0)
		return FIFO_NULL;
	fifo->base=buf;
	fifo->head=buf;
	fifo->tail=buf;
	fifo->length=length;
	fifo->count=0;

	return FIFO_No_ERROR;

}

/*enter user data of student
 * 1_Roll
 * 2_first name
 * 3_second name
 * 4_GPA
 * 5_Course id (number of course id: 5)
 * */
fifo_status Add_studentManual(fifo_buff* fifo ){

	char student_name[2][20];
	//char student_fame[20];
	//char student_lame[20];

	u32 data;
	u32 id[5];
	float gpa_student;
	//static u16 count=0;
	student_info *ptr = fifo->head ;

	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(FIFO_full(fifo) == FIFO_FULL)
		return FIFO_FULL;

	DPRINTF("------------------------------------\n");
	DPRINTF("Add the student details\n");
	DPRINTF("-------------------------------------\n");

	DPRINTF("enter roll number:");
	scanf("%d",&data);

	DPRINTF("enter first name:");
	//gets(student_fame);
	gets(student_name[0]);

	DPRINTF("enter last name:");
	//gets(student_lame);
	gets(student_name[1]);
	DPRINTF("enter GPA:");
	scanf("%f",&gpa_student);

	for(u16 i=0;i<5;i++){
		DPRINTF("enter id course:");
		scanf("%d",&id[i]);
	}/*end of for loop*/

	if(F_checkRoll(data,fifo) == 1 && F_checkname(student_name,fifo) == 1) {
		ptr->roll = data;
		ptr->GPA =  gpa_student;
		strcpy(ptr->fname,student_name[0]);
		strcpy(ptr->lname,student_name[1]);
		for(u16 i=0;i<5;i++){
			ptr->cid[i] = id[i];

		}/*end of for loop*/
		fifo->head++;
		fifo->count++;
	}
	else{
		DPRINTF("[Error] student not save\n");
	}

	if(fifo->head == (fifo->base + (fifo->length * sizeof(ptr))))
		fifo->head = fifo->base;

	DPRINTF("##################################\n");
	DPRINTF("[Info]you can add up to 50 student\n");
	DPRINTF("[Info]student added :%d\n",fifo->count);
	DPRINTF("[Info]you can %d more students \n",50-fifo->count);
	DPRINTF("##################################\n");

	return FIFO_No_ERROR;
}

/*function read data of students in file */
fifo_status Add_studentFile(fifo_buff* fifo ){
	student_info *ptr = fifo->head;
	int data,id[5];
	float gpa;
	char student_fname[20];
	char student_lname[20];
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(FIFO_full(fifo) == FIFO_FULL)
		return FIFO_FULL;


	FILE *info_ptr = fopen("file_data.txt","r"); // read only

	if( info_ptr == 0 ){
		DPRINTF("file can't be read\n");
		return FIFO_ERROR;
	}

	while(fscanf(info_ptr,"%d %s %s %f %d %d %d %d %d\n", &data, student_fname,student_lname,&gpa,&id[0],&id[1],&id[2],&id[3],&id[4])!=EOF)
	{
		if(FIFO_full(fifo) == FIFO_FULL){
			DPRINTF("[Info]you can add up to 50 student\n");
			DPRINTF("The Total number of students:%d\n",fifo->count);
			DPRINTF("[Info]you can %d more students \n",50-fifo->count);
			return FIFO_FULL;
		}

		if(F_checkRoll(data,fifo) ==0){
			DPRINTF("[Error] Roll number %d is already taken\n",data);
		}

		else {
			DPRINTF("[Info] Roll number %d save successfully\n",data);
			ptr->roll = data;
			strcpy(ptr->fname,student_fname);
			strcpy(ptr->lname,student_lname);
			ptr->GPA = gpa;
			for(u16 i=0;i<5;i++){
				ptr->cid[i] =id[i];
			}
			ptr++;
			fifo->head++;
			fifo->count++;
		}


	}/*end while loop*/

	DPRINTF("##################################\n");
	DPRINTF("[Info]you can add up to 50 student\n");
	DPRINTF("The Total number of students:%d\n",fifo->count);
	DPRINTF("[Info]you can %d more students \n",50-fifo->count);
	DPRINTF("##################################\n");
	fclose(info_ptr);


	return FIFO_No_ERROR;
}


/*find student by Roll*/
fifo_status F_roll(fifo_buff* fifo ){
	u32 roll_number;
	student_info *ptr = student;

	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(FIFO_full(fifo) == FIFO_FULL)
		return FIFO_FULL;
	if(fifo->count == 0)
		return FIFO_EMPTY;

	DPRINTF("enter Roll number of student:");
	scanf("%d",&roll_number);

	for(u16 i=0;i<fifo->count;i++) {
		if(ptr->roll == roll_number) {
			DPRINTF("First name: %s\n",ptr->fname);
			DPRINTF("Last name: %s\n",ptr->lname);
			DPRINTF("GPA :%.3f\n",ptr->GPA);
			for(u16 i=0;i<5;i++){
				DPRINTF("Course ID: %d\n",ptr->cid[i]);
			}/*end of for loop2*/
			break;
		}/*end of if condition*/

		else {
			ptr++;
		}/*end of else condition*/
		DPRINTF("[error] Roll number no found\n");
		DPRINTF("########################################\n");
		break;
	}/*end of for loop1*/

	DPRINTF("############################################\n");
	DPRINTF("[Info]you can add up to 50 student\n");
	DPRINTF("The Total number of students:%d\n",fifo->count);
	DPRINTF("[Info]you can %d more students \n",50-fifo->count);
	DPRINTF("############################################\n");

	return FIFO_No_ERROR;
}

/*find student by first name*/
fifo_status F_firstName(fifo_buff* fifo ){
	char first_name[20];
	student_info *ptr = student;
	u16 count=0;
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(FIFO_full(fifo) == FIFO_FULL)
		return FIFO_FULL;

	DPRINTF("enter First name of student:");
	gets(first_name);
	for(u16 i=0;i<fifo->count;i++) {
		if((strcmp(ptr->fname,first_name)) == 0) {
			DPRINTF("Roll number of student:%d\n",ptr->roll);
			DPRINTF("First name of student:%s\n",ptr->fname);
			DPRINTF("Last name of student:%s\n",ptr->lname);
			DPRINTF("GPA of student:%.3f\n",ptr->GPA);
			for(u16 i= 0;i<5;i++){
				DPRINTF("Course ID:%d\n",ptr->cid[i]);

			}/*end of for loop2*/
			count++;
			break;
		} /*end if condition*/
		else {
			ptr++;
		} /*end of else condition*/

	} /*end of for loop1*/
	if(count !=0)
		DPRINTF("[Error] student not found\n");

	return FIFO_No_ERROR;
}
/*show number of student*/
fifo_status F_countStudent(fifo_buff* fifo ){
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(FIFO_full(fifo) == FIFO_FULL)
		return FIFO_FULL;

	DPRINTF("##################################################\n");
	DPRINTF("The Total number of students:%d\n",fifo->count);
	DPRINTF("[Info]you can add up to 50 student\n");
	DPRINTF("[Info]you can %d more students \n",50-fifo->count);
	DPRINTF("##################################################\n");

	return FIFO_No_ERROR;
}

/*find student by course id*/
fifo_status F_courseid(fifo_buff* fifo ){
	student_info *ptr =student;
	int id;
	u16 count = 0;
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(FIFO_full(fifo) == FIFO_FULL)
		return FIFO_FULL;
	if(FIFO_empty(fifo) == FIFO_EMPTY)
		return FIFO_EMPTY;
	DPRINTF("enter course id:")
	scanf("%d",&id);
	for(u16 i =0;i<fifo->count;i++) {
		for(u16 j =0;j<5;j++) {
			if(ptr->cid[j] == id) {
				DPRINTF("==============================================\n");
				DPRINTF("Roll number of student:%d\n",ptr->roll);
				DPRINTF("First name of student:%s\n",ptr->fname);
				DPRINTF("Last name of student:%s\n",ptr->lname);
				DPRINTF("GPA of student:%.3f\n",ptr->GPA);
			}/*end if condition*/
			count++;
		} /*end for loop2*/
		ptr++;
	}/*end for loop1*/
	if(count !=0)
		DPRINTF("[Error] course id not found\n");
	DPRINTF("##################################################\n");
	DPRINTF("The Total number of students:%d\n",fifo->count);
	DPRINTF("[Info]you can add up to 50 student\n");
	DPRINTF("[Info]you can %d more students \n",50-fifo->count);
	DPRINTF("##################################################\n");

	return FIFO_No_ERROR;
}
/*update data of student*/
fifo_status update_student(fifo_buff* fifo ){
	student_info *ptr = student;
	u32 roll_student,change_data;
	u32 id,course_id;
	char student_name[2][20];
	float gpa;

	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(FIFO_full(fifo) == FIFO_FULL)
		return FIFO_FULL;
	if(FIFO_empty(fifo) == FIFO_EMPTY)
		return FIFO_EMPTY;
	DPRINTF("enter roll number of student:");
	scanf("%d",&roll_student);

	for(u16 i=0;i<fifo->count;i++) {

		if(ptr->roll == roll_student) {
			DPRINTF("Roll number of student:%d\n",ptr->roll);
			DPRINTF("First name of student:%s\n",ptr->fname);
			DPRINTF("Last name of student:%s\n",ptr->lname);
			DPRINTF("GPA of student:%.3f\n",ptr->GPA);
			for(u16 i= 0;i<5;i++){
				DPRINTF("Course ID:%d\n",ptr->cid[i]);

			}/*end of for loop2*/
			DPRINTF("-----------------------------\n");
			DPRINTF("1) first name\n");
			DPRINTF("2) last name \n");
			DPRINTF("3) GPA\n");
			DPRINTF("4) courses ID\n");
			DPRINTF("enter option update data:");
			scanf("%d",&change_data);
			switch (change_data) {
			case 1: {
				DPRINTF("enter first name:");
				gets(student_name[0]);
				strcpy(student_name[1],ptr->lname);
				/*check first name is already save in FIFO or not
				 * this function is return 1(True) so first name will update not saved but
				 * return 0(False) first name will update not saved
				 */
				if(F_checkname(student_name,fifo) == 1){
					strcpy(ptr->fname,student_name[0]);
					DPRINTF("update successfully\n");
				}
				else
					DPRINTF("update not successfully\n");
				break;
			} /*end case1*/
			case 2: {
				DPRINTF("enter last name:");
				gets(student_name[1]);
				strcpy(student_name[0],ptr->fname);
				/*check last name is already save in FIFO or not
				 * this function is return 1(True) so last name will update not saved but
				 * return 0(False) last name will update not saved
				 */
				if(F_checkname(student_name,fifo) == 1){
					strcpy(ptr->lname,student_name[1]);
					DPRINTF("update successfully\n");
				}
				else
					DPRINTF("update not successfully\n");
				break;
			} /*end case2*/
			case 3: {
				DPRINTF("enter GPA:");
				scanf("%f",&gpa);
				ptr->GPA =gpa;
				break;
			} /*end case4*/
			case 4: {
				DPRINTF("if you want change once course id enter(1) or change all courses id(2)\n");
				scanf("%d",&id);
				if(id == 1){
					DPRINTF("enter course id:");
					scanf("%d",&course_id);
					DPRINTF("enter number course id:");
					scanf("%d",&id);
					ptr->cid[id] = course_id;
				} /*end if*/
				else {
					for(u16  i=0;i<5;i++) {
						DPRINTF("enter course id[%d]:",i+1);
						scanf("%d",&course_id);
						ptr->cid[i] = course_id;
					}/*end for loop*/
				} /*end else*/

				break;
			} /*end case4*/
			default: {
				DPRINTF("[Error] select wrong option\n");
				break;
			}
			} /*end of switch case*/
			break;
		}/*end of if condition*/
		else
			ptr++;
	}/*end of for loop*/

	DPRINTF("#################################################\n");
	DPRINTF("[INFO]The Total number of students:%d\n",fifo->count);
	DPRINTF("[INFO]you can add up to 50 student\n");
	DPRINTF("[INFO]you can %d more students \n",50-fifo->count);
	DPRINTF("#################################################\n");

	return FIFO_No_ERROR;
}

/*delete student from queue*/
fifo_status Delete_student(fifo_buff* fifo ){
	student_info *ptr = student;
	student_info temparr[55];
	fifo->tail = fifo->base;
	int roll_number;
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(FIFO_full(fifo) == FIFO_FULL)
		return FIFO_FULL;
	if(FIFO_empty(fifo) == FIFO_EMPTY)
		return FIFO_EMPTY;

	DPRINTF("Enter Roll Number:");
	scanf("%d",&roll_number);
	for(u16 i=0;i<fifo->count;i++) {
		if(ptr->roll == roll_number){
			fifo->tail = ptr+1; //tail increment for ptr
			//size of elements from tail and head
			u16 size = ((fifo->head - fifo->tail)/sizeof(student_info))+1;
			/* destination : temparr
			 * source : tail
			 * copy source(tail) to destination(temparr)
			 * */
			memcpy(temparr,fifo->tail,size*sizeof(student_info));
			//copy temparr to ptr
			memcpy(ptr,temparr,size*sizeof(student_info));
			/* decrement head and count*/
			fifo->head--;
			fifo->count--;
			break;
		}/*end if condition*/
		ptr++;
	}/*end for loop1*/

	/* check tail in last FIFO (head)
	 * Check if condition is correct tail will equal base(first element in FIFO)
	 */
	if(fifo->tail == (fifo->base + (fifo->length * sizeof(ptr))))
		fifo->tail = fifo->base;

	DPRINTF("#################################################\n");
	DPRINTF("[INFO]The Total number of students:%d\n",fifo->count);
	DPRINTF("[INFO]you can add up to 50 student\n");
	DPRINTF("[INFO]you can %d more students \n",50-fifo->count);
	DPRINTF("#################################################\n");
	return FIFO_No_ERROR;
}

/*show all student in queue*/
fifo_status show_students(fifo_buff* fifo ){
	//student_info *ptr = student;

	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(FIFO_full(fifo) == FIFO_FULL)
		return FIFO_FULL;
	if(FIFO_empty(fifo) == FIFO_EMPTY)
		return FIFO_EMPTY;

	for(u16 i=0;i<fifo->count;i++) {
		DPRINTF("---------------------------------------\n");
		DPRINTF("Roll number of student:%d\n",fifo->tail->roll);
		DPRINTF("First name of student:%s\n",fifo->tail->fname);
		DPRINTF("Last name of student:%s\n",fifo->tail->lname);
		DPRINTF("GPA of student:%.3f\n",fifo->tail->GPA);
		for(u16 i= 0;i<5;i++) {
			DPRINTF("Course ID:%d\n",fifo->tail->cid[i]);
		} /*end of for loop2*/
		fifo->tail++;
	}/*end of for1 loop*/
	fifo->tail = fifo->base;
	return FIFO_No_ERROR;
}

/*exit from FIFO*/
void f_exit(){
	DPRINTF("######### Thank you ##########\n");
	exit(0);
}

/*function check of roll student,this function return true or false*/
char F_checkRoll(int data,fifo_buff *fifo ){
	student_info *ptr= student;
	//static u32 count=0;

	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(FIFO_full(fifo) == FIFO_FULL)
		return FIFO_FULL;

	//check roll number of students is frequent
	for(u16 i=0;i<fifo->count;i++) {
		if(ptr->roll == data ){
			return FALSE;
		}/*end of if condition*/
		ptr++;
	}/*end of for loop1*/


	return TRUE;
}

// function check name student and return true or false
char F_checkname(char name_student[ROW][Column],fifo_buff *fifo){
	student_info *ptr= student;
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(FIFO_full(fifo) == FIFO_FULL)
		return FIFO_FULL;

	for(u16 i=0;i<fifo->count;i++) {
		// compare name of student
		if(strcmp(name_student[0],ptr->fname) == 0 && strcmp(name_student[1],ptr->lname) == 0) {
			return FALSE;
		}/*end of if condition*/
		ptr++;
	} /*end of for loop*/

	return TRUE;
}

#if 0
/*other solution to implement this function*/
char F_checkname(char *fname_student,char *lname_student,fifo_buff *fifo){
	student_info *ptr= student;
	//fifo_buff *fifo  ;
	//student_info *next= student;

	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(FIFO_full(fifo) == FIFO_FULL)
		return FIFO_FULL;


	//if(fifo->count > 0){
	for(u16 i=0;i<fifo->count;i++) {
		// compare name of student
		if(strcmp(fname_student,ptr->fname) == 0 && strcmp(lname_student,ptr->lname) == 0) {
			return FALSE;
		}/*end of if condition*/
		ptr++;
	} /*end of for loop*/
	//}

	return TRUE;
}
#endif


fifo_status FIFO_empty(fifo_buff* fifo ){
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(fifo->count == 0)
		return FIFO_EMPTY;

	return FIFO_No_ERROR;
}

fifo_status FIFO_full(fifo_buff* fifo ){
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(fifo->count == fifo->length)
		return FIFO_FULL;
	return FIFO_No_ERROR;
}
