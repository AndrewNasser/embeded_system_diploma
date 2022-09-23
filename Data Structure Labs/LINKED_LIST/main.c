/*
 ============================================================================
 Name        : lifo.h
 Author      : ANDREW NASSER
 Created on  : 18/9
 ============================================================================
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"



struct Sdata{
	int ID;
	char name[40];
	float height;
};
/*linke_list_node*/
struct Sstudent{
	struct Sdata student;
	struct Sstudent* PNextStudent;

};
struct Sstudent* gpFirststudent = NULL ;
void AddStruct(){

	struct Sstudent* Pnewstudent;
	struct Sstudent* Plaststudent;
	char temp[40];

	/*check list is empty == yes*/

	if(gpFirststudent == NULL)
	{
		Pnewstudent=(struct Sstudent*) malloc (sizeof(struct Sstudent));
		/*assign to the gp first*/
		gpFirststudent=Pnewstudent;

	}
	else
		/*list have record*/
	{
		/*navigate until reach to last record*/

		Plaststudent= gpFirststudent;
		while(Plaststudent->PNextStudent)
			Plaststudent=Plaststudent->PNextStudent;

		/*create new record*/

		Pnewstudent=(struct Sstudent*) malloc (sizeof(struct Sstudent));
		Plaststudent->PNextStudent = Pnewstudent;

	}
	/*fill the record*/

	printf(" \n Enter your ID ");
	fflush(stdin);fflush(stdout);
	gets(temp);
	Pnewstudent->student.ID = atoi(temp);
	printf(" \n Enter your Name ");
	fflush(stdin);fflush(stdout);
	gets(Pnewstudent->student.name);
	printf(" \n Enter your height ");
	fflush(stdin);fflush(stdout);
	gets(temp);
	Pnewstudent->student.ID = atof(temp);

}

/***************************************************/


int delete_student(){
	char temp[40];
	unsigned int selected_id ;
	/* get selected id*/
	printf("\n enter the student id to be delete : ");
	fflush(stdin);fflush(stdout);
	gets(temp);
	selected_id = atoi (temp);
	/*list no empty*/
	if (gpFirststudent){
		struct Sstudent* pselectedstudent= gpFirststudent;
		struct Sstudent* ppreviosstudent = NULL;
		/*LOOP IN RECORDSS */
		while(pselectedstudent){
			/* compare each node with selected id*/
			if (pselectedstudent->student.ID == selected_id){
				if (ppreviosstudent){
					ppreviosstudent->PNextStudent=pselectedstudent->PNextStudent;

				}
				else
				{
					gpFirststudent=pselectedstudent->PNextStudent;
				}
				free(pselectedstudent);
				return 1;

			}
			else{
			ppreviosstudent=pselectedstudent;
			pselectedstudent=pselectedstudent->PNextStudent;
		}

	}
}
	printf("\n cannet find selected student");
			return 0;
}

/***************************************************/


void view_student () {
    struct Sstudent* pcurrentstudent = gpFirststudent ;
    int count=0;
    if(gpFirststudent==NULL)
    {
        printf("\n empty list");
    }
    else
    {
        while(pcurrentstudent)
        {
            printf("\n\trecord number %d",count+1);
            printf("\n id: %d",pcurrentstudent->student.ID );
            printf("\n name: %s",pcurrentstudent->student.name);
            printf("\n height: %f",pcurrentstudent->student.height);
            count++;
            pcurrentstudent=pcurrentstudent-> PNextStudent;

        }
    }
}

 /***************************************************/


void DeleteALL ()
{
    struct Sstudent* pcurrentstudent = gpFirststudent ;
    if(gpFirststudent==NULL)
    {
        printf("\n empty list");
    }
    else
    {
        while(pcurrentstudent)
        {
           struct Sstudent* pTempstudent =pcurrentstudent;
           pcurrentstudent=pcurrentstudent->PNextStudent;
           free(pTempstudent);

        }
        gpFirststudent= NULL;
    }
}

