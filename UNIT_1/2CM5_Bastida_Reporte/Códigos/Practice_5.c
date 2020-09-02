#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>

#define BLOCK_LENGTH 100
#define STR_LENGTH 100
#define Q0 0
#define Q1 1
#define Q2 2
#define Q3 3
#define Q4 4
#define Q5 5
#define Q6 6
#define Q7 7
#define Q8 8
#define Q9 9
#define Q10 10

bool getBlock(char block[], int n, FILE *read_fp);
int getString(char block[], char string[]);
int acknowledge(char *p, FILE *write_fp);
bool automCopiar(char *p, FILE *write_fp);
bool automCorrupcion(char *p, FILE *write_fp);
bool automEngano(char *p, FILE *write_fp);
bool automEnganar(char *p, FILE *write_fp);
bool automFalso(char *p, FILE *write_fp);
bool automFalsificar(char *p, FILE *write_fp);
bool automMentir(char *p, FILE *write_fp);
bool automRobar(char *p, FILE *write_fp);
bool automViolencia(char *p, FILE *write_fp);
bool automTraficar(char *p, FILE *write_fp);

int block_ch = 0;

int main (void)
{
	int option = 0, i = 0, ch, characters_read = 0, last_ch = ' ', on = 1;
	char block[BLOCK_LENGTH + 1], read_file[50] = {' '}, string[STR_LENGTH + 1];
	bool keep_reading = true;
	FILE *read_fp, *write_fp;
	int copiar = 0, corrupcion = 0, engano = 0, enganar = 0, falso = 0, falsificar = 0, mentir = 0, robar = 0, violencia = 0, traficar = 0;  

	srand((unsigned) time (NULL));

	printf("AUTOMATA: PROTOCOL FOR SENDING DATA.\n");
	for(;;)
	{
		printf("|+|+|+|+|+|+|+|+|+|+|MENU|+|+|+|+|+|+|+|+|+|+|+|\n1.-Always ON.\n2.-Simulation.\n3.-Exit.\n");
		scanf(" %d", &option);
		system("cls");
		switch(option)
		{
			case 1:
				i = 0;
				fflush(stdin);
				printf("Enter name of the file: ");
				while((ch = getchar()) != '\n')
					read_file[i++] = ch;
				if ((read_fp = fopen(read_file, "rb")) == NULL)
				{
					fprintf(stderr, "Can't open: %s\n", read_file);
					break;
				}
				if ((write_fp = fopen("Automata_record.txt", "w")) == NULL)
					fprintf(stderr, "Can't write to file.\n");
				while(keep_reading)
				{
					printf("\n|+|+|+|+|+|+|+|I'M ON|+|+|+|+|+|+|+|.\n");
					fprintf(write_fp, "\n|+|+|+|+|+|+|+|I'M ON|+|+|+|+|+|+|+|.\n");	
					keep_reading = getBlock(block, BLOCK_LENGTH, read_fp);
					printf("BLOCK READ: %s\n\n", block);
					fprintf(write_fp, "BLOCK READ: %s\n\n", block);
					Sleep(3000);
					while(getString(block, string) != '\0')
					{
						switch(acknowledge(string, write_fp))
						{
							case 1:
								copiar += 1;
							break;
							case 2:
								corrupcion += 1;
							break;
							case 3:
								engano += 1;
							break;
							case 4:
								enganar += 1;
							break;
							case 5:
								falso += 1;
							break;
							case 6:
								falsificar += 1;
							break;
							case 7:
								mentir += 1;
							break;
							case 8:
								robar += 1;
							break;
							case 9:
								violencia += 1;
							break;
							case 10:
								traficar += 1;
							break;
							case 11:
								printf("The word %s is not suspicious.\n\n", string);
								fprintf(write_fp, "The word %s is not suspicious.\n\n", string);
							break;
							default:
								printf("There was an error.\n");
								fprintf(write_fp, "There was an error.\n");
							break;
						}
					}
					block_ch = 0;
				}
				keep_reading = true;
				fclose(read_fp);
				printf("SAW COPIAR: %d TIMES.\nSAW CORRUPCION: %d TIMES.\nSAW ENGANO: %d TIMES.\nSAW ENGANAR: %d TIMES.\nSAW FALSO: %d TIMES.\nSAW FALSIFICAR: %d TIMES.\nSAW MENTIR: %d TIMES.\nSAW ROBAR: %d TIMES.\nSAW VIOLENCIA: %d TIMES.\nSAW TRAFICAR: %d TIMES.\n\n", copiar, corrupcion, engano, enganar, falso, falsificar, mentir, robar, violencia, traficar);
				fprintf(write_fp, "SAW COPIAR: %d TIMES.\nSAW CORRUPCION: %d TIMES.\nSAW ENGANO: %d TIMES.\nSAW ENGANAR: %d TIMES.\nSAW FALSO: %d TIMES.\nSAW FALSIFICAR: %d TIMES.\nSAW MENTIR: %d TIMES.\nSAW ROBAR: %d TIMES.\nSAW VIOLENCIA: %d TIMES.\nSAW TRAFICAR: %d TIMES.\n\n", copiar, corrupcion, engano, enganar, falso, falsificar, mentir, robar, violencia, traficar);
				fclose(write_fp);
				copiar = 0; corrupcion = 0; engano = 0; enganar = 0; falso = 0; falsificar = 0; mentir = 0; robar = 0; violencia = 0; traficar = 0;
			break;
			case 2:
				i = 0;
				fflush(stdin);
				printf("Enter name of the file: ");
				while((ch = getchar()) != '\n')
					read_file[i++] = ch;
				if ((read_fp = fopen(read_file, "rb")) == NULL)
				{
					fprintf(stderr, "Can't open: %s\n", read_file);
					break;
				}
				if ((write_fp = fopen("Automata_record.txt", "w")) == NULL)
					fprintf(stderr, "Can't write to file.\n");
				while(keep_reading && on == 1)
				{
					on = rand() % 2;
					printf("\n|+|+|+|+|+|+|+|I'M ON|+|+|+|+|+|+|+|.\n");
					fprintf(write_fp, "\n|+|+|+|+|+|+|+|I'M ON|+|+|+|+|+|+|+|.\n");	
					keep_reading = getBlock(block, BLOCK_LENGTH, read_fp);
					printf("BLOCK READ: %s\n\n", block);
					fprintf(write_fp, "BLOCK READ: %s\n\n", block);
					Sleep(3000);
					while((ch = getString(block, string)) != '\0')
					{
						switch(acknowledge(string, write_fp))
						{
							case 1:
								copiar += 1;
							break;
							case 2:
								corrupcion += 1;
							break;
							case 3:
								engano += 1;
							break;
							case 4:
								enganar += 1;
							break;
							case 5:
								falso += 1;
							break;
							case 6:
								falsificar += 1;
							break;
							case 7:
								mentir += 1;
							break;
							case 8:
								robar += 1;
							break;
							case 9:
								violencia += 1;
							break;
							case 10:
								traficar += 1;
							break;
							case 11:
								printf("The word %s is not suspicious.\n\n", string);
								fprintf(write_fp, "The word %s is not suspicious.\n\n", string);
							break;
							default:
								printf("There was an error.\n");
								fprintf(write_fp, "There was an error.\n");
							break;
						}
					}
					block_ch = 0;
				}
				on = 1;
				keep_reading = true;
				fclose(read_fp);
				printf("\n|+|+|+|+|+|+|+|I'M OF|+|+|+|+|+|+|+|.\n");
				fprintf(write_fp, "\n|+|+|+|+|+|+|+|I'M OF|+|+|+|+|+|+|+|.\n");	
				printf("SAW COPIAR: %d TIMES.\nSAW CORRUPCION: %d TIMES.\nSAW ENGANO: %d TIMES.\nSAW ENGANAR: %d TIMES.\nSAW FALSO: %d TIMES.\nSAW FALSIFICAR: %d TIMES.\nSAW MENTIR: %d TIMES.\nSAW ROBAR: %d TIMES.\nSAW VIOLENCIA: %d TIMES.\nSAW TRAFICAR: %d TIMES.\n\n", copiar, corrupcion, engano, enganar, falso, falsificar, mentir, robar, violencia, traficar);
				fprintf(write_fp, "SAW COPIAR: %d TIMES.\nSAW CORRUPCION: %d TIMES.\nSAW ENGANO: %d TIMES.\nSAW ENGANAR: %d TIMES.\nSAW FALSO: %d TIMES.\nSAW FALSIFICAR: %d TIMES.\nSAW MENTIR: %d TIMES.\nSAW ROBAR: %d TIMES.\nSAW VIOLENCIA: %d TIMES.\nSAW TRAFICAR: %d TIMES.\n\n", copiar, corrupcion, engano, enganar, falso, falsificar, mentir, robar, violencia, traficar);
				fclose(write_fp);
				copiar = 0; corrupcion = 0; engano = 0; enganar = 0; falso = 0; falsificar = 0; mentir = 0; robar = 0; violencia = 0; traficar = 0;
			break;
			case 3:
				exit(EXIT_SUCCESS);
			break;
			default: 
				printf("Choose a correct option.\n");
			break;
		}	
	}
	return 0;
}

