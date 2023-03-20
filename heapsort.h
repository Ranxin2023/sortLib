#pragma once
#include<iostream>
#include<vector>
#include<functional>
using namespace std;
#ifndef HEAP_H
#define HEAP_H
bool MAX_HEAP_FUNC(int a, int b);
bool MIN_HEAP_FUNC(int a, int b);
class heap {
private:
	vector<int>arr;
	vector<int>indexArr;
	function<bool(int, int)>compareFunc;
	int arrSize = 0;
	void swap(int i, int j);
public:
	heap(function<bool(int, int)>func, vector<int>arr);
	void insert(int num);
	void shiftUp(int idx);
	void shiftDown(int idx, int endIdx);
	void remove();
	void buildHeap();
	//bool changeSize(int length);
	void heapSort();
	void printArr();
};


#endif
