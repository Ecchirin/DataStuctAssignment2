#include "DetectMemoryLeak.h"
#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>

using std::string;
using std::vector;
using std::list;
using std::map;
using std::stack;
using std::queue;

// DO NOT MODIFY ANY LINE ABOVE OR ADD EXTRA INCLUDES

/*!
*  \brief     DM2126 Assignment 2
*  \details   Submit the whole solution, but only this file will be used to grade
*  \author    <Lim Zi Sheng>
*  \date      24 / 01 / 2017
*  \note      <160397M>
*/

//*******************************************************************//
// Linked list stuff
//*******************************************************************//
LinkedList::LinkedList()
{
	head_ = NULL;
}

LinkedList::~LinkedList()
{
	Node *delPtr = head_;

	while (delPtr)
	{
		head_ = head_->next;
		delete delPtr;

		delPtr = head_;
	}

	head_ = NULL;
}

void LinkedList::push_front(int data)
{
	if (!head_)
	{
		head_ = new Node;
		head_->data = data;
	}
	else
	{
		Node* newData = new Node;
		newData->data = data;
		newData->next = head_;
		head_ = newData;

		newData = 0;
		delete newData;
	}
}

void LinkedList::push_back(int data)
{
	Node* curr;
	curr = head_;

	if (!head_)
	{
		head_ = new Node;
		head_->data = data;
	}
	else
	{
		while (curr->next)
		{
			curr = curr->next;
		}
		curr->next = new Node;
		curr->next->data = data;
	}
}

int LinkedList::pop_front()
{
	Node* curr;
	curr = head_;

	if (!head_)
	{
		return 0;
	}

	head_ = head_->next;
	curr->next = 0;

	return curr->data;
}

int LinkedList::pop_back()
{
	if (!head_)
		return 0;

	Node *delPtr = head_;
	Node *prev = delPtr;

	while (delPtr->next)
	{
		prev = delPtr;
		delPtr = delPtr->next;
	}

	prev->next = NULL;
	return delPtr->data;
	delete delPtr;
}

void LinkedList::insert_at(int pos, int data)
{
	if (pos <= 0)
	{
		pos = 0;
		push_front(data);
		return;
	}

	int tempIdx = 0;
	Node* curr;
	Node* prev;
	Node* newData = new Node;

	newData->data = data;
	prev = head_;
	curr = head_;

	if (!head_)
	{
		head_ = newData;
		return;
	}

	while (tempIdx < pos)
	{
		if (curr->next)
		{
			tempIdx++;
			prev = curr;
			curr = curr->next;
		}
		else
		{
			break;
		}
	}

	newData->next = curr;
	prev->next = newData;

	newData = 0;
	newData->next = 0;
	delete newData;
}

int LinkedList::pop_at(int pos)
{
	if (!head_)
		return 0;

	if (pos <= 0)
	{
		pos = 0;
		return pop_front();
	}

	int tempIdx = 0;
	Node* curr;
	Node* prev;

	prev = head_;
	curr = head_;

	while (tempIdx < pos)
	{
		if (curr->next)
		{
			tempIdx++;
			prev = curr;
			curr = curr->next;
		}
		else
		{
			break;
		}
	}

	prev->next = curr->next;
	curr->next = 0;

	int tempData;
	tempData = curr->data;
	delete curr;
	return tempData;
}

size_t LinkedList::size()
{
	size_t countSize;
	countSize = 0;
	Node* curr;
	curr = head_;

	while (curr->next)
	{
		countSize++;
		curr = curr->next;
	}

	return countSize;
}

//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue()
{
	front_ = back_ = NULL;
}

Queue::~Queue()
{
	Node *delPtr = front_;

	while (front_)
	{
		front_ = front_->next;
		delete delPtr;
		delPtr = front_;
	}

	back_ = front_ = NULL;
}

void Queue::enqueue(int data)
{
	if (!front_)
	{
		front_ = new Node;
		front_->data = data;
		back_ = front_;
	}
	else
	{
		back_->next = new Node;
		back_->next->data = data;
		back_ = back_->next;
	}
}

int Queue::dequeue()
{
	if (!front_)
		return 0;

	Node *delPtr = NULL;

	delPtr = front_;
	front_ = delPtr->next;
	int tempData = delPtr->data;
	delete delPtr;
	return tempData;
}

size_t Queue::size()
{
	int indexCount = 0;
	if (!front_)
		return 0;

	back_ = front_;

	while (back_)
	{
		indexCount++;
		if (back_->next)
			back_ = back_->next;
		else
			break;
	}

	return indexCount;
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack()
{
	top_ = NULL;
}

Stack::~Stack()
{
	Node *delPtr = top_;

	while (delPtr)
	{
		top_ = top_->next;
		delete delPtr;
		delPtr = top_;
	}

	top_ = NULL;
}

void Stack::push(int data)
{
	if (!top_)
	{
		top_ = new Node;
		top_->data = data;
	}
	else
	{
		Node *temp = new Node;
		temp->data = data;

		temp->next = top_;
		top_ = temp;
	}
}

int Stack::pop()
{
	if (!top_)
		return 0;

	Node *delPtr = top_;
	top_ = delPtr->next;
	int tempData = delPtr->data;
	delete delPtr;
	return tempData;
}

size_t Stack::size()
{
	if (!top_)
		return 0;

	Node* temp;
	temp = top_;

	int indexCount = 0;

	while (temp)
	{
		indexCount++;

		if (temp->next)
			temp = temp->next;
		else
			break;
	}

	return indexCount;
}



// Balanced parenthesis
bool Brackets(const string& input)
{
    return true;
}

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results)
{
}