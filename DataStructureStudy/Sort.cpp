#include "Common.h"
#define Max_DATA 1000

template <typename data, typename compare>
void sequential_sort(data* base, size_t n, compare com)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			if (com(base[i], base[j]) > 0)
			{
				swap(base[i], base[j]);
			}
		}
	}
}

template <typename data, typename compare>
void bubble_sort(data* base, size_t n, compare com)
{
	for (size_t i = n; i > 1; i--)
	{
		for (size_t j = 1; j < i; j++)
		{
			if (com(base[j - 1], base[j]) > 0)
			{
				swap(base[j - 1], base[j]);
			}
		}
	}
}

template <typename data, typename compare>
void selection_sort(data* base, size_t n, compare com)
{
	for (size_t i = 0; i < n; i++)
	{
		size_t min = i;
		for (size_t j = i + 1; j < n; j++)
		{
			if (com(base[min], base[j]) > 0)
			{
				min = j;
			}
		}
		swap(base[i], base[min]);
	}
}

template <typename data, typename compare>
void insertion_sort(data* base, size_t n, compare com)
{
	for (size_t i = 1; i < n; i++)
	{
		for (size_t j = i; j > 0; j--)
		{
			if (com(base[j - 1], base[j]) > 0)
			{
				swap(base[j - 1], base[j]);
			}
			else
			{
				break;
			}
		}
	}
}

int main()
{
	Member* base[Max_DATA];
	MakeRandomMembers(base, 10);
	cout << "Before Sorting" << endl;
	ViewMembers(base, 10);
	insertion_sort(base, 10, CompareByNum);
	cout << "After Sorting By Num" << endl;
	ViewMembers(base, 10);
	insertion_sort(base, 10, CompareByName);
	cout << "After Sorting By Name" << endl;
	ViewMembers(base, 10);
	RemoveMembers(base, 10);

	clock_t st, et;

	MakeRandomMembers(base, Max_DATA);
	cout << "testing test1's number: " << Max_DATA << endl;
	st = clock();
	insertion_sort(base, Max_DATA, CompareByName);
	et = clock();
	cout << "testing time: " << et - st << endl;
	RemoveMembers(base, Max_DATA);

	cout << "testing test2's number" << Max_DATA / 10 << endl;
	st = clock();
	MakeRandomMembers(base, Max_DATA / 10);
	insertion_sort(base, Max_DATA / 10, CompareByName);
	et = clock();
	cout << "testing time: " << et - st << endl;
	RemoveMembers(base, Max_DATA / 10);
	return 0;

}