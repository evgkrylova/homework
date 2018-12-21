#pragma once
#include "binaryTree.h"

struct QueueElement
{
	BinaryTreeNode *value;
	int priority;
	QueueElement *next;
};

struct Queue
{
	QueueElement *first;
	QueueElement *last;
};

void addToQueue(BinaryTreeNode *value, int priority, Queue *queue);
Queue *createQueue();
bool queueIsEmpty(Queue *queue);
void deleteQueue(Queue *queue);
BinaryTreeNode *popFromQueue(Queue *queue);
BinaryTree *buildHuffmanTreeFromQueue(Queue *queue);

