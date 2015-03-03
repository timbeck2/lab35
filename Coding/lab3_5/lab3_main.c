/** lab3_main.c: Implements a front end for lab3_lib.c.
*
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
*Select Statement Resource: http://www.tutorialspoint.com/cprogramming/c_decision_making.htm
*
* Find time of exection: http://stackoverflow.com/questions/5248915/execution-time-of-c-program
* Malloc Help: http://en.wikipedia.org/wiki/C_dynamic_memory_allocation
*/

#include <time.h> //for time()
#include <stdio.h>
#include "lab3_lib.h"


/**
 * Calls the functions implemented in lab3_lib.c and implements a menu system
 * for them.
 *
 * 	@return 	0 - Successful completion of the program.
 * 				1 - An error during execution.
 */
int main(){
	/* Initialize */

	srand(time(NULL));

  // Set the array size HERE
  int array_size = 10000;

  int i;
  int selection = 0;
  
  //int unsorted_arr[array_size];
  //int sorted_arr[array_size];
  int searchfor;
  int found_loc;

  clock_t begin, end;
  double time_spent, sort_time_spent = 0, total_time_spent = 0;

	/* Menu */
  printf("\e[1;1H\e[2J");


	//Your code goes here!
  
  printf("\n\n How big of an array would you like to sort or search?\n");
  scanf("%d", &array_size);
  int * unsorted_arr = malloc(array_size * sizeof(int));
  int * sorted_arr = malloc(array_size * sizeof(int));

  if ( NULL == (unsorted_arr = malloc(10 * sizeof(int))) ) {
  printf("Unsorted Array Malloc Failed\n");
  return(-1);
  }

  if ( NULL == (sorted_arr = malloc(10 * sizeof(int))) ) {
  printf("Sorted Array Malloc Failed\n");
  return(-2);
  }

  while (1) 
  {
    
    printf("\n\nWhat would you like to do?\n");
    printf(" 1) Bubble Sort\n 2) Selection Sort\n 3) Insertion Sort\n 4) Linear Search\n 5) Binary Search\n 6) Change Array Size\n-1) Exit\n");
    scanf("%d", &selection);
    printf("\e[1;1H\e[2J");
  
    switch(selection)
    {
    case -1 :
      printf("\e[1;1H\e[2J");
      printf("Goodbye... \n\n\n");
      return 0;
    case 1 :
      // Option to Bubble Sort
      printf("Sorting %d values...\n", array_size);
      generate_random_int_array(unsorted_arr, array_size);

      begin = clock();

      bubble_sort(unsorted_arr, array_size, sorted_arr);

      end = clock();
      printf("Sorting Completed Successfully\n");
      time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
      printf("Execution Time: %lf \n", time_spent);
    break;
    case 2 :
      //Option to Selection Sort
      printf("Sorting %d values...\n", array_size);
      generate_random_int_array(unsorted_arr, array_size);

      begin = clock();

      selection_sort(unsorted_arr, array_size, sorted_arr);

      end = clock();
      time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
      printf("Selection Sort Completed");
      printf("Execution Time: %lf \n", time_spent);
    break;
    case 3 :
      // Option to Insertion Sort

      printf("Sorting %d values...\n", array_size);
      generate_random_int_array(unsorted_arr, array_size);

      begin = clock();

      insertion_sort(unsorted_arr, array_size, sorted_arr);

      end = clock();
      time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

      /*for (i = 0; i < array_size; i++)
        {
        //printf("%d) %d\n", i+1, sorted_arr[i]);
      }*/
      printf("Execution Time: %lf \n", time_spent);
    break;
    case 4 :
      //Option for Linear Search

      printf("What integer value would you like to search for?\n");
      scanf("%d", &searchfor);
      generate_random_int_array(unsorted_arr, array_size);
      
      begin = clock();

      linear_search(unsorted_arr, array_size, searchfor, &found_loc);
      
      end = clock();
      time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
      printf("\n\nExecution Time: %lf \n", time_spent);
      
      if (found_loc != -1) {
        printf("\nThe linear search found the value %d in the array!\nLocation in Array = %d\n\n", searchfor, found_loc);

        printf("Here are the surrounding 5 numbers around the found number\n");

        for (i = (found_loc - 5); i <= found_loc + 5; i++)
          { 
            if (i < 0) {
              // do nothing
            } 
            else if (i == found_loc) {
              printf("%d) %d <-- Your Searched Value!\n", i, unsorted_arr[i]);
            } 
            else {
              printf("%d) %d\n", i, unsorted_arr[i]);
            }
          }
      }
      else {
        printf("The value you searched for was not found");
      }
    break;
    case 5 :
      // Option for Binary Search
      
      printf("What integer value would you like to search for?\n");
      scanf("%d", &searchfor);
      generate_random_int_array(unsorted_arr, array_size);
      
      printf("Sorting %d values...\n", array_size);
      begin = clock();
      insertion_sort(unsorted_arr, array_size, sorted_arr); 
      end = clock();
      
      time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
      sort_time_spent = time_spent;
      total_time_spent = time_spent;

      printf("Searching for your requested value...\n");
      begin = clock();
      binary_search(sorted_arr, array_size, searchfor, &found_loc);
      end = clock();
      
      time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
      total_time_spent = total_time_spent + time_spent;
      
      // Output Results
      printf("\n\nTime Spent Sorting:                     %lf \n", sort_time_spent);
      printf("Time Spent Searching:                   %lf \n", time_spent);
      printf("Total Time Spent Sorting and Searching: %lf \n", total_time_spent);
      
      if (found_loc != -1) {
        printf("\nThe binary search found the value \"%d\" in the array!\nLocation in Array = %d\n\n", searchfor, found_loc);

        printf("Here are the surrounding 5 numbers around the found number\n");

        for (i = (found_loc - 5); i <= found_loc + 5; i++)
          { 
            if (i < 0) {
              // do nothing
            } 
            else if (i == found_loc) {
              printf("%d) %d <-- Your Searched Value!\n", i, sorted_arr[i]);
            } 
            else {
              printf("%d) %d\n", i, sorted_arr[i]);
            }
          }
      }
      else {
        printf("The value you searched for was not found");
      }

    break;
    case 6 :
      // Option To Change Array Size
      
      printf("\n\n How big of an array would you like to sort or search?\n");
      scanf("%d", &array_size);

      free(unsorted_arr);
      free(sorted_arr);

      int * unsorted_arr = malloc(array_size * sizeof(int));
      int * sorted_arr = malloc(array_size * sizeof(int));

      if ( NULL == (unsorted_arr = malloc(10 * sizeof(int))) ) {
      printf("Unsorted Array Malloc Failed\n");
      return(-1);
      }

      if ( NULL == (sorted_arr = malloc(10 * sizeof(int))) ) {
      printf("Sorted Array Malloc Failed\n");
      return(-2);
      }

    break;
    default :
      //Option if an invalid selection is made
      printf("You did not make a valid selection.\n" );
    }
  }


	/* Wrap up */
  free(unsorted_arr);
  free(sorted_arr);

	return 0;
}
