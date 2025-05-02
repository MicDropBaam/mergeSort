#include "mergesort.h"
#include <iostream>
using namespace std;



void merge(int* arr, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int* left = new int[n1];
	int* right = new int[n2];

	for (int i = 0; i < n1; ++i)
		left[i] = arr[l + i];

	for (int i = 0; i < n2; ++i)
		right[i] = arr[m + 1 + i];

	int i = 0;
	int j = 0;
	int k = l;

	while (i < n1 && j < n2)
	{
		if (left[i] < right[j])
			arr[k] = left[i++];
		else
			arr[k] = right[j++];

		++k;
	}
	while (i < n1)
		arr[k++] = left[i++];
	while (j < n2)
		arr[k++] = right[j++];

	delete[] right;
	delete[] left;

}

void mergesort(int* a, unsigned p, unsigned r)
{
	if (p < r)
	{
		int mid = (p + r) / 2;
		mergesort(a, p, mid);
		mergesort(a, mid + 1, r);
		merge(a, p, mid, r);
	}
}
