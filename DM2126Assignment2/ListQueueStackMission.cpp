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
 *  \author    <John Doe>
 *  \date      2015 
 *  \note      <Admin ID>
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
}

Queue::~Queue()
{   
}

void Queue::enqueue(int data)
{   
}

int Queue::dequeue()
{
    return 0;
}

size_t Queue::size()
{
    return 0;
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack()
{

}

Stack::~Stack()
{
}

void Stack::push(int data)
{
}

int Stack::pop()
{
    return 0;
}

size_t Stack::size()
{
    return 0;
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