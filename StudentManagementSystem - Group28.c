// C program for the implementation of
// menu driven program for
// student record management system
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>  

// Variable to keep track of
// number of students
int i = 0;

// Structure to store the student
struct studentinfo {
	char firstname[50];
	char lastname[50];
	int matric;
	float cgpa;
	int course_id[5];
	char course_name[5];
} st[100];

// Function to add the student
void add_student()
{
    int j=0,duplicate=0; 
    bool check_matric = true;
   
	printf("\n========[STUDENT] [INFORMATION] [SYSTEM]=========\n");
	printf("\nEnter First Name Of The Student     :");
	scanf("%s", st[i].firstname);
	printf("Enter Last Name Of The Student      :");
	scanf("%s", st[i].lastname);

	   
	while(check_matric){ 
	    char matric_id[7];
	    int length_id = 0;
	    int duplicate_matric=0; 
	     
	    	printf("Enter The Matric Number             :A");
            scanf("%d", &st[i].matric);
        
           sprintf(matric_id, "%d", st[i].matric); 
           length_id = strlen(matric_id);
         
           
           if(length_id != 6){
                   printf( "INVALID! Need 6 Characters Of Input!\n" 
                "TRY AGAIN,\n" );
                duplicate_matric = 1;
                check_matric = true;
            
            }
            
            else{
                 //duplicate_matric = 0;
            }
      
            
        for ( int y = 0; y < i; y++ ) {
            
        
  
            if ( st[i].matric == st[y].matric ) {
                printf( "INVALID! This Student ID ALREADY EXISTS!\n" 
                "TRY AGAIN,\n" );
                duplicate_matric = 1;
                break;
            }
          
        }
        
        if ( ! duplicate_matric )
            check_matric = false;
	    
	  }
 
	printf("Enter CGPA                          :");
	scanf("%f", &st[i].cgpa);
	printf("Enter The Registered Courses        \n");
    while ( j < 5 ) {
        int duplicated = 0;
        int length =0;
        char course_name[5];
        printf("Course ID:");
        scanf("%d",&st[i].course_id[j]);
        
        sprintf(course_name, "%d", st[i].course_id[j]); 
        length = strlen(course_name);
        
          if(length != 4){
                   printf( "INVALID! Course ID requries only four digits!\n" 
                "TRY AGAIN,\n" );
                
                j -= 1; 
            
            } 
    
         
        for ( int y = 0; y < j; y++ ) {
        

        
            if ( st[i].course_id[j] == st[i].course_id[y] ) {
                printf( "INVALID! This Course ID ALREADY EXISTS!\n" 
                "TRY AGAIN,\n" );
                duplicated = 1;
                break;
            }
        }

        if ( ! duplicated )
            j++;
    }      
	i = i+1;
	printf("\nStudent's Particulars Has Been Added SUCCESSFULLY!\n");
	
}

// Function to find student by matric number
void find_matric()
{
	int x;
	printf("\n========[STUDENT] [INFORMATION] [SYSTEM]=========\n");
	printf("\nEnter Matric Number Of The Student:A");
	scanf("%d", &x);
	for (int j = 0; j <= i; j++) {
		if (x == st[j].matric) {
			printf("\nThe Student Details Are     : \n");
			printf("\nStudent's First Name        : %s",st[j].firstname);
			printf("\nStudent's Last Name         : %s",st[j].lastname);
			printf("\nStudent's CGPA              : %f",st[j].cgpa);
			printf("\nStudent's Registered Courses: \n");
			
			for (int m = 0; m <= 4; m++) {
			printf("Course ID: %d\n",st[j].course_id[m]);
		    }
		    break;
		}
	}
}

// Function to print
// total number of students
void total_students()
{   
    printf("\n========[STUDENT] [INFORMATION] [SYSTEM]=========\n");
	printf("\nTotal Number Of Students: %d\n",i);
	printf("\nYou Can Have 100 Students At MAXIMUM\n");
	printf("You Can Have %d MORE Students\n",100 - i);
}

// Function to delete a student
// by the matric number
void delete_student()
{
	int a;
	printf("\n========[STUDENT] [INFORMATION] [SYSTEM]=========\n");
	printf("\nTo Delete Student's Record, Enter The Specific Student's Matric Number:A");
	scanf("%d", &a);
	for (int j = 0; j <= i; j++) {
		if (a == st[j].matric) {
			for (int k = j; k <= 100; k++)
				st[k] = st[k + 1];
			i--;
		printf("Student's Record Is REMOVED! \n");
		}
	}
}

