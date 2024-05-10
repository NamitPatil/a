#include<stdio.h>
#include<stdlib.h>
int mutex=1;
int full=0;
int empty=0,x=0;

void producer()
{
	--mutex;
	++full;
	x++;
	print("producer produces item %d",x);
	++mutex;
}

void consumer()
{
	--mutex;
	--full;
	++empty;
	print("consumer consume item %d",x);
	x--;
	++mutex;
}
--------------------------------------------------

// Define the number of philosophers
define NUM_PHILOSOPHERS 5

// Initialize semaphores for each chopstick
for i from 0 to NUM_PHILOSOPHERS - 1
    initialize semaphore chopsticks[i] with value 1

// Function to represent a philosopher's actions
function philosopher(id):
    while true:
        // Philosopher thinks
        print "Philosopher ", id, " is thinking."
        sleep(1) // Simulate thinking

        // Attempt to pick up left chopstick
        wait(chopsticks[id])
        print "Philosopher ", id, " picked up left chopstick."

        // Attempt to pick up right chopstick
        wait(chopsticks[(id + 1) mod NUM_PHILOSOPHERS])
        print "Philosopher ", id, " picked up right chopstick."

        // Philosopher eats
        print "Philosopher ", id, " is eating."
        sleep(1) // Simulate eating

        // Put down chopsticks
        signal(chopsticks[id])
        print "Philosopher ", id, " put down left chopstick."
        signal(chopsticks[(id + 1) mod NUM_PHILOSOPHERS])
        print "Philosopher ", id, " put down right chopstick."

