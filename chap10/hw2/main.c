#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void addq(struct node **head, struct node **tail, int data) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	if (newNode == NULL) {
		printf("memory \n");
		return;
	}

	newNode->data = data;
	newNode->next = NULL;

	if (*tail == NULL) {
		*head = *tail = newNode;
	} else {
		(*tail)->next = newNode;
		*tail = newNode;
	}

	printf("%d Q add\n", data);
}

int delete(struct node **head, struct node **tail) {
	if (*head == NULL) {
		printf("Error\n");
		return -1;
	}

	int deletedData = (*head)->data;
	struct node *temp = *head;

	if (*head == *tail) {
		*head = *tail = NULL;
	} else {
		*head = (*head)->next;
	}

	free(temp);
	return deletedData;
}

void printQueue(struct node *head) {
	if (head == NULL) {
		printf("Error\n");
		return;
	}

	printf("detail: ");
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int main() {
	struct node *head = NULL;
	struct node *tail = NULL;

	addq(&head, &tail, 5);
	addq(&head, &tail, 10);
	addq(&head, &tail, 15);

	printQueue(head);

	int deleted = delete(&head, &tail);
	if (deleted != -1) {
		printf("%d is del\n", deleted);
	}
	
	printQueue(head);

	return 0;
}
