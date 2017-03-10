/* Header file for queue operations */

/* C header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_LENGTH 5
#define NUM_SIZE 8
#define MEM_ALLOC(str) str = (char *) malloc(NUM_SIZE);
#define VALIDATE_MALLOC(str) if (!str) {\
				printf("Memory allocation failed!");\
				exit(0);\
				}

int rear;
int front;
int count;
int queue[MAX_QUEUE_LENGTH];
int element;

enum choice {enqueue = 1, dequeue, display, clear};

int validate(char *);

int str_len(char *);

void enq(void);

void deq(void);

void disp(void);
