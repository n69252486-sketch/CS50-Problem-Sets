#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("%s\n",argv[0]);
		return 1;
	}
	for (int i = 0;argv[1][i] != '\0';i++)
	{
		if (!isdigit(argv[1][i]))
		{
			printf("%s\n",argv[0]);
			return 1;
		}
	}
	char input[100];
	printf("Enter the text: ");
	fgets(input, sizeof(input), stdin);
	int c = 0;
	input[strcspn(input, "\n")] = '\0';
	int key = atoi(argv[1]);
	printf("ciphertext:");
	if (argc == 2)
	{
		for (int index = 0;input[index] != '\0';index++)
		{
			if (input[index] <= 'z' && input[index] >= 'a')
			{
			
				c = ((input[index] - 'a' + key) % 26) + 'a';
				printf("%c", c);

		}
			else if(input[index]<='Z'&&input[index]>='A')
			{
				c = ((input[index] - 'A' + key) % 26) + 'A';
				printf("%c", c);
			}
			else
			{
				printf("%c", input[index]);
			}
}
	}
	printf("\n");
	return 0;
}