/***************************************************/


void find_student(struct Sstudent* student){
int count=0,index;
printf("ENTER RHE INDEX \n");
scanf("%d",&index);
struct Sstudent* indexstudent=student;
while(indexstudent){
    if(count==index){
        printf("\n===============Student Data=============\n");
			printf("The student name : %s\n",indexstudent->student.name);
			printf("The student ID : %d\n",indexstudent->student.ID);
			printf("The student height : %f\n",indexstudent->student.height);
			printf("\n============================\n");
    }
    count++;
    indexstudent=indexstudent->PNextStudent;

}
}

/***************************************************/


int length_list(){

int count;
struct Sstudent* currentstudent= gpFirststudent;
while(currentstudent)
    {
        count++;
        currentstudent=currentstudent->PNextStudent;

}
return count ;
}

/***************************************************/

void find_student_from_end(){

int i,count=1,length;
unsigned int select_index;
char temp [40];
printf("Enter the Index you Select");
gets(temp);
select_index=atoi(temp);

struct Sstudent* pcurrentstudent=gpFirststudent;
length=length_list();
for(i=1;i<length-select_index+1; i++){
    pcurrentstudent=pcurrentstudent->PNextStudent;
}
count=i;
    printf("\n\tRecord number %d",count);
    printf("\n Id: %d",pcurrentstudent->student.ID);
    printf("\n Name: %s",pcurrentstudent->student.name);
    printf("\n Height: %f",pcurrentstudent->student.height);

}

/***************************************************/

void middle_list(){
if(gpFirststudent== NULL){
    printf("THE LIST IS EMPTY");
}
else{
    struct Sstudent* pcurrentstudent=gpFirststudent;
    int i,count=1,length;
    length=length_list();
        if(length%2 !=0){
            length=(length/2 )+1;
            while(count){
                if(length==count){
                    printf("\n\tRecord number %d",count);
                    printf("\n ID: %d",pcurrentstudent->student.ID);
                    printf("\n Name: %s",pcurrentstudent->student.name);
                    printf("\n Height: %f",pcurrentstudent->student.height);
                    count=0;
                }
                else{
                    pcurrentstudent=pcurrentstudent->PNextStudent;
                    count++;
                }
            }
        }
        else{
             length=(length/2);
            while(count)
            {
                if(length==count)
                {
                    for(i=0;i<2;i++)
                    {
                        printf("\n\tRecord number %d",count);
                        printf("\n ID: %d",pcurrentstudent->student.ID);
                        printf("\n Name: %s",pcurrentstudent->student.name);
                        printf("\n Height: %f",pcurrentstudent->student.height);
                        pcurrentstudent=pcurrentstudent->PNextStudent;
                        count++;
                    }
                    count=0;
                }
                else
                {
                    pcurrentstudent=pcurrentstudent->PNextStudent;
                    count++;
                }
            }
        }

    }
}

/***************************************************/



int main(){
unsigned int num;
	while(1){
	printf("=====Choose some=====\n");
	printf("1 : ADD STUDENT\n");
	printf("2 : Delete Student\n");
	printf("3 : PRINT STUDENTS\n");
	printf("4 : Delete All\n");
	printf("5 : VIEW STUDENT FROM NUMBER OF INDEX \n");
    printf("6 : GET LENGTH OF LIST \n");
    printf("7 : VIEW STUDENT FROM NUMBER OF INDEX FROM END \n");
    printf("8 : VIEW STUDENT IN MIDDLE OF LIST\n");

	scanf("%d",&num);
	switch (num){
	case 1:
		AddStruct();
		break;
	case 2:
		delete_student();
			break;
	case 3:
		view_student();
			break;
	case 4:
		DeleteALL();
			break;
    case 5:
        view_student();
            break;
    case 6:
        length_list();
            break;
    case 7:
        find_student_from_end();
            break;
    case 8:
        middle_list();
            break;
	}
	}
	}


