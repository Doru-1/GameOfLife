#include <stdio.h>

#include "task1.h"
#include "task2.h"
#include "task3.h"

int main(int argc, const char * argv[])
{
	for(int i = 0; i < argc; ++i)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	int t, // nr task
		n, // nr linii 
		m, // nr coloane
		k; // nr generatii de calculat
	FILE * fin = fopen(argv[1], "r"),
		 * fout = fopen(argv[2], "w");

	fscanf(fin, "%d%d%d%d", &t, &n, &m, &k);

	switch(t)
	{
	case 1:
		task1(fin, fout, n, m, k);
		break;
	case 2:
		task2(fin, fout, n, m, k);
		break;
	case 3:
		task3(fin, fout, n, m, k);
		break;
	default:
		printf("Aces caz nu a fost implementat inca! \n");
	}

	fclose(fin);
	fclose(fout);

	return 0;
}
