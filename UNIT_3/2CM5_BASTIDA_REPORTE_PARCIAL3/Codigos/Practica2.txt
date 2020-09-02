#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define RANDOM_TOP 10
#define Q0 0
#define Q1 1
#define Q2 2
#define Q3 3
#define Q4 4

int main(void)
{
	int option, ch, state;
	bool change;
	long i = 0, option_random = 0, random_length = 0;
	char *string, *machine;
	char file_name[FILENAME_MAX];
	FILE *write_fp, *read_fp;

	for(;;)
	{
		srand((unsigned) time(NULL));
		printf("|+|+|+|A TURING MACHINE TO ACCEPT {0^(n)1^(n)| n >= 1}|+|+|+|\n");
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
			case 1: case 2: case 3:
				system("cls");
				getchar(); //Catches the '\n' entered by the user
				write_fp = fopen("C:/Users/Daniela/Documents/JAMES/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_3/TM/Automata_Record.txt", "w");
				if(option == 1)
				{
					string = malloc(100);
					machine = malloc(100);
					printf("Enter a string: ");
					i = 0;
					while((ch = getchar()) != '\n')
					{
						machine[i] = ' ';
						string[i++] = ch;
					}	
					string[i] = '\0';
					machine[i] = '\0';
					printf("|+|+|The string is: %s\n\n", string);
					fprintf(write_fp, "|+|+|The string is: %s\n\n", string);
				}
				else if(option == 2)
				{
					fflush(stdin);
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
					machine = malloc(i);
					fseek(read_fp, 0, SEEK_SET);
					i = 0;
					while((ch = getc(read_fp)) != EOF)
					{
						machine[i] = ' ';
						string[i++] = ch;
					}
					string[i] = '\0';
					machine[i] = '\0';
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
					machine = malloc(random_length);
					printf("|+|+|The random length is: %d\n", random_length);
					fprintf(write_fp, "|+|+|The random length is: %d\n", random_length);
					for(i = 0; i < random_length; i++)
					{
						if(rand() % 2)
							string[i] = '1';
						else
							string[i] = '0';
						machine[i] = ' ';
					}
					string[i] = '\0';
					machine[i] = '\0';
					printf("|+|+|The string is: %s\n\n", string);	
					fprintf(write_fp, "|+|+|The string is: %s\n\n", string);	
				}
				printf("|+|+|Start\n");
				fprintf(write_fp, "|+|+|Start\n");
				printf("%s\n", string);
				fprintf(write_fp, "%s\n", string);
				machine[0] = '^';
				printf("%s\n\n", machine);
				fprintf(write_fp, "%s\n\n", machine);
				machine[0] = ' ';
				//AUTOMATA
				state = Q0;
				for(i = 0; string[i] != '\0';)
				{
					//HANDLES POSIBILITIES IN Q0
					if(state == Q0 && string[i] == '0')
					{
						state = Q1;
						string[i] = 'X';
						i++;
					}
					else if(state == Q0 && string[i] == 'Y')
					{
						state = Q3;
						i++;
					}

					//HANDLES POSIBILITIES IN Q1
					else if(state == Q1 && string[i] == '0')
					{
						i++;
					}
					else if(state == Q1 && string[i] == '1')	
					{
						state = Q2;
						string[i] = 'Y';
						i--;
					}
					else if(state == Q1 && string[i] == 'Y')
					{
						i++;
					}

					//HANDLES POSIBILITIES IN Q2
					else if(state == Q2 && string[i] == '0')
					{
						i--;
					}
					else if(state == Q2 && string[i] == 'X')
					{
						state = Q0;	
						i++;
					}
					else if(state == Q2 && string[i] == 'Y')
					{
						i--;
					}

					//HANDLES POSIBILITIES IN Q3
					else if(state == Q3 && string[i] == 'Y')
					{
						i++;
					}
					if(state == Q3 && string[i] == '\0')
					{
						state = Q4;	
					}

					//HANDLES EXCEPTIONS
					else if(state == Q0 && string[i] == '1')
						break;
					else if(state == Q3 && string[i] == '1')
					{
						i++;
					}	
					else if(state == Q3 && string[i] == '0')
						i++;

					if(state == Q4)
					{
						printf("\n|+|+|STRING ACCEPTED\n\n");
						fprintf(write_fp, "\n|+|+|STRING ACCEPTED\n\n");
						break;
					}
					
					if(string[i] != '\0')
					{
						printf("%s\n", string);
						fprintf(write_fp, "%s\n", string);
						machine[i] = '^';
						printf("%s\n\n", machine);
						fprintf(write_fp, "%s\n\n", machine);
						machine[i] = ' ';
					}	
				}
				if(state != Q4)
				{
					printf("\n|+|+|STRING NOT ACCEPTED\n\n");
					fprintf(write_fp, "\n|+|+|STRING NOT ACCEPTED\n\n");
				}	
				fclose(write_fp);
			break;
			case 4:
				system("C:/Users/Daniela/Documents/JAMES/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_3/TM/Automata_Record.txt");
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