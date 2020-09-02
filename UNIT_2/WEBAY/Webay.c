#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define STR_LENGTH 100
#define MAX_RECO 100
#define B 0
#define C 1
#define D 2
#define E 3
#define F 4
#define G 5
#define H 6
#define I 7

int getString(char *string, int n);
int getStringFile(char *string, int n, FILE *read_fp);
bool automata(char *ch, FILE *write_fp);

int main (void)
{
	int i = 0, j = 0, ch, last_ch, counter = 0, option = 0;
	char string[STR_LENGTH + 1] = {'\0'};
	char *recognized_strings[MAX_RECO];
	long recognized_positions[MAX_RECO] = {0};
	char file_name[FILENAME_MAX]; //DEFINED IN <stdio.h>
	FILE *read_fp, *write_fp;

	system("cls");
	for(;;)
	{
		printf("|+|+|+|A DFA TO RECOGNIZE A SET OF KEYWORDS: WEB AND EBAY.|+|+|+|\n");
		printf("|+|+|+|MENU|+|+|+|\n");
		printf("1.Read from the command-line.\n");
		printf("2.Read from a file.\n");
		printf("3.Show graph.\n");
		printf("4.Show the Automata record from file.\n");
		printf("5.Exit.\n");
		printf("Option: ");
		scanf(" %d", &option);
		system("cls");
		switch(option)
		{
			case 1:
				counter = 0;
				fflush(stdin); //CLEANS THE BUFFER TO PREVENT READING '\n' IN THE FIRST TRY
				printf("Enter the text: ");
				if((write_fp = fopen("C:/Users/Daniela/Documents/JAMES/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/WEBAY/Automata_Record.txt", "w")) == NULL)
				{
					fprintf(stderr, "Can't write to file.\n");
					break;
				}
				for(;;)
				{
					last_ch = getString(string, STR_LENGTH);
					if(string[0] != '\0')	
					{
						printf("The string is: %s\n", string);
						fprintf(write_fp, "The string is: %s\n", string);
						if(automata(string, write_fp))
						{
							recognized_strings[counter] = malloc(strlen(string) + 1); //WE ADD "+ 1" BECAUSE OF THE '\0' AT THE END OF EACH STRING
							strcpy(recognized_strings[counter], string);
							counter += 1;
						}
					}	
					if(last_ch == '\n')
						break;
				}
				printf("Number of words recognized: %d.\n", counter);
				fprintf(write_fp, "Number of words recognized: %d.\n", counter);
				printf("Words recognized: \n");
				fprintf(write_fp, "Words recognized: \n");
				for(i = 0; i < counter; i++)
				{
					printf("%s.\n", recognized_strings[i]);	
					fprintf(write_fp, "%s.\n", recognized_strings[i]);	
				}
				fclose(write_fp);
			break;
			case 2:
				counter = 0;
				fflush(stdin); //CLEANS THE BUFFER TO PREVENT READING '\n' IN THE FIRST TRY
				printf("Enter the file name (you may add an adress): ");
				scanf("%s", file_name);
				printf("The file name is: %s\n", file_name);
				if((read_fp = fopen(file_name, "rb")) == NULL)
				{
					fprintf(stderr, "Can't open: %s\n", file_name);
					break;
				}
				if((write_fp = fopen("C:/Users/Daniela/Documents/JAMES/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/WEBAY/Automata_Record.txt", "w")) == NULL)
				{
					fprintf(stderr, "Can't write to file.\n");
					break;
				}
				for(;;)
				{
					last_ch = getStringFile(string, STR_LENGTH, read_fp);
					if(string[0] != '\0')	
					{
						printf("The string is: %s\n", string);
						fprintf(write_fp, "The string is: %s\n", string);
						if(automata(string, write_fp))
						{
							recognized_strings[counter] = malloc(strlen(string) + 1);
							recognized_positions[counter] = (ftell(read_fp) - strlen(string));
							strcpy(recognized_strings[counter], string);
							counter += 1;
						}
					}	
					if(last_ch == EOF)
						break;
				}
				fclose(read_fp);
				printf("Number of words recognized: %d.\n", counter);
				fprintf(write_fp, "Number of words recognized: %d.\n", counter);
				printf("Words recognized: \n");
				fprintf(write_fp, "Words recognized: \n");
				for(i = 0; i < counter; i++)
				{
					printf("Recognized string \"%s\" at position %ld.\n", recognized_strings[i], recognized_positions[i]);	
					fprintf(write_fp, "Recognized string \"%s\" at position %ld.\n", recognized_strings[i], recognized_positions[i]);	
				}
				fclose(write_fp);
			break;
			case 3:
				system("appletviewer WebayGraph.html");
			break;
			case 4:
				system("C:/Users/Daniela/Documents/JAMES/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/WEBAY/Automata_Record.txt");
			break;
			case 5:
				system("cls");
				exit(EXIT_SUCCESS);
			break;
			default:
				printf("Choose a correct option.\n");
				Sleep(2000);
			break;
		}
	}
	return 0;
}

