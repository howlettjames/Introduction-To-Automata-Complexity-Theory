#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM_TOP 10

int main(void)
{
	int option = 0, ch;
	long option_random = 0, random_length = 0, derivation_length = 0, i = 0, j = 0, k = 0;
	char *string, *derivation, *aux_derivation;
	char file_name[FILENAME_MAX];
	FILE *read_fp, *write_fp;

	for(;;)
	{
		srand((unsigned) time(NULL));
		printf("|+|+|+|CONTEXT FREE GRAMMAR FOR BALANCED-PARENTHESES|+|+|+|\n");
		printf("|+|+|+|MENU|+|+|+|\n");
		printf("1.Read from the command-line.\n");
		printf("2.Read from a file.\n");
		printf("3.Generate a random string.\n");
		printf("4.Show file record.\n");
		printf("5.Exit.\n");
		printf("Choose an option: ");
		scanf(" %d", &option);

		switch(option)
		{
			case 1:	case 2: case 3:
			system("cls");
			getchar(); //Catches the '\n' entered by the user
			write_fp = fopen("C:/Users/Daniela/Documents/JAMES/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_3/CFG_2/Automata_Record.txt", "w");
			if(option == 1)
			{
				string = malloc(100);
				printf("Enter a string of parentheses: ");
				i = 0;
				while((ch = getchar()) != '\n')
					string[i++] = ch;
				string[i] = '\0';
				printf("|+|+|The string is: %s\n\n", string);
				fprintf(write_fp, "|+|+|The string is: %s\n\n", string);
			}
			else if(option == 2)
			{
				printf("Enter name of the file (it may include an adress): ");
				i = 0;
				while((ch = getchar()) != '\n')
					file_name[i++] = ch;
				file_name[i] = '\0';
				if((read_fp = fopen(file_name, "rb")) == NULL)
				{
					printf("Can't open %s\n", file_name);
					break;
				}
				i = 0;
				while((ch = getc(read_fp)) != EOF)
					i++;
				string = malloc(i);
				fseek(read_fp, 0, SEEK_SET);
				i = 0;
				while((ch = getc(read_fp)) != EOF)
					string[i++] = ch;
				string[i] = '\0';
				printf("|+|+|The string is: %s\n\n", string);
				fprintf(write_fp, "|+|+|The string is: %s\n\n", string);
				fclose(read_fp);
			}
			else if(option == 3)
			{
				printf("Enter a length for the random string (0 if you want the program to choose): ");
				scanf(" %d", &option_random);
				if(option_random != 0)
					random_length = option_random;
				else
					random_length = rand() % RANDOM_TOP + 1;
				string = malloc(random_length);
				printf("|+|+|The random length is: %d\n", random_length);
				fprintf(write_fp, "|+|+|The random length is: %d\n", random_length);
				for(i = 0; i < random_length; i++)
				{
					if(rand() % 2)
						string[i] = '(';
					else
						string[i] = ')';
				}
				string[i] = '\0';
				printf("|+|+|The string is: %s\n\n", string);	
				fprintf(write_fp, "|+|+|The string is: %s\n\n", string);	
			}
			derivation = malloc(2);
			derivation[0] = 'B';
			derivation[1] = '\0';
			derivation_length = 1;
			aux_derivation = malloc(1); //To be able to use realloc 
			printf("|+|+|Remaining input: %s\t%s\n", string, derivation);
			fprintf(write_fp, "|+|+|Remaining input: %s\t%s\n", string, derivation);
			for(i = 0; string[i] != '\0'; i++)
			{
				if(string[i] == '(' && derivation[i] == 'B')
				{
					derivation_length += 2;
					derivation = realloc(derivation, derivation_length + 1);
					derivation[i] = '(';
					derivation[i + 1] = 'R';
					derivation[i + 2] = 'B';
					derivation[i + 3] = '\0';
				}
				else if(string[i] == '(' && derivation[i] == 'R')
				{
					derivation_length += 2;
					derivation = realloc(derivation, derivation_length + 1);
					aux_derivation = realloc(aux_derivation, derivation_length + 1); //Just in case
					for(j = 0, k = i + 1; derivation[k] != '\0'; j++, k++)
						aux_derivation[j] = derivation[k];
					aux_derivation[j] = '\0';
					derivation[i] = '(';
					derivation[i + 1] = 'R';
					derivation[i + 2] = 'R';
					for(j = i + 3, k = 0; aux_derivation[k] != '\0'; j++, k++)
						derivation[j] = aux_derivation[k];
					derivation[j] = '\0';
				}
				else if(string[i] == ')' && derivation[i] == 'R')
					derivation[i] = ')';
				
				else if(string[i] == ')' && derivation[i] == 'B')
				{
					derivation[i] = '\0';
					break;
				}
				string[i] = ' ';
				printf("|+|+|Remaining input: %s\t%s\n", string, derivation);	
				fprintf(write_fp, "|+|+|Remaining input: %s\t%s\n", string, derivation);	
			}
			if(derivation[i] == 'B')
			{
				derivation[i] = '\0';
				printf("|+|+|Remaining input: %s\t%s\n\n", string, derivation);
				fprintf(write_fp, "|+|+|Remaining input: %s\t%s\n\n", string, derivation);
				printf("|+|+|ACCEPTED: The string has balaced-parentheses.\n\n");	
				fprintf(write_fp, "|+|+|ACCEPTED: The string has balaced-parentheses.\n\n");	
			}
			else 
			{
				printf("|+|+|Remaining input: %s\t%s\n\n", string, derivation);
				fprintf(write_fp, "|+|+|Remaining input: %s\t%s\n\n", string, derivation);
				printf("|+|+|NOT ACCEPTED: The string has no balaced-parentheses.\n\n");
				fprintf(write_fp, "|+|+|NOT ACCEPTED: The string has no balaced-parentheses.\n\n");
			}
			fclose(write_fp);
			free(string);
			free(derivation);
			free(aux_derivation);
			break;
			case 4:
				system("C:/Users/Daniela/Documents/JAMES/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_3/CFG_2/Automata_Record.txt");
			break;
			case 5:
				system("cls");
				exit(EXIT_SUCCESS);
			break;
			default:
				system("cls");
				printf("Choose a correct option.\n");
				Sleep(2500);
			break;
		}
	}

	return 0;
}