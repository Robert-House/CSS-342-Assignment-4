//
//  SortImpls.h
//  Assignment_4
//
//  Created by Kunlakan Cherdchusilp on 11/5/14.
//  Copyright (c) 2014 shokorakis. All rights reserved.
//

#ifndef Assignment_4_SortImpls_h
#define Assignment_4_SortImpls_h

#include <iostream>
#include <vector>

using namespace std;


void Merge(vector<int> &item, int first, int mid, int last);

int Min(int x, int y)
{
	if (x <= y)
		return x;
	else
		return y;
}

void BubbleSort(vector<int> &item, int begin, int end)
{
	bool sorted = false;
	int newEnd = end;

	while (!sorted && (end - newEnd < end - 1))
	{
		sorted = true;
		for (int i = begin; i < newEnd; i++)
		{
			if (item.at(i) > item.at(i + 1))
			{
				swap(item.at(i), item.at(i + 1));
				sorted = false;
			}
		}
		newEnd--;
	}
}

void InsertSort(vector<int> &item, int begin, int end)
{
	int j, temp;
	for (int i = begin; i < end + 1; i++)
	{
		j = i;
		temp = item.at(i);
		while ((j > 0) && (item.at(j - 1) > temp))
		{
			item.at(j) = item.at(j - 1);
			j--;
		}
		item.at(j) = temp;
	}
}

void MergeSort(vector<int> &item, int begin, int end)
{
	if (begin < end) {
		int mid = begin + (end - begin) / 2;
		MergeSort(item, begin, mid);
		MergeSort(item, mid + 1, end);
		Merge(item, begin, mid, end);
	}
}

void IterativeMergeSort(vector<int> &item, int begin, int end)
{
	int i, j;
	int front, mid, last;
	for (i = 2; i <= end + 1; i *= 2)
	{
		for (j = 0; j < end + 1; j += i)
		{
			front = j;
			last = min(j + i - 1, end);
			mid = (front + last) / 2;
			Merge(item, front, mid, last);
		}
	}

	if (end + 1 % (i / 2) != 0)
	{
		//mid = end - (end + 1) % (i / 2);
		mid = 1;
		Merge(item, 0, mid, end);
	}

	//InsertSort(item, begin, end);

}

void QuickSort(vector<int> &item, int begin, int end)
{
	if (end - begin < 4)
	{
		InsertSort(item, begin, end);
		return;
	}

	int mid = (begin + end) / 2;
	if (item[begin] > item[end])
	{
		swap(item[begin], item[end]);
	}
	if (item[begin] > item[mid])
	{
		swap(item[begin], item[mid]);
	}
	else if (item[mid] > item[end])
	{
		swap(item[mid], item[end]);
	}
	int pivot = item[mid];

	swap(item[mid], item[end - 1]);

	int left = begin + 1;
	int right = end - 2;
	bool done = false;
	while (!done)
	{
		while (item[left] < pivot)
		{
			left++;
		}
		while (item[right] > pivot)
		{
			right--;
		}
		if (right > left)
		{
			swap(item[left], item[right]);
			right--;
			left++;
		}
		else
		{
			done = true;
		}

		swap(item[left], item[end - 1]);
		QuickSort(item, begin, left - 1);
		QuickSort(item, left + 1, end);
	}


}

void Merge(vector<int> &item, int first, int mid, int last)
{
	vector<int> tempArray(item.size());
	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;

	int index = first1;

	//
	while ((first1 <= last1) && (first2 <= last2))
	{
		if (item.at(first1) <= item.at(first2))
		{
			tempArray.at(index) = item.at(first1);
			first1++;
		}
		else
		{
			tempArray.at(index) = item.at(first2);
			first2++;
		}
		index++;
	}

	//
	while (first1 <= last1)
	{
		tempArray.at(index) = item.at(first1);
		first1++;
		index++;
	}

	//
	while (first2 <= last2)
	{
		tempArray.at(index) = item.at(first2);
		first2++;
		index++;
	}

	//
	for (index = first; index <= last; index++)
	{
		item.at(index) = tempArray.at(index);
	}
}

#endif
