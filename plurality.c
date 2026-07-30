#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		printf("usage:./plurality candidate1 candidate2 candidate3\n");
		return 1;
	}
	char input[50];
	printf("How many candidates? ");
	fgets(input, sizeof(input), stdin);
	int number = atoi(input);
	input[strcspn(input, "\n")] = '\0';
	char input2[100];
	int voits[3] = { 0,0,0 };
	for (int x = 0;x < number;x++)
	{
		printf("the voite that i choose is:");
		fgets(input2, sizeof(input2), stdin);
		input2[strcspn(input2, "\n")] = '\0';
		for (int d = 0;d < argc - 1;d++)
		{
			if (strcmp(input2, argv[d + 1]) == 0)
			{
				voits[d]++;
			}
		}

	}
	int winner = voits[0];
	for (int r = 0;r < argc - 1;r++)
	{
		if (winner < voits[r])
		{
			winner = voits[r];
		}
		for(int x=0;x<argc-1;x++)
		{ 
		if (winner == voits[x])
		{
			printf("the winner is %s with %ld voits\n", argv[x + 1], winner);
		}
	}
	}





	
}