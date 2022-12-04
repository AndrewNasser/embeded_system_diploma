/*
 ============================================================================
 File Name        : Student Management
 Author           : Andrew Nasser
 Description      : system.c
 ============================================================================
 */
#include "system.h"
#include "FIFO.h"

FIFO_BUFFER buff;

unsigned char init = 0;

void add_student_file(){
	int count = 0;
	struct sinfo student;
	if(init){
		FILE *fp;
		fp = fopen("students.txt","r");

		if(!fp){
			DPRINTF("Sorry cannot read file\n");
		}
		else{
			while(fscanf(fp,"%d %s %s %f %d %d %d %d %d[^\n]",&(student.roll),student.fname,student.lname,
					&(student.gpa),&(student.cid[0]),&(student.cid[1]),
					&(student.cid[2]),&(student.cid[3]),&(student.cid[4]))!=EOF){

				switch(FIFO_add(&buff,student)){
				case FIFO_NO_ERROR:
					DPRINTF("[INFO] Roll number %d has been saved successfully\n",student.roll);
					count++;
					break;
				case FIFO_ITEM_ID_NOT_UNIQUE:
					DPRINTF("[ERROR] Roll number %d is already taken\n",student.roll);
					break;
				default:
					DPRINTF("[ERROR]  Students database is full\n");
					break;
				}

			}
			if(count > 0){
				DPRINTF("[INFO] Students details were added successfully\n");
			}
			find_total_no_of_students();
		}
		fclose(fp);
	}else{
		if(FIFO_init(st,SIZE,&buff) == FIFO_NO_ERROR){

			init = 1;
			FILE *fp;

			fp=fopen("students.txt","r");
			if(!fp){
				DPRINTF("Couldn't read file\n");
			}
			else{
				while(fscanf(fp,"%d %s %s %f %d %d %d %d %d[^\n]",&(student.roll),student.fname,student.lname,
						&(student.gpa),&(student.cid[0]),&(student.cid[1]),
						&(student.cid[2]),&(student.cid[3]),&(student.cid[4]))!=EOF){
					switch(FIFO_add(&buff,student)){
					case FIFO_NO_ERROR:
						DPRINTF("[INFO] Roll number %d saved successfully\n",student.roll);
						count++;
						break;
					case FIFO_ITEM_ID_NOT_UNIQUE:
						DPRINTF("[ERROR] Roll number %d is already taken\n",student.roll);
						break;
					default:
						DPRINTF("[ERROR]  Students database is full\n");
						break;
					}
				}
				if(count > 0){
					DPRINTF("[INFO] Students details were added successfully\n");
				}
				find_total_no_of_students();
			}
			fclose(fp);
		}
		else{
			DPRINTF("Error in initialization\n");
		}
	}
}

void add_student_manually(){

	int i;
	struct sinfo student;

	if(init){
		DPRINTF("--------------------------\n");
		DPRINTF("Add the student details\n");
		DPRINTF("--------------------------\n");
		DPRINTF("Enter the roll number: ");
		scanf("%d",&student.roll);
		DPRINTF("Enter the first name of student: ");
		gets(student.fname);
		DPRINTF("Enter the last name of student: ");
		gets(student.lname);
		DPRINTF("Enter the GPA: ");
		scanf("%f",&student.gpa);
		DPRINTF("Enter the course ID for each course: \n");
		for(i = 0; i < 5; i++){
			DPRINTF("Course %d ID: ",i+1);
			scanf("%d",&student.cid[i]);
		}
		switch(FIFO_add(&buff,student)){

		case FIFO_NO_ERROR:
			DPRINTF("[INFO] Student details was added successfully\n");
			break;
		case FIFO_ITEM_ID_NOT_UNIQUE:
			DPRINTF("[ERROR] Roll number %d is already taken\n",student.roll);
			break;
		default:
			DPRINTF("[ERROR]  Students database is full\n");
			break;
		}
		find_total_no_of_students();
	}
	else{
		if(FIFO_init(st,SIZE,&buff) == FIFO_NO_ERROR){
			init = 1;

			DPRINTF("--------------------------\n");
			DPRINTF("Add the student details\n");
			DPRINTF("--------------------------\n");
			DPRINTF("Enter the roll number: ");
			scanf("%d",&student.roll);
			DPRINTF("Enter the first name of student: ");
			gets(student.fname);
			DPRINTF("Enter the last name of student: ");
			gets(student.lname);
			DPRINTF("Enter the GPA: ");
			scanf("%f",&student.gpa);
			DPRINTF("Enter the course ID for each course\n");
			for(i = 0; i < 5; i++){
				DPRINTF("Course %d ID: ",i+1);
				scanf("%d",&student.cid[i]);
			}
			switch(FIFO_add(&buff,student)){

			case FIFO_NO_ERROR:
				DPRINTF("[INFO] Student details was added successfully\n");
				break;
			case FIFO_ITEM_ID_NOT_UNIQUE:
				DPRINTF("[ERROR] Roll number %d is already taken\n",student.roll);
				break;
			default:
				DPRINTF("[ERROR] Students database is full\n");
				break;
			}
			find_total_no_of_students();
		}
		else{
			DPRINTF("Error in initialization\n");
		}
	}
}

