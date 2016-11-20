#include "Queue.h"

float* Avg_ar(int w_size, int* array, int ar_size)
{
	if ((w_size < 1) || (w_size > ar_size))
		throw 1;

	MyQueue q;

	int sum = 0;
	float *avg = NULL;
	avg = new float[7 - w_size + 1];

	q.push(array[0]);

	for (int i = 0; i < w_size; ++i)
	{
		sum += array[i];
	}
	for (int i = 0; i < 7 - w_size + 1; ++i)
	{
		avg[i] = (double)sum / w_size;
		sum = sum - q.front() + array[i + w_size];
		q.pop();
		q.push(array[i + 1]);
	}

	return avg;
}


MyQueue::MyQueue()
{
	begin = NULL;
	end = NULL;
}

MyQueue::~MyQueue()
{
	while (begin != end)
	{
		CNode* temp = begin;
		begin = temp->next;
		temp->prev = NULL;
		temp->next = NULL;
		temp = NULL;
		delete temp;
	}
	begin = NULL;
	end = NULL;
}

void MyQueue::push(int data)
{
	CNode* temp = new CNode;
	temp->data = data;
	temp->prev = NULL;
	if (begin != NULL)
	{
		temp->next = begin;
		begin->prev = temp;
		begin = temp;
	}
	else
	{
		temp->next = NULL;
		begin = end = temp;
	}
}

void MyQueue::pop()
{
	if (!empty())
	{
		if (end == begin)
		{
			end = NULL;
			begin = NULL;
			return;
		}
		CNode* temp = end;
		end = temp->prev;
		end->prev = temp->prev->prev;
		end->next = NULL;
	}
	else
		throw 1;
}

int MyQueue::front()
{
	if (!empty())
		return end->data;
	else
		throw 1;
}

int MyQueue::back()
{
	if (!empty())
		return begin->data;
	else
		throw 1;
}

bool MyQueue::empty()
{
	if ((begin == NULL) && (end == NULL))
		return true;
	else
		return false;

}

int MyQueue::size()
{
	int count = 0;
	if (empty())
		return 0;
	else
	{
		CNode* tmp = begin;
		while (tmp != end)
		{
			count++;
			tmp = tmp->next;
		}
		return (count + 1);
	}
}