//================================================================
// SortImpls.h
// Robert House
//
// Different implementations of sort algorithms for Assignment 4.
// ===============================================================

#ifndef SORTIMPLS_H
#define SORTIMPLS_H

#pragma once
#include <vector>
#include <algorithm>

using namespace std;

#pragma region BubbleSort
void BubbleSort(vector<int> &list, int start, int length)
{
	int temp = 0;

	for (int i = 0; i < list.size(); i++)
	{
		for (int j = 1; j < list.size() - i; j++)
		{
			if (list[j - 1] > list[j])
			{
				// Swap (std::swap)
				swap(list[j], list[j - 1]);

			}
		}
	}
}
#pragma endregion

#pragma region Insert Sort
void InsertSort(vector<int> &list, int start, int length)
{
	int temp = 0;
	int j = 0;

	for (int i = 1; i < list.size(); i++)
	{
		if (list[i] < list[i - 1])
		{
			temp = list[i];
			j = i;

			// Never really used a do-while loop before. Change it up from
			// doing another nested for loop!
			do
			{
				// Shift down
				list[j] = list[j - 1];
				j--;
			} while (j > 0 && list[j - 1] > temp);

			// Insert!
			list[j] = temp;
		}
	}
}
#pragma endregion

#pragma region MergeSort
void Merge(vector<int> &list, int start, int middle, int end)
{
	vector<int> temp;


	// Clamp to list size so we don't out of bounds
	if (middle > list.size() - 1)
	{
		middle = (list.size() - 1);
	}

	int first1 = start;
	int end1 = middle;
	int first2 = middle + 1;
	int end2 = end;
	int index = 0; // So the temp array doesn't go out of bounds

	// Loop through and add values to the temp list while the first1 and first2
	// indices don't pass the ends of the sub arrays
	while ((first1 <= end1) && (first2 <= end2))
	{
		if (list[first1] <= list[first2])
		{
			temp.push_back(list[first1]);
			first1++;
		}
		else
		{
			temp.push_back(list[first2]);
			first2++;
		}
	}

	// Fill in the rest of the values if sub array 2 is smaller
	while (first1 <= end1)
	{
		temp.push_back(list[first1]);
		first1++;
	}

	// Fill in the rest of the values if sub array 1 is smaller
	while (first2 <= end2)
	{
		temp.push_back(list[first2]);
		first2++;
	}

	// Copy back
	for (int i = start; i <= end; i++)
	{
		list[i] = temp[index];
		index++;
	}
}

void MergeSort(vector<int> &list, int start, int length)
{
	if (start < length)
	{
		int middle = (start + length) / 2;

		MergeSort(list, start, middle);
		MergeSort(list, middle + 1, length);
		Merge(list, start, middle, length);
	}

}
#pragma endregion

#pragma region Iterative Merge Sort
void IterativeMergeSort(vector<int> &list, int start, int length)
{
	// first select groups of 2 then 4, 8, ect...
	for (int i = 1; i < list.size(); i *= 2)
	{
		// Merge the sub arrays by selecting the starting point, j.
		for (int j = 0; j < list.size(); j += 2 * i)
		{
			Merge(list, j, j + i - 1, min((j + 2 * i - 1), list.size() - 1));
		}
	}
}
#pragma endregion

#pragma region QuickSort
void QuickSort(vector<int> &list, int start, int length)
{
	int i = start;
	int j = length;
	int temp = 0;
	int pivot = list[(i + j) / 2];

#pragma region Split
	// Split the array
	while (i <= j)
	{
		while (list[i] < pivot)
		{
			// Iterate through the list until we find a
			// value greater than the pivot
			i++;
		}
		while (list[j] > pivot)
		{
			// Iterate the opposite direction through the 
			// list until a value greater than the pivot
			// is found
			j--;
		}

		// Swap
		if (i <= j)
		{
			swap(list[i], list[j]);
			i++;
			j--;
		}
	}
#pragma endregion

	// Recurse
	if (start < j)
	{
		QuickSort(list, start, j);
	}
	if (i < length)
	{
		QuickSort(list, i, length);
	}
}
#pragma endregion
#endif