// Function to update a students' data
void update_student()
{
    int q=0,duplicate=0; 
    bool check_matric = true;
    printf("\n========[STUDENT] [INFORMATION] [SYSTEM]=========\n");
	printf("\nEnter The Student's Matric Number To Update The Specific Student's Particulars:A");
	int x;
	scanf("%d", &x);
	for (int j = 0; j <= i; j++) {
		if (x == st[j].matric) {
			printf("1. Update Student's First Name\n"
				"2. Update Student's Last Name\n"
				"3. Update Student's Matric Number\n"
				"4. Update Student's CGPA\n"
				"5. Update Student's Registered Courses\n");
			int z;
			printf("Your Option:");
			scanf("%d", &z);
			switch (z) {
			case 1:
				printf("Enter The NEW First Name:");
				scanf("%s", st[j].firstname);
				break;
			case 2:
				printf("Enter The NEW Last Name:");
				scanf("%s", st[j].lastname);
				break;
			case 3:
				//printf("Enter The NEW Matric Number:A");
				//scanf("%d", &st[j].matric);
				while(check_matric){ 
	            char matric_id[7];
	            int length_id = 0;
	            int duplicate_matric=0; 
	     
	    	    printf("Enter The Matric Number             :A");
                scanf("%d", &st[j].matric);
        
                sprintf(matric_id, "%d", st[j].matric); 
                length_id = strlen(matric_id);
         
           
                if(length_id != 6){
                   printf( "INVALID! Need 6 Characters Of Input!\n" 
                "TRY AGAIN,\n" );
                duplicate_matric = 1;
                check_matric = true;
            
            }
            
            else{
                 //duplicate_matric = 0;
            }
      
            
            for ( int y = 0; y < j; y++ ) {
            
        
  
            if ( st[j].matric == st[y].matric ) {
                printf( "INVALID! This Student ID ALREADY EXISTS!\n" 
                "TRY AGAIN,\n" );
                duplicate_matric = 1;
                break;
            }
          
        }
        
            if ( ! duplicate_matric )
            check_matric = false;
	    
	        }
 
			break;
			case 4:
				printf("Enter The NEW CGPA:");
				scanf("%f", &st[j].cgpa);
			break;
			case 5:
				printf("Enter The NEW ID Of Registered Courses: \n");
				//scanf(
				//	"%d%d%d%d%d", &st[j].course_id[0],
				//	&st[j].course_id[1], &st[j].course_id[2],
				//	&st[j].course_id[3], &st[j].course_id[4]);
				while ( q < 5 ) {
                int duplicated = 0;
                int length =0;
                char course_name[5];
                printf("Course ID:");
                scanf("%d",&st[j].course_id[q]);
        
                sprintf(course_name, "%d", st[j].course_id[q]); 
                length = strlen(course_name);
        
                 if(length != 4){
                   printf( "INVALID! Course ID requries only four digits!\n" 
                "TRY AGAIN,\n" );
                
                q -= 1; 
            
                } 
    
         
                for ( int y = 0; y < q; y++ ) {
        

        
                    if ( st[j].course_id[q] == st[j].course_id[y] ) {
                        printf( "INVALID! This Course ID ALREADY EXISTS!\n" 
                        "TRY AGAIN,\n" );
                    duplicated = 1;
                    break;
                    }
                }

                if ( ! duplicated )
                q++;
            }      
			break;
			}
			printf("Student's Particular Has Been UPDATED!\n");
		}
	}
}

// Driver code 
void main()

