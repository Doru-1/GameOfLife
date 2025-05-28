#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "task3.h"

void push(Node ** head, int l, int c)
{
	Node * node = newNode(l, c);

	if(NULL == node)
	{
		printf("Eroare la alocarea unui nod de adaugat la lista. \n");
		return;
	}

	if(NULL == * head)
	{
		* head = node;
	}
	else
	{
		Node * curr = * head;

		while(curr -> next)
		{
			curr = curr -> next;
		}

		curr -> next = node;
	}
}

TreeNode * newTreeNode()
{
	TreeNode * tmp = (TreeNode *)malloc(sizeof(TreeNode));

	if(NULL == tmp)
	{
		printf("Eroare la alocarea unui nod din arbore. \n");
		return NULL;
	}

	tmp -> lista = NULL;
	tmp -> left = NULL;
	tmp -> right = NULL;

	return tmp;
}

TreeNode * addDiffs(char ** mat, char ** nMat)
{
	//Node * node = newTreeNode();
	return NULL;
}

TreeNode * genArbore(char ** mat, int n, int m, int k)
{
	if(0 == k)return NULL;

	TreeNode * root = newTreeNode();

	if(NULL == root)
	{
		printf("Eroare la locarea unui nod din arbore. \n");
		return NULL;
	}

	char ** nMatL = (char **)malloc(n * sizeof(char *)),
		 ** nMatR = (char **)malloc(n * sizeof(char *));

	for(int i = 0; i < n; ++i)
	{
		nMatL[i] = (char *)malloc((m + 1) * sizeof(char)),
		nMatR[i] = (char *)malloc((m + 1) * sizeof(char));

		if(NULL == nMatL[i] || NULL == nMatR[i])
		{
			printf("Eroare la alocarea matricelor de generat. \n");
			return NULL;
		}

		nMatL[i][m] = '\0';
		nMatR[i][m] = '\0';
	}

	Node * listal,
		 * listar;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			int v = nr_vecini(mat, n, m, i, j);
			
			if(2 == v)
			{
				if(mat[i][j] == '+')
				{
					push(&listal, i, j);
				}
				nMatL[i][j] = 'X';
			}
			else
			{
				nMatL[i][j] = mat[i][j];
			}

			if('X' == mat[i][j])
			{
				if(v < 2 || v > 3)
				{
					push(&listar, i, j); // adaugam un nod cu valorile (i,j) la sfarsitul listei
					nMatR[i][j] = '+'; // suprapopulare sau subpopulare
				}
				else nMatR[i][j] = 'X'; // caz nimic viu
			}
			else if(v == 3)
			{
				push(&listar, i, j);
				nMatR[i][j] = 'X'; // reproducere
			}
			else nMatR[i][j] = '+'; 
		}
	}

	TreeNode * left = newTreeNode();
	left -> lista = listal;

	TreeNode * right = newTreeNode();
	right -> lista = listar;

	root -> left = left;
	root -> right = right;

	root -> left = genArbore(nMatL, n, m, k - 1);
	root -> right = genArbore(nMatR, n, m, k - 1); // kmskmskmskmskmskms

	return root;
}

void task3(FILE * fin, FILE * fout, int n, int m, int k)
{
	char ** mat = (char **)malloc(n * sizeof(char *));

	if(NULL == mat)
	{
		printf("Eroare la alocarea randurilor matricei.\n");
		free(mat);

		return;
	}

	for(int i = 0; i < n; ++i)
	{
		mat[i] = (char *)malloc((m + 1) * sizeof(char));

		if(NULL == mat[i])
		{
			printf("Eroare la alocarea randului %d.\n", i);
			return;
		}

		fscanf(fin, "%s", mat[i]);
		fgetc(fin);
	}

	TreeNode * root = newTreeNode();

	if(NULL == root)
	{
		printf("Eroare la alocarea radacinii arborelui. \n");
		return;
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if('X' == mat[i][j])
			{
				push((&root -> lista), i, j);
			}
		}
	}

}