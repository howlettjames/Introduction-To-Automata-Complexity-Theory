#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
	int option = 0;

	system("cls");
	for(;;)
	{
		printf("|+|+|+|+|+|MAIN MENU|+|+|+|+|+|\n");
		printf("1. Run Webay.\n");
		printf("2. Run Chess.\n");
		printf("3. Run Regular Expression (0 + 10)*(e + 1).\n");
		printf("4. Run Regular Expression [(10)*0 + 1(01)*1][(0(01)*(1 + 00) + 1(10)*(0 + 11))]*.\n");
		printf("5. Run Palindrome.\n");
		printf("6. Run PDA.\n");
		printf("7. Exit.\n");
		printf("Option: ");
		scanf(" %d", &option);
		switch(option)
		{
			case 1:
				system("cls");
				system("C:/Users/Daniela/Documents/JAMES/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/WEBAY/a.exe");
			break;
			case 2:
				system("cls");
				system("C:/Users/Daniela/Documents/JAMES/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/CHESS/chess.exe");
			break;
			case 3:
				system("cls");
				system("C:/Users/Daniela/Documents/JAMES/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/RE_1/a.exe");
			break;
			case 4:
				system("cls");
				system("C:/Users/Daniela/Documents/JAMES/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/RE_2/a.exe");
			break;
			case 5:
				system("cls");
				system("C:/Users/Daniela/Documents/JAMES/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/CFG_1/a.exe");
			break;
			case 6:
				system("cls");
				system("C:/Users/Daniela/Documents/JAMES/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/PDA/pda.exe");
			break;
			case 7:
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