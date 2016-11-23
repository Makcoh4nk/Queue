#pragma once
#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

struct CNode
{
	int data;
	CNode* next;
	CNode* prev;
};

class MyQueue
{
	CNode* begin;
	CNode* end;

public:

	MyQueue();
	~MyQueue();

	void push(int);
	void pop();
	int front();
	int back();
	bool empty();
	int size();
};

float* Avg_ar(int, int*, int);