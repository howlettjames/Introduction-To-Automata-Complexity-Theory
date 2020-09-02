#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define STR_LENGTH 10000
#define Q0 0
#define Q1 1
#define Q2 2
#define Q3 3
#define TOP 100

int getString(int string_length, char string[string_length], int first_ch);
int getStringFile(int string_length, char string[string_length], int first_ch, FILE *read_fp);
bool automata(char *p, int mode);

int main (void)
{
	int option = 0, first_ch, last_ch = ' ', ch, top, i = 0, random, strings = 0, mode;
	char string[STR_LENGTH + 1], read_file[50];
	bool accepted;
	FILE *read_fp, *write_fp;

	srand((unsigned) time(NULL));

	printf("DFA recognizing the language: L = {w | w has both an even number of 0's and an even number of 1's}.\n");
	for(;;)
	{
		fflush(stdin);
		printf("**************MENU****************\n1.-Read from the command-line.\n2.-Generate a random string.\n3.-Read from a text file.\n4.-Exit.\n");
		printf("Option: ");
		scanf(" %d", &option);
		system("cls");
		switch(option)
		{
			case 1:
				fflush(stdin);
				last_ch = ' ';
				printf("Enter a string: ");
				while((first_ch = getchar()) != '\n')
				{
					if (first_ch == '1' || first_ch == '0')
						last_ch = getString(STR_LENGTH, string, first_ch); 
					if(last_ch == '\n')
						break;
				}
				automata(string, 'w');
			break;

			case 2:
				top = rand() % TOP + 1;
				printf("Random top: %d\n", top);
				for(i = 0; i < top; i++)
				{
					if (rand() % 2)
						ch = '1';
					else 
						ch = '0';
					string[i] = ch;
				}
				string[i] = '\0';
				automata(string, 'w');
			break;

			case 3:
				strings = 0;
				fflush(stdin);									//SE ENCUENTRA AQUÍ DADO QUE EL BUFFER SE QUEDA CON EL '\n' QUE INGRESAMOS AL ELEGIR OPCIÓN
				printf("Enter name of the file: ");
				while((ch = getchar()) != '\n')
				{
					read_file[i++] = ch;
				}
				i = 0;
				if ((read_fp = fopen(read_file, "rb")) == NULL)
				{
					fprintf(stderr, "Can't open: %s\n", read_file);
					break;
				}

				while ((first_ch = getc(read_fp)) != EOF)
				{
					if(first_ch == '1' || first_ch == '0')
					{
						getStringFile(STR_LENGTH, string, first_ch, read_fp);
						strings += 1;

						if (strings == 1)
							mode = 'w';
						else 
							mode = 'a';

						automata(string, mode);
					}
				}
			break;

			case 4:
				exit(EXIT_SUCCESS);
			break;
		}
	}
	return 0;
}

int getString(int string_length, char string[string_length], int first_ch)
{
	int i = 0; int ch;

	string[i++] = first_ch;

	while((ch = getchar()) == '1' || ch == '0' && i < string_length)
		string[i++] = ch;
	string[i] = '\0';	

	return ch;
}

int getStringFile(int string_length, char string[string_length], int first_ch, FILE *read_fp)
{
	int i = 0; int ch;

	string[i++] = first_ch;

	while((ch = getc(read_fp)) == '1' || ch == '0' && i < string_length && ch != EOF)
		string[i++] = ch;
	string[i] = '\0';	

	return ch;
}

bool automata(char *p, int mode)
{
	int state = Q0;
	bool move = false;
	FILE *fp;

	if (mode == 'w')
		fp = fopen("Automata_record.txt", "w");
	else
		fp = fopen("Automata_record.txt", "a");

	printf("String: %s\n", p);
	fprintf(fp, "String: %s\n", p);

	for(;;)
	{
		if (state == Q0 && *p == '1' && move == false)
			{
				state = Q1;
				move = true;
				printf("**State: &(Q0, 1) = Q1\n");
				fprintf(fp, "**State: &(Q0, 1) = Q1\n");
			}
		else if (state == Q0 && *p == '0' && move == false)
			{
				state = Q2;
				move = true;
				printf("**State: &(Q0, 0) = Q2\n");
				fprintf(fp, "**State: &(Q0, 0) = Q2\n");
			}

		if (state == Q1 && *p == '1' && move == false)
			{
				state = Q0;
				move = true;
				printf("**State: &(Q1, 1) = Q0\n");
				fprintf(fp, "**State: &(Q1, 1) = Q0\n");
			}
		else if (state == Q1 && *p == '0' && move == false)
			{
				state = Q3;
				move = true;
				printf("**State: &(Q1, 0) = Q3\n");
				fprintf(fp, "**State: &(Q1, 0) = Q3\n");
			}

		if (state == Q2 && *p == '0' && move == false)
			{
				state = Q0;
				move = true;
				printf("**State: &(Q2, 0) = Q0\n");
				fprintf(fp, "**State: &(Q2, 0) = Q0\n");
			}
		else if (state == Q2 && *p == '1' && move == false)
			{
				state = Q3;
				move = true;
				printf("**State: &(Q2, 1) = Q3\n");
				fprintf(fp, "**State: &(Q2, 1) = Q3\n");
			}

		if (state == Q3 && *p == '0' && move == false)
			{
				state = Q1;
				move = true;
				printf("**State: &(Q3, 0) = Q1\n");
				fprintf(fp, "**State: &(Q3, 0) = Q1\n");
			}
		else if (state == Q3 && *p == '1' && move == false)
			{
				state = Q2;
				move = true;
				printf("**State: &(Q3, 1) = Q2\n");
				fprintf(fp, "**State: &(Q3, 1) = Q2\n");
			}

		if(state == Q0 && *p == '\0')
		{
			printf("String accepted.\n\n");
			fprintf(fp, "String accepted.\n\n");
			return true;
		}
		else if (state != Q0 && *p == '\0')
		{
			printf("String not accepted.\n\n");
			fprintf(fp, "String not accepted.\n\n");
			return false;
		}

		p++;
		move = false;
	}
	fclose(fp);
}
