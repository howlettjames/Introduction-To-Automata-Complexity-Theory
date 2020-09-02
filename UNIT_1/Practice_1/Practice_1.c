#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void print(int power, char alphabet[], int length_alphabet)
{
	int w, x, y, z, v;
	FILE *fp;
	if((fp = fopen("LenguajePotencia.txt", "w")) != NULL)
	{
		for(v = 0; v <= power; v++) //CONTROLA EL NUMERO DE ALFABETOS SEGÚN LA POTENCIA
		{              
			printf("S^%d = {", v);
			fprintf(fp,"S^%d = {", v);
			for(w = 0; w <= v; w++)           //CONTROLA EL NÚMERO DE CADENAS DE LONGITUD V POR ALFABETO
			{				
				if(w == 0)
				{
					printf("e");
					fprintf(fp,"e");
				}
				for(x = 0; x < pow(length_alphabet, w); x++)    //CONTROLA EL NÚMERO DE CADENAS SEGUN LA POTENCIA
				{  
					char *array;
					int i, b;
					array = (char *)malloc(w * sizeof(char));
					b = x;
					for(i = 0; i < w ; i++)                   //CONTROLA EL NÚMERO DE SÍMBOLOS POR CADENA Y LOS ACOMODA  
					{					
						if(b == 1) 
							array[i] = alphabet[b];
						else 
							array[i] = alphabet[b % length_alphabet];
						b = b / length_alphabet;
					}
					for(i = (w - 1); i >= 0; i--)          //IMPRIME SÍMBOLO POR SÍMBOLO LA CADENA YA ACOMODADA
					{				
						printf("%c", array[i]);
						fprintf(fp,"%c", array[i]);
					}
					if(x == (pow(length_alphabet, w) - 1));		//SI ENTRA AL ELSE SIGNIFICA QUE HAY CADENAS POR IMPRIMIR DE LA MISMA POTENCIA
					else
					{
						printf(",");
						fprintf(fp,",");
					}
				}
				if(v == w);
				else                                      //SI ENTRA AL ELSE SIGNIFICA QUE FALTAN CADENAS POR IMPRIMIR PERO DE LA SIG POTENCIA
				{											
					printf(",");
					fprintf(fp,",");
				}
			}
			printf("}\n");
			fprintf(fp,"}\n");
		}
	fclose(fp);
	}
}

void Set(int power, int length_alphabet)
{
	FILE *fp;

	if( (fp = fopen("LenguajePotencia.txt", "a")) != NULL)
	{
		printf("El numero de palabras de longitud 'k' es de:\n");
		fprintf(fp,"El numero de palabras de longitud 'k' es de:\n");
		printf("%d^%d\n", length_alphabet, power);
		fprintf(fp,"%d^%d\n", length_alphabet, power);
	}
}

void Universe(int power, int length_alphabet)
{
	FILE *fp;

	if( (fp = fopen("LenguajePotencia.txt","a")) != NULL)
	{
		printf("El numero de palabras en el universo de longitud 'k' es de:\n");
		fprintf(fp,"El numero de palabras en el universo de longitud 'k' es de:\n");
		int i;
		for(i = 0; i <= power; i++)
		{
		if(i == power)
		{
		printf("%d^%d", length_alphabet, i);
		fprintf(fp,"%d^%d", length_alphabet, i);
		printf("\n");
		fprintf(fp,"\n");
		}
		else
		{
		printf("%d^%d + ", length_alphabet, i);
		fprintf(fp,"%d^%d + ", length_alphabet, i);
		}
		}
	}
}

