#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1;
int n=5;
int q[5];
int starttime[5]={0};

void enqueue(int c,int start)
{
    int i,j;
    if(rear==n-1)
    {
        printf("Queue is full");
        return;
    }
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        q[rear]=c;
        starttime[rear]=start;
    }
    else
    {
        rear++;
        for(i=rear-1;i>=front;i--)
        {
            if(start<starttime[i])
            {
                q[i+1]=q[i];
                starttime[i+1]=starttime[i+1];
            }
            else
            {
                break;
            }

        }
        q[i+1]=c;
        starttime[i+1]=start;
    }
    dis();
}

void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty");
    }
    else if(front==rear)
    {
        printf("The dequeued element is %d",q[front]);
        front = rear = -1;
    }
    else
    {
        printf("The dequeued element is %d",q[front]);
        front++;
    }
    dis();
}

void view()
{
     if(front==-1 && rear==-1)
    {
        printf("Queue is empty");
    }
    else{
        printf("The peek element is %d",q[front]);
    }
}

void dis()
{
   int wait=0;
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\nprocess\t\tstart time\twait\n");
        for(int j=front;j<=rear;j++)
        {
            if(j==front)
            {
                wait=0;
            }
            else{
                wait=starttime[j]+wait;
            }
            printf("\n%d\t\t%d\t\t%d",q[j],starttime[j],wait);
        }
    }
}

void queue()
{
    int y,c,start=0;

       while (y != 5) {
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.VIEW\n4.DISPLAY\n5.EXIT\n");
        printf("\nEnter the operation :");
        scanf("%d", &y);
        switch (y) {
            case 1:
                printf("\nEnter the process: ");
                scanf("%d", &c);
                printf("\nEnter the start time: ");
                scanf("%d", &start);
                enqueue(c, start);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                view();
                break;
            case 4:
                dis();
                break;
            case 5:
                exit(0);
                break;
        }
    }
}

int main()
{
    int choice;
    while (choice != 3) {
        printf("\n1.QUEUE\n2.EXIT");
        printf("\nEnter the operation : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                queue();
                break;
            case 2:
                exit(0);
                break;
        }
    }

    return 0;
}
