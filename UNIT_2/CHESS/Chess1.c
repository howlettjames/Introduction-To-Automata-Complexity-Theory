#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "TADArbol.h"

#define TRACE_LENGTH 1000

int main (void)
{
	int i = 0, levels = 0, inf_level = 0, j = 0, nines = 0, option = 0, nodes = 0, successfuls = 3, top_random = 0, random_ch;
	char string[100] = {'\0'};
	Tree tree;
	Position position, father;
	element state;
	bool first_time = true, proceed = true;
	int trace[TRACE_LENGTH];
	FILE *read_fp, *write_trails_fp, *write_success_fp;
	char file_name[FILENAME_MAX];
	srand((unsigned) time(NULL));

	for(;;)
	{
		printf("|+|+|+|A NFA THAT MOVES IN A CHEESSBOARD|+|+|+|.\n");
		printf("|+|+|+|MENU|+|+|+|\n");
		printf("1.Read from command-line.\n");
		printf("2.Read from a file.\n");
		printf("3.Generate a random string.\n");
		printf("4.Check succesful trails.\n");
		printf("5.Check trails.\n");
		printf("6.Exit.\n");
		printf("Choose an option: ");
		scanf(" %d", &option);

		if(option == 1)
		{
			system("cls");
			printf("Enter the string: ");
			scanf("%s", string);
			printf("The string is: %s\n", string);
			proceed = true;	
		}
		else if(option == 2)
		{
			system("cls");
			printf("Name of the file to read (you may add an adress): ");
			scanf("%s", file_name);
			printf("The file name is: %s\n");
			if((read_fp = fopen(file_name, "rb")) == NULL)
			{
			printf("Can't read %s.\n", file_name);
			}
			fscanf(read_fp, "%s", string);
			printf("The string is: %s\n", string);
			proceed = true;
			fclose(read_fp);
		}
		else if(option == 3)
		{
			system("cls");
			printf("Enter the top of the string length: ");
			scanf("%d", &top_random);
			for(i = 0; i < top_random; i++)
			{	
			random_ch = rand() % 2;
			if(random_ch == 0)
			string[i] = 'r';
			else if(random_ch == 1)
			string[i] = 'b';				
			}
			string[i] = '\0';
			printf("The string is: %s\n", string);
			proceed = true;
		}
		else if(option == 4)
		{
			system("C:/Users/Jaime/Documents/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/CHESS/Successful_Trails.txt");
			proceed = false;
		}
		else if(option == 5)
		{
			system("C:/Users/Jaime/Documents/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/CHESS/Trails.txt");
			proceed = false;
		}
		else if(option == 6)
		{
			system("cls");
			exit(EXIT_SUCCESS);
		}
		else
		{
			system("cls");
			printf("Choose a correct option.\n");
			Sleep(2500);
			proceed = false;
		}

		if(proceed == true)
		{
			levels = 0;
			nodes = 0;
			successfuls = 3;
			Initialize(&tree);
			NewRightSon(&tree, position, (element) {.c = '1', .visited = false, .level = levels});
			nodes++;
			position = Root(&tree);
			i = 0;	
			while(string[i] != '\0')
			{		
			levels++;
			printf("\nLevel: %d\n", levels);
			if(string[i] == 'r')
			{
			printf("Read r\n");
			for(position = Root(&tree); position != NULL; position = SearchNonVisited(&tree, inf_level)) //Visits all nodes
			{
			printf("State: %c\n", position->e.c);
			if(position->e.c == '1' && position->e.visited == false) //Just this one has the second condition because if the first symbol in the chain is r
			{
			position->e.visited = true;
			NewRightSon(&tree, position, (element) {.c = '4', .visited = false, .level = levels});
			NewMiddleRightSon(&tree, position, (element) {.c = '2', .visited = false, .level = levels});
			printf("Sons of 1: 4 and 2 created in level: %d\n", levels);
			nodes += 2;
			}
			else if(position->e.c == '2')
			{
			position->e.visited = true;
			NewRightSon(&tree, position, (element) {.c = '6', .visited = false, .level = levels});
			NewMiddleRightSon(&tree, position, (element) {.c = '4', .visited = false, .level = levels});
			printf("Sons of 2: 6 and 4 created in level: %d\n", levels);	
			nodes += 2;
			}
			else if(position->e.c == '3')
			{
			position->e.visited = true;
			NewRightSon(&tree, position, (element) {.c = '6', .visited = false, .level = levels});
			NewMiddleRightSon(&tree, position, (element) {.c = '2', .visited = false, .level = levels});
			printf("Sons of 3: 6 and 2 created in level: %d\n", levels);	
			nodes += 2;
			}
			else if(position->e.c == '4')
			{
			position->e.visited = true;
			NewRightSon(&tree, position, (element) {.c = '8', .visited = false, .level = levels});
			NewMiddleRightSon(&tree, position, (element) {.c = '2', .visited = false, .level = levels});
			printf("Sons of 4: 8 and 2 created in level: %d\n", levels);
			nodes += 2;
			}
			else if(position->e.c == '5')
			{
			position->e.visited = true;
			NewRightSon(&tree, position, (element) {.c = '8', .visited = false, .level = levels});
			NewMiddleRightSon(&tree, position, (element) {.c = '6', .visited = false, .level = levels});
			NewMiddleLeftSon(&tree, position, (element) {.c = '4', .visited = false, .level = levels});
			NewLeftSon(&tree, position, (element) {.c = '2', .visited = false, .level = levels});
			printf("Sons of 5: 8, 6, 4 and 2 created in level: %d\n", levels);
			nodes += 4;
			}
			else if(position->e.c == '6')
			{
			position->e.visited = true;
			NewRightSon(&tree, position, (element) {.c = '8', .visited = false, .level = levels});
			NewMiddleRightSon(&tree, position, (element) {.c = '2', .visited = false, .level = levels});
			printf("Sons of 6: 8 and 2 created in level: %d\n", levels);
			nodes += 2;
			}
			else if(position->e.c == '7')
			{
			position->e.visited = true;
			NewRightSon(&tree, position, (element) {.c = '8', .visited = false, .level = levels});
			NewMiddleRightSon(&tree, position, (element) {.c = '4', .visited = false, .level = levels});
			printf("Sons of 7: 8 and 4 created in level: %d\n", levels);
			nodes += 2;
			}
			else if(position->e.c == '8')
			{
			position->e.visited = true;
			NewRightSon(&tree, position, (element) {.c = '6', .visited = false, .level = levels});
			NewMiddleRightSon(&tree, position, (element) {.c = '4', .visited = false, .level = levels});
			printf("Sons of 8: 6 and 4 created in level: %d\n", levels);
			nodes += 2;
			}
			else if(position->e.c == '9')
			{
			position->e.visited = true;
			NewRightSon(&tree, position, (element) {.c = '8', .visited = false, .level = levels});
			NewMiddleRightSon(&tree, position, (element) {.c = '6', .visited = false, .level = levels});
			printf("Sons of 9: 8 and 6 created in level: %d\n", levels);
			nodes += 2;
			}
			if(first_time)
			{
			first_time = false;
			break;
			}
			inf_level = levels - 1;
			}
			}
			else if(string[i] == 'b')
			{
			printf("Read b\n");
			for(position = Root(&tree); position != NULL; position = SearchNonVisited(&tree, inf_level)) //Visits all nodes
			{
			printf("State: %c\n", position->e.c);
			if(position->e.c == '1' && position->e.visited == false)
			{
			position->e.visited = true;
			NewRightSon(&tree, position, (element) {.c = '5', .visited = false, .level = levels});
			printf("Son of 1: 5 created in level: %d\n", levels);
			nodes++;
			}
			else if(position->e.c == '2')
			{
			position->e.visited = true;
			NewRightSon(&tree, position, (element) {.c = '5', .visited = false, .level = levels});
			NewMiddleRightSon(&tree, position, (element) {.c = '3', .visited = false, .level = levels});
			NewMiddleLeftSon(&tree, position, (element) {.c = '1', .visited = false, .level = levels});	
			printf("Sons of 2: 5, 3 and 1 created in level: %d\n", levels);
			nodes += 3;
			}
			else if(position->e.c == '3')
			{
			position->e.visited = true;
			NewRightSon(&tree, position, (element) {.c = '5', .visited = false, .level = levels});
			printf("Son of 3: 5 created in level: %d\n", levels);
			nodes++;
			}
			else if(position->e.c == '4')
			{
			position->e.visited = true; 
			NewRightSon(&tree, position, (element) {.c = '7', .visited = false, .level = levels});
			NewMiddleRightSon(&tree, position, (element) {.c = '5', .visited = false, .level = levels});
			NewMiddleLeftSon(&tree, position, (element) {.c = '1', .visited = false, .level = levels});
			printf("Sons of 4: 7, 5 and 1 created in level: %d\n", levels);
			nodes += 3;
			}
			else if(position->e.c == '5')
			{
			position->e.visited = true; 
			NewRightSon(&tree, position, (element) {.c = '9', .visited = false, .level = levels});
			NewMiddleRightSon(&tree, position, (element) {.c = '7', .visited = false, .level = levels});
			NewMiddleLeftSon(&tree, position, (element) {.c = '3', .visited = false, .level = levels});
			NewLeftSon(&tree, position, (element) {.c = '1', .visited = false, .level = levels});
			printf("Sons of 5: 9, 7, 3 and 1 created in level: %d\n", levels);
			nines++;
			nodes += 4;
			}
			else if(position->e.c == '6')
			{
			position->e.visited = true; 
			NewRightSon(&tree, position, (element) {.c = '9', .visited = false, .level = levels});
			NewMiddleRightSon(&tree, position, (element) {.c = '5', .visited = false, .level = levels});
			NewMiddleLeftSon(&tree, position, (element) {.c = '3', .visited = false, .level = levels});
			printf("Son of 6: 9, 5 and 3 created in level: %d\n", levels);
			nines++;
			nodes += 3;
			}
			else if(position->e.c == '7')
			{
			position->e.visited = true; 
			NewRightSon(&tree, position, (element) {.c = '5', .visited = false, .level = levels});
			printf("Son of 7: 5 created in level: %d\n", levels);
			nodes++;
			}
			else if(position->e.c == '8')
			{
			position->e.visited = true; 
			NewRightSon(&tree, position, (element) {.c = '9', .visited = false, .level = levels});
			NewMiddleRightSon(&tree, position, (element) {.c = '7', .visited = false, .level = levels});
			NewMiddleLeftSon(&tree, position, (element) {.c = '5', .visited = false, .level = levels});
			printf("Son of 8: 9, 7 and 5 created in level: %d\n", levels);
			nines++;
			nodes += 3;
			}
			else if(position->e.c == '9')
			{
			position->e.visited = true; 
			NewRightSon(&tree, position, (element) {.c = '5', .visited = false, .level = levels});
			printf("Son of 9: 5 created in level: %d\n", levels);
			nodes++;
			}
			if(first_time)
			{
			first_time = false;
			break;
			}
			inf_level = levels - 1;
			}	
			}
			i++;	
			} 

			if((write_trails_fp = fopen("C:/Users/Jaime/Documents/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/CHESS/Trails.txt", "w")) == NULL)
			{
			printf("Can't open file to write trails.\n");
			break;	
			}
			else
			{
			if((write_success_fp = fopen("C:/Users/Jaime/Documents/ESCOM_SEMESTRE_4/2CM5_TEORIA_COMPUTACIONAL/UNIT_2/CHESS/Successful_Trails.txt", "w")) == NULL)
			{
			printf("Can't open file to write successful trails.\n");
			break;
			}
			printf("\n|+|+|The string is: %s\n", string);
			fprintf(write_trails_fp, "\n|+|+|The string is: %s\n", string);
			fprintf(write_success_fp, "\n|+|+|The string is: %s\n", string);
			printf("|+|+|The last level is: %d\n", levels);
			fprintf(write_trails_fp, "|+|+|The last level is: %d\n", levels);
			fprintf(write_success_fp, "|+|+|The last level is: %d\n", levels);
			printf("|+|+|The number of nines is: %d\n", nines);
			fprintf(write_trails_fp, "|+|+|The number of nines is: %d\n", nines);
			fprintf(write_success_fp, "|+|+|The number of nines is: %d\n", nines);
			printf("|+|+|The number of nodes is: %d\n", nodes);
			fprintf(write_trails_fp, "|+|+|The number of nodes is: %d\n", nodes);
			fprintf(write_success_fp, "|+|+|The number of nodes is: %d\n", nodes);
			if((position = SearchNode(&tree, '9', levels)) != NULL) //Search if any node with '9' exists ergo the string succeded
			{
			printf("|+|+|The string succeeded.\n\n");
			fprintf(write_trails_fp, "|+|+|The string succeeded.\n\n");
			fprintf(write_success_fp, "|+|+|The string succeeded.\n\n");	
			}
			else
			{
			printf("|+|+|The string did not succeed.\n\n");
			fprintf(write_trails_fp, "|+|+|The string did not succeed.\n\n");
			fprintf(write_success_fp, "|+|+|The string did not succeed.\n\n");		
			}
			for(position = Root(&tree); position != NULL && nodes > 0; position = Root(&tree), nodes--) //Looks for all nodes in the specified level
			{
			if((position = SearchNode(&tree, 'A', levels)) != NULL) //The code 'A' means searching for All nodes in the specified level, in this case in the last level
			{
			if(position->e.c == '9' && successfuls > 0) //If the node contains a '9' it means this trail is succesful so we print it to the corresponding file
			{
			printf("Found node %c in level %d.\n", position->e.c, position->e.level);
			fprintf(write_success_fp, "Found node %c in level %d.\n", position->e.c, position->e.level);	
			position->e.level = -1;
			for(i = 0; position != NULL; position = Father(&tree, position))
			{
			trace[i++] = position->e.c;
			}
			printf("The trail is: ");
			fprintf(write_success_fp, "The trail is: ");
			for(j = 0; j < i; j++)
			{
			printf("%c--", trace[j]);
			fprintf(write_success_fp, "%c--", trace[j]);
			}
			printf("\n\n");
			fprintf(write_success_fp, "\n\n");
			successfuls--;  //The condition specifies that we only search for 3 successful trails
			}
			else //Here the program prints all trails of the nodes in the last level
			{
			printf("Found node %c in level %d.\n", position->e.c, position->e.level);
			fprintf(write_trails_fp, "Found node %c in level %d.\n", position->e.c, position->e.level);	
			position->e.level = -1;
			for(i = 0; position != NULL; position = Father(&tree, position))
			{
			trace[i++] = position->e.c;
			}
			printf("The trail is: ");
			fprintf(write_trails_fp, "The trail is: ");
			for(j = 0; j < i; j++)
			{
			printf("%c--", trace[j]);
			fprintf(write_trails_fp, "%c--", trace[j]);
			}
			printf("\n\n");
			fprintf(write_trails_fp, "\n\n");	
			}			
			}	
			}
			}
			fclose(write_trails_fp);
			fclose(write_success_fp);
		}
	}	
	return 0;
}

