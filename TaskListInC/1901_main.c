/*
Author:Aishwarya
Roll No: 1901
Description: Main file for 'Implementation of Priority Queue using Link List'
*/

#include <string.h>
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> //for sleep()
#include "1901_header.h"

void main() 
{ 
    //home menu
    system("clear");
    printf("Welcome to Task Priority\n");
    int opt;
    do{
		opt=0;
		printf("--------------------------------------------------\n");
		printf("1:Add task\n2:Complete Task of Highest priority\n3:Total Number of tasks\n4:Your Task List\n5:Your Highest priority Tasks\n6:Modify Task Name\n7:Exit\n\n");
		printf("--------------------------------------------------\n");
		printf("Choose your option\n");
		scanf("%d",&opt);
		while((getchar())!= '\n');	//clear input buffer of non int data
		
		switch(opt)
		{
			case 1: system("clear");
					addTask();
					break;
					
			case 2:	system("clear");
					completeTask();
					break;
					
			case 3:	system("clear");
					getCounter();
					break;
			
			case 4:	system("clear");
					displayAll();
					break;
				
			case 5:	system("clear");
					highestPriority();
					break;
			
			case 6: system("clear");
					modifyName();		
					break;
			
			case 7:	system("clear");
					printf("You have chosen to exit\n");
					printf("--------------------------------------------------\n");
					sleep(1);
					system("clear");
					break;
			
			default: system("clear");
				 	 printf("Invalid choice please try again\n");
		}
		
    }while(opt!=7);
    
	
} 

