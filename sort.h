#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "randomvectorset.h"
#include "binarysearchtree.h"

enum sortFunctions {
	MERGE_SORT,
	INSERTION_SORT,
	SELECTION_SORT,
	QUICK_SORT,
	BINARY_SEARCH_TREE_SORT,
	HEAP_SORT,
	STD_SORT,
	END
};



namespace Sort {

	template<class T>
	void mergeSort(std::vector<T> vectorToSort) {

		int i, j, k, lower1, lower2, size, upper1, upper2;

		int n = vectorToSort.size();

		std::vector<T> help;

		for(unsigned int x = 0; x < vectorToSort.size(); x++) {
			help.push_back(0);
		}

		size = 1;
		while(size < n) {
			lower1 = 0;
			k = 0;
			while(lower1 + size < n) {
				upper1 = lower1 + size - 1;
				lower2 = upper1 + 1;
				upper2 = (lower2 + size - 1 < n) ? lower2 + size-1 : n-1;
				for(i = lower1, j = lower2; i <= upper1 && j <= upper2; k++)
					if(vectorToSort[i] < vectorToSort[j])
						help[k] = vectorToSort[i++];
					else
						help[k] = vectorToSort[j++];

				for(; i <= upper1; k++)
					help[k] = vectorToSort[i++];
				for(; j <= upper2; k++)
					help[k] = vectorToSort[j++];

				lower1 = upper2 + 1;
			} // endwhile

			for(i=lower1; k<n; i++)
				help[k++] = vectorToSort[i];
			for(i=0; i<n; i++)
				vectorToSort[i] = help[i];

			size = size*2;
		} //endwhile
	}

	template<class T>
	void insertionSort(std::vector<T> vectorToSort);

	template<class T>
	void swap(int *xp, int *yp) {
		int temp = *xp;
		*xp = *yp;
		*yp = temp;
	}

	template<class T>
	void selectionSort(std::vector<T> vectorToSort) {

		int n = vectorToSort.size();
		int i, j, minIndex;

		// One by one move boundary of unsorted subarray
		for(i = 0; i < n-1; i++) {
			// Find the minimum element in unsorted array
			minIndex = i;
			for(j = i+1; j < n; j++)
				if(vectorToSort[j] < vectorToSort[minIndex])
					minIndex = j;

			// Swap the found minimum element with the first element
			swap<T>(&vectorToSort[minIndex], &vectorToSort[i]);
		}
	}

	template<class T>
	void quickSort(std::vector<T> vectorToSort);

	template<class T>
	void binarySearchTreeSort(std::vector<T> vectorToSort) {

		BinarySearchTree<T>* binarySearchTree = new BinarySearchTree<T>;

		for(unsigned int i = 0; i < vectorToSort.size(); i++) {
			binarySearchTree->insert(vectorToSort[i]);
		}
	}

	template<class T>
	void heapSort(std::vector<T> vectorToSort) {
		std::sort_heap(vectorToSort.begin(), vectorToSort.end());
	}

	template<class T>
	void stdSort(std::vector<T> vectorToSort) {
		std::sort(vectorToSort.begin(), vectorToSort.end());
	}

	template<class T>
	double testTime(int vectorSize, int vectorAmount, sortFunctions sortFunctionToTest) {

		auto vectors = new RandomVectorSet<int>(vectorSize, vectorAmount);
		auto start = std::chrono::high_resolution_clock::now();

		for(unsigned int j = 0; j < vectors->m_vectorSet.size(); j++) {
			switch(sortFunctionToTest) {
				case MERGE_SORT :
					mergeSort<T>(vectors->m_vectorSet[j]);
					break;
					//				case INSERTION_SORT : insertionSort<T>(vectors->m_vectorSet[j]);
				case SELECTION_SORT : selectionSort<T>(vectors->m_vectorSet[j]);
					//				case QUICK_SORT : quickSort<T>(vectors->m_vectorSet[j]);
				case BINARY_SEARCH_TREE_SORT : binarySearchTreeSort<T>(vectors->m_vectorSet[j]);
				case HEAP_SORT : heapSort<T>(vectors->m_vectorSet[j]);
				case STD_SORT :
					stdSort<T>(vectors->m_vectorSet[j]);
					break;
				case END :
					break;
			}
		}

		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		double durationInSeconds = duration.count() * 0.000000001;

		return durationInSeconds;

	}
}


#endif // SORT_H
