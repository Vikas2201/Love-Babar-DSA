/* Implement Queue from Scratch 
(https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/) */

#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

const int size=100;
int front=-1,rear=-1;
void enqueue(int Q[],int ele)
{
	if(rear==(size-1))
    {
		printf("\nQUEUE IS FULL(OVERFLOW)");
	}
	else		
	{
		if(rear==-1)
		{
			front=0,rear=0;
			Q[rear]=ele;
		}
		else
		{
		    rear=rear+1;
	    	Q[rear]=ele;
		}
	}
}
int dequeue(int Q[])
{
	int temp=-1;
	if((front==-1)&&(rear==-1))
	{
		printf("\nQUEUE IS EMPTY(UNDERFLOW)");
	}
	else
	{
		temp=Q[front];
		front=front+1;
	    return temp;
    }
}
void display(int Q[])
{
	int temp;
	if((front==-1)&&(rear==-1))
	{
	   printf("\nQUEUE IS EMPTY(UNDERFLOW)");
	}
	else
	{
		temp=front;
		printf("\nQUEUE IS :");
		while(temp!=rear)
		{
			printf("%d ",Q[temp]);
			temp=temp+1;
		}
		printf("%d ",Q[rear]);
	}
}
int main()
{
	int value,choice,Q[100],dele;
	while(1)
	{
		printf("\nour option will be:");
		printf("\n[1].insertation an element");
		printf("\n[2].deletion of element");
	    printf("\n[3].print a queue");
	    printf("\n[4].exit");
	    printf("\nenter your choice:");
	    scanf("%d",&choice);
	    switch(choice)
	    {
	    	case 1:
	    	{
	    		printf("\nenter a element for insertion:");
	    		scanf("%d",&value);
	    		enqueue(Q,value);
	    		getch();
	    		break;
			}
			case 2:
			{
				dele=dequeue(Q);
				if(dele==-1)
				{
					printf("\nelement does not deleted");
				}
				else
				{
					printf("\ndeleted element is %d",dele);
				}
				getch();
				break;
		    }
			case 3:
			{
				display(Q);
				getch();
				break;
			}
			case 4:
			{
				exit(1);
				break;
			}
			default:
			{
				printf("\nenter correct choice:");
				getch();
				break;
			}
				
		}
    }
    return 0;
}