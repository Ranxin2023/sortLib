//#include<iostream>
int* merge(int[], int[], int, int);
int * merge_sort_helper(int [], int, int);
void merge_sort(int arr[], int n) {
	int* new_arr = merge_sort_helper(arr, 0, n - 1);
	for (int i = 0; i < n; i++ ) {
		arr[i] = new_arr[i];
	}
}
int * merge_sort_helper(int arr[] , int start, int end) {
	if (start == end) {
		return new int [] {arr[start]};
	}
	int mid = (start + end) / 2;
	return merge(merge_sort_helper(arr, start, mid), merge_sort_helper(arr, mid+1, end), mid-start+1, end-mid);
}

int* merge(int left[], int right[], int left_size, int right_size) {
	int* res = new int[left_size+right_size];
	int i = 0, l = 0, r = 0;
	for (; i < left_size + right_size; i++) {
		if (l >= left_size) {
			res[i] = right[r++];
		}
		else if (r >= right_size) {
			res[i] = left[l++];
		}
		else if (left[l] > right[r]) {
			res[i] = right[r++];
		}
		else {
			res[i] = left[l++];
		}
	}
	return res;
}