#ifndef RANDOMVECTOR_H
#define RANDOMVECTOR_H

#include <iostream>
#include <vector>
#include <string>

template<class T>

class RandomVectorSet {

private:


public:

	RandomVectorSet(int vectorSize, int vectorAmount){
		m_vectorSet = createMultiple(vectorSize, vectorAmount);
	}
	~RandomVectorSet(){}

	std::vector<std::vector<T>> m_vectorSet;

	std::vector<T> create(int size) {
		std::vector<T> tempVector;
		for(int i = 0; i < size; i++) {
			tempVector.push_back(rand() % 1000);
		}
		return tempVector;
	}

	std::vector<std::vector<T>> createMultiple(int vectorSize, int vectorAmount) {
		std::vector<std::vector<T>> tempVector;
		for(int i = 0; i < vectorAmount; i++) {
			tempVector.push_back(create(vectorSize));
		}
		return tempVector;
	}

};

#endif // RANDOMVECTOR_H
