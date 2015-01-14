#include <iostream> 
#include <vector> 
#include <string> // windows.h is specific for windows.  For Linux please use // 
#include <stdlib.h> // #include <sys/time.h> 
#include <windows.h> 
//#include "SortImpls.h"
#include "JeenSort.h"

using namespace std;

void PrinArray(const vector<int> &array, string name); 
void InitArray(vector<int> &array, int randMax);

int main(int argc, char* argv[])
{
	if (argc != 3) 
	{ 
		cout << "Usage: Sorter SORT_TYPE ARRAY_SIZE"; 
		return -1; 
	}
	string sort_name = string(argv[1]); 
	int size = atoi(argv[2]);
	if (size <= 0) 
	{ 
		cerr << "array size must be positive" << endl; 
		return -1; 
	}

	srand(1); 
	vector<int> items(size); 
	InitArray(items, size); 
	cout << "Sort employed:  " << sort_name << endl; 
	cout << "initial:" << endl; 
	PrinArray(items, string("items"));
	
	// GetTickCount is windows specific.    
#if WIN32
	int begin = GetTickCount();
#else
	struct timeval startTime, endTime; 
	gettimeofday(&startTime, 0);
#endif

	if (sort_name == "BubbleSort")
	{
		BubbleSort(items, 0, items.size() - 1);
	}
	else if (sort_name == "InsertSort")
	{
		InsertSort(items, 0, items.size() - 1);
	}
	else if (sort_name == "MergeSort")
	{
		MergeSort(items, 0, items.size() - 1);
	}
	else if (sort_name == "IterativeMergeSort")
	{
		IterativeMergeSort(items, 0, items.size() - 1);
	}
	else if (sort_name == "QuickSort")
	{
		QuickSort(items, 0, items.size() - 1);
	}
	
#if WIN32
	int end = GetTickCount(); 
#else
	gettimeofday(&endTime, 0);
#endif

	cout << "sorted:" << endl;    
	PrinArray(items, string("item")); 

#if WIN32
	int elapsed_secs = end - begin;
#else
	int elapsed_secs = elapsed( startTime, endTime);
#endif
	cout << "Time (ms): " << elapsed_secs << endl;
	return 0;
}

// array initialization with random numbers 
void InitArray(vector<int> &array, int randMax) 
{ 
	int size = array.size();
	for (int i = 0; i < size;) 
	{ 
		int tmp = (randMax == -1) ? rand() : rand() % randMax; 
		bool hit = false; 
		for (int j = 0; j < i; j++) 
		{ 
			if (array[j] == tmp) 
			{ 
				hit = true; 
				break; 
			} 
		} 
		if (hit) 
		{ 
			continue; 
		} 
		array[i] = tmp; i++; 
	}
}

// Function to Print Array 
void PrinArray(const vector<int> &array, string name) 
{ int size = array.size();
	for (int i = 0; i < size; i++) 
		cout << name << "[" << i << "] = " << array[i] << endl;
}

// Function to calculate elapsed time is using gettimeofday // 
int elapsed( timeval &startTime, timeval &endTime )  
{  
	return ( endTime.tv_sec - startTime.tv_sec ) * 1000000 + ( endTime.tv_usec - startTime.tv_usec ); 
}