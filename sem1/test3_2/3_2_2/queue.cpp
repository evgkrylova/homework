#include <iostream>
#include <fstream>
#include "queue.h"

using namespace std;

QueueElement *createQueueElement(int value, int priority)
{
	return new QueueElement{ value, priority, nullptr, nullptr };
}

Queue *createQueue()
{
	return new Queue{ nullptr, nullptr, -1, nullptr };
}

bool queueIsEmpty(Queue *queue)
{
	return !queue->first;
}

void enqueue(int value, int priority, Queue *queue)
{
	QueueElement *newElement = createQueueElement(value, priority);

	if (queueIsEmpty(queue))
	{
		queue->first = newElement;
		queue->last = newElement;
	}

	else
	{
		queue->last->next = newElement;
		newElement->previous = queue->last;
		queue->last = newElement;
	}
	
	if (queue->maxPriority < priority)
	{
		queue->maxPriority = priority;
		queue->maxPriorityElement = newElement;
	}
}

void findMaxPriority(Queue *queue)
{
	if (queueIsEmpty(queue))
	{
		queue->maxPriority = -1;
		queue->maxPriorityElement = nullptr;
		return;
	}

	QueueElement *current = queue->first;
	queue->maxPriority = current->priority;
	queue->maxPriorityElement = current;

	while (current->next)
	{
		if (queue->maxPriority < current->priority)
		{
			queue->maxPriority = current->priority;
			queue->maxPriorityElement = current;
		}
		current = current->next;

		if (!current)
		{
			break;
		}
	}
}

int dequeue(Queue *queue)
{
	if (queueIsEmpty(queue))
	{
		return -1;
	}

	int maxPriority = queue->maxPriority;

	if (queue->maxPriorityElement->previous == nullptr)
	{
		queue->first = queue->maxPriorityElement->next;

		if (!queueIsEmpty(queue))
		{
			queue->first->previous = nullptr;
		}		
	}

	else if (queue->maxPriorityElement->next == nullptr)
	{
		queue->last = queue->maxPriorityElement->previous;
		queue->last->next = nullptr;
	}
	
	else
	{
		queue->maxPriorityElement->previous->next = queue->maxPriorityElement->next;
		queue->maxPriorityElement->next->previous = queue->maxPriorityElement->previous;
	}
	
	delete queue->maxPriorityElement;

	findMaxPriority(queue);

	return maxPriority;
}

void deleteQueue(Queue *queue)
{
	QueueElement *current = queue->first;

	while (current->next)
	{
		QueueElement *next = current->next;
		delete current;
		current = next;
	}

	delete current;
	delete queue;
}