void find_by_roll_no(){
	int rl, i;
	struct sinfo student;

	DPRINTF("Enter the roll number of the student: ");
	scanf("%d",&rl);

	switch(FIFO_findByRL(&buff,rl,&student,FIFO_FIND)){
	case FIFO_NO_ERROR:
		DPRINTF("The student's details are\n");
		DPRINTF("The first name is %s\n",student.fname);
		DPRINTF("The last name is %s\n",student.lname);
		DPRINTF("The GPA is %.2f\n",student.gpa);
		DPRINTF("The course ID of each course\n");
		for(i = 0; i < 5; i++){
			DPRINTF(" The course ID is: %d\n",student.cid[i]);
		}
		break;
	case FIFO_ITEM_NOT_FOUND:
		DPRINTF("[ERROR] Roll number %d was not found\n",rl);
		break;
	default:
		DPRINTF("[ERROR] Students database is empty or not yet initialized\n");
		break;

	}


}
void find_by_first_name(){
	char name[50];
	int j, i = 0;
	struct sinfo student[SIZE] = {{""}};

	DPRINTF("Enter the first name of the student: ");
	gets(name);

	switch(FIFO_findByFName(&buff,name,student)){
	case FIFO_NO_ERROR:
		while(student[i].roll){
			DPRINTF("The student's details are\n");
			DPRINTF("The first name is %s\n",student[i].fname);
			DPRINTF("The last name is %s\n",student[i].lname);
			DPRINTF("The roll number is %d\n",student[i].roll);
			DPRINTF("The GPA is %.2f\n",student[i].gpa);
			DPRINTF("The course ID of each course\n");
			for(j = 0; j < 5; j++){
				DPRINTF(" The course ID is: %d\n",student[i].cid[j]);
			}
			i++;
		}
		break;
	case FIFO_ITEM_NOT_FOUND:
		DPRINTF("[ERROR] First name %s was not found\n",name);
		break;
	default:
		DPRINTF("[ERROR] Students database is empty or not yet initialized\n");
		break;
	}
}

