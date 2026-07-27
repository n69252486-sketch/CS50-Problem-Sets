#include <stdio.h>
#include <stdlib.h>
int main()
{
	char input[50];
	int height;
	do
	{
		printf("Enter the height(1-8)\n");
		fgets(input, sizeof(input), stdin);
		height = atoi(input);
	} 
	while (height <= 0 || height > 8);
	for (int lines = 1;lines<=height;lines++)
	{
		for (int space = 1;space <= height-lines;space++)
		{
			printf(" ");
	}
		for(int printedsymbol =1;printedsymbol<=lines;printedsymbol++)
		{
			printf("#");
	}
		printf("\n");
		

	}
	





}