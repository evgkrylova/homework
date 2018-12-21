#include <iostream>
#include "queue.h"
#include "binaryTree.h"

QueueElement *createQueueElement(BinaryTreeNode *value, int priority, QueueElement *next)
{
	return new QueueElement{ value, priority, next};
}

Queue *createQueue()
{
	Queue *newQueue = new Queue;
	newQueue->last = createQueueElement(nullptr, 0, nullptr);
	newQueue->first = createQueueElement(nullptr, 0, newQueue->last);

	return newQueue;
}

void addToQueue(BinaryTreeNode *value, int priority, Queue *queue)
{

	QueueElement *temp = queue->first;

	while (temp->next != queue->last && priority > temp->next->priority)
	{
		temp = temp->next;
	}

	QueueElement *newQueueElement = createQueueElement(value, priority, temp->next);
	temp->next = newQueueElement;
}

BinaryTree *buildHuffmanTreeFromQueue(Queue *queue)
{
	while (queue->first->next->next != queue->last)
	{
		BinaryTreeNode *firstNode = queue->first->next->value;
		BinaryTreeNode *secondNode = queue->first->next->next->value;
		BinaryTreeNode *newNode = createBinaryTreeNode('0', firstNode, secondNode);

		int newPriority = queue->first->next->priority + queue->first->next->next->priority;

		QueueElement *firstQueueElement = queue->first->next;
		QueueElement *secondQueueElement = queue->first->next->next;

		queue->first->next = queue->first->next->next->next;
		addToQueue(newNode, newPriority, queue);

		delete firstQueueElement;
		delete secondQueueElement;
	}

	BinaryTree *tree = createBinaryTree(queue->first->next->value);
	return tree;
}

BinaryTreeNode *popFromQueue(Queue *queue)
{
	BinaryTreeNode *result = queue->first->next->value;
	QueueElement *queueElement = queue->first->next;
	queue->first->next = queue->first->next->next;
	delete queueElement;

	return result;
}

bool queueIsEmpty(Queue *queue)
{
	return queue->first->next == queue->last;
}

void deleteQueue(Queue *queue)
{
	QueueElement *current = queue->first;

	if (!queueIsEmpty(queue))
	{
		while (current->next)
		{
			QueueElement *next = current->next;
			delete current;
			current = next;
		}
	}

	delete current;
	delete queue;
}