int main(void)
{
	int option, power, i = 0;
	option = 1;
	while(option > 0 && option < 3)
	{
		printf("MENU.\n");
		printf("Programa que calcula los conjuntos potencia, desde la potencia 0 hasta la potencia 1000.\n");
		printf("Opciones.\n");
		printf("1.- Ingresar potencia.\n");
		printf("2.- Potencia Random.\n");
		printf("3.- Salir.\n");

		printf("Opcion: ");
		scanf("%d", &option);

		system("cls");

		switch(option)
		{
		case 1:
		printf("Ingrese la potencia para el conjunto potencia.\n");
		printf("Potencia: ");
		scanf("%d", &power);

		int option2 = 1;
		while(option2 >= 1 && option2 <= 3)
		{
		system("cls");
		printf("Opciones.\n");
		printf("1.- Ingresar los caracteres del alfabeto.\n");
		printf("2.- Utilizar alfabeto de '0' y '1'.\n");
		printf("3.- Salir.\n");

		printf("Opcion: ");
		scanf("%d", &option2);

		if(option2 == 3)
		{
		system("cls");
		}

		switch(option2)
		{
		case 1:
		{
		system("cls");
		int n_characters;
		printf("Ingrese la cantidad de caracteres que contendra al alfabeto.\n");
		printf("Cantidad: ");
		scanf("%d", &n_characters);

		char alphabet[n_characters];

		printf("Ingrese los caracteres del alfabeto.\n");
		for(i = 0; i < n_characters; i++){
			printf("Caracter %d: ", i + 1);
			scanf(" %c", &alphabet[i]);
		}

		system("cls");
		printf("Los caracteres del alfabeto son:\n");
		i = 0;
		int length_alphabet = sizeof(alphabet);
		printf("S = {");
		while(i < length_alphabet){ 
			printf("%c,", alphabet[i]);
			i++;
		}
		printf("\b}");
		printf("\n");
		printf("Conjuntos potencia.\n");
		print(power, alphabet, length_alphabet);
		Set(power, length_alphabet);
		Universe(power, length_alphabet);
		return 0;
		}
		break;
		case 2:
		system("cls");
		char alphabet2[2] = {'0','1'};
		printf("Los caracteres del alfabeto son:\n");
		int j = 0;
		int length_alphabet2 = sizeof(alphabet2);
		printf("S = {");
		while(j < length_alphabet2)
		{
			printf("%c,", alphabet2[j]);
			j++;
		}
		printf("\b}");
		printf("\n");
		printf("Conjuntos potencia.\n");
		print(power, alphabet2 ,length_alphabet2);
		Set(power, length_alphabet2);
		Universe(power, length_alphabet2);
		return 0;
		system("cls");
		break;
		case 3:
		break;
		default:
		printf("Error.\n");
		}
		}
		break;
		case 2:
		srand((unsigned) time(NULL));
		system("cls");
		power = rand() % 10;
		printf("Potencia: %d\n", power);

		option2 = 1;
		while(option2 >= 1 && option2 < 3)
		{
		printf("Opciones.\n");
		printf("1.- Ingresar los caracteres del alfabeto.\n");
		printf("2.- Utilizar alfabeto de '0' y '1'.\n");
		printf("3.- Salir.\n");

		printf("Opcion: ");
		scanf("%d", &option2);

		if(option2 == 3)
		{
		system("cls");
		}

		switch(option2)
		{
		case 1:
		{
		system("cls");
		int n_characters;
		printf("Ingrese la cantidad de caracteres que contendra al alfabeto.\n");
		printf("Cantidad: ");
		scanf("%d", &n_characters);

		char alphabet3[n_characters];

		printf("Ingrese los caracteres del alfabeto.\n");
		int k;
		for(k = 0; k < n_characters; k++)
		{
			printf("Caracter %d: ", k + 1);
			scanf(" %c",&alphabet3[k]);
		}
		system("cls");
		printf("Los caracteres del alfabeto son:\n");
		k = 0;
		int length_alphabet3 = sizeof(alphabet3);
		printf("S = {");
		while(k < length_alphabet3)
		{
			printf("%c,", alphabet3[k]);
			k++;
		}
		printf("\b}");
		printf("\n");
		printf("Conjuntos potencia.\n");
		print(power, alphabet3, length_alphabet3);
		Set(power, length_alphabet3);
		Universe(power, length_alphabet3);
		return 0;
		system("cls");
		}
		break;
		case 2:
		system("cls");
		char alphabet4[2]={'0','1'};
		printf("Los caracteres del alfabeto son:\n");
		int o = 0;
		int length_alphabet4 = sizeof(alphabet4);
		printf("S = {");
		while(o < length_alphabet4)
		{
			printf("%c,", alphabet4[o]);
			o++;
		}
		printf("\b}");
		printf("\n");
		printf("Conjuntos potencia.\n");
		print(power, alphabet4, length_alphabet4);
		Set(power, length_alphabet4);
		Universe(power, length_alphabet4);
		return 0;
		system("cls");
		break;
		case 3:
		break;
		default:
		printf("Error.\n");
		}
		}
		break;
		case 3:
		break;
		default:
		printf("Error.\n");
		}
		system("cls");
	}
}
