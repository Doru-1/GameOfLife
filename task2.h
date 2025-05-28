#pragma once
#include <stdio.h>

#include "common.h"

struct elem_stiva
{
	Node * head;
	struct elem_stiva * next;
};

typedef struct elem_stiva StackNode;

struct stiva
{
	StackNode * top;
};

typedef struct stiva Stack;

Node * newNode(int l, int c);
StackNode * newStackNode();
Stack * newStack();
void pushNodeTop(Stack * stiva, int l, int c);
void pushGen(Stack * stiva);
void task2(FILE * fin, FILE * fout, int n, int m, int k);
