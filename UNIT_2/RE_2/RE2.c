#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define RANDOM_TOP 100

int main(void)
{
	int option = 0, k = 0, i = 0, j = 0;
	long int length = 0;
	int index;
	char *string1, *alpha_string;
	FILE *write_fp;

	srand((unsigned) time(NULL));
	for(;;)
	{
		printf("|+|+|+|REGULAR EXPRESSION: [(10)*0 + 1(01)*1][(0(01)*(1 + 00) + 1(10)*(0 + 11))]*.|+|+|+|\n");
		printf("|+|+|+|MENU|+|+|+|\n");
		printf("1.Generate 5 strings.\n");
		printf("2.Check file record.\n");
		printf("3.Exit.\n");
		printf("Choose an option: ");
		scanf(" %d", &option);

		switch(option)
		{
			case 1:
				system("cls");
				if((write_fp = fopen("C:/Users/Daniela/Documents/JAMES/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/RE_2/Automata_Record.txt", "w")) == NULL)
				{
					printf("Can't open Automatomata_record.txt\n");
					break;
				}
				for(j = 0; j < 5; j++)
				{
					printf("Start.\n");
					index = 0;
					length = 0;
					k = 0;
					i = 0;
					printf("|+|+|Computing: [(10)*0 + 1(01)*1].\n");
					if((rand() % 2) == 1)
					{
						printf("|+|+|Computing: (10)*0.\n");
						if((rand() % 2) == 1)
						{
							k = rand() % RANDOM_TOP + 1;
							printf("|+|+|The k at (10)* is: %d\n", k);
							length = k * 2;
							string1 = calloc(length, sizeof(char));
							for(i = index; i < length; i++)
							{
								string1[i++] = '1';
								string1[i] = '0';
							}
							index = i;
							length++;							
							string1 = realloc(string1, length);
							string1[index++] = '0';
						}
						else
						{
							printf("|+|+|Empty string at (10)*.\n");
							length++;
							string1 = calloc(length, sizeof(char));
							string1[index++] = '0';
							length = index;
						}
					}
					else
					{
						printf("|+|+|Computing: 1(01)*1.\n");
						length++;
						string1 = calloc(length, sizeof(char));
						string1[index++] = '1';
						if((rand() % 2) == 1)
						{
							k = rand() % RANDOM_TOP + 1;
							printf("|+|+|The k at (01)* is: %d\n", k);
							length = length + (k * 2);
							string1 = realloc(string1, length);
							for(i = index; i < length; i++)
							{
								string1[i++] = '0';
								string1[i] = '1';
							}
							index = i;
							length++;
							string1 = realloc(string1, length);
							string1[index++] = '1';
						}
						else
						{
							printf("|+|+|Empty string at (01)*.\n");
							length++;
							string1 = realloc(string1, length);
							string1[index++] = '1';
						}
					}	
					printf("|+|+|Computing: [(0(01)*(1 + 00) + 1(10)*(0 + 11))]*.\n");				
					if((rand() % 2) == 1)
					{
						printf("|+|+|Empty string at: [(0(01)*(1 + 00) + 1(10)*(0 + 11))]*.\n");
						length++;
						string1 = realloc(string1, length);
						string1[index] = '\0';
						printf("The string %d is: %s\n\n", j + 1, string1);
						fprintf(write_fp, "The string %d is: %s\n\n", j + 1, string1);
					}
					else
					{
						if((rand() % 2) == 1)
						{
							printf("|+|+|Computing: 0(01)*(1 + 00).\n");
							length++;
							string1 = realloc(string1, length);
							string1[index++] = '0';
							if((rand() % 2) == 1)
							{
								k = rand() % RANDOM_TOP + 1;
								printf("|+|+|The k at (01)* is: %d\n", k);
								length = length + (k * 2);
								string1 = realloc(string1, length);
								for(i = index; i < length; i++)
								{
									string1[i++] = '0';
									string1[i] = '1';
								}
								index = i;
							}
							else
								printf("|+|+|Empty string at (01)*.\n");
							if((rand() % 2) == 1)
							{
								length += 2;
								string1 = realloc(string1, length);
								string1[index++] = '1';
								string1[index] = '\0';
							}
							else
							{
								length += 3;
								string1 = realloc(string1, length);
								string1[index++] = '0';
								string1[index++] = '0';
								string1[index] = '\0';
							}
						}
						else
						{
							printf("|+|+|Computing: 1(10)*(0 + 11)\n");
							length++;
							string1 = realloc(string1, length);
							string1[index++] = '1';
							if((rand() % 2) == 1)
							{
								k = rand() % RANDOM_TOP + 1;
								printf("|+|+|The k at (10)* is: %d\n", k);
								length = length + (k * 2);
								string1 = realloc(string1, length);
								for(i = index; i < length; i++)
								{
									string1[i++] = '1';
									string1[i] = '0';
								}
								index = i;							
							}
							else
								printf("|+|+|Empty string at (10)*.\n");
							if((rand() % 2) == 1)
							{
								length += 2;
								string1 = realloc(string1, length);
								string1[index++] = '0';
								string1[index] = '\0';
							}
							else
							{
								length += 3;
								string1 = realloc(string1, length);
								string1[index++] = '1';
								string1[index++] = '1';
								string1[index] = '\0';
							}	
						}
						k = rand() % RANDOM_TOP + 1;
						printf("The k at [(0(01)*(1 + 00) + 1(10)*(0 + 11))]* is: %d\n", k);					
						length = strlen(string1);
						printf("The length of the string is: %ld\n", length);
						alpha_string = malloc((length * k) + 1);
						strcpy(alpha_string, string1);
						for(i = 0; i < (k - 1); i++)
							strcat(alpha_string, string1);
						printf("The string %d is: %s\n\n", j + 1, alpha_string);
						fprintf(write_fp, "The string %d is: %s\n\n", j + 1, alpha_string);
					}
					free(string1);
					free(alpha_string);
				}
				fclose(write_fp);
			break;
			case 2:
				system("C:/Users/Daniela/Documents/JAMES/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/RE_2/Automata_Record.txt");
			break;
			case 3:
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

