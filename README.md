# Testing-Sorting-Algorithms
2018
A comparison between sorting algorithms done as part of a school assignment.
Wrote a small program and report on this topic.

## Introduction

Sorting seems to come natural to us humans, it is something we do a lot. We like to arrange things or data in a certain order based on our own criteria. Sometimes to improve the readability of that data, and other times to make it easier and faster to search for or extract specific data.
<br><br>
We see it all around us, wether we are sorting our money bills by value before we count their sum or looking up a word alphabetically in a dictionary, sorting is a processes that can make certain tasks a lot easier and less time consuming.

## Why do we need sorting algorithms
Sorting can also make certain tasks easier and less time consuming for computers. If we imagine a list of unsorted data, a computer would have to do what we call a linear search. This means it would have to start at the beginning of the list, and look at every single element until it finds the one it is looking for. Of course it might get lucky, but what it is searching for might not even be in that list. In this worst case scenario the computer would still have to look at every single element. Using this type of search when dealing with big sets of data, will require a lot of processing power and time. However, if we were to sort this data before searching, we could greatly reduce the cost of the search by for example doing a binary search - leading to much quicker results.
<br>Here is a mathematical comparison to show this reduced cost:

> __Unsorted: Linear Search__
<br>  _size = n → n comparisons_

> __Sorted: Binary Search__
<br> _size = n → log2 n comparisons_


Luckily, there exists a lot of sorting algorithms that can help us sort our datasets. In fact, there are so many it can be difficult to find the one most suited for your specific needs. We will take a look at a few of the more known and common ones throughout this report, and compare them to see what makes them differ from each other.

### How I test performance

I have created a simple QT Application to run and test these algorithms. It might not produce an exact result due to some delays caused by debugging-elements. However, all sorting functions suffer the same delays, so relative to each other they should still be comparable. 

![QT Application UI](/images/UI.png)

The image above shows the basic layout of the application. In order to handle dynamic array sizes, it uses vectors rather than arrays. The user can chose how many vectors to create, and how long each of them will be. This is to be able to better test the difference in performance between the sort functions. One function might be better at sorting one very big array, while another may be better at sorting many small arrays. Almost all of the code is templated, so it would be easy to make it work on different data types, but for now it fills each vector with an integer between 1 and 100.

## The different Sorting Algorithms

There will be a few collective indications on each sorting function:
> __Time complexity:__ Big O notation on the expected runtime 
<br>__In-Place:__ Means that the sorting uses no extra memory


### Selection Sort

Selecting sort is one of the simpler sorting algorithms, and is quite intuitive. 
<br>It uses one array, divided into two subarrays: one sorted subarray that starts off empty and one containing the remaining unsorted subarray. 
The algorithm repeatedly finds the smallest element in the unsorted subarray and adds it to the sorted subarray by swapping it with the element directly after the highest element in the sorted subarray, until you are eventually left with one fully sorted array.

> __Time Complexity:__ O(n^2) 
<br>as there are two nested loops.
<br>__In-Place:__ Yes, using only one array it does not require extra space.

![Selection Sort Performance](/images/SelectionSort.png)

### Insertion Sort

In the same way selection sort consists of two subarrays, so does Insertion sort, one sorted left, and one unsorted right part. At first the sorted subarray contains only one element, and we keep track of where the sorted subarray ends and the unsorted starts. We then take the first element in the unsorted subarray, and going left compare it to the elements in the sorted subarray one by one. The goal is to insert the element at the correct position, and to do this it swaps places with the element on its left until it finds an element smaller than itself. Then we look at the next unsorted card, repeating this process leaves us with a fully sorted array.

Insertion sort can be used when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array. Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted.

> __Time Complexity:__ O(n^2)
<br> It is still better than Selection Sort because it requires fewer swaps on average
<br> __In-Place:__ Yes, only uses one array

![Insertion Sort Performance](/images/InsertionSort.png)

### Merge Sort

Unlike the two previous algorithms, Merge sort is a recursive algorithm, reducing itself in a self-similar manner. It operates by spitting the original unsorted array into two equal arrays and then repeats by further splitting those two into four new ones, this goes on until we are left with arrays of only single elements. We then merge two and two arrays by comparing their leftmost untouched index's data, whichever is smallest overwrites the leftmost unsorted index of the array they once split from. By doing this, we reduce the problem to sub problems, sorting the children and merging them to replace the parent. This all happens recursively, so we focus on one split array at a time, and when the parent is sorted, and we are done with the child, we delete it from memory before moving on.

> __Time Complexity:__  O(n log n)
<br> in all 3 cases (worst, average and best) as merge sort always divides the array in two halves and take linear time to merge two halves.
<br>__In-Place:__ No, Creates new arrays when sorting, so uses more memory.

![Merge Sort Performance](/images/MergeSort.png)

### std::Sort

`std::sort()` is C++ Standard Library's generic sort function. It uses something called Intro Sort, which is a hybrid algorithm, meaning that it uses more than one sorting algorithm. By using three sorting algorithm to minimise the running time, Quicksort, Heapsort and Insertion Sort, it is possibly the best sorting algorithm there is.

> __Time Complexity:__ O(n log n)
<br> __In-Place:__ Yes

![std::Sort Performance](/images/stdSort.png)

### Binary Search Tree

A binary search tree does not use an array like the other sorting functions mentioned here, instead it sets up a node-based binary tree data structure with the following properties:
* The left subtree of a node contains only nodes with keys lesser than the node’s key.
* The right subtree of a node contains only nodes with keys greater than the node’s key.
* The left and right subtree each must also be a binary search tree.

When sorting using this method we do not actually restructure an array, though we can collect data from an array and insert it into the binary tree. The sorting has to do with how we collect data from the tree once it is filled, by traversing in a certain order we can easily collect the data and place it back into the original array fully sorted.
Depending on what you want, an array would usually be preferable since its elements are placed in consecutive order in memory, while nodes in a binary tree can be random. However binary trees have the advantage that they are always sorted.

> __Time Complexity:__ Average: O(log n)

![Binary Search Tree Performance](/images/BinarySearchTree.png)

### Heap Sort

Just like a Binary Search Tree, Heap sort does not use an array but instead its own binary tree data structure using either one of these properties:
* Max heap: A parent node needs to be larger than its children
* Min heap: A parent node needs to be smaller than its children

However, because of its structure and the way it always fills the next empty node to create a Complete Binary Tree, it is often represented as an array. This is because we can calculate what position in an array corresponds to which node in a filled binary tree. If the parent node is at index i, and indexing starts at 0:
* left child = 2 x i + 1
* right child = 2 x i + 2

It is similar to selection sort in that it uses a sorted and unsorted part, finds the largest element and places it at the end of the heap. This process is repeated until the heap is fully sorted.

> __Time Complexity:__ O(n log n).
<br> __In-Place:__ Yes

![Heap Sort Performance](/images/HeapSort.png)

## Conclusion}

Looking at these different performances side by side like in the image with 100000 elements it is easy to see that std::Sort and Binary Search Tree by far outperforms the rest when it comes to large sets of data. However, when sorting smaller sets of data as seen in the image with 1000 elements it does not really matter, they all perform quite well. Using the std::sort as a standard could be a good idea though, as it performs well in all shown cases, also when dealing with multiple datasets as seen in the final image using 1000 vectors.

![Small dataset](/images/smallDataset.png)
![Large dataset](/images/largeDataset.png)

![More than one dataset](/images/severalVectors.png)
