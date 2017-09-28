#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void merge_(int* a, int left, int mid, int right)
{
	int n = right - left + 1;
	int* b = new int[n];
	int index_1 = left;
	int index_2 = mid + 1;
	int count_ = 0;
	while (index_1 <= mid && index_2 <= right)
	{
		if (a[index_1] < a[index_2])
		{
			b[count_] = a[index_1];
			index_1++;
		}
		else
		{
			b[count_] = a[index_2];
			index_2++;
		}
		count_++;
	}
	if (n > count_)
	{
		if (index_1 > mid)
		{
			for (int i = count_; i < n; i++)
			{
				b[i] = a[index_2 - count_ + i];
			}
		}
		else
		{
			for (int i = count_; i < n; i++)
			{
				b[i] = a[index_1 - count_ + i];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		a[left + i] = b[i];
	}
}

void mergesort(int* a, int left, int right)
{
	if (left >= right) return;
	int mid = (left + right) / 2;
	mergesort(a, left, mid);
	mergesort(a, mid + 1, right);
	merge_(a, left, mid, right);
}

int partition_(int* a, int left, int right)
{
	int pivot = rand() % (right - left + 1) + left;
	int key = a[pivot];

	int victim = a[left];
	a[left] = a[pivot];
	a[pivot] = victim;
	//exchange the value of integer[left] & integer[pivot]

	int index_1 = left + 1;
	int index_2 = right;
	while (index_1 < index_2)
	{
		for (int i = index_1; i <= right; i++)
		{
			if (a[i] > key)
			{
				index_1 = i;
				break;
			}
			if (i == right)
				index_1 = right + 1;
		}
		for (int i = index_2; i > left; i--)
		{
			if (a[i] < key)
			{
				index_2 = i;
				break;
			}
			if (i == left + 1)
				index_2 = left;
		}
		if (index_1 < index_2)
		{
			victim = a[index_1];
			a[index_1] = a[index_2];
			a[index_2] = victim;
		}
	}
	if (key > a[index_2])
	{
		a[left] = a[index_2];
		a[index_2] = key;
	}
	return index_2;
	//exchangepivot&index_2
}

void quicksort_inplace(int* a, int left, int right)
{
	if (left >= right) return;
	int index = partition_(a, left, right);
	quicksort_inplace(a, left, index - 1);
	quicksort_inplace(a, index + 1, right);
}

int partition_extra(int* a, int left, int right)
{
	int n = right - left + 1;
	int* b = new int[n];
	int pivot = rand() % (right - left + 1) + left;
	int key = a[pivot];

	int victim = a[left];
	a[left] = a[pivot];
	a[pivot] = victim;

	int index_1 = 0;
	int index_2 = n - 1;
	for (int i = left + 1; i <= right; i++)
	{
		if (a[i] < key)
		{
			b[index_1] = a[i];
			index_1++;
		}
		else
		{
			b[index_2] = a[i];
			index_2--;
		}
	}
	b[index_1] = key;
	for (int i = 0; i < n; i++)
	{
		a[left + i] = b[i];
	}
	return left + index_1;
}

void quicksort_extra(int* a, int left, int right)
{
	if (left >= right) return;
	int index = partition_extra(a, left, right);
	quicksort_extra(a, left, index - 1);
	quicksort_extra(a, index + 1, right);
}

void print(int* integer, int integer_number)
{
	for (int i = 0; i < integer_number; i++)
	{
		cout << integer[i] << endl;
	}
}

int main()
{
	int sort_value;
	int integer_number;
	cin >> sort_value;
	cin >> integer_number;
	//int integer[integer_number];
	int* integer = new int[integer_number];
	for (int i = 0; i < integer_number; i++)
	{
		cin >> integer[i];
	}
	//read file
	//save integer_number and all integers in integer[]

	if (sort_value == 0)
	{
		for (int i = 0; i < integer_number; i++)
		{
			for (int j = 0; j < integer_number - 1 - i; j++)
			{
				if (integer[j] > integer[j + 1])
				{
					swap(integer[j], integer[j + 1]);
				}
			}
		}
		print(integer, integer_number);
	}
	//bubble sort

	if (sort_value == 1)
	{
		for (int i = 1; i < integer_number; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (integer[i] < integer[j])
				{
					int victim = integer[i];
					for (int k = i - 1; k >= j; k--)
					{
						integer[k + 1] = integer[k];
					}
					integer[j] = victim;
				}
			}
		}
		print(integer, integer_number);
	}
	//insertion sort

	if (sort_value == 2)
	{
		for (int i = 0; i < integer_number - 1; i++)
		{
			int min = integer[i];
			int index = i;
			for (int j = i + 1; j < integer_number; j++)
			{
				if (integer[j] < min)
				{
					min = integer[j];
					index = j;
				}
			}

			if (i != index)
			{
				int victim = integer[i];
				integer[i] = integer[index];
				integer[index] = victim;
			}

		}
		print(integer, integer_number);
	}
	//selection sort

	if (sort_value == 3)
	{
		mergesort(integer, 0, integer_number - 1);
		print(integer, integer_number);
	}
	//merger sort

	if (sort_value == 5)
	{
		quicksort_inplace(integer, 0, integer_number - 1);
		print(integer, integer_number);
	}
	//quick sort in place
	if (sort_value == 4)
	{
		quicksort_extra(integer, 0, integer_number - 1);
		print(integer, integer_number);
	}
	//quick sort extra array

}