void find_by_course_id(){

	int cid, i = 0;
	struct sinfo student[SIZE] = {{""}};

	DPRINTF("Enter the course ID: ");
	scanf("%d",&cid);

	switch(FIFO_findByCID(&buff,cid,student)){
	case FIFO_NO_ERROR:
		while(student[i].roll){
			DPRINTF("The student's details are\n");
			DPRINTF("The first name is %s\n",student[i].fname);
			DPRINTF("The last name is %s\n",student[i].lname);
			DPRINTF("The roll number is %d\n",student[i].roll);
			DPRINTF("The GPA is %.2f\n",student[i].gpa);
			i++;
		}
		DPRINTF("[INFO] Total number of students enrolled: %d\n",i);
		break;
	case FIFO_ITEM_NOT_FOUND:
		DPRINTF("[ERROR] Course ID %d was not found\n",cid);
		break;
	default:
		DPRINTF("[ERROR] Students database is empty or not yet initialized\n");
		break;
	}

}
void find_total_no_of_students(){

	if(init){
		DPRINTF("--------------------------\n");
		DPRINTF("[INFO] Total number of students is %d\n",buff.count);
		DPRINTF("[INFO] You can add up to %d students\n",buff.length);
		DPRINTF("[INFO] You can add %d more students\n",buff.length-buff.count);
	}
	else{
		DPRINTF("[ERROR] Students database is empty or not yet initialized\n");
	}
}
void delete_student(){

	int rl;
	struct sinfo student;

	DPRINTF("Enter the roll number which you want to delete: ");
	scanf("%d",&rl);
	switch(FIFO_findByRL(&buff,rl,&student,FIFO_DELETE)){
	case FIFO_NO_ERROR:
		DPRINTF("[INFO] Roll number %d was deleted successfully\n",rl);
		break;
	case FIFO_ITEM_NOT_FOUND:
		DPRINTF("[ERROR] Roll number %d was not found\n",rl);
		break;
	default:
		DPRINTF("[ERROR] Students database is empty or not yet initialized\n");
		break;
	}

}
void update_student(){

	int i, rl, choice;
	struct sinfo student;
	DPRINTF("Enter the roll number to update the entry: ");
	scanf("%d",&rl);
	switch(FIFO_findByRL(&buff,rl,&student,FIFO_FIND)){
	case FIFO_NO_ERROR:
		while(choice <= 0 || choice > 5){
			DPRINTF("1.First name\n");
			DPRINTF("2.Last name\n");
			DPRINTF("3.Roll no.\n");
			DPRINTF("4.GPA\n");
			DPRINTF("5.Courses ID\n");
			scanf("%d",&choice);
			switch(choice){
			case 1:
				DPRINTF("Enter new first name: ");
				gets(student.fname);
				FIFO_findByRL(&buff,rl,&student,FIFO_UPDATE);
				DPRINTF("[INFO] Updated successfully\n");
				break;
			case 2:
				DPRINTF("Enter new last name: ");
				gets(student.lname);
				FIFO_findByRL(&buff,rl,&student,FIFO_UPDATE);
				DPRINTF("[INFO] Updated successfully\n");
				break;
			case 3:
				DPRINTF("Enter new roll no.: ");
				scanf("%d",&student.roll);
				if(FIFO_findByRL(&buff,student.roll,&student,FIFO_FIND)==FIFO_ITEM_NOT_FOUND){
					FIFO_findByRL(&buff,rl,&student,FIFO_UPDATE);
					DPRINTF("[INFO] Updated successfully\n");
				}else{
					DPRINTF("[ERROR] Roll number %d is already taken\n",student.roll); }
				break;
			case 4:
				DPRINTF("Enter new GPA: ");
				scanf("%f",&student.gpa);
				FIFO_findByRL(&buff,rl,&student,FIFO_UPDATE);
				DPRINTF("[INFO] Updated successfully\n");
				break;
			case 5:
				DPRINTF("Enter new courses ID: \n");
				for(i=0;i<5;i++){
					DPRINTF("Course %d ID: ",i+1);
					scanf("%d",&student.cid[i]);
				}
				FIFO_findByRL(&buff,rl,&student,FIFO_UPDATE);
				DPRINTF("[INFO] Updated successfully\n");
				break;
			default:
				DPRINTF("[ERROR] Invalid input\n");
				break;
			}
		}
		break;
	case FIFO_ITEM_NOT_FOUND:
		DPRINTF("[ERROR] Roll number %d was not found\n",rl);
		break;
	default:
		DPRINTF("[ERROR] Students database is not yet initialized\n");
		break;
	}

}
void show_student(){

	if(init){
		FIFO_printAll(&buff);
	}
	else{
		DPRINTF("[ERROR] Students database is empty or not yet initialized\n");
	}
}
