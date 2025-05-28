#include <stdio.h>
#include <stdlib.h>

#include "task2.h"
#include "common.h"

StackNode * newStackNode()
{
	StackNode * tmp = (StackNode *)malloc(sizeof(StackNode));

	if(!tmp)
	{
		printf("Eroare la alocarea unui nod din stiva.\n");
		return NULL;
	}

	tmp -> head = NULL;
	tmp -> next = NULL;

	return tmp;
}

Stack * newStack()
{
	Stack * tmp = (Stack *)malloc(sizeof(Stack));

	if(!tmp)
	{
		printf("Eroare la alocarea stivei.\n");
		return NULL;
	}

	tmp -> top = NULL;
	return tmp;
}

void pushNodeTop(Stack * stiva, int l, int c)
{
	if(!stiva -> top)
	{
		printf("Stiva nu a fost alocata bine.\n");
		return;
	}

	Node * node = newNode(l, c);
	if(!node)return;

	// adaugam la sfarsitul listei
	if(NULL == stiva -> top -> head)
	{
		stiva -> top -> head = node;
	}
	else
	{
		Node * curr = stiva -> top -> head;
		while(curr -> next)
		{
			curr = curr -> next;
		}

		curr -> next = node;
	}
}

void pushGen(Stack * stiva)
{
	StackNode * stacknode = newStackNode();

	if(!stacknode)return;

	stacknode -> next = stiva -> top;
	stiva -> top = stacknode;
}

void task2(FILE * fin, FILE * fout, int n, int m, int k)
{
	StackNode ** generatii = (StackNode **)malloc(k * sizeof(StackNode *));

	// vector de pointeri pt generatiile din stiva ca sa le afisez in ordine inversa cum le salvez ceea ce strica toata ideea stivei si ma cam agaseaza

	if(!generatii)
	{
		printf("Eroare la alocarea vectorului de pointeri.\n");
	}

	char ** mat = (char **)malloc(n * sizeof(char *));
	char ** nextMat = (char **)malloc(n * sizeof(char *));

	if(NULL == mat || NULL == nextMat)
	{
		printf("Eroare la alocarea randurilor matricei.\n");
		free(mat);
		free(nextMat);
		return;
	}

	for(int i = 0; i < n; ++i)
	{
		mat[i] = (char *)malloc((m + 1) * sizeof(char));
		nextMat[i] = (char *)malloc((m + 1) * sizeof(char));

		if(NULL == mat[i])
		{
			printf("Eroare la alocarea randului %d.\n", i);
			return;
		}

		if(NULL == nextMat[i])
		{
			printf("Eroare la alocarea randului %d in matricea next.\n", i);
			return;
		}

		fscanf(fin, "%s", mat[i]);
		fgetc(fin);
	}

	// fprintm(fout, mat, n, m);

	Stack * schimbari = newStack();

	if(!schimbari)
	{
		printf("Eroare la alocarea stivei.\n");
		return;
	}

	int gen = k;
	while(k--)
	{
		pushGen(schimbari);

		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				int x = nr_vecini(mat, n, m, i, j);

				if('X' == mat[i][j])
				{
					if(x < 2 || x > 3)
					{
						pushNodeTop(schimbari, i, j); // adaugam un nod cu valorile (i,j) la sfarsitul listei head din topul stivei
						nextMat[i][j] = '+'; // suprapopulare sau subpopulare
					}
					else nextMat[i][j] = 'X'; // caz nimic viu
				}
				else if(x == 3)
				{
					pushNodeTop(schimbari, i, j);
					nextMat[i][j] = 'X'; // reproducere
				}
				else nextMat[i][j] = '+'; // caz nimic mort
			}
		}

		// afisam generatia

		// fprintm(fout, nextMat, n, m);
		
		// copiem nextMat in mat

		char ** aux = mat;
		mat = nextMat;
		nextMat = aux;
	}

	StackNode * curr = schimbari -> top;
	for(int i = gen - 1; i >= 0 && curr; --i)
	{
		generatii[i] = curr;
		curr = curr -> next;
	}

	for(int i = 0; i < gen; ++i)
	{
		fprintf(fout, "%d", i + 1); // nr gen

		Node * curr_list = generatii[i] -> head;
		while(curr_list != NULL)
		{
			fprintf(fout, " %d %d", curr_list -> l, curr_list -> c);
			curr_list = curr_list -> next;
		}

		fprintf(fout, "\n");
	}

	// eliberam toata memoria 

	for(int i = 0; i < n; ++i)free(mat[i]), free(nextMat[i]);

	free(mat);
	free(nextMat);
	free(generatii);
	// freeStack(schimbari);
}