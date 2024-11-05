#include <stdio.h>

int GCD_iter(int a, int b)
{
	int temp; 
	while (b != 0)
	{
		temp = b; 
		b = a % b; 
		a = temp; 
	}

	return a; 
}

int GCD_recu(int a, int b)
{
	if (b == 0)
		return a; 
	else 
		return GCD_recu(b, a % b); 
}

int main(void)
{
	int a, b; 
	printf("Input two non-zero integers: "); 
	scanf("%d %d", &a, &b); 

	int ans1 = GCD_iter(a, b); 
	int ans2 = GCD_recu(a, b); 
	
	printf("The answer obtained from the iterative function: %d\nThe answer obtained from the recursive function: %d\n", ans1, ans2); 

	return 0; 
}