int getString(char *string, int max_length)
{
	int i = 0, ch;

	while (((ch = getchar()) != ' ') && ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) && i < max_length && ch != '\n')
		string[i++] = ch;
	string[i] = '\0';

	return ch;
}

int getStringFile(char *string, int max_length, FILE *read_fp)
{
	int i = 0, ch;

	while (((ch = getc(read_fp)) != ' ') && ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) && i < max_length && ch != EOF)
		string[i++] = ch;
	string[i] = '\0';

	return ch;
}

bool automata(char *ch, FILE *write_fp)
{
	int i = 0, state = B;

	printf("Start: B.\n");
	fprintf(write_fp, "Start: B.\n");
	//WE HAVE GUARANTEED THAT NON EMPTY STRINGS WILL STEP THROUGH THIS POINT SO WE CAN USE DO-WHILE
	do
	{
		//HANDLES ALL POSIBILITIES WHILE BEING IN STATE B
		if(state == B && toupper(ch[i]) == 'W')
		{
			printf("State: &(B, w) = C.\n");
			fprintf(write_fp, "State: &(B, w) = C.\n");
			state = C;
		}
		else if(state == B && toupper(ch[i]) == 'E')
		{
			printf("State: &(B, e) = D.\n");
			fprintf(write_fp, "State: &(B, e) = D.\n");
			state = D;
		}
		else if (state == B)
		{
			printf("State: B not e,w then B.\n");
			fprintf(write_fp, "State: B not e,w then B.\n");
			state = B;	
		}
		//HANDLES ALL POSIBILITIES WHILE BEING IN STATE C
		else if(state == C && toupper(ch[i]) == 'E')
		{
			printf("State: &(C, e) = E.\n");
			fprintf(write_fp, "State: &(C, e) = E.\n");
			state = E;
		}
		else if(state == C && toupper(ch[i]) == 'W')
		{
			printf("State: &(C, w) = C.\n");
			fprintf(write_fp, "State: &(C, w) = C.\n");
			state = C;
		}
		else if (state == C)
		{
			printf("State: C not e,w then B.\n");
			fprintf(write_fp, "State: C not e,w then B.\n");
			state = B;	
		}
		//HANDLES ALL POSIBILITIES WHILE BEING IN STATE D
		else if(state == D && toupper(ch[i]) == 'B')
		{
			printf("State: &(D, b) = F.\n");
			fprintf(write_fp, "State: &(D, b) = F.\n");
			state = F;
		}
		else if(state == D && toupper(ch[i]) == 'E')
		{
			printf("State: &(D, e) = D.\n");
			fprintf(write_fp, "State: &(D, e) = D.\n");
			state = D;
		}
		else if(state == D && toupper(ch[i]) == 'W')
		{
			printf("State: &(D, w) = C.\n");
			fprintf(write_fp, "State: &(D, w) = C.\n");
			state = C;
		}
		else if (state == D)
		{
			printf("State: D not e,w,b then B.\n");
			fprintf(write_fp, "State: D not e,w,b then B.\n");
			state = B;	
		}
		//HANDLES ALL POSIBILITIES WHILE BEING IN STATE E
		else if(state == E && toupper(ch[i]) == 'B')
		{
			printf("State: &(E, b) = G.\n");
			fprintf(write_fp, "State: &(E, b) = G.\n");
			state = G;
		}
		else if(state == E && toupper(ch[i]) == 'W')
		{
			printf("State: &(E, w) = C.\n");
			fprintf(write_fp, "State: &(E, w) = C.\n");
			state = C;
		}
		else if(state == E && toupper(ch[i]) == 'E')
		{
			printf("State: &(E, e) = D.\n");
			fprintf(write_fp, "State: &(E, e) = D.\n");
			state = D;
		}
		else if (state == E)
		{
			printf("State: D not e,w,b then B.\n");
			fprintf(write_fp, "State: D not e,w,b then B.\n");
			state = B;	
		}
		//HANDLES ALL POSIBILITIES WHILE BEING IN STATE F
		else if(state == F && toupper(ch[i]) == 'A')
		{
			printf("State: &(F, a) = H.\n");
			fprintf(write_fp, "State: &(F, a) = H.\n");
			state = H;
		}
		else if(state == F && toupper(ch[i]) == 'E')
		{
			printf("State: &(F, e) = D.\n");
			fprintf(write_fp, "State: &(F, e) = D.\n");
			state = D;
		}
		else if(state == F && toupper(ch[i]) == 'W')
		{
			printf("State: &(F, w) = C.\n");
			fprintf(write_fp, "State: &(F, w) = C.\n");
			state = C;
		}
		else if (state == F)
		{
			printf("State: F not e,w,a then B.\n");
			fprintf(write_fp, "State: F not e,w,a then B.\n");
			state = B;	
		}	
		//HANDLES ALL POSIBILITIES WHILE BEING IN STATE G
		else if(state == G && toupper(ch[i]) == 'A')
		{
			printf("State: &(G, a) = H.\n");
			fprintf(write_fp, "State: &(G, a) = H.\n");
			state = H;
		}
		else if(state == G && toupper(ch[i]) == 'E')
		{
			printf("State: &(G, e) = D.\n");
			fprintf(write_fp, "State: &(G, e) = D.\n");
			state = D;
		}
		else if(state == G && toupper(ch[i]) == 'W')
		{
			printf("State: &(G, w) = C.\n");
			fprintf(write_fp, "State: &(G, w) = C.\n");
			state = C;
		}
		else if (state == G)
		{
			printf("State: G not e,w,a then B.\n");
			fprintf(write_fp, "State: G not e,w,a then B.\n");
			state = B;	
		}
		//HANDLES ALL POSIBILITIES WHILE BEING IN STATE H
		else if(state == H && toupper(ch[i]) == 'Y')
		{
			printf("State: &(H, y) = I.\n");
			fprintf(write_fp, "State: &(H, y) = I.\n");
			state = I;
		}
		else if(state == H && toupper(ch[i]) == 'E')
		{
			printf("State: &(H, e) = D.\n");
			fprintf(write_fp, "State: &(H, e) = D.\n");
			state = D;
		}
		else if(state == H && toupper(ch[i]) == 'W')
		{
			printf("State: &(H, w) = C.\n");
			fprintf(write_fp, "State: &(H, w) = C.\n");
			state = C;
		}
		else if (state == H)
		{
			printf("State: H not e,w,y then B.\n");
			fprintf(write_fp, "State: H not e,w,y then B.\n");
			state = B;	
		}
		//HANDLES ALL POSIBILITIES WHILE BEING IN STATE I
		else if(state == I && toupper(ch[i]) == 'W')
		{
			printf("State: &(I, w) = C.\n");
			fprintf(write_fp, "State: &(I, w) = C.\n");
			state = C;
		}
		else if(state == I && toupper(ch[i]) == 'E')
		{
			printf("State: &(I, e) = D.\n");
			fprintf(write_fp, "State: &(I, e) = D.\n");
			state = D;
		}
		else if (state == I)
		{
			printf("State: I not e,w then B.\n");
			fprintf(write_fp, "State: I not e,w then B.\n");
			state = B;	
		}				
		//HANDLES FINAL STATES
		if(state == G && ch[i + 1] == '\0')
		{
			printf("String accepted.\n\n");
			fprintf(write_fp, "String accepted.\n\n");
			return true;
		}
		if(state == I && ch[i + 1] == '\0')
		{
			printf("String accepted.\n\n");
			fprintf(write_fp, "String accepted.\n\n");
			return true;
		}
		i++;
	}
	while(ch[i] != '\0');

	printf("String not accepted.\n\n");
	fprintf(write_fp, "String not accepted.\n\n");
	return false;
}

