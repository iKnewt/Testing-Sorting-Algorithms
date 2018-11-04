#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "randomvectorset.h"

enum sortFunctions {
	mergeSort,
	insertionSort,
	selectionSort,
	quickSort,
	binarySearchTreeSort,
	heapSort,
	stdSort,
	end
};



namespace Sort {

	template<class T>
	void merge(std::vector<T> vectorToSort);

	template<class T>
	void insertion(std::vector<T> vectorToSort);

	template<class T>
	void selection(std::vector<T> vectorToSort);

	template<class T>
	void quick(std::vector<T> vectorToSort);

	template<class T>
	void binarySearchTree(std::vector<T> vectorToSort);

	template<class T>
	void heap(std::vector<T> vectorToSort){
		std::sort_heap(vectorToSort.begin(), vectorToSort.end());
	}

	template<class T>
	void std(std::vector<T> vectorToSort){
		std::sort(vectorToSort.begin(), vectorToSort.end());
	}


	template<class T>
	void merge(std::vector<T> vectorToSort){
	}


	template<class T>
	double testTime(int vectorSize, int vectorAmount, sortFunctions sortFunctionToTest) {

		auto vectors = new RandomVectorSet<int>(vectorSize, vectorAmount);
		auto start = std::chrono::high_resolution_clock::now();

		for (unsigned int j = 0; j < vectors->m_vectorSet.size(); j++) {
			switch (sortFunctionToTest) {
				case mergeSort :
					merge<T>(vectors->m_vectorSet[j]);
					break;
					//					case insertionSort : insertion<T>(tempVector[j]);
					//					case selectionSort : selection<T>(tempVector[j]);
					//					case quickSort : quick<T>(tempVector[j]);
					//					case binarySearchTreeSort : binarySearchTree<T>(tempVector[j]);
				case heapSort : heap<T>(vectors->m_vectorSet[j]);
				case stdSort :
					std<T>(vectors->m_vectorSet[j]);
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
