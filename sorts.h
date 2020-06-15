#ifndef SORTS_H
#define SORTS_H

/**
 * @brief Sorts the given integer array using bubble sort
 * 
 * @param list pointer to the first element in the array
 * @param size size of the array
 * @param verbose 'V' if passes are to be printed to standard output (linux colors)
 */
void bubble_sort(int * list, unsigned int size, char verbose);

/**
 * @brief Sorts the given integer array using bubble sort
 * 
 * @param list pointer to the first element in the array
 * @param size size of the array
 * @param verbose 'V' if passes are to be printed to standard output (linux colors)
 */
void selection_sort(int * list, unsigned int size, char verbose);

/**
 * @brief Sorts the given integer array using merge sort
 *
 * @param list pointer to the first element in the array
 * @param size size fo the array
 * @param verbose 'V', if passes are to be printed to stdout
 */
void merge_sort(int * list, unsigned int size, char verbose);
#endif /*SORTS_H*/