bool getBlock(char block[], int n, FILE *read_fp)
{
	int ch, i = 0;
	long file_pos;

	while(i <= n)
	{
		ch = getc(read_fp);
		if(ch == EOF)
		{
			block[i] = '\0';
			return false;
		}
		else if (ch == ' ')
			file_pos = ftell(read_fp);
		block[i++] = ch;
	}
	if ((ch = getc(read_fp)) != ' ')
		fseek(read_fp, file_pos, SEEK_SET);
	block[i] = '\0';

	return true;
}

int getString(char block[], char string[])
{
	int i = 0;

	while(block[block_ch] != ' ' && ((block[block_ch] >= 65 && block[block_ch] <= 90) || (block[block_ch] >= 97 && block[block_ch] <= 122)) && block[block_ch] != '\0')
		string[i++] = block[block_ch++];

	string[i] = '\0';
	return block[block_ch++];
}

int acknowledge(char *p, FILE *write_fp)
{
	if (automCopiar(p, write_fp))
		return 1;
	else if (automCorrupcion(p, write_fp))
		return 2;
	else if (automEngano(p, write_fp))
		return 3;
	else if (automEnganar(p, write_fp))
		return 4;
	else if (automFalso(p, write_fp))
		return 5;
	else if (automFalsificar(p, write_fp))
		return 6;
	else if (automMentir(p, write_fp))
		return 7;
	else if (automRobar(p, write_fp))
		return 8;
	else if (automViolencia(p, write_fp))
		return 9;
	else if (automTraficar(p, write_fp))
		return 10;
	else
		return 11;
}

