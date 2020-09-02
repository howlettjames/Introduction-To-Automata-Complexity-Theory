#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

#define RANDOM_TOP 1000

int main(void)
{
	int option = 0, k = 0, i = 0, j = 0;
	char *string;
	FILE *write_fp;

	srand((unsigned) time(NULL));
	for(;;)
	{
		printf("|+|+|+|REGULAR EXPRESSION: (0 + 10)*(e + 1).|+|+|+|\n");
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
			if((write_fp = fopen("C:/Users/Jaime/Documents/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/RE_1/Automata_Record.txt", "w")) == NULL)
			{
			printf("Can't open Automata_record.txt\n");
			break;
			}
			for(j = 0; j < 5; j++)
			{
			//Computes in case of epsilon/empty string
			if((rand() % 2) == 1) //If 1 we don't add any symbol to the string, that means the empty string
			{
			printf("Empty string.\n");
			//Computes (e + 1)
			if((rand() % 2) == 1) //If 1 we concatenate the string with nothing, that means we concatenate with epsilon
			{
			printf("Concatenates the empty string.\n");
			string = malloc(2); //C guarantees that a char only occupies one byte so we can write 1 instead of sizeof(char)
			string[0] = 'e';
			string[1] = '\0';
			printf("The string %d is: %s\n\n", j + 1, string);
			fprintf(write_fp, "The string %d is: %s\n\n", j + 1, string);
			}
			else	//We concatenate with 1
			{
			printf("Concatenates '1'.\n");
			string = malloc(2);
			string[0] = '1';
			string[1] = '\0';
			printf("The string %d is: %s\n\n", j + 1, string);
			fprintf(write_fp, "The string %d is: %s\n\n", j + 1, string);
			}
			}
			//Computes (0 + 10)* when there is no epsilon/empty string
			else 
			{
			printf("No empty string.\n");
			k = rand() % RANDOM_TOP + 1;
			printf("The random top is: %d\n", k);
			if((rand() % 2) == 1) //If 1 generates symbol '0' k-times
			{
			printf("Takes '0'.\n");
			string = malloc(k + 2); //Adds 2 because of the next symbol to concatenate and plus the '\0' character at the end
			for(i = 0; i < k; i++)
				string[i] = '0';
			}
			else
			{
			printf("Takes \"10\".\n");
			string = malloc((2 * k) + 2); //Alocates memory for the two simbols "10" plus the next symbol in concatenation plus the '\0' character
			for(i = 0; i < 2 * k; i++)
			{
				string[i++] = '1';
				string[i] = '0';
			}
			}
			//Computes (e + 1)	
			if((rand() % 2) == 1) //Concatenates epsilon, that means nothing
			{
			printf("Concatenates the empty string.\n");
			string[i] = '\0';
			printf("The string %d is: %s\n\n", j + 1, string);
			fprintf(write_fp, "The string %d is: %s\n\n", j + 1, string);
			}
			else //Concatenates '1'
			{
			printf("Concatenates '1'.\n");
			string[i++] = '1';
			string[i] = '\0';
			printf("The string %d is: %s\n\n", j + 1, string);
			fprintf(write_fp, "The string %d is: %s\n\n", j + 1, string);
			}	
			}
			}
			fclose(write_fp);
			break;
			case 2:
			system("C:/Users/Jaime/Documents/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/RE_1/Automata_Record.txt");
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
