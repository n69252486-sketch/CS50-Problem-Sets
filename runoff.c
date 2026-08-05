#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX_candidate 5
#define MAX_voters 100
int preference[MAX_voters][MAX_candidate] ;
typedef struct
{
	char name[50];
	int voters;
	bool eliminate;
	
}person;
int main(int argc, char* argv[])
{
	if (argc<3 || (argc - 1)>MAX_candidate)
	{
		printf("Usage:./runoff candidate1 candidate2.......candidate10\n");
		return 1;
	}
	person candidate[MAX_candidate] = { 0 };

	for (int x = 0;x < argc - 1;x++)
	{
		strcpy(candidate[x].name, argv[x + 1]);
		candidate[x].voters = 0;
		candidate[x].eliminate = false;
	}
	
	printf("Available candidates:");
	for (int r = 0;r < argc - 1;r++)
	{
		printf("%s ", argv[r + 1]);
	}
	printf("\n");

	char input[50];
	printf("How many voters? ");
	fgets(input, sizeof(input), stdin);
	int number = atoi(input);
	input[strcspn(input, "\n")] = '\0';
	for (int index = 0;index < number;index++)
	{
		char input2[50];
		printf("Enter candidates you chose in order(space-separated): ");
		if (fgets(input2, sizeof(input2), stdin) != NULL)
		{
			input2[strcspn(input2, "\n")] = '\0';

			char* cand = strtok(input2, " ");
			int rank = 0;
			while (cand != NULL)
			{
				for (int e = 0;e < argc - 1;e++)
				{
					if (strcmp(cand, candidate[e].name) == 0)
					{
						preference[index][rank]=e;
						break;
					}
					
				}
				rank++;
				cand = strtok(NULL, " ");


			}

		}
	}
	do {
		for (int t = 0;t < argc - 1;t++)
		{
			candidate[t].voters = 0;
		}
		
		for (int s = 0;s < number;s++)
		{
			for (int u = 0;u < argc - 1;u++)
			{
				int first_pref = preference[s][u];
				if (candidate[first_pref].eliminate == false)
				{
					candidate[first_pref].voters++;
					break;
				}

			}
		}
	
		int winner = 0;
		for (int d = 0;d < argc - 1;d++)
		{
			if (winner < candidate[d].voters&&candidate[d].eliminate==false)
			{
				winner = candidate[d].voters;
			}


		}
		int loser =number+1;
		for (int q = 0;q < argc - 1;q++)
		{
			if (loser > candidate[q].voters && candidate[q].eliminate == false)
			{
				loser = candidate[q].voters;
			}
		}
		for(int g=0;g<argc-1;g++)
		{
			if (winner <= (number / 2) && loser == candidate[g].voters&&!candidate[g].eliminate)
			{
				candidate[g].eliminate = true;
			}
		}


		for (int f = 0;f < argc - 1;f++)
		{

			if (winner == candidate[f].voters && candidate[f].voters > (number / 2) && candidate[f].eliminate == false)
			{
				printf("the winner is %s\n", candidate[f].name);
				return 0;
			}

			
		}

			if (loser == winner)
			{
				for (int z = 0;z < argc - 1;z++)
				{
					if (!candidate[z].eliminate)
					{
						printf("%s ", candidate[z].name);
					}
				}
				return 0;
			}
			
		
	} 
		while (true);
		
	



	}
