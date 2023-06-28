#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void dump(int *arr, int size)
{
	int idx;

	for (idx = 0; idx < size; idx++)
		printf("%08d\n", arr[idx]);
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int *arr, int p, int r)
{
	//int pivot = arr[r];
	int i, j;

	i = j = p;

	for (; j < r; j++) {
		if (arr[j] < arr[r]) {
			if(i != j)
			{
			swap(arr + i, arr + j);

			}
			i++;
		}
	}
	
	swap(arr + i, arr + r);
	return i;
}

void __quick_sort(int *arr, int p, int r)
{
	int q;

	if (p >= r)
		return;

	q = partition(arr, p, r);
	__quick_sort(arr, p, q-1);
	__quick_sort(arr, q+1, r);
}

void quick_sort(int *arr, int size)
{
	__quick_sort(arr, 0, size - 1);
}

void quick_sort_test()
{
	//int test[10] = {5, 8, 9, 23, 56, 1, 3, 7, 31, 67};
    int a[8] = {6,7,5,3,1,2,4,8};
	quick_sort(a, 8);

	dump(a, 8);
}

int main()
{
	quick_sort_test();
	return 0;
}
