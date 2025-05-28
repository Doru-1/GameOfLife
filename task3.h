#pragma once
#include <stdio.h>

#include "common.h"

struct Elem
{
	Node * lista;
	struct Elem * left;
	struct Elem * right;
};

typedef struct Elem TreeNode; 

Node * newNode(int l, int c);
void push(Node ** head, int l, int c);
TreeNode * newTreeNode();
void task3(FILE * fin, FILE * fout, int n, int m, int k);