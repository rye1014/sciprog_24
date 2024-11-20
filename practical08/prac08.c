#include <stdio.h>

int GCD_iter(int a, int b)	// compute GCD
{
	int temp; 
	while (b != 0)			// if b == 0, a is the GCD
	{						
		temp = b; 			// if not, repeatedly calculate the remainder of a divided by b
		b = a % b; 			// then replace a with b and b with the remainder, 
		a = temp; 			// and continue the calculation
	}
	return a; 
}

int GCD_recu(int a, int b)
{
	if (b == 0)						// if b == 0, a is the GCD
		return a; 					
	else 							// if b != 0, 
		return GCD_recu(b, a % b); 	// replace a with b, and b with the remainder of a divided by b, 
}									// then continue the calculation

int main(void)
{
	int a, b; 
	printf("Input two non-zero integers: "); 	// input two non-zero integers
	scanf("%d %d", &a, &b); 

	int ans1 = GCD_iter(a, b); 					// use two method to get the GCD
	int ans2 = GCD_recu(a, b); 
	
	printf("The answer obtained from the iterative function: %d\nThe answer obtained from the recursive function: %d\n", ans1, ans2); 

	return 0; 
}