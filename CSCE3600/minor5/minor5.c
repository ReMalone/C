/*
 * minor5.c - using producer-consumer paradigm.
 *
 *Robert E Malone
 *CSCE 3600
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NITEMS 10		// number of items in shared buffer

pthread_cond_t FULL = PTHREAD_COND_INITIALIZER;   //two global pthread variables FULL and EMPTY
pthread_cond_t EMPTY = PTHREAD_COND_INITIALIZER;

// shared variables
char shared_buffer[NITEMS];	// echo buffer
int shared_count;		// item count

pthread_mutex_t mutex;		// pthread mutex
unsigned int prod_index = 0; 	// producer index into shared buffer
unsigned int cons_index = 0; 	// consumer index into shard buffer

// function prototypes
void * producer(void *arg);
void * consumer(void *arg);

int main() 
{ 
	pthread_t prod_tid, cons_tid1, cons_tid2; 

	// initialize pthread variables
	pthread_mutex_init(&mutex, NULL);

        // condititon initializer
        pthread_cond_init(&FULL, NULL);
        pthread_cond_init(&EMPTY, NULL);	

	// start producer thread
	pthread_create(&prod_tid, NULL, producer, NULL);

	// start consumer threads
	pthread_create(&cons_tid1, NULL, consumer, NULL);
	pthread_create(&cons_tid2, NULL, consumer, NULL);
	
	// wait for threads to finish
	pthread_join(prod_tid, NULL);
	pthread_join(cons_tid1, NULL);
	pthread_join(cons_tid2, NULL);
			
	// clean up
	pthread_mutex_destroy(&mutex);
 	
        //Condition clean up destroy
        pthread_cond_destroy(&FULL); 
        pthread_cond_destroy(&EMPTY);

	return 0;
}

// producer thread executes this function
void * producer(void *arg)
{
	char key;

	while (1)
	{
		// read input key
		scanf("%c", &key);

		while (1)
		{
			// acquire mutex lock
			pthread_mutex_lock(&mutex);
                  
                  // created while loop for the condition
                  while(shared_count == NITEMS)
                  {                       
                       pthread_cond_wait(&FULL, &mutex);
                  
 	          }
			// if buffer is full, release mutex lock and check again
			if (shared_count == NITEMS)
				pthread_mutex_unlock(&mutex);
			else
				break;
		}

		// store key in shared buffer
		shared_buffer[prod_index] = key;

		// update shared count variable
		shared_count++;

		// update producer index
		if (prod_index == NITEMS - 1)
			prod_index = 0;
		else
			prod_index++;
	                pthread_cond_signal(&EMPTY);		

		// release mutex lock
		pthread_mutex_unlock(&mutex); 
	}

	return NULL;
}

// consumer thread executes this function
void * consumer(void *arg)
{
	char key;

	int id = (int)pthread_self();

	while (1)
	{
		while (1)
		{
			// acquire mutex lock
			pthread_mutex_lock(&mutex);
	            
	          //while loop for condition waiting to be empty
                  while(shared_count == 0)
                  {                       
                       pthread_cond_wait(&EMPTY, &mutex);
                  
 	          }

			// if buffer is empty, release mutex lock and check again
			if (shared_count == 0)
				pthread_mutex_unlock(&mutex);
			else
				break;
		}

		// read key from shared buffer
		key = shared_buffer[cons_index];
		
		// echo key
		printf("consumer %d %c\n", id, key);

		// update shared count variable
		shared_count--;

		// update consumer index
		if (cons_index == NITEMS - 1)
			cons_index = 0;
		else
			cons_index++;
                        pthread_cond_signal(&FULL);
	
		// release mutex lock
		pthread_mutex_unlock(&mutex);
	}

	return NULL;
}
