#include<stdio.h>
#include<stdlib.h>

int front = -1, rear = -1;
int n = 5;
int q[5];
int startTime[5] = {0};

void dis();

void enqueue(int c, int start) {
    int i, j;
    if (rear == n - 1) {
        printf("\nQUEUE IS FULL!");
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
        q[rear] = c;
        startTime[rear] = start;
    } else {
        rear++;
    
        for (i = rear - 1; i >= front; i--) {
            if (start < startTime[i]) {
                q[i + 1] = q[i];
                startTime[i + 1] = startTime[i];
            } else {
                break;
            }
        }
        q[i + 1] = c;
        startTime[i + 1] = start;
    }
    dis();
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("\nQUEUE IS EMPTY!");
    } else if (front == rear) {
        printf("\nThe Dequeued element is: %d", q[front]);
        front = rear = -1;
    } else {
        printf("\nThe Dequeued element is: %d ", q[front]);
        front++;
    }
    dis();
}

void view() {
    if (front == -1 && rear == -1) {
        printf("\nQUEUE IS EMPTY!");
    } else {
        printf("\nPeek element is: %d", q[front]);
    }
}

void dis() {
    int wait = 0;
    if (front == -1 && rear == -1) {
        printf("\nQUEUE IS EMPTY!");
    } else {
        printf("\nprocess\t\tstart time\twait\n");
        for (int j = front; j <= rear; j++) {
            if (j == front) {
                wait = 0;
            } else {
                wait = startTime[j] + wait;
            }
            printf("[%d]\t\t%d\t\t%d\t\t\n", q[j], startTime[j], wait);
        }
    }
}

void queue() {
    int y, c, start = 0;
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

int main() {
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