{
	int choice,option,count;
	while (1) 
	{
	    printf("\n= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
	    printf("     S T U D E N T S  R E C O R D  M A N A G E M E N T  S Y S T E M   \n");
	    printf("             * * *        M A I N   M E N U       * * *             \n");
	    printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
		printf("\nMenu Options:\n");
		printf("Press [1] To Add Student's Particulars\n");
		printf("Press [2] To Find Student's Details By Matric Number\n");
		printf("Press [3] To Find Total Number Of Students\n");
		printf("Press [4] To Delete Student's Details By Matric Number\n");
		printf("Press [5] To Update Student's Details By Matric Number\n");
		printf("Press [6] To Exit System\n");
		printf("Your Option:");
		scanf("%d", &choice);
		switch (choice) 
		{
		case 1:
		    printf("\n========[STUDENT] [INFORMATION] [SYSTEM]=========\n");
		    printf("\nPress [1] To Continue\n");
		    printf("Press [2] To Go Back To Main Menu\n");
	    	printf("\n!!! CAUTION: PRESS [1] TO CONTINUE ONLY If YOU'RE SURE TO PROCEED. THERE IS NO BACK OPTION AFTER CONFIRMATION.\n" 
	    	"YOU'LL HAVE TO EXIT THE SYSTEM AND RE-ENTER IF YOU CHANGED YOUR MIND AFTER CONFIRMATION. !!!\n");
		    printf("\nYour Option:");
		    scanf("%d", &option);
		    if (option == 1)
		    {
			    add_student();
		    }
		    else if (option == 2)
		    {
		        main();
		    }
		    else 
		    {
		        printf("\nSORRY,INVALID OPTION! PLEASE ENTER A VALID OPTION FROM THE MENU LIST. THANK YOU.\n");
		    }
			break;
		case 2:
		    printf("\n========[STUDENT] [INFORMATION] [SYSTEM]=========\n");
		    printf("\nPress [1] To Continue\n");
		    printf("Press [2] To Go Back To Main Menu\n");
	    	printf("\n!!! CAUTION: PRESS [1] TO CONTINUE ONLY If YOU'RE SURE TO PROCEED. THERE IS NO BACK OPTION AFTER CONFIRMATION.\n" 
	    	"YOU'LL HAVE TO EXIT THE SYSTEM AND RE-ENTER IF YOU CHANGED YOUR MIND AFTER CONFIRMATION. !!!\n");
		    printf("\nYour Option:");
		    scanf("%d", &option);
		    if (option == 1)
		    {
			    find_matric();
		    }
		    else if (option == 2)
		    {
		        main();
		    }
		    else 
		    {
		        printf("\nSORRY,INVALID OPTION! PLEASE ENTER A VALID OPTION FROM THE MENU LIST. THANK YOU.\n");
		    }
			break;
		case 3:
		    printf("\n========[STUDENT] [INFORMATION] [SYSTEM]=========\n");
			printf("\nPress [1] To Continue\n");
		    printf("Press [2] To Go Back To Main Menu\n");
	    	printf("\n!!! CAUTION: PRESS [1] TO CONTINUE ONLY If YOU'RE SURE TO PROCEED. THERE IS NO BACK OPTION AFTER CONFIRMATION.\n" 
	    	"YOU'LL HAVE TO EXIT THE SYSTEM AND RE-ENTER IF YOU CHANGED YOUR MIND AFTER CONFIRMATION. !!!\n");
		    printf("\nYour Option:");
		    scanf("%d", &option);
            if (option == 1)
		    {
			    total_students();
		    }
		    else if (option == 2)
		    {
		        main();
		    }
		    else 
		    {
		        printf("\nSORRY,INVALID OPTION! PLEASE ENTER A VALID OPTION FROMM THE MENU LIST. THANK YOU.\n");
		    }
			break;
		case 4:
		    printf("\n========[STUDENT] [INFORMATION] [SYSTEM]=========\n");
		    printf("\nPress [1] To Continue\n");
		    printf("Press [2] To Go Back To Main Menu\n");
	    	printf("\n!!! CAUTION: PRESS [1] TO CONTINUE ONLY If YOU'RE SURE TO PROCEED. THERE IS NO BACK OPTION AFTER CONFIRMATION.\n" 
	    	"YOU'LL HAVE TO EXIT THE SYSTEM AND RE-ENTER IF YOU CHANGED YOUR MIND AFTER CONFIRMATION. !!!\n");
		    printf("\nYour Option:");
		    scanf("%d", &option);
		    if (option == 1)
		    {
			    delete_student();
		    }
		    else if (option == 2)
		    {
		        main();
		    }
		    else 
		    {
		        printf("\nSORRY,INVALID OPTION! PLEASE ENTER A VALID OPTION FROM THE MENU LIST. THANK YOU.\n");
		    }
			break;
		case 5:
		    printf("\n========[STUDENT] [INFORMATION] [SYSTEM]=========\n");
		    printf("\nPress [1] To Continue\n");
		    printf("Press [2] To Go Back To Main Menu\n");
	    	printf("\n!!! CAUTION: PRESS [1] TO CONTINUE ONLY If YOU'RE SURE TO PROCEED. THERE IS NO BACK OPTION AFTER CONFIRMATION.\n" 
	    	"YOU'LL HAVE TO EXIT THE SYSTEM AND RE-ENTER IF YOU CHANGED YOUR MIND AFTER CONFIRMATION. !!!\n");
		    printf("\nYour Option:");
		    scanf("%d", &option);
		    if (option == 1)
		    {
			   update_student();
		    }
		    else if (option == 2)
		    {
		        main();
		    }
		    else 
		    {
		        printf("\nSORRY,INVALID OPTION! PLEASE ENTER A VALID OPTION FROM THE MENU LIST. THANK YOU.\n");
		    }
			break;
		case 6:
		    printf("THANK YOU! HAVE A NICE DAY!");
			exit(0);
			break;
		default:
		    printf("\nSORRY,INVALID OPTION! PLEASE ENTER A VALID OPTION FROM THE MENU LIST. THANK YOU.\n");
		    break;
		}
	}
}