#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "TADStack.h"

#define STR_LENGTH 10000
#define RANDOM_TOP 1000

long printer = 1;

int main(void)
{
	Stack stack1;
	element e1;
	int option = 0, ch;
	long i = 0, random_length = 0, string_length = 0, aux_string_length = 0, j = 0, stack_length = 0; 
	char *string, *stack, *aux_string;
	char file_name[FILENAME_MAX];
	FILE *write_fp, *read_fp;

	srand((unsigned) time(NULL));

	for(;;)
	{
		printf("|+|+|+|A PDA to accept {0^(n)1^(n) | n >= 1}|+|+|+|\n");
		printf("|+|+|+|MENU|+|+|+|\n");
		printf("1. Read from the command-line.\n");	
		printf("2. Read from a file.\n");	
		printf("3. Generate a random string.\n");	
		printf("4. Check the file record.\n");
		printf("5. Exit.\n");
		printf("Choose an option: ");
		scanf(" %d", &option);				
		switch(option)
		{
			case 1: case 2: case 3:
			system("cls");
			getchar(); //Catches the '\n' entered by the user
			write_fp = fopen("C:/Users/Jaime/Documents/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/PDA/Automata_Record.txt", "w");
			if(option == 1)
			{
			string = malloc(STR_LENGTH);
			printf("|+|Enter the string: ");
			for(i = 0; (ch = getchar()) != '\n'; i++)
				string[i] = ch;
			string[i] = '\0';
			printf("|+|The string is: %s\n", string);	
			fprintf(write_fp, "|+|The string is: %s\n", string);	
			}
			else if(option == 2)
			{
			printf("|+|Enter the file name (it may include an adress): ");
			scanf("%s", file_name);
			if((read_fp = fopen(file_name, "rb")) == NULL)
			{
				printf("|+|Can't open: %s", file_name);
				break;
			}
			for(i = 0; (ch = getc(read_fp)) != EOF; i++)
			{}
			string = malloc(i);
			fseek(read_fp, 0, SEEK_SET);
			for(i = 0; (ch = getc(read_fp)) != EOF; i++)
				string[i] = ch;
			string[i] = '\0';
			printf("|+|The string is: %s\n", string);	
			fprintf(write_fp, "|+|The string is: %s\n", string);	
			}
			else if(option == 3)
			{
			random_length = rand() % RANDOM_TOP + 1;
			printf("|+|The random length is: %ld\n", random_length);	
			fprintf(write_fp, "|+|The random length is: %ld\n", random_length);	
			string = malloc(random_length + 1);
			for(i = 0; i < random_length / 2; i++)
				string[i] = '0';
			for(i = random_length / 2; i < random_length; i++)
				string[i] = '1';
			string[i] = '\0';
			printf("|+|The string is: %s\n", string);	
			fprintf(write_fp, "|+|The string is: %s\n", string);	
			}
			//AUTOMATA
			if(string[0] != '\0' && string[0] == '0')
			{
			printf("|+|Start.\n\n");
			fprintf(write_fp, "|+|Start.\n\n");
			Initialize(&stack1);
			string_length = strlen(string);
			stack = malloc(string_length + 3); //We add 3 because fuck it
			Push(&stack1, (element) {.value = 'Z'});
			stack[0] = 'Z';
			stack[1] = '\0';
			printf("(q, %s, %s)|-", string, stack);
			fprintf(write_fp, "(q, %s, %s)|-", string, stack);
			printer++;
			aux_string = malloc(string_length + 1);
			strcpy(aux_string, string);
			aux_string_length = string_length;
			stack_length = 1;

			for(i = 0; string[i] != '1'; i++)
			{
			for(j = 0; j < aux_string_length; j++)
				aux_string[j] = aux_string[j + 1];
			aux_string_length--;

			for(j = stack_length; j > 0; j--)
				stack[j] = stack[j - 1];
			stack[0] = 'X';
			stack_length++;
			stack[stack_length] = '\0';

			printf("(q, %s, %s)|-", aux_string, stack);
			fprintf(write_fp, "(q, %s, %s)|-", aux_string, stack);
			printer++;
			if(printer == 8)
			{
				printf("\n");
				fprintf(write_fp, "\n");
				printer = 1;
			}
			Push(&stack1, (element) {.value = 'X'});
			}
			for(; string[i] != '\0'; i++)
			{
			for(j = 0; j < aux_string_length; j++)
				aux_string[j] = aux_string[j + 1];
			aux_string_length--;

			for(j = 0; j < stack_length; j++)
				stack[j] = stack[j + 1];
			stack_length--;

			if(stack[0] == '\0')
			{
				Pop(&stack1);
				break;
			}
			if(aux_string[0] != '\0')
			{
			printf("(p, %s, %s)|-", aux_string, stack);					
			fprintf(write_fp, "(p, %s, %s)|-", aux_string, stack);					
			printer++;
			}
			if(printer == 8)
			{
				printf("\n");
				fprintf(write_fp, "\n");
				printer = 1;
			}						
			Pop(&stack1);
			}

			if(!Empty(&stack1))
			{
			e1 = Top(&stack1);
			if(e1.value == 'Z') //Succeed
			{
			printf("(p, e, Z)|-(f, e, Z)\n\n");
			fprintf(write_fp, "(p, e, Z)|-(f, e, Z)\n\n");
			printf("|+|THE STRING SUCCEEDED.\n\n");
			fprintf(write_fp, "|+|THE STRING SUCCEEDED.\n\n");
			}
			else //More 0's than 1's
			{
			printf("(p, e, %s)|-(f, e, %s)\n\n", stack, stack);
			fprintf(write_fp, "(p, e, %s)|-(f, e, %s)\n\n", stack, stack);
			printf("|+|THE STRING DID NOT SUCCEED.\n\n");
			fprintf(write_fp, "|+|THE STRING DID NOT SUCCEED.\n\n");
			}
			}
			else //More 1's than 0's
			{
			printf("(f, %s, Z)\n\n", aux_string);
			fprintf(write_fp, "(f, %s, Z)\n\n", aux_string);
			printf("|+|THE STRING DID NOT SUCCEED.\n\n");
			fprintf(write_fp, "|+|THE STRING DID NOT SUCCEED.\n\n");
			}
			Destroy(&stack1);
			}
			else
			{
			printf("|+|Error: The string is empty or it begins with 1's.\n\n");
			fprintf(write_fp, "|+|Error: The string is empty or it begins with 1's.\n\n");
			}
			fclose(write_fp);
			break;	
			case 4:
			system("cls");
			system("C:/Users/Jaime/Documents/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/PDA/Automata_Record.txt");
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
