#include "heapsort.h"

bool MAX_HEAP_FUNC(int a, int b) { return a > b; }
bool MIN_HEAP_FUNC(int a, int b) { return a < b; }

void heap::swap(int i, int j)
{
	int temp = this->arr[i];
	this->arr[i] = this->arr[j];
	this->arr[j] = temp;
	temp = indexArr[i];
	indexArr[i] = indexArr[j];
	indexArr[j] = temp;
}

heap::heap(function<bool(int, int)>func, vector<int> arr) :compareFunc(func), arr(arr)
{
	this->arrSize = arr.size();
	for (int i = 0; i < arrSize; i++) {
		indexArr.push_back(i);
	}
	buildHeap();
}

void heap::insert(int num)
{
	arr.push_back(num);
	arrSize += 1;
	shiftUp(arrSize - 1);
}

void heap::shiftUp(int idx)
{
	int parent = (idx - 1) / 2;
	while (idx > 0) {
		if (compareFunc(arr[parent], arr[idx])) {
			swap(idx, parent);
			idx = parent;
			parent = (idx - 1) / 2;
		}
	}
}

void heap::shiftDown(int idx, int endIdx)
{
	int childOneIdx = 2 * idx + 1;
	while (childOneIdx < endIdx) {
		int childTwoIdx = 2 * idx + 2 < endIdx ? 2 * idx + 2 : -1;
		int idxToSwap;
		if (childTwoIdx != -1) {
			if (compareFunc(arr[childTwoIdx], arr[childOneIdx])) {
				idxToSwap = childTwoIdx;
			}
			else {
				idxToSwap = childOneIdx;
			}

		}
		else {
			idxToSwap = childOneIdx;
		}
		if (compareFunc(arr[idxToSwap], arr[idx])) {
			swap(idx, idxToSwap);
			idx = idxToSwap;
			childOneIdx = 2 * idx + 1;
		}
		else return;
	}
}

void heap::remove()
{
	swap(0, arrSize - 1);
	arr.pop_back();
	shiftDown(0, arrSize);
}

void heap::buildHeap()
{
	int start = (arrSize - 2) / 2;
	for (int i = start; i >= 0; i--) {
		shiftDown(i, arrSize);
	}
}


void heap::heapSort()
{
	buildHeap();
	//int length = arrSize;
	for (int end = arrSize - 1; end > 0; end--) {
		swap(0, end);
		shiftDown(0, end);
	}
}

void heap::printArr()
{
	int TwentyLine = (arrSize - 1) / 20 + 1;

	for (int i = 0, k = 0; i < TwentyLine; i++) {
		if (i == TwentyLine - 1) {
			while (k < arrSize) {
				cout << arr[k++] << "\t";
			}
		}
		else {
			for (int j = 0; j < 20; j++, k++)cout << arr[k] << "\t";
		}
		cout << endl;
	}

}