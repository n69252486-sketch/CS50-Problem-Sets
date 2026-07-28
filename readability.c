#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
	char input[200];
	printf("Enter the text:");
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = '\0';
	int sentence = 0;
	int word = 1;
	int letter = 0;
	for (int i = 0;input[i] != '\0';i++)
	{
		if (input[i] == '.' || input[i] == '!' || input[i] == '?')
		{
			sentence++;
		}
	}
	for (int index = 0;input[index] != '\0';index++)
	{
		if (input[index] == ' ')
		{
			word++;
		}
	}
	for (int index2 = 0;input[index2] != '\0';index2++)
	{
		if (isalpha(input[index2]))
		{
			letter++;
		}
	}
	float l;
	l = ((float)letter / word) * 100;
	float s;
	s = ((float)sentence / word) * 100;
	float number;
	number = 0.0588 * l - 0.296 * s - 15.8;
	int grade;
	grade = round(number);
	if (grade < 1)
	{
		printf("Before Grade 1\n");
	}
	else if (grade >= 16)
	{
		printf("Grade 16+\n");
	}
	else
	{
		printf("Grade %i\n", grade);
	}
	return 0;
}