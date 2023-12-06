#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void push(struct node **top, int data) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	if (newNode == NULL) {
		printf("error\n");
		return;
	}

	newNode->data = data;
	newNode->next = *top;
	*top = newNode;

	printf("%d\n", data);
}

int pop(struct node **top) {
	if (*top == NULL) {
		printf("Error\n");
		return -1;
	}

	int poppedData = (*top)->data;
	struct node *temp = *top;
	*top = (*top)->next;
	free(temp);

	return poppedData;
}

void printStack(struct node *top) {
	if (top == NULL) {
		printf("Error\n");
		return;
	}

	printf("Stack detail: ");
	while (top != NULL) {
		printf("%d ", top->data);
		top = top->next;
	}
	printf("\n");
}

int main() {
	struct node *top = NULL;
	
	push(&top, 5);
	push(&top, 10);
	push(&top, 15);

	printStack(top);

	int popped = pop(&top);
	if (popped != -1) {
		printf("%d stack del\n", popped);
	}

	printStack(top);
	
	return 0;
}
