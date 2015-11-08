/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K)
{
	if (len <= 0 || students == NULL || K <= 0)
		return NULL;
	struct student temp;
	struct student **topK;
	topK = (struct student **)malloc(sizeof(struct student));
	struct student **finalK;
	finalK = (struct student **)malloc(sizeof(struct student));
	int iterator, high, iterator1;
	char temp1;
	char temp_name[10];
	if (K > len)
		K = len;
		for (iterator = 0; iterator < len; iterator++)
		{
			high = iterator;
			for (iterator1 = iterator + 1; iterator1 < len; iterator1++)
			{
				if (students[iterator1].score > students[high].score)
					high = iterator1;
			}
			temp = students[iterator];
			students[iterator] = students[high];
			students[high] = temp;
		}
		iterator = 0;
		while (K > 0)
		{
			finalK[iterator] = &students[iterator];
			K--;
			iterator++;
		}
	return finalK;
}