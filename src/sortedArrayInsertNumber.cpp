/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (len <= 0)
		return NULL;
	if (Arr == NULL)
		return NULL;
	int iterator, iterator1, temp, temp1;
	if (num < *(Arr))
	{
		//Arr = (int *)realloc(Arr, len + 1);
		temp = *(Arr);
		*(Arr) = num;
		for (iterator1 = 1; iterator1 < len; iterator1++)
		{
			temp1 = *(Arr + iterator1);
			*(Arr + iterator1 + 1) = temp1;
		}
		*(Arr + 1) = temp;
	}
	else if (num > *(Arr + len - 1))
	{
		//Arr = (int *)realloc(Arr, len + 1);
		*(Arr + len) = num;
	}
	else if (num > *(Arr))
	{
		for (iterator = 0; iterator < len; iterator++)
		{
			if (*(Arr + iterator)<num && *(Arr + iterator + 1) > num)
			{
				//Arr = (int *)realloc(Arr, len + 1);
				temp = *(Arr + iterator + 1);
				*(Arr + iterator + 1) = num;
				for (iterator1 = iterator + 2; iterator1 < len; iterator1++)
				{
					temp1 = *(Arr + iterator1);
					*(Arr + iterator1 + 1) = temp1;
				}
				*(Arr + iterator + 2) = temp;
			}
		}
	}
	return Arr;
}