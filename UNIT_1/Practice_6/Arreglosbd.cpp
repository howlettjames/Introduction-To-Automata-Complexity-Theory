#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int n = 5, i, j;
	int **arreglo2 = (int **) malloc(n * sizeof(int *));

	srand((unsigned) time(NULL));

	for(i = 0; i < 5; i++)
	{
		arreglo2[i] = (int *) calloc(1, sizeof(int));
		for(j = 0; j < 5; j++)
		{
			arreglo2[i][j] = rand() % 6;
			printf("%d ", arreglo2[i][j]);
		}
		printf("\n");
	}
	free(arreglo2);

}	