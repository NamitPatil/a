#include<stdio.h>
#include<stdlib.h>

int front = -1, rear = -1,v=0;
int n = 5;
int q[5];
int startTime[5] = {0};
int prioty[5];
int at[5];

void dis();

void enqueue(int c, int start,int pri,int arr)
 {
    int i, j,k;
    if (rear == n - 1) 
	{
        printf("\nQUEUE IS FULL!");
        return;
    }
    if (front == -1 && rear == -1) 
	{
        front = rear = 0;
        q[rear] = c;
        startTime[rear] = start;
        prioty[rear]=pri;
        at[rear]=arr;
    } 
	else
	{
        rear++;
    
        for (i=rear-1; i>front;i--) 
		{
			 if (arr< at[i]  || pri< prioty[i]) 
			 {
                q[i + 1] = q[i];
                startTime[i + 1] = startTime[i];
                prioty[i+1]=pri;
       			at[i+1]=arr;
       		}
       		else
       		break;
    	}
        q[i + 1] = c;
    	startTime[i +1] = start;
   		prioty[rear]=pri;
    	at[rear]=arr;
    }
   
//        rear++;
//    
//        for (k=rear-1; k>=front;k--) 
//		{
//			 if (pri< prioty[k]) 
//			 {
//                q[k + 1] = q[k];
//                startTime[k + 1] = startTime[k];
//                prioty[k+1]=pri;
//       			at[k+1]=arr;
//       		}
//       		else
//       		break;
//    	}
//        q[k + 1] = c;
//    	startTime[k+ 1] = start;
//   		prioty[rear]=pri;
//    	at[rear]=arr;
//    
    v++;
}
void dequeue() 
{
    if (front == -1 && rear == -1) 
	{
        printf("\nQUEUE IS EMPTY!");
    } 
	else if (front == rear) 
	{
        printf("\nThe Dequeued element is: %d", q[front]);
        front = rear = -1;
    } 
	else 
	{
        printf("\nThe Dequeued element is: %d ", q[front]);
        front++;
    }
    
}

void dis() 
{
    int wait = 0,j,sum,avg;
    if (front == -1 && rear == -1) 
    {
        printf("\nQUEUE IS EMPTY!");
    }
     else 
    {
        printf("\nprocess\t\tArrival\t\tBust time\tPrioty\t\twait\n");
        printf("______________________________________\n\n");
        for ( j = front; j <= rear; j++) 
        {
            if (j == front) 
			{
                wait = 0;
            } 
			else 
			{
                wait = startTime[j] + wait;
                sum+=wait;
            }
            printf("[%d]\t\t%d\t\t%d\t\t\%d\t\t%d\n", q[j],at[j], startTime[j],prioty[j], wait);
        }
        avg=sum/v;
        printf("\nTotal waiting time is:%d",sum);
        printf("\nAvg Waiting time is:%d\n",avg);
    }
}
int main()
{
 int y, c, start = 0,pri,arr;
    while (y != 4) 
	{
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
        printf("\nEnter the operation :");
        scanf("%d", &y);
        switch (y) 
		{
            case 1:
                printf("\nEnter the process: ");
                scanf("%d", &c);
                printf("\nEnter the bust time: ");
                scanf("%d", &start);
                printf("\nEnter the arrival time: ");
                scanf("%d", &arr);
                printf("\nEnter the prioty time: ");
                scanf("%d", &pri);
                enqueue(c, start,pri,arr);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                dis();
                break;
            case 4:
                exit(0);
                break;
        }
    }
}