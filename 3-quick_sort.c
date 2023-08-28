#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swaps integers in array.
 * @a: first integer to be swapped.
 * @b: second integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - arrange array subset of integers according to
 * lomuto partition scheme with the last element as the pivot.
 * @array: array of integers.
 * @size: array size.
 * @left: first index of subset to be arranged.
 * @right: last index of subset to be arranged.
 *
 * Return: returns final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *driver, up, down;

	driver = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *driver)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *driver)
	{
		swap_ints(array + up, driver);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - activates quicksort algorithm by recursion.
 * @array: Array of integers to be sorted.
 * @size: Array size.
 * @left: First index of array partition to be arranged.
 * @right: Last index of array partition to be arranged.
 *
 * Description: utilizes the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, belong - 1);
		lomuto_sort(array, size, belong + 1, right);
	}
}

/**
 * quick_sort - Sort array of integers in ascending
 * order with quicksort algorithm.
 * @array: array of integers.
 * @size: array size.
 *
 * Description: Utilizes Lomuto partition scheme and prints
 * array after every swap.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
