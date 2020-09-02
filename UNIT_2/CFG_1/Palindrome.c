#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define RULE4 4
#define RULE5 5
#define RANDOM_TOP 1000

bool first_time[3] = {true};

char *upToP(char *string, int length, int rule);
char *fromP(char *string, int length, int rule);

int main(void)
{
	int option = 0, rule;
	long int length = 0, index = 0, choices = 0, i = 0, j = 0, k = 0, random = 0;
	char *string, *aux_string, *prev_string, *auxe_string;
	FILE *write_fp, *write_shape;

	srand((unsigned) time(NULL));
	for(;;)
	{
		length = 0;
		index = 0;
		choices = 0;
		printf("|+|+|+|CONTEXT FREE GRAMATIC THAT GENERATES PALINDROMES|+|+|+|\n");
		printf("|+|+|+|MENU|+|+|+|\n");
		printf("1. Read length from the command-line.\n");
		printf("2. Generate a random length.\n");
		printf("3. Check the file record.\n");
		printf("4. Check shape file.\n");
		printf("5. Exit.\n");
		printf("Choose an option: ");
		scanf(" %d", &option);	
		switch(option)
		{
			case 1: case 2:
				system("cls");
				write_fp = fopen("C:/Users/Daniela/Documents/JAMES/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/CFG_1/Automata_Record.txt", "w");
				write_shape = fopen("C:/Users/Daniela/Documents/JAMES/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/CFG_1/Shape.txt", "w");
				if(option == 1)
				{
					printf("Enter the length: ");
					scanf("%ld", &length);
				}
				else
				{
					length = rand() % RANDOM_TOP;
					printf("The random length is: %d\n", length);
					fprintf(write_fp, "The random length is: %d\n", length);
					fprintf(write_shape, "The random length is: %d\n", length);
				}
				if(length == 0)
				{
					printf("Rule: 1|>>>|P --> e.\n");
					fprintf(write_fp, "Rule: 1|>>>|P --> e.\n");
					fprintf(write_shape, "Rule: 1|>>>|P --> e.\n");
				}
				else if(length == 1)
				{
					if((rand() % 2) == 0)
					{
						printf("Rule: 2|>>>|P --> 0.\n");		
						fprintf(write_fp, "Rule: 2|>>>|P --> 0.\n");		
						fprintf(write_shape, "Rule: 2|>>>|P --> 0.\n");		
					}
					else
					{
						printf("Rule: 2|>>>|P --> 1.\n");			
						fprintf(write_fp, "Rule: 2|>>>|P --> 1.\n");			
						fprintf(write_shape, "Rule: 2|>>>|P --> 1.\n");			
					}
				}
				else
				{
					if(length % 2 == 0)
						length++;
					string = malloc(length + 1);
					for(i = 0; i < length; i++)
						string[i] = ' ';
					string[i] = '\0';
					string[length / 2] = 'P';
					choices = length / 2;
					for(i = 0; i < choices; i++)
					{
						if((rand() % 2) == 1)
							rule = RULE4;
						else
							rule = RULE5;

						aux_string = upToP(string, length, rule);
						for(j = 0; string[j] != 'P'; j++)
							string[j] = aux_string[j];
						aux_string = fromP(string, length, rule);
						for(j = (length / 2) + 1, k = 0; string[j] != '\0'; j++, k++)
							string[j] = aux_string[k];

						printf("Rule: %d|>>>|%s\n", rule, string);	
						fprintf(write_fp, "Rule: %d|>>>|%s\n", rule, string);	
						fprintf(write_shape, "%s\n", string);	
					}
					random = rand() % 3;
					if(random == 0)
					{
						aux_string = malloc(length + 1);
						for(i = 0; string[i] != 'P'; i++)
							aux_string[i] = string[i];
						for(; string[i] != '\0'; i++)
							aux_string[i] = string[i + 1];
						aux_string[i] = '\0';
						printf("Rule: 1|>>>| %s\n", aux_string);		
						fprintf(write_fp, "Rule: 1|>>>| %s\n", aux_string);		
						fprintf(write_shape, " %s\n", aux_string);		
					}
					else if(random == 1)
					{
						string[length / 2] = '0';
						printf("Rule: 2|>>>|%s\n", string);			
						fprintf(write_fp, "Rule: 2|>>>|%s\n", string);			
						fprintf(write_shape, "%s\n", string);			
					}
					else if(random == 2)
					{
						string[length / 2] = '1';
						printf("Rule: 3|>>>|%s\n", string);		
						fprintf(write_fp, "Rule: 3|>>>|%s\n", string);		
						fprintf(write_shape, "%s\n", string);		
					}
					fclose(write_fp);
					fclose(write_shape);
				}
			break;
			case 3:
				system("C:/Users/Daniela/Documents/JAMES/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/CFG_1/Automata_Record.txt");
				system("cls");
			break;
			case 4:
				system("C:/Users/Daniela/Documents/JAMES/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/CFG_1/Shape.txt");
				system("cls");
			break;
			case 5:
				system("cls");
				exit(EXIT_SUCCESS);
			break;
			default:
				system("cls");
				printf("Choose a correct option.\n");
				Sleep(2000);
			break;
		}
	}
	return 0;
}

