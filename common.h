#pragma once
#include <stdio.h>

struct lista
{
	int l, c;
	struct lista * next;
};

typedef struct lista Node;

Node * newNode(int l, int c);

void fprintm(FILE * fout, char ** mat, int n, int m);
int nr_vecini(char ** mat, int n, int m, int l, int c);