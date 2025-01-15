#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1;
void insert_rear();
int delete_front();
void display();
int peek();
void main()
{
  int ch,item;
  clrscr();
  for(;;)
  {
  printf("Press 1 for Insert \n 2 for Delete \n 3 for display\n");
  printf("Press 4 for Peek\n");
  printf("Enter your choice\n");
  scanf("%d",&ch);
  switch(ch)
  {
     case 1: insert_rear();
	     break;
     case 2 : item=delete_front();
	     if(item!=-1)
	     printf("Item deleted=%d",item);
	     break;
     case 3 : display();
	      break;
     case 4:item=peek();
	    if(item!=-1)
	     printf("First Value in the Queue=%d",item);
	     break;
    default : exit(0);
  }
}
  getch();
}
void insert_rear()
{
   int num;
   printf("\n Enter the item to be Inserted");
   scanf("%d",&num);
   if(rear==MAX-1)
    printf("Queue is full\n");
   else if(front==-1 && rear==-1)
      front=rear=0;
   else
    rear++;
    queue[rear]=num;
}
int delete_front()
{
   int item_deleted;
   if(front==-1 || front >rear)
   {
      printf("QUEUE is empty\n");
      return -1;
   }
   else
   {
	item_deleted=queue[front];
	front++;
		if(front>rear)
		  {
		     front=rear=-1;
		  }
     return item_deleted;
   }
}
void display()
{
 int i;
   if(front==-1 || front >rear)
     printf("QUEUE is empty\n");
  else
  {
   printf("Content of the QUEUE is\n");
   for(i=front;i<=rear;i++)
     printf("%d\t",queue[i]);
  }
}
int peek()
{
   if(front==-1 || front >rear)
     printf("QUEUE is empty\n");
  else
  {
     return queue[front];
  }
}
