/*
 ============================================================================
 Name        : Day25RunningTimeAndComplexity.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

struct Queue {
	size_t size;
	struct Node * head;
	struct Node * tail;
};

struct Queue init() {
	struct Queue queue;
	queue.size = 0;
	queue.head = NULL;
	queue.tail = NULL;

	return queue;
}

void push(struct Queue * queue, int data) {
	struct Node * node = (struct Node *) malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;

	if (queue->head == NULL)
		queue->head = node;
	else
		queue->tail->next = node;

	queue->tail = node;
	queue->size++;
}

int pop(struct Queue * queue) {
	int data;
	struct Node * head = queue->head;

	if (head != NULL) {
		data = head->data;
		queue->head = head->next;
		queue->size--;
		free(head);
	}

	return data;
}

char * isPrime(int data) {
	int i = 0;

	if (data == 1)
		return "Not prime";

	if (data == 2 || data == 3)
		return "Prime";

	if (data % 2 == 0)
		return "Not prime";

	for (i = 3; i < (data / 2); i = i + 2) {
		if (data % i == 0)
			return "Not prime";
	}

	return "Prime";
}

int main() {
	int i, n;
	struct Queue queue = init();

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		int data;
		scanf("%d", &data);
		push(&queue, data);
	}

	for (i = 0; i < n; i++) {
		int data = pop(&queue);
		printf("%s\n", isPrime(data));
	}

	return 0;
}

