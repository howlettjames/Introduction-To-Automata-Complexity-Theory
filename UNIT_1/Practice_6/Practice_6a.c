#include <stdio.h>
#include <stdlib.h>

#define LENGHT 200

int main (void)
{
	int i = 0, j = 0, k = 0, ch;
	char **states = malloc(LENGHT + 1); //THE NUMBER OF ROWS IS ALWAYS EQUAL TO THE LENGTH OF THE STRING PLUS ONE
	char string[LENGHT];

	i = 0;
	printf("Enter a string: ");
	while((ch = getchar()) != '\n')
		string[i++] = ch;
	string[i] = '\0';
	
	printf("\n");
	i = 0;
	states[i] = calloc(LENGHT, sizeof(char));
	states[0][0] = '0';
	while(string[i] != '\0')
	{
		states[i + 1] = calloc(LENGHT, sizeof(char));
		if(string[i] == '1')
		{
			for(j = 0; j < LENGHT; j++)
			{
				if(states[i][j] == '0')
					states[i + 1][j] = '0';

				else if(states[i][j] == '1')
					states[i + 1][j] = '2';

				else if(states[i][j] == '2')
					states[i + 1][j] = 'X';

				else if(states[i][j] == 'X')
					states[i + 1][j] = 'X';
			}
			
		}
		else if(string[i] == '0')
		{
			for(j = 0; j < LENGHT; j++)
			{
				if(states[i][j] == '0')
				{
					states[i + 1][j] = '0';

					k = 0;
					while(k < LENGHT)
					{
						if(states[i][k] == '1' || states[i][k] == '2' || states[i][k] == 'X')
						{
							j = k;
						}
						if(states[i][k] == 'X')
							states[i + 1][k] = 'X';
						k++;
					}
					
					states[i + 1][j + 1] = '1';
				}

				if(states[i][j] == '1')
					states[i + 1][j] = 'X';

				if(states[i][j] == '2')
					states[i + 1][j] = 'X';
			}
		}
		i++;		
	}
	k = i;
	for(i = 0; i <= k; i++)
	{
		for(j = 0; j < LENGHT; j++)
		{
			putchar(states[i][j]);
			printf(" ");
		}
		printf("\n");
	}



	return 0;
}