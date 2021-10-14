/*
Author:Aishwarya
Roll No: 1901
Description: Header file for 'Implementation of Priority Queue using Link List'
*/



struct node { 
    char data[20]; //name of task
    int priority; // higher values indicate higher priority 
    struct node* link; //next node address
}; 
typedef struct node TaskNode; // datatype of Node for priority queue

void addTask();	//enqueue
void completeTask();	//dequeue
void getCounter();	//counts tasks
void displayAll();	//displays all
void highestPriority();	//top priority and peek
void modifyName();	//change task name

int taskExists(char task[20]);	//check if task exists