char *upToP(char *string, int length, int rule)
{
	long int i, aux_length;
	char *aux_string;

	aux_string = malloc((length / 2) + 1);
	for(i = 0; string[i] != 'P'; i++)
		aux_string[i] = string[i];
	aux_string[i] = '\0';

	if(first_time[0] == true && rule == RULE4)
	{
		aux_string[(length / 2) - 1] = '0';
		first_time[0] = false;
		return aux_string;
	}
	else if(first_time[0] == true && rule == RULE5)
	{
		aux_string[(length / 2) - 1] = '1';	
		first_time[0] = false;
		return aux_string;
	}

	if(first_time[0] == false && rule == RULE4)
	{
		aux_length = strlen(aux_string);
		for(i = 0; i < (aux_length - 1); i++)
			aux_string[i] = aux_string[i + 1];
		aux_string[aux_length - 1] = '0';
	}
	else if(first_time[0] == false && rule == RULE5)
	{
		aux_length = strlen(aux_string);
		for(i = 0; i < (aux_length - 1); i++)
			aux_string[i] = aux_string[i + 1];
		aux_string[aux_length - 1] = '1';
	}

	return aux_string;
}

char *fromP(char *string, int length, int rule)
{
	long int i, j, aux_length;
	char *aux_string;

	aux_string = malloc((length / 2) + 1);
	for(i = (length / 2) + 1, j = 0; string[i] != '\0'; i++, j++)
		aux_string[j] = string[i];
	aux_string[j] = '\0';

	if(first_time[1] == true && rule == RULE4)
	{
		aux_string[0] = '0';
		first_time[1] = false;
		return aux_string;
	}
	else if(first_time[1] == true && rule == RULE5)
	{
		aux_string[0] = '1';	
		first_time[1] = false;
		return aux_string;
	}

	if(first_time[1] == false && rule == RULE4)
	{
		aux_length = strlen(aux_string);
		for(i = aux_length; i > 0; i--)
			aux_string[i] = aux_string[i - 1];
		aux_string[i] = '0';
		aux_string = realloc(aux_string, aux_length + 1);
		aux_string[aux_length] = '\0';
	}
	else if(first_time[1] == false && rule == RULE5)
	{
		aux_length = strlen(aux_string);
		for(i = aux_length; i > 0; i--)
			aux_string[i] = aux_string[i - 1];
		aux_string[i] = '1';
		aux_string = realloc(aux_string, aux_length + 1);
		aux_string[aux_length] = '\0';
	}

	return aux_string;
}