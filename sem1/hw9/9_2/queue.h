#pragma once
#include "AVLTree.h"

struct QueueElement
{
	AVLTreeNode *value;
	int priority;
	QueueElement *next;
};

struct Queue
{
	QueueElement *first;
	QueueElement *last;
};

void addToQueue(AVLTreeNode *value, int priority, Queue *queue);
Queue *createQueue();
bool queueIsEmpty(Queue *queue);
void deleteQueue(Queue *queue);
AVLTreeNode *pushFromQueue(Queue *queue);
AVLTree *spliceOfNodes(Queue *queue);

