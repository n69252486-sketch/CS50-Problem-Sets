#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 10
int main(int argc, char* argv[])
{
	if (argc < 3 || (argc-1)>MAX)
	{
		printf("usage:./plurality candidate1 candidate2 candidate3\n");
		return 1;
	}
	char input[50];
	printf("How many voters? ");
	fgets(input, sizeof(input), stdin);
	int number = atoi(input);
	input[strcspn(input, "\n")] = '\0';
	char input2[100];
	int voters[MAX];
	for (int i= 0;i <MAX;i++)
	{
		voters[i] = 0;
	}
	for (int index = 0;index < number;index++)
	{
		printf("the candidate that i choose is:");
		fgets(input2, sizeof(input2), stdin);
		input2[strcspn(input2, "\n")] = '\0';
		for (int index2 = 0;index2 < argc - 1;index2++)
		{
			if (strcmp(input2, argv[index2 + 1]) == 0)
			{
				voters[index2]++;
			}
		}

	}
	int winner = voters[0];
	for (int index3 = 0;index3< argc - 1;index3++)
	{
		if (winner < voters[index3])
		{
			winner = voters[index3];
		}
	}

		for (int index4= 0;index4 < argc - 1;index4++)
		{
			if (winner == voters[index4])
			{
				printf("the winner is %s with %d voters\n", argv[index4 + 1], winner);
			}
		}




	
}