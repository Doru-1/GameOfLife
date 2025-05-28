#include <stdio.h>
#include <stdlib.h>

#include "common.h"

Node * newNode(int l, int c)
{
	Node * tmp = (Node *)malloc(sizeof(Node));

	if(!tmp)
	{
		printf("Eroare la alocarea unui nod. \n");
		return NULL;
	}

	tmp -> l = l;
	tmp -> c = c;
	tmp -> next = NULL;

	return tmp;
}

void fprintm(FILE * fout, char ** mat, int n, int m)
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			fprintf(fout, "%c", mat[i][j]);
		}

		fprintf(fout, "\n");
	}

	fprintf(fout, "\n");
}

int nr_vecini(char ** mat, int n, int m, int l, int c)
{
	int cnt = 0;
	for(int i = -1; i < 2; ++i)
	{
		for(int j = -1; j < 2; ++j)
		{
			if(0 == i && 0 == j)continue; // sarim celula

			// localizam coordonatele
			int lin = l + i;
			int col = c + j;

			if(lin >= 0 && lin < n && col >= 0 && col < m && 'X' == mat[lin][col])++cnt; // vecin viu! :D
		}
	}

	return cnt;
}
