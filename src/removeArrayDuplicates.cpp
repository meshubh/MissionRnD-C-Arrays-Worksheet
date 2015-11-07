/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void * removeArrayDuplicates(int *Arr, int len)
{
	if (len <= 0)
		return NULL;
	if (Arr == NULL)
		return NULL;
	int iterator, iterator1, NewLength = 1;
	for (iterator = 1; iterator < len; iterator++)
	{

		for (iterator1 = 0; iterator1 < NewLength; iterator1++)
		{

			if (*(Arr + iterator) == *(Arr + iterator1))
				break;
		}

		/* if none of the values in index[0..j] of array is not same as array[i],
		then copy the current value to corresponding new position in array */

		if (iterator1 == NewLength)
		{
			*(Arr + NewLength) = *(Arr + iterator);
			NewLength++;
		}
	}
}