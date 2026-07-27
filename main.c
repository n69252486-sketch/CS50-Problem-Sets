#include <stdio.h>
#include <stdlib.h>
int main()
{
	//to ask the user to enter the remaining amount
	char input [50];
	int remainingamount;
	do
	{
		printf("Enter the remaining amount(in cents)\n");
		fgets(input, sizeof(input), stdin);
		remainingamount = atoi(input);
	}
	while (remainingamount < 1);
	int quarter = 25;
	int dime = 10;
	int nickel = 5;
	int penny = 1;
	int coins = 0;
	if(remainingamount>=quarter)
	{
		coins = coins + (remainingamount / quarter);
		remainingamount = remainingamount % quarter;

	}
	if (remainingamount>=dime)
	{
		coins = coins + (remainingamount /dime);
		remainingamount = remainingamount % dime;
	} 
	if(remainingamount>=nickel)3
	{
		coins = coins + (remainingamount / nickel);
		remainingamount = remainingamount % nickel;
	}
	if (remainingamount>=penny)
	{
		coins = coins + (remainingamount / penny);
		remainingamount = remainingamount % penny;
	} 
	printf("%i\n", coins);












	

}


