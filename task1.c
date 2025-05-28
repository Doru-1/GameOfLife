#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "task1.h"

void task1(FILE * fin, FILE * fout, int n, int m, int k)
{
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

	fprintm(fout, mat, n, m);

	while(k--)
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				int x = nr_vecini(mat, n, m, i, j);

				if('X' == mat[i][j])
				{
					if(x < 2 || x > 3)
					{
						nextMat[i][j] = '+'; // suprapopulare sau subpopulare
					}
					else nextMat[i][j] = 'X'; // caz nimic viu
				}
				else if(x == 3)nextMat[i][j] = 'X'; // reproducere
				else nextMat[i][j] = '+'; // caz nimic mort
			}
		}

		// afisam generatia

		fprintm(fout, nextMat, n, m);
		
		// copiem nextMat in mat

		char ** aux = mat;
		mat = nextMat;
		nextMat = aux;
	}

	// eliberam toata memoria 

	for(int i = 0; i < n; ++i)free(mat[i]), free(nextMat[i]);

	free(mat);
	free(nextMat);
}
