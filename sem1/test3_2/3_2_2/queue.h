#pragma once

struct QueueElement
{
	int value;
	int priority;
	QueueElement *next;
	QueueElement *previous;
};

struct Queue
{
	QueueElement *first;
	QueueElement *last;
	int maxPriority;
	QueueElement *maxPriorityElement;
};

Queue *createQueue();
void enqueue(int value, int priority, Queue *queue);
int dequeue(Queue *queue);
void deleteQueue(Queue *queue);
