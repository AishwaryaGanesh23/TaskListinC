/*
Author:Aishwarya
Roll No: 1901
Description: Function/Implementaion file for 'Implementation of Priority Queue using Link List'
*/

#include <string.h>
#include <stdio.h> 
#include <stdlib.h> 
#include "1901_header.h"

TaskNode *front=NULL; //saves address of 1st node

int counter=0;//count number of tasks/nodes in list



void addTask()
{
	
	int tPriority,status,ch;
    char task[20];
	printf("--------------------------------------------------\n");
	printf("Higher Priority Tasks are denoted by a higher number\n");
	printf("\nThere is no upper or lower bound for priority,\nthe user can choose their own higher or lower bound numbers\n");
	printf("\nPriority is to be entered as integer only,\nValue after decimal point will be dropped\n\n");
	printf("--------------------------------------------------\n");
	while(1)
	{
		printf("\nEnter Task Name: ");
		fgets(task,20,stdin);	//fgets to allow use of space in name but also stores \n
		
		if(taskExists(task))
		{
			printf("Task already exists, please change task name\n");
		}
		else
		{
			do
			{
				printf("\nEnter Priority of task: ");
				status = scanf("%d",&tPriority);	//scanf returns 1 on valid datatype input and 0 on invalid
				
				while((getchar())!= '\n');	//clear input buffer of non int chars
				
				if(status!=1)//no integer is input
					printf("Invalid input, please enter integer values only\n");
			}while(status!=1);
			break;
		}
	}
	system("clear");
	do
	{
		
		printf("Name: %sPriority: %d\n",task,tPriority);
		printf("--------------------------------------------------\n");
		printf("Confirm Addition of Task?\n1:Yes\n2:Back to Menu\n");
		status = scanf("%d",&ch);	//scanf returns 1 on valid datatype input and 0 on invalid
		while((getchar())!= '\n');	//clear input buffer of non int chars
		
		system("clear");
					
		if(status!=1)//no integer is input
			printf("Invalid input, please enter integer values only\n");
		
		
		if(ch==1) //confirm
		{
			//enqueue
			TaskNode *tmp,*p;
			tmp=(TaskNode *)malloc(sizeof(TaskNode));
			
			if(tmp==NULL)
			{
				printf("Memory not available\n");
				
			}
			else
			{
				strcpy(tmp->data,task);
				tmp->priority=tPriority;
				//Queue is empty or item to be added has priority more than first element
				if( front == NULL || tPriority > front->priority )
				{
					tmp->link=front;
					front=tmp;
				}
				else //add node at appropriate place (descending order of priority)
				{
					p = front;
					while( p->link!=NULL && p->link->priority>=tPriority )
						p=p->link;
					tmp->link=p->link;
					p->link=tmp;
				}
				counter++;
			}
	
			
			printf("\nAdded Task\n----------------\nName: %sPriority: %d\n",task,tPriority);
			return;
		}
		else if(ch==2)//decline
		{
			system("clear");
			printf("Task Not Added\n");
			return;
		}
		else	//invalid integer input
		{
			ch=0;
			printf("Please choose between 1 and 2\n");
			printf("--------------------------------------------------\n");	
		}
	}while(status!=1 || ch==0);//loop continues till valid integer is input
}

void getCounter()
{
	printf("--------------------------------------------------\n");
	printf("Current Total Number of Tasks in Your Tasklist: %d\n",counter);
}

void completeTask()
{
	TaskNode *tmp;
	char task[20];
	int p,ch,status;
	if( front == NULL )
	{
		printf("Your Task List is Empty\n");
	}
	else
	{
		do
		{
			printf("Task that will be be completed:\n");
			printf("--------------------------------------------------\n");
			printf("Task: %sPriority: %d\n",front->data,front->priority);
			printf("--------------------------------------------------\n");
			
			printf("Confirm Task Completion?\n1:Yes\n2:Back to Menu\n");
			status = scanf("%d",&ch);	//scanf returns 1 on valid datatype input and 0 on invalid
			while((getchar())!= '\n');	//clear input buffer of non int chars
			
			system("clear");
							
			if(status!=1)//no integer is input
				printf("Invalid input, please enter integer values only\n");
			
			
			if(ch==1)//confirm
			{
				//dequeue
				tmp=front;
				strcpy(task,tmp->data);
				p=tmp->priority;
				front=front->link;
				free(tmp);
				
				system("clear");
				printf("Completed Task:\n %s ", task);
				counter--;
				getCounter();//show current total tasks
				return;
			}
			else if(ch==2)//decline
			{
				system("clear");
				printf("Task Not completed\n");
				return;
			}
			else//invalid integer input
			{	
				ch=0;
			    printf("Please choose between 1 and 2\n");
			    printf("--------------------------------------------------\n");
			}
		}while(status!=1 || ch==0);//loop continues till valid integer is input
	}
}

