#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define STR_LENGTH 51

int getString(int n, char string[n],  int first_ch);
int getStringFile(int n, char string[n],  int first_ch, FILE *read_fp);
bool automata(char *p, int mode);

int main (void)
{
	char string[STR_LENGTH];
	int first_ch, ch, i = 0, words = 0, count_ing = 0, option, mode, last_ch;
	FILE *write_fp, *read_fp;
	char read_file[51] = {' '};

	printf("AUTOMATA: Recognizing strings ending in ing.\n");
	for(;;)
	{
		printf("***1.-Read from the command-line.\n***2.-Read from a text file.\n***3.-Exit.\n");
		printf("Option: ");
		scanf(" %d", &option);
		system("cls");
		count_ing = 0;
		switch (option)
		{
			case 1:
				words = 0; 
				printf("Enter a text finishing with a point: ");
				for(;;)
				{
					if((first_ch = getchar()) == '.')
						break;
					last_ch = getString(STR_LENGTH, string, first_ch);               //OBTIENE UNA CADENA YA DEPURADA (SIN OTRA COSA QUE LETRAS)
					words += 1;
					if (words == 1)
						mode = 'w';
					else 
						mode = 'a';
					if(automata(string, mode))
						count_ing += 1;	
					if (last_ch == '.')
						break;
				}

				write_fp = fopen("Automata_record.txt", "a");
				printf("Number of words ending in ing: %d\n\n", count_ing);
				fprintf(write_fp, "Number of words ending in ing: %d\n\n", count_ing);
				fclose(write_fp);	
			break;

			case 2:
				words = 0;
				fflush(stdin);                              //SE ENCUENTRA AQUÍ DADO QUE EL BUFFER SE QUEDA CON EL '\n' QUE INGRESAMOS AL ELEGIR OPCIÓN
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

				while((first_ch = getc(read_fp)) != EOF)
				{
					getStringFile(STR_LENGTH, string, first_ch, read_fp);
					words += 1;
					if(words == 1)
						mode = 'w';
					else 
						mode = 'a';
					if(automata(string, mode))
						count_ing += 1;
				}
				fclose(read_fp);

				write_fp = fopen("Automata_record.txt", "a");
				printf("Number of words ending in ing: %d\n\n", count_ing);
				fprintf(write_fp, "Number of words ending in ing: %d\n", count_ing);
				fclose(write_fp);
			break;

			case 3: exit(EXIT_SUCCESS);
			break;
		}
	}
	return 0;
}


int getString(int n, char string[n], int first_ch)
{
	int ch, i = 0;

	if((first_ch != ' ') && ((first_ch >= 65 && first_ch <= 90) || (first_ch >= 97 && first_ch <= 122)))
		string[i++] = first_ch;	
	while(((ch = getchar()) != ' ') && ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) && i < n && ch != '.')
		string[i++] = ch;	
	string[i] = '\0';

	return ch;
}

int getStringFile(int n, char string[n], int first_ch, FILE *read_fp)
{
	int ch, i = 0;

	if( (first_ch != ' ') && ((first_ch >= 65 && first_ch <= 90) || (first_ch >= 97 && first_ch <= 122)) )
		string[i++] = first_ch;	
	while(((ch = getc(read_fp)) != ' ') && ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) && i < n && ch != EOF)
		string[i++] = ch;	
	string[i] = '\0';

	return i;
}

bool automata(char *p, int mode)
{
	int state = -1;
	bool accepted = false;
	FILE *fp;

	if (mode == 'w')
		fp = fopen("Automata_record.txt", "w");
	else 
		fp = fopen("Automata_record.txt", "a");
	printf("Word: %s\n", p);
	fprintf(fp, "Word: %s\n", p);
	if(*p != '\0')
	{
		printf("**State: QI.\n");
		fprintf(fp, "**State: QI.\n");
	}

	while(*p != '\0')                                      //RECORRE LA CADENA	
	{
		if((*p == 'i' || *p == 'I') && state == -1)			//SI ENTRA EN ESTE IF, SE ENCONTRARÁ EN EL ESTADO Q0
		{
			p++;
			state = 0;
			printf("**State: &(QI,i) = Q0.\n");
			fprintf(fp, "**State: &(QI,i) = Q0.\n");
		}
		if((*p == 'n' || *p == 'N') && state == 0)			//SI ENTRA EN ESTE IF, SE ENCONTRARÁ EN EL ESTADO Q1
		{
			p++;
			state = 1;
			printf("**State: &(Q0,n) = Q1.\n");	
			fprintf(fp, "**State: &(Q0,n) = Q1.\n");
		}
		if((*p == 'g' || *p == 'G') && state == 1)			//SI ENTRA EN ESTE ESTADO, SE ENCONTRARÁ EN EL ESTADO Q2 Y FINAL
		{
			p++;
			state = 2;
			printf("**State: &(Q1,g) = Q2.\n");
			fprintf(fp, "**State: &(Q1,g) = Q2.\n");
		}

		if(state == 2 && *p == '\0')						//SI ENTRA EN ESTE IF, SIGNIFICA QUE LA PALABRA HA SIDO ACEPTADA
		{
			printf("++Word accepted.\n\n");
			fprintf(fp, "++Word accepted.\n\n");
			accepted = true;
		}

		if((toupper(*p) != 'I') && state == -1  && *p != '\0')
			p++;

		if((toupper(*p) == 'I') && state == 0 && *p != '\0')
			state = -1;
		if((toupper(*p) != 'I') && state == 0 && *p != '\0')
			state = -1;

		if((toupper(*p) == 'I') && state == 1 && *p != '\0')
			state = 0;
		if((toupper(*p) != 'I') && state == 1 && *p != '\0')
			state = -1;

		if((toupper(*p) == 'I') && state == 2 && *p != '\0')
			state = 0;
		if((toupper(*p) != 'I') && state == 2 && *p != '\0')
			state = -1;

		if((state == -1 && toupper(*p) != 'I') || (state == 2 && toupper(*p) != 'I' && *p != '\0'))
		{
			printf("*+State: QI.\n");
			fprintf(fp, "*+State: QI.\n");
		}
		if(*p == '\0' && accepted == false)
		{
			printf("++Word not accepted.\n\n");
			fprintf(fp, "++Word not accepted.\n\n");
		}
	}
	fclose(fp);
	return accepted;
}