bool automCopiar(char *p, FILE *write_fp)
{
	int state = Q0;
	char *word = p;

	printf("|+|+|+|AUTOMATA: COPIAR\nWord: %s\n", p);
	printf("State: Q0\n");
	fprintf(write_fp, "|+|+|+|AUTOMATA: COPIAR\nWord: %s\n", p);
	fprintf(write_fp, "State: Q0\n");
	while(*p != '\0')
	{
		//AUTOMATA CORE
		if(toupper(*p) == 'C' && state == Q0)
		{
			state = Q1;
			printf("State: &(Q0, c) = Q1.\n");
			fprintf(write_fp, "State: &(Q0, c) = Q1.\n");
		}
		else if(toupper(*p) == 'O' && state == Q1)
		{
			state = Q2;
			printf("State: &(Q1, o) = Q2.\n");
			fprintf(write_fp, "State: &(Q1, o) = Q2.\n");
		}
		else if(toupper(*p) == 'P' && state == Q2)
		{
			state = Q3;
			printf("State: &(Q2, p) = Q3.\n");
			fprintf(write_fp, "State: &(Q2, p) = Q3.\n");
		}
		else if(toupper(*p) == 'I' && state == Q3)
		{
			state = Q4;
			printf("State: &(Q3, i) = Q4.\n");
			fprintf(write_fp, "State: &(Q3, i) = Q4.\n");
		}
		else if(toupper(*p) == 'A' && state == Q4)
		{
			state = Q5;
			printf("State: &(Q4, a) = Q5.\n");
			fprintf(write_fp, "State: &(Q4, a) = Q5.\n");
		}
		else if(toupper(*p) == 'R' && state == Q5)
		{
			state = Q6;
			printf("State: &(Q5, r) = Q6.\n");
			fprintf(write_fp, "State: &(Q5, r) = Q6.\n");
		}
		
		//FINAL STATE
		if(state == Q6)
		{
			printf("|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			fprintf(write_fp, "|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			return true;
		}

		p++;
	}
	return false;
}

bool automCorrupcion(char *p, FILE *write_fp)
{
	int state = Q0;
	char *word = p;

	printf("|+|+|+|AUTOMATA: CORRUPCION\nWord: %s\n", p);
	printf("State: Q0\n");
	fprintf(write_fp, "|+|+|+|AUTOMATA: CORRUPCION\nWord: %s\n", p);
	fprintf(write_fp, "State: Q0\n");
	while(*p != '\0')
	{
		//AUTOMATA CORE
		if(toupper(*p) == 'C' && state == Q0)
		{
			state = Q1;
			printf("State: &(Q0, c) = Q1.\n");
			fprintf(write_fp, "State: &(Q0, c) = Q1.\n");
		}
		else if(toupper(*p) == 'O' && state == Q1)
		{
			state = Q2;
			printf("State: &(Q1, o) = Q2.\n");
			fprintf(write_fp, "State: &(Q1, o) = Q2.\n");
		}
		else if(toupper(*p) == 'R' && state == Q2)
		{
			state = Q3;
			printf("State: &(Q2, r) = Q3.\n");
			fprintf(write_fp, "State: &(Q2, r) = Q3.\n");
		}
		else if(toupper(*p) == 'R' && state == Q3)
		{
			state = Q4;
			printf("State: &(Q3, r) = Q4.\n");
			fprintf(write_fp, "State: &(Q3, r) = Q4.\n");
		}
		else if(toupper(*p) == 'U' && state == Q4)
		{
			state = Q5;
			printf("State: &(Q4, u) = Q5.\n");
			fprintf(write_fp, "State: &(Q4, u) = Q5.\n");
		}
		else if(toupper(*p) == 'P' && state == Q5)
		{
			state = Q6;
			printf("State: &(Q5, p) = Q6.\n");
			fprintf(write_fp, "State: &(Q5, p) = Q6.\n");
		}
		else if(toupper(*p) == 'C' && state == Q6)
		{
			state = Q7;
			printf("State: &(Q6, c) = Q7.\n");
			fprintf(write_fp, "State: &(Q6, c) = Q7.\n");
		}
		else if(toupper(*p) == 'I' && state == Q7)
		{
			state = Q8;
			printf("State: &(Q7, i) = Q8.\n");
			fprintf(write_fp, "State: &(Q7, i) = Q8.\n");
		}
		else if(toupper(*p) == 'O' && state == Q8)
		{
			state = Q9;
			printf("State: &(Q8, o) = Q9.\n");
			fprintf(write_fp, "State: &(Q8, o) = Q9.\n");
		}
		else if(toupper(*p) == 'N' && state == Q9)
		{
			state = Q10;
			printf("State: &(Q9, n) = Q10.\n");
			fprintf(write_fp, "State: &(Q9, n) = Q10.\n");
		}	
		//FINAL STATE
		if(state == Q10)
		{
			printf("|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			fprintf(write_fp, "|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			return true;
		}

		p++;
	}
	return false;
}

bool automEngano(char *p, FILE *write_fp)
{
	int state = Q0;
	char *word = p;

	printf("|+|+|+|AUTOMATA: ENGANO\nWord: %s\n", p);
	printf("State: Q0\n");
	fprintf(write_fp, "|+|+|+|AUTOMATA: ENGANO\nWord: %s\n", p);
	fprintf(write_fp, "State: Q0\n");
	while(*p != '\0')
	{
		//AUTOMATA CORE
		if(toupper(*p) == 'E' && state == Q0)
		{
			state = Q1;
			printf("State: &(Q0, e) = Q1.\n");
			fprintf(write_fp, "State: &(Q0, e) = Q1.\n");
		}
		else if(toupper(*p) == 'N' && state == Q1)
		{
			state = Q2;
			printf("State: &(Q1, n) = Q2.\n");
			fprintf(write_fp, "State: &(Q1, n) = Q2.\n");
		}
		else if(toupper(*p) == 'G' && state == Q2)
		{
			state = Q3;
			printf("State: &(Q2, g) = Q3.\n");
			fprintf(write_fp, "State: &(Q2, g) = Q3.\n");
		}
		else if(toupper(*p) == 'A' && state == Q3)
		{
			state = Q4;
			printf("State: &(Q3, a) = Q4.\n");
			fprintf(write_fp, "State: &(Q3, a) = Q4.\n");
		}
		else if(toupper(*p) == 'N' && state == Q4)
		{
			state = Q5;
			printf("State: &(Q4, n) = Q5.\n");
			fprintf(write_fp, "State: &(Q4, n) = Q5.\n");
		}
		else if(toupper(*p) == 'O' && state == Q5)
		{
			state = Q6;
			printf("State: &(Q5, o) = Q6.\n");
			fprintf(write_fp, "State: &(Q5, o) = Q6.\n");
		}
		//FINAL STATE
		if(state == Q6)
		{
			printf("|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			fprintf(write_fp, "|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			return true;
		}

		p++;
	}
	return false;
}

bool automEnganar(char *p, FILE *write_fp)
{
	int state = Q0;
	char *word = p;

	printf("|+|+|+|AUTOMATA: ENGANAR\nWord: %s\n", p);
	printf("State: Q0\n");
	fprintf(write_fp, "|+|+|+|AUTOMATA: ENGANAR\nWord: %s\n", p);
	fprintf(write_fp, "State: Q0\n");
	while(*p != '\0')
	{
		//AUTOMATA CORE
		if(toupper(*p) == 'E' && state == Q0)
		{
			state = Q1;
			printf("State: &(Q0, e) = Q1.\n");
			fprintf(write_fp, "State: &(Q0, e) = Q1.\n");
		}
		else if(toupper(*p) == 'N' && state == Q1)
		{
			state = Q2;
			printf("State: &(Q1, n) = Q2.\n");
			fprintf(write_fp, "State: &(Q1, n) = Q2.\n");
		}
		else if(toupper(*p) == 'G' && state == Q2)
		{
			state = Q3;
			printf("State: &(Q2, g) = Q3.\n");
			fprintf(write_fp, "State: &(Q2, g) = Q3.\n");
		}
		else if(toupper(*p) == 'A' && state == Q3)
		{
			state = Q4;
			printf("State: &(Q3, a) = Q4.\n");
			fprintf(write_fp, "State: &(Q3, a) = Q4.\n");
		}
		else if(toupper(*p) == 'N' && state == Q4)
		{
			state = Q5;
			printf("State: &(Q4, n) = Q5.\n");
			fprintf(write_fp, "State: &(Q4, n) = Q5.\n");
		}
		else if(toupper(*p) == 'A' && state == Q5)
		{
			state = Q6;
			printf("State: &(Q5, a) = Q6.\n");
			fprintf(write_fp, "State: &(Q5, a) = Q6.\n");
		}
		else if(toupper(*p) == 'R' && state == Q6)
		{
			state = Q7;
			printf("State: &(Q6, r) = Q7.\n");
			fprintf(write_fp, "State: &(Q6, r) = Q7.\n");
		}
		//FINAL STATE
		if(state == Q7)
		{
			printf("|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			fprintf(write_fp, "|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			return true;
		}

		p++;
	}
	return false;
}

bool automFalso(char *p, FILE *write_fp)
{
	int state = Q0;
	char *word = p;

	printf("|+|+|+|AUTOMATA: FALSO\nWord: %s\n", p);
	printf("State: Q0\n");
	fprintf(write_fp, "|+|+|+|AUTOMATA: FALSO\nWord: %s\n", p);
	fprintf(write_fp, "State: Q0\n");
	while(*p != '\0')
	{
		//AUTOMATA CORE
		if(toupper(*p) == 'F' && state == Q0)
		{
			state = Q1;
			printf("State: &(Q0, f) = Q1.\n");
			fprintf(write_fp, "State: &(Q0, f) = Q1.\n");
		}
		else if(toupper(*p) == 'A' && state == Q1)
		{
			state = Q2;
			printf("State: &(Q1, a) = Q2.\n");
			fprintf(write_fp, "State: &(Q1, a) = Q2.\n");
		}
		else if(toupper(*p) == 'L' && state == Q2)
		{
			state = Q3;
			printf("State: &(Q2, l) = Q3.\n");
			fprintf(write_fp, "State: &(Q2, l) = Q3.\n");
		}
		else if(toupper(*p) == 'S' && state == Q3)
		{
			state = Q4;
			printf("State: &(Q3, s) = Q4.\n");
			fprintf(write_fp, "State: &(Q3, s) = Q4.\n");
		}
		else if(toupper(*p) == 'O' && state == Q4)
		{
			state = Q5;
			printf("State: &(Q4, o) = Q5.\n");
			fprintf(write_fp, "State: &(Q4, o) = Q5.\n");
		}
		//FINAL STATE
		if(state == Q5)
		{
			printf("|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			fprintf(write_fp, "|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			return true;
		}

		p++;
	}
	return false;
}

bool automFalsificar(char *p, FILE *write_fp)
{
	int state = Q0;
	char *word = p;

	printf("|+|+|+|AUTOMATA: FALSIFICAR\nWord: %s\n", p);
	printf("State: Q0\n");
	fprintf(write_fp, "|+|+|+|AUTOMATA: FALSIFICAR\nWord: %s\n", p);
	fprintf(write_fp, "State: Q0\n");
	while(*p != '\0')
	{
		//AUTOMATA CORE
		if(toupper(*p) == 'F' && state == Q0)
		{
			state = Q1;
			printf("State: &(Q0, f) = Q1.\n");
			fprintf(write_fp, "State: &(Q0, f) = Q1.\n");
		}
		else if(toupper(*p) == 'A' && state == Q1)
		{
			state = Q2;
			printf("State: &(Q1, a) = Q2.\n");
			fprintf(write_fp, "State: &(Q1, a) = Q2.\n");
		}
		else if(toupper(*p) == 'L' && state == Q2)
		{
			state = Q3;
			printf("State: &(Q2, l) = Q3.\n");
			fprintf(write_fp, "State: &(Q2, l) = Q3.\n");
		}
		else if(toupper(*p) == 'S' && state == Q3)
		{
			state = Q4;
			printf("State: &(Q3, s) = Q4.\n");
			fprintf(write_fp, "State: &(Q3, s) = Q4.\n");
		}
		else if(toupper(*p) == 'I' && state == Q4)
		{
			state = Q5;
			printf("State: &(Q4, i) = Q5.\n");
			fprintf(write_fp, "State: &(Q4, i) = Q5.\n");
		}
		else if(toupper(*p) == 'F' && state == Q5)
		{
			state = Q6;
			printf("State: &(Q5, f) = Q6.\n");
			fprintf(write_fp, "State: &(Q5, f) = Q6.\n");
		}
		else if(toupper(*p) == 'I' && state == Q6)
		{
			state = Q7;
			printf("State: &(Q6, i) = Q7.\n");
			fprintf(write_fp, "State: &(Q6, i) = Q7.\n");
		}
		else if(toupper(*p) == 'C' && state == Q7)
		{
			state = Q8;
			printf("State: &(Q7, c) = Q8.\n");
			fprintf(write_fp, "State: &(Q7, c) = Q8.\n");
		}
		else if(toupper(*p) == 'A' && state == Q8)
		{
			state = Q9;
			printf("State: &(Q8, a) = Q9.\n");
			fprintf(write_fp, "State: &(Q8, a) = Q9.\n");
		}
		else if(toupper(*p) == 'R' && state == Q9)
		{
			state = Q10;
			printf("State: &(Q9, r) = Q10.\n");
			fprintf(write_fp, "State: &(Q9, r) = Q10.\n");
		}
		//FINAL STATE
		if(state == Q10)
		{
			printf("|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			fprintf(write_fp, "|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			return true;
		}

		p++;
	}
	return false;
}

bool automMentir(char *p, FILE *write_fp)
{
	int state = Q0;
	char *word = p;

	printf("|+|+|+|AUTOMATA: MENTIR\nWord: %s\n", p);
	printf("State: Q0\n");
	fprintf(write_fp, "|+|+|+|AUTOMATA: MENTIR\nWord: %s\n", p);
	fprintf(write_fp, "State: Q0\n");
	while(*p != '\0')
	{
		//AUTOMATA CORE
		if(toupper(*p) == 'M' && state == Q0)
		{
			state = Q1;
			printf("State: &(Q0, m) = Q1.\n");
			fprintf(write_fp, "State: &(Q0, m) = Q1.\n");
		}
		else if(toupper(*p) == 'E' && state == Q1)
		{
			state = Q2;
			printf("State: &(Q1, e) = Q2.\n");
			fprintf(write_fp, "State: &(Q1, e) = Q2.\n");
		}
		else if(toupper(*p) == 'N' && state == Q2)
		{
			state = Q3;
			printf("State: &(Q2, n) = Q3.\n");
			fprintf(write_fp, "State: &(Q2, n) = Q3.\n");
		}
		else if(toupper(*p) == 'T' && state == Q3)
		{
			state = Q4;
			printf("State: &(Q3, t) = Q4.\n");
			fprintf(write_fp, "State: &(Q3, t) = Q4.\n");
		}
		else if(toupper(*p) == 'I' && state == Q4)
		{
			state = Q5;
			printf("State: &(Q4, i) = Q5.\n");
			fprintf(write_fp, "State: &(Q4, i) = Q5.\n");
		}
		else if(toupper(*p) == 'R' && state == Q5)
		{
			state = Q6;
			printf("State: &(Q5, r) = Q6.\n");
			fprintf(write_fp, "State: &(Q5, r) = Q6.\n");
		}
		//FINAL STATE
		if(state == Q6)
		{
			printf("|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			fprintf(write_fp, "|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			return true;
		}

		p++;
	}
	return false;
}

bool automRobar(char *p, FILE *write_fp)
{
	int state = Q0;
	char *word = p;

	printf("|+|+|+|AUTOMATA: ROBAR\nWord: %s\n", p);
	printf("State: Q0\n");
	fprintf(write_fp, "|+|+|+|AUTOMATA: ROBAR\nWord: %s\n", p);
	fprintf(write_fp, "State: Q0\n");
	while(*p != '\0')
	{
		//AUTOMATA CORE
		if(toupper(*p) == 'R' && state == Q0)
		{
			state = Q1;
			printf("State: &(Q0, r) = Q1.\n");
			fprintf(write_fp, "State: &(Q0, r) = Q1.\n");
		}
		else if(toupper(*p) == 'O' && state == Q1)
		{
			state = Q2;
			printf("State: &(Q1, o) = Q2.\n");
			fprintf(write_fp, "State: &(Q1, o) = Q2.\n");
		}
		else if(toupper(*p) == 'B' && state == Q2)
		{
			state = Q3;
			printf("State: &(Q2, b) = Q3.\n");
			fprintf(write_fp, "State: &(Q2, b) = Q3.\n");
		}
		else if(toupper(*p) == 'A' && state == Q3)
		{
			state = Q4;
			printf("State: &(Q3, a) = Q4.\n");
			fprintf(write_fp, "State: &(Q3, a) = Q4.\n");
		}
		else if(toupper(*p) == 'R' && state == Q4)
		{
			state = Q5;
			printf("State: &(Q4, r) = Q5.\n");
			fprintf(write_fp, "State: &(Q4, r) = Q5.\n");
		}
		//FINAL STATE
		if(state == Q5)
		{
			printf("|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			fprintf(write_fp, "|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			return true;
		}

		p++;
	}
	return false;
}

bool automViolencia(char *p, FILE *write_fp)
{
	int state = Q0;
	char *word = p;

	printf("|+|+|+|AUTOMATA: VIOLENCIA\nWord: %s\n", p);
	printf("State: Q0\n");
	fprintf(write_fp, "|+|+|+|AUTOMATA: VIOLENCIA\nWord: %s\n", p);
	fprintf(write_fp, "State: Q0\n");
	while(*p != '\0')
	{
		//AUTOMATA CORE
		if(toupper(*p) == 'V' && state == Q0)
		{
			state = Q1;
			printf("State: &(Q0, v) = Q1.\n");
			fprintf(write_fp, "State: &(Q0, v) = Q1.\n");
		}
		else if(toupper(*p) == 'I' && state == Q1)
		{
			state = Q2;
			printf("State: &(Q1, i) = Q2.\n");
			fprintf(write_fp, "State: &(Q1, i) = Q2.\n");
		}
		else if(toupper(*p) == 'O' && state == Q2)
		{
			state = Q3;
			printf("State: &(Q2, o) = Q3.\n");
			fprintf(write_fp, "State: &(Q2, o) = Q3.\n");
		}
		else if(toupper(*p) == 'L' && state == Q3)
		{
			state = Q4;
			printf("State: &(Q3, l) = Q4.\n");
			fprintf(write_fp, "State: &(Q3, l) = Q4.\n");
		}
		else if(toupper(*p) == 'E' && state == Q4)
		{
			state = Q5;
			printf("State: &(Q4, e) = Q5.\n");
			fprintf(write_fp, "State: &(Q4, e) = Q5.\n");
		}
		else if(toupper(*p) == 'N' && state == Q5)
		{
			state = Q6;
			printf("State: &(Q5, n) = Q6.\n");
			fprintf(write_fp, "State: &(Q5, n) = Q6.\n");
		}
		else if(toupper(*p) == 'C' && state == Q6)
		{
			state = Q7;
			printf("State: &(Q6, c) = Q7.\n");
			fprintf(write_fp, "State: &(Q6, c) = Q7.\n");
		}
		else if(toupper(*p) == 'I' && state == Q7)
		{
			state = Q8;
			printf("State: &(Q7, i) = Q8.\n");
			fprintf(write_fp, "State: &(Q7, i) = Q8.\n");
		}
		else if(toupper(*p) == 'A' && state == Q8)
		{
			state = Q9;
			printf("State: &(Q8, a) = Q9.\n");
			fprintf(write_fp, "State: &(Q8, a) = Q9.\n");
		}
		//FINAL STATE
		if(state == Q9)
		{
			printf("|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			fprintf(write_fp, "|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			return true;
		}

		p++;
	}
	return false;
}

bool automTraficar(char *p, FILE *write_fp)
{
	int state = Q0;
	char *word = p;

	printf("|+|+|+|AUTOMATA: TRAFICAR\nWord: %s\n", p);
	printf("State: Q0\n");
	fprintf(write_fp, "|+|+|+|AUTOMATA: TRAFICAR\nWord: %s\n", p);
	fprintf(write_fp, "State: Q0\n");
	while(*p != '\0')
	{
		//AUTOMATA CORE
		if(toupper(*p) == 'T' && state == Q0)
		{
			state = Q1;
			printf("State: &(Q0, t) = Q1.\n");
			fprintf(write_fp, "State: &(Q0, t) = Q1.\n");
		}
		else if(toupper(*p) == 'R' && state == Q1)
		{
			state = Q2;
			printf("State: &(Q1, r) = Q2.\n");
			fprintf(write_fp, "State: &(Q1, r) = Q2.\n");
		}
		else if(toupper(*p) == 'A' && state == Q2)
		{
			state = Q3;
			printf("State: &(Q2, a) = Q3.\n");
			fprintf(write_fp, "State: &(Q2, a) = Q3.\n");
		}
		else if(toupper(*p) == 'F' && state == Q3)
		{
			state = Q4;
			printf("State: &(Q3, f) = Q4.\n");
			fprintf(write_fp, "State: &(Q3, f) = Q4.\n");
		}
		else if(toupper(*p) == 'I' && state == Q4)
		{
			state = Q5;
			printf("State: &(Q4, i) = Q5.\n");
			fprintf(write_fp, "State: &(Q4, i) = Q5.\n");
		}
		else if(toupper(*p) == 'C' && state == Q5)
		{
			state = Q6;
			printf("State: &(Q5, c) = Q6.\n");
			fprintf(write_fp, "State: &(Q5, c) = Q6.\n");
		}
		else if(toupper(*p) == 'A' && state == Q6)
		{
			state = Q7;
			printf("State: &(Q6, a) = Q7.\n");
			fprintf(write_fp, "State: &(Q6, a) = Q7.\n");
		}	
		else if(toupper(*p) == 'R' && state == Q7)
		{
			state = Q8;
			printf("State: &(Q7, r) = Q8.\n");
			fprintf(write_fp, "State: &(Q7, r) = Q8.\n");
		}	
		//FINAL STATE
		if(state == Q8)
		{
			printf("|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			fprintf(write_fp, "|+|+|+|+|+|SUSPICIOUS WORD: %s\n\n", word);
			return true;
		}

		p++;
	}
	return false;
}
















































