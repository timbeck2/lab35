/** lab3_lib.c: implements sorting and searching functions.
*
* With New Edits
*
* Name: Timothy Becker
* Email: becker43@purdue.edu
* Course: CNIT 315
* Lab batch: 008
* Lab assignment: 3
* Date: Feb 17, 2015
*
* Collaborators:
* Chris Fox
* Everett Kennedy
*/

#include <stdio.h>
#include <string.h> //for memcpy

#include "lab3_lib.h"

/*
 * Pro-tip: use this function to copy arrays.
 */
void deep_copy_array(int* array_from, int* array_to, int array_length){
	//Read more about memcpy over here: http://www.cplusplus.com/reference/cstring/memcpy/
	memcpy(array_to, array_from, array_length*sizeof(int));
}

/*
 * Pro-tip:use this function to generate random arrays.
 */
int generate_random_int_array(int* array, int array_length){
	/* Initialize */
	int i;
	/* Validate input */
	if(!array){
		printf("Error: Input array was NULL\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: required array size < 1\n");
		return 1;
	}
	/* Generate random values */
	for (i = 0; i < array_length; i++) {
		array[i] = rand()%100;
	}
	return 0;
}


int bubble_sort(int* array_unsorted, int array_length, int* array_sorted){
	/* Initialize */

	//Put your variable declarations here.
	int n = 0;
	int i = 0;

	/* Validate input */
	if(!array_unsorted){
		printf("Error: Unsorted array was NULL\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: unsorted array size < 1\n");
		return 1;
	}
	if(array_sorted == NULL){
		printf("Error: sorted array is NULL\n");
		return 1;
	}
	/* Sort array */
	deep_copy_array(array_unsorted, array_sorted, array_length);
	//I can has code?
	for (n = 0; n < array_length - 1; n++)
	{
		for (i = 0; i < (array_length - n - 1); i++)
		{
			if (array_sorted[i] > array_sorted[i + 1])
			{
				int temp;
				temp = array_sorted[i];
				array_sorted[i] = array_sorted[i+1];
				array_sorted[i+1] = temp;
			}
		}
	}

	return 0; //Change me!
}


int selection_sort(int* array_unsorted, int array_length, int* array_sorted){
	/* Initialize */

	int i, h, temp; 

	//Put your variable declarations here.

	/* Validate input */
	if(!array_unsorted){
		printf("Error: Unsorted array was NULL\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: unsorted array size < 1\n");
		return 1;
	}
	if(array_sorted == NULL){
		printf("Error: sorted array is NULL\n");
		return 1;
	}
	/* Sort array */
	deep_copy_array(array_unsorted, array_sorted, array_length);

	//Let the code-pocalypse begin!
	for (h = 0; h < array_length; h++) {
		int lowest = h;
		for (i = h+1; i < (array_length); i++) {
			if (array_sorted[lowest] > array_sorted[i]) {
				lowest = i;
			}
		}
		temp = array_sorted[h];
		array_sorted[h] = array_sorted[lowest];
		array_sorted[lowest] = temp;
	}

	return 0; //Change me!
}

int insertion_sort(int* array_unsorted, int array_length, int* array_sorted){
	/* Initialize */
	int h;
	//Put your variable declarations here.

	/* Validate input */
	if(!array_unsorted){
		printf("Error: Unsorted array was NULL\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: unsorted array size < 1\n");
		return 1;
	}
	if(array_sorted == NULL){
		printf("Error: sorted array is NULL\n");
		return 1;
	}
	deep_copy_array(array_unsorted, array_sorted, array_length);

	/* Sort array */
	for(h=1; h <= array_length - 1; h++) {
		int dec = h;
		while (array_sorted[dec - 1] > array_sorted[dec] && dec > 0)
		{
			int temp = array_sorted[dec];
			array_sorted[dec] = array_sorted[dec-1];
			array_sorted[dec-1] = temp;
			dec--;
		}
	}
	//Round 4: CODE!


	return 0; //Change me!
}

int linear_search(int* array, int array_length, int value, int* location){
	/* Initialize */
	int i = 0;
	//Put your variable declarations here.

	/* Validate input */
	if(!array){
		printf("Error: array pointer is NULL\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: array size < 1\n");
		return 1;
	}
	if(!location){
		printf("Error: location variable is NULL\n");
		return 1;
	}
	/* Search array */

	for (i = 0; i < array_length; i++) {
		if (value == array[i]) {
			*location = i;
			break;
		}
		else {
			*location = -1;
		}
	}
	//All of your code-base are belong to us.

	return 0; //Change me!
}

/*
 * You will have to implement this entire function! Remember to check for
 * input errors like the other functions.
 */
int binary_search(int* array, int array_length, int value, int* location){

	/* Validate input */
	if(!array){
		printf("Error: array pointer is NULL\n");
		printf("!array triggered\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: array size < 1\n");
		printf("array_length triggered\n");
		return 1;
	}
	if(!location){
		printf("Error: location variable is NULL\n");
		printf("!location triggered\n");
		return 1;
	}
	
	//The cake is a lie.

	int pos = -1;
	int min = 0;
	int max = (array_length - 1);

  	while (max >= min && pos == -1) {
    	int mid = (max+min)/2;

    	if(array[mid] ==  value){
      	pos = mid;
    }	
    else if(array[mid] < value){
      	min = mid +1;
    }
    else if(array[mid] > value){
      	max = mid -1;
    }

  }

  *location = pos;

	return 0;
}
