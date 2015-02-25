/**
 * lab3_lib.h
 *
 * Provides the function prototypes for lab3_lib.c.
 *
 *		 --------------------------
 * 		|	DO NOT MODIFY THIS FILE. |
 *		 --------------------------
 *
 *      Author: Shiva Ghose
 *      Email:	shivaghose@purdue.edu
 *      Course: CNIT 315
 *      Lab:	3
 *		Created on:	30-Jan-2015
 */

#ifndef LAB3_LIB_H_
#define LAB3_LIB_H_

/**
 * Function: generate_random_int_array()
 *
 * Generates an integer array of specified size filled with random numbers.
 *
 *
 * Parameters:
 * 	@param array 			Pointer to the integer array.
 * 	@param array_length 	Number elements to be stored in the array.
 *
 * Returns:
 * 	@return 	0 - Successful.
 * 				1 - Fail/Error.
 *
 * Expectations:
 * 	- None
 */
int generate_random_int_array(int* array, int array_length);

/**
 * Function: bubble_sort()
 *
 * Sorts an integer array in ascending order using the bubble sort algorithm.
 * The function does not modify the input array, and instead returns a sorted
 * copy.
 *
 * Parameters:
 * 	@param array_unsorted	Pointer to the unsorted integer array.
 * 	@param array_length		Number of elements in the array.
 * 	@param array_sorted		Pointer to the desired sorted array.
 *
 *
 * Returns:
 * 	@return 	0 - Successful.
 * 				1 - Fail/Error.
 *
 * Expectations:
 * 	- Sorted array is the same size as the unsorted array.
 */
int bubble_sort(int* array_unsorted, int array_length, int* array_sorted);

/**
 * Function: selection_sort()
 *
 * Sorts an integer array in ascending order using the selection sort
 * algorithm. The function does not modify the input array, and instead
 * returns a sorted copy.
 *
 * Parameters:
 * 	@param array_unsorted	Pointer to the unsorted integer array.
 * 	@param array_length		Number of elements in the array.
 * 	@param array_sorted		Pointer to the desired sorted array.
 *
 * Returns:
 * 	@return 	0 - Successful.
 * 				1 - Fail/Error.
 *
 * Expectations:
 * 	- Sorted array is the same size as the unsorted array.
 */
int selection_sort(int* array_unsorted, int array_length, int* array_sorted);

/**
 * Function: insertion_sort()
 *
 * Sorts an integer array in ascending order using the insertion sort
 * algorithm. The function does not modify the input array, and instead
 * returns a sorted copy.
 *
 * Parameters:
 * 	@param array_unsorted	Pointer to the unsorted integer array.
 * 	@param array_length		Number of elements in the array.
 * 	@param array_sorted		Pointer to the desired sorted array.
 *
 * Returns:
 * 	@return 	0 - Successful.
 * 				1 - Fail/Error.
 *
 * Expectations:
 * 	- Sorted array is the same size as the unsorted array.
 */
int insertion_sort(int* array_unsorted, int array_length, int* array_sorted);

/**
 * Function: linear_search()
 *
 * Searches through an integer array to find the first occurrence of a value.
 * If the value is found, the function stores the location in the corresponding
 * variable, otherwise, -1 is used.
 *
 * Parameters:
 * @param array			Pointer to the integer array.
 * @param array_length  Number of elements in the array.
 * @param value			Integer that the algorithm searches for.
 * @param location		Pointer to the location of the search:
 * 							-1 - indicates that the value was not found.
 * 							location>=0 - 	indicates the position of the first
 * 											occurrence of the search value.
 *
 * Returns:
 * 	@return 	0 - Successful completion of the function.
 * 				1 - An error during operation.
 *
 * Expectations:
 * 	- None.
 */
int linear_search(int* array, int array_length, int value, int* location);

/**
 * Function: binary_search()
 *
 * Searches through a sorted integer array to find the first occurrence of a
 * value using the binary search algorithm. If the value is found, the
 * function stores the location in the corresponding variable, otherwise, -1
 * is used to indicate that the query value was not found inside the array.
 *
 * Parameters:
 * @param array			Pointer to the sorted integer array.
 * @param array_length  Number of elements in the array.
 * @param value			Integer that the algorithm searches for.
 * @param location		Pointer to the location of the search:
 * 							-1 - indicates that the value was not found.
 * 							location>=0 - 	indicates the position of the first
 * 											occurrence of the search value.
 *
 * Returns:
 * 	@return 	0 - Successful completion of the function.
 * 				1 - An error during operation.
 *
 * Expectations:
 * 	- The input array is sorted.
 */
int binary_search(int* array, int array_length, int value, int* location);


/**
 * Function: deep_copy_array()
 *
 * Duplicates the input array and stores the deep copy in the output array.
 *
 * Parameters:
 * @param array_from	The array that needs to be copied.
 * @param array_to  	The new array which will hold a deep copy of the input
 * 						array.
 * @param array_length	The length of the input array.
 *
 * Returns:
 * 	@return 	0 - Successful completion of the function.
 * 				1 - An error during operation.
 *
 * Expectations:
 * 	- All parameters are valid, i.e.:
 * 			* array_from is declared.
 *			* array_to has enough memory allocated.
 *			* array_length accurately portrays the number of elements in
 *			  array_from
 */
void deep_copy_array(int* array_from, int* array_to, int array_length);

#endif /* LAB3_LIB_H_ */
