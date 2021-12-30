#include "push_swap.h"

int	partition(int *array, int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	pivot = array[high];
	i = low;
	j = high - 1;
	while (i < j)
	{
		while (array[i] < pivot && i < high)
			i++;
		while (array[j] > pivot && j > i)
			j--;
		if (i < j)
			swap_int(&array[i], &array[j]);
	}
	if (array[i] > array[high])
		swap_int(&array[i], &array[high]);
	return (i);
}

void	quick_sort(int *array, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(array, low, high);
		quick_sort(array, low, pi - 1);
		quick_sort(array, pi + 1, high);
	}
}
