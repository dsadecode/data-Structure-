#include<stdio.h>
#include<conio.h>
typedef struct _nodeQueue
{
    int info;
    struct _nodeQueue *next;
}nodeQueue;
nodeQueue *front,*rear;
void frontEnqueue(int data)
{
nodeQueue *new1=(nodeQueue*)malloc(sizeof(nodeQueue));
new1->info=data;
if(front==NULL)
    {
    front=new1;
    new1->next=NULL;
    rear=new1;
    }
else
    {
    new1->next=front;
    front=new1;
    }
}
void rearEnqueue(int data)
{
    nodeQueue *new1=(nodeQueue*)malloc(sizeof(nodeQueue));
    rear=new1;
    nodeQueue *ptr=front;
    new1->next=NULL;
    new1->info=data;
    if(front==NULL)
    {
	front=new1;
	return;
    }
    else
    {
	while(ptr->next)
	{
	    ptr = ptr->next;
	}
	 ptr->next =new1;
	return;
    }

}
void frontDequeue ()
{
    nodeQueue *ptr=front;
if(front==NULL)
printf("\nUnderflow condition reached\n");
else
    {
    if(front->next==NULL)
    {
	free(front);
	front=NULL;
	rear=NULL;
	return;
    }
    else
    {
     front=front->next;
     free(ptr);
	}

}
}
void rearDequeue()
{
nodeQueue *ptr=front;
if(front==NULL)
{
printf("\nUnderflow condition reached\n");
return;
}
else if(front==rear)
{
free(front);
front=NULL;
rear=NULL;

}
else
{
    while(ptr->next!=rear)
    ptr=ptr->next;
    ptr->next=NULL;
    free(rear);
    rear=ptr;

    }


}
void display()
{
    nodeQueue *ptr=front;
    printf("\nQueue is as follows --------:");
    while(ptr)
    {
	printf("\n\t\t%d(%p) ",ptr->info,ptr);
	ptr = ptr->next;
    }
    printf("\n");
    printf("front-->%p \t rear---->%p\n",front,rear);
}
int main()
{
    int d,data;
    while(1)
    {

	printf("Queue implementation using link list (structure) \nMenu---------------\n\t1.Front Enqueue\n\t2.Rear Enqueue\n\t3.Front Dequeue\n\t4.Rear Dequeue \n\t5.Display\n\t6.EXIT\n");
	fflush(stdin);
	scanf("%d",&d);
	system("cls");//clrscr();
	switch(d)
	{

	    case 1:printf("\nEnter the number :");
	    fflush(stdin);
	    scanf("%d",&data);
	    frontEnqueue(data);
	    getch();
	    break;
	    case 2:printf("\nEnter the number :");
	    fflush(stdin);
	    scanf("%d",&data);
	    rearEnqueue(data);
	    getch();
	    break;
	    case 3:frontDequeue();
	    getch();
	    break;
	    case 4 :rearDequeue();
	    getch();
	    break;
	    case 5:
		display();
		getch();
		break;
	    case 6:
		return 0;
	}
    }
}
