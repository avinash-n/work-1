
#include "header.h"

int after_at_pos(ST **head)
{
	int pos;
	int count = 1;	
	char poss[MAX];

	
	printf("enter the position to insert after this\n");
	fgets(poss, MAX, stdin);
	*(poss + strlen(poss) - 1) = '\0';

	pos = atoi(poss);

	if((pos > nodes) || (pos < 0)) {
		printf("enter the postion with in nodes \n");	
		return 0;
		}

	ST *new = (ST *)malloc(sizeof(ST));

	ST *temp = (ST *)malloc(sizeof(ST));

	temp->next = *head;

	while((temp->next != NULL) && (count != (pos + 1))) {
		temp = temp->next;
		count++;
	}

	printf("enter the data \n");
	fgets(&new->data, MAX, stdin);

	if(pos == 0) {
		new->next = *head;
		*head = new;
	}
	else {
		new->next = temp->next;
		temp->next = new;
	}
	nodes++;
}
