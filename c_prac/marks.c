#include <stdio.h>

void main()
{
	int i;
	float avg;
	float sum = 0;
	int marks[5];

	printf("Enter the marks of each student: ");
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &marks[i]);
	}
	for (i = 0; i < 5; i++)
	{
		sum = sum + marks[i];
	}
	avg = sum / 5;
	printf("avg is : %2.2f\n", avg);
}
