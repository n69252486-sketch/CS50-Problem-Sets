#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
	char input1[50];
	printf("Enter the word:");
	fgets(input1, sizeof(input1), stdin);
	input1[strcspn(input1, "\n")] = '\0';
	char input2[50];
	printf("Enter the word:");
	fgets(input2, sizeof(input2), stdin);
	input2[strcspn(input2, "\n")] = '\0';
	for (int i = 0;input1[i] != '\0'; i++)
	{
		input1[i] = toupper(input1[i]);
	}
	for (int n = 0;input2[n] != '\0'; n++)
	{
		input2[n] = toupper(input2[n]);
	}
	int points[] = { 1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10 };
	char letters[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	int counter1 = 0;
	int counter2 = 0;
	for (int index = 0;input1[index] != '\0';index++)
	{
		for (int d = 0;d < 26;d++)
		{
			if (input1[index] == letters[d])
			{
				counter1 = counter1 + points[d];
				break;
			}
	
		}
	}
	for (int line = 0;input2[line] != '\0';line++)
	{
		for (int x = 0;x < 26;x++)
		{
			if (input2[line] == letters[x])
			{
				counter2 = counter2 + points[x];
				break;
			}
	
	}
	}
	if (counter1 < counter2)
	{
		printf("The winner is user2");

	}
	else if (counter2 < counter1)
	{
		printf("The winner is user1");
	}
	else
	{
		printf("The two users drew");
	}
}


















