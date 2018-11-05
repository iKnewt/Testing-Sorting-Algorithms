#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "randomvectorset.h"

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
	void merge(std::vector<T> vectorToSort, int leftIndex, int middleIndex, int rightIndex) {

		int	i, j, k;
		int n1 = middleIndex - leftIndex + 1;
		int n2 = rightIndex - middleIndex;

		/* create temp arrays */
		std::vector<T> tempVecOne;
		std::vector<T> tempVecTwo;

		/* Copy data to temp arrays L[] and R[] */
		for(i = 0; i < n1; i++)
			tempVecOne.push_back(vectorToSort[leftIndex + i]);
		for(j = 0; j < n2; j++)
			tempVecTwo.push_back(vectorToSort[middleIndex + 1 + j]);

		/* Merge the temp arrays back into arr[l..r]*/
		i = 0; // Initial index of first subarray
		j = 0; // Initial index of second subarray
		k = leftIndex; // Initial index of merged subarray
		while (i < n1 && j < n2) {
			if(tempVecOne[i] <= tempVecTwo[j]) {
				vectorToSort[k] = tempVecOne[i];
				i++;
			}
			else {
				vectorToSort[k] = tempVecTwo[j];
				j++;
			}
			k++;
		}

		/* Copy the remaining elements of L[], if there
		   are any */
		while(i < n1) {
			vectorToSort[k] = tempVecOne[i];
			i++;
			k++;
		}

		/* Copy the remaining elements of R[], if there
		   are any */
		while(j < n2) {
			vectorToSort[k] = tempVecTwo[j];
			j++;
			k++;
		}
	}

	template<class T>
	void mergeSort(std::vector<T> vectorToSort, int leftIndex, int rightIndex) {
		if(leftIndex < rightIndex) {
			// Same as (l+r)/2, but avoids overflow for
			// large l and h
			int middleIndex = leftIndex + ( rightIndex - leftIndex) / 2;

			// Sort first and second halves
			mergeSort(vectorToSort, leftIndex, middleIndex);
			mergeSort(vectorToSort, middleIndex + 1, rightIndex);

			merge(vectorToSort, leftIndex, middleIndex, rightIndex);
		}
	}

	template<class T>
	void mergeSort(std::vector<T> vectorToSort) {

		int rightIndex = vectorToSort.size() - 1;
		mergeSort(vectorToSort, 0, rightIndex);
	}

	template<class T>
	void insertionSort(std::vector<T> vectorToSort);

	template<class T>
	void selectionSort(std::vector<T> vectorToSort);

	template<class T>
	void quickSort(std::vector<T> vectorToSort);

	template<class T>
	void binarySearchTreeSort(std::vector<T> vectorToSort);

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
					//					case insertionSort : insertion<T>(tempVector[j]);
					//					case selectionSort : selection<T>(tempVector[j]);
					//					case quickSort : quick<T>(tempVector[j]);
					//					case binarySearchTreeSort : binarySearchTree<T>(tempVector[j]);
				case HEAP_SORT : heapSort<T>(vectors->m_vectorSet[j]);
				case STD_SORT :
					stdSort<T>(vectors->m_vectorSet[j]);
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
