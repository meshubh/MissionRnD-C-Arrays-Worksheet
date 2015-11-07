/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr == NULL || len <= 0)
		return NULL;
	int iterator, wrong1 = NULL, wrong2 = NULL, iterator1, temp;
	for (iterator = 0; iterator < len; iterator++)
	{
		if (*(Arr + iterator)>*(Arr + iterator + 1))
		{
			wrong1 = iterator;
			break;
		}
	}
	for (iterator1 = iterator + 1; iterator1 < len; iterator1++)
	{
		if (*(Arr + iterator1) > *(Arr + iterator1 + 1))
		{
			wrong2 = iterator1 + 1;
			break;
		}
	}
	temp = *(Arr + wrong1);
	*(Arr + wrong1) = *(Arr + wrong2);
	*(Arr + wrong2) = temp;
}