void displayAll()
{
	TaskNode *ptr=front;
	int count=0;
	if( front == NULL )
		printf("Your Task List is Empty\n");
	else
	{    
		printf("Your Task List :\n");
		printf("--------------------------------------------------\n");
		printf("Number\tPriority\tName\n\n");
		
		while(ptr!=NULL)
		{
			count++;
			printf("%d\t%d\t\t%s",count,ptr->priority,ptr->data);//ptr->data has \n char stored at end
			ptr=ptr->link;
		}
		getCounter();//show current total tasks
	}
}

void highestPriority() 
{
	int count=0;
  	TaskNode *ptr=front;
	if(front == NULL)
		printf("Your Task List is Empty\n");
	else
	{    
		printf("Your Highest Priority Tasks are :\n");
		printf("--------------------------------------------------\n");
		printf("Number\tPriority\tName\n\n");
		
		while(ptr!=NULL && ptr->priority==front->priority) //pointer should not be null and priority should be the same for all(max in list)
		{
			count++;
			printf("%d\t%d\t\t%s",count,ptr->priority,ptr->data);//ptr->data has \n char stored at end
			ptr=ptr->link;
		}
		printf("--------------------------------------------------\n");
		printf("Total Number of Highest Priority Tasks: %d\n",count);
		printf("--------------------------------------------------\n");
		printf("Next task that is to be completed:\n\n");
		printf("Task: %sPriority: %d\n",front->data,front->priority);//peek, next task to be dequeued/at the front of queue
	}
}

void modifyName()
{
	//priority cannot be modified as that would require rearrangement of nodes, cannot be search key as priorities are repeated
	//name cannot be primary key for search as that is changeable
	//number is generated in dispay to what node number the task is at (from 1 to 0)
	TaskNode *ptr=front;
	int count=0,ch,status,node_num;
	char newName[20];
	if(front == NULL)
		printf("Your Task List is Empty\n");
	else
	{    
		displayAll(); //show all tasks so user knows what task number they need to modify
		printf("--------------------------------------------------\n");
		do
		{
			printf("Which Task would like to modify? Task Number:");
			status = scanf("%d",&node_num); 	//scanf returns 1 on valid datatype input and 0 on invalid
			while((getchar())!= '\n');			//clear input buffer of non int data
			
			if(status!=1)						//no integer is input
				printf("Invalid input, please enter integer values only\n");
		}while(status!=1);
			
		system("clear");
		
		while(ptr!=NULL)
		{
			count++;			//counts nodes traversed 
			if(count==node_num)	
			{
				do
				{
					
					printf("--------------------------------------------------\n");
					printf("Task: %sPriority: %d\n",ptr->data,ptr->priority);
					printf("--------------------------------------------------\n");			
			
					printf("Is this the task you want to modify?\n1:Yes\n2:No\n");
					status = scanf("%d",&ch);	//scanf returns 1 on valid datatype input and 0 on invalid
					while((getchar())!= '\n');	//clear input buffer of non int data
					system("clear");
					if(status!=1)	//no integer is input
						printf("Invalid input, please enter integer values only\n");	
					
					
					if(ch==1)	//confirm
					{
						while(1)
						{
							printf("New Task Name: ");
							fgets(newName,20,stdin);
							
							if(taskExists(newName))
							{
								printf("Task already exists, please change task name\n");
							}
							else 
							{
								strcpy(ptr->data,newName);
								
								system("clear");
								printf("\nTask Modified To\nName: %s",ptr->data);
								return;
							}
						}
					}
					else if(ch==2) //decline
					{
						system("clear");
						printf("Task Name not modified\n");
						return;
					}
					else //invalid integer is input
					{	
						ch=0;
						printf("Please choose between 1 and 2\n");
						printf("--------------------------------------------------\n");
					}
				}while(status!=1 || ch==0); //loop continues till valid integer is input
			}
			ptr=ptr->link;
		}
		printf("--------------------------------------------------\n");
		printf("Task Number %d Not Found\n",node_num);
	}
}

int taskExists(char task[20])	//check if task exists in task list
{
	TaskNode *ptr=front;
	if(front == NULL)
		return 0;
	else
	{    
		while(ptr!=NULL)
		{
			if(strcmp(task,ptr->data)==0)
			{
				return 1;
			}
			ptr=ptr->link;
		}
	}
	return 0;
}

