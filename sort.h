#pragma once

class Sort
{
public:
	Sort() {}
	~Sort() {}
	template<typename T, size_t N>
	static int get_array_length(T(&arr)[N])
	{
		return N;
	}
	template<typename T, size_t N>
	void bubbleSort(T(&arr)[N], bool up = false);	//冒泡排序
	template<typename T, size_t N>
	void selectionSort(T(&arr)[N], bool up = false);	//选择排序
	template<typename T, size_t N>
	void insertionSort(T(&arr)[N], bool up = false);	//插入排序
	template<typename T, size_t N>
	void quickSort(T(&arr)[N], bool up = false);	//快速排序
	template<typename T, size_t N>
	void mergeSort(T(&arr)[N], bool up = false);	//归并排序
	template<typename T, size_t N>
	void heapSort(T(&arr)[N], bool up = false);	//堆排序
	template<typename T, size_t N>
	void countingSort(T(&arr)[N], bool up = false);	//计数排序
	template<typename T, size_t N>
	void radixSort(T(&arr)[N], bool up = false);	//基数排序
	template<typename T, size_t N>
	void shellSort(T(&arr)[N], bool up = false);	//希尔排序
private:
	template<typename T, size_t N>
	void bubbleSort_up(T(&arr)[N], int length);
	template<typename T, size_t N>
	void bubbleSort_down(T(&arr)[N], int length);
	template<typename T, size_t N>
	void selectionSort_up(T(&arr)[N], int length);
	template<typename T, size_t N>
	void selectionSort_down(T(&arr)[N], int length);
	template<typename T, size_t N>
	void insertionSort_up(T(&arr)[N], int length);
	template<typename T, size_t N>
	void insertionSort_down(T(&arr)[N], int length);
	template<typename T, size_t N>
	void quickSort_up(T(&arr)[N], int low, int high);
	template<typename T, size_t N>
	void quickSort_down(T(&arr)[N], int low, int high);
	template<typename T, size_t N>
	void mergeSort_up(T(&arr)[N], int l, int r);
	template<typename T, size_t N>
	void mergeSort_down(T(&arr)[N], int l, int r);
	template<typename T, size_t N>
	void heapSort_up(T(&arr)[N], int n);
	template<typename T, size_t N>
	void heapSort_down(T(&arr)[N], int n);
	template<typename T, size_t N>
	void countingSort_up(T(&arr)[N], int n);
	template<typename T, size_t N>
	void countingSort_down(T(&arr)[N], int n);
	template<typename T, size_t N>
	void bucketSort_up(T(&arr)[N], int n);
	template<typename T, size_t N>
	void bucketSort_down(T(&arr)[N], int n);
	template<typename T, size_t N>
	void shellSort_up(T(&arr)[N], int n);
	template<typename T, size_t N>
	void shellSort_down(T(&arr)[N], int n);
	template<typename T, size_t N>
	void radixSort_up(T(&arr)[N], int n, int exp);	
	template<typename T, size_t N>
	void radixSort_down(T(&arr)[N], int n, int exp);	
protected:
	template<typename T, size_t N>
	T getMax(T(&arr)[N], int n);	//获取最大值
	template<typename T, size_t N>
	T getMin(T(&arr)[N], int n);	//获取最小值
	template<typename T, size_t N>
	int partition_up(T(&arr)[N], int low, int high);	//快速排序辅助函数
	template<typename T, size_t N>
	int partition_down(T(&arr)[N], int low, int high);	//快速排序辅助函数
	template<typename T, size_t N>
	void merge_up(T(&arr)[N], int l, int m, int r);	//归并排序辅助函数
	template<typename T, size_t N>
	void merge_down(T(&arr)[N], int l, int m, int r);	//归并排序辅助函数
	template<typename T, size_t N>
	void heapify_up(T(&arr)[N], int n, int i);	//堆排序辅助函数
	template<typename T, size_t N>
	void heapify_down(T(&arr)[N], int n, int i);	//堆排序辅助函数
};

//
//#include "Sort.h"

template<typename T,size_t N>
void Sort::bubbleSort(T(&arr)[N], bool up)
{
	int length = get_array_length(arr);
	if (up)
	{
		bubbleSort_up(arr, length);
	}
	else
	{
		bubbleSort_down(arr, length);
	}
}

template<typename T,size_t N>
void Sort::bubbleSort_up(T(&arr)[N], int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		for (int j = 0; j < length - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

template<typename T,size_t N>
void Sort::bubbleSort_down(T(&arr)[N], int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		for (int j = 0; j < length - i - 1; ++j)
		{
			if (arr[j] < arr[j + 1])
			{
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

template<typename T,size_t N>
void Sort::selectionSort(T(&arr)[N], bool up)
{
	int length = get_array_length(arr);
	if (up)
	{
		selectionSort_up(arr, length);
	}
	else
	{
		selectionSort_down(arr, length);
	}
}

template<typename T,size_t N>
void Sort::selectionSort_up(T(&arr)[N], int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		int minIndex = i;
		for (int j = i + 1; j < length; ++j)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		T temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

template<typename T,size_t N>
void Sort::selectionSort_down(T(&arr)[N], int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		int maxIndex = i;
		for (int j = i + 1; j < length; ++j)
		{
			if (arr[j] > arr[maxIndex])
			{
				maxIndex = j;
			}
		}
		T temp = arr[i];
		arr[i] = arr[maxIndex];
		arr[maxIndex] = temp;
	}
}

template<typename T,size_t N>
void Sort::insertionSort(T(&arr)[N], bool up)
{
	int length = get_array_length(arr);
	if (up)
	{
		insertionSort_up(arr, length);
	}
	else
	{
		insertionSort_down(arr, length);
	}
}

template<typename T,size_t N>
void Sort::insertionSort_up(T(&arr)[N], int length)
{
	for (int i = 1; i < length; ++i)
	{
		T key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

template<typename T,size_t N>
void Sort::insertionSort_down(T(&arr)[N], int length)
{
	for (int i = 1; i < length; ++i)
	{
		T key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] < key)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

template<typename T,size_t N>
void Sort::quickSort(T(&arr)[N], bool up)
{
	int length = get_array_length(arr);
	if (up)
	{
		quickSort_up(arr, 0, length - 1);
	}
	else
	{
		quickSort_down(arr, 0, length - 1);
	}
}

template<typename T,size_t N>
void Sort::quickSort_up(T(&arr)[N], int low, int high)
{
	if (low < high)
	{
		int pivot = partition_up(arr, low, high);
		quickSort_up(arr, low, pivot - 1);
		quickSort_up(arr, pivot + 1, high);
	}
}

template<typename T,size_t N>
void Sort::quickSort_down(T(&arr)[N], int low, int high)
{
	if (low < high)
	{
		int pivot = partition_down(arr, low, high);
		quickSort_down(arr, low, pivot - 1);
		quickSort_down(arr, pivot + 1, high);
	}
}

template<typename T,size_t N>
int Sort::partition_up(T(&arr)[N], int low, int high)
{
	T pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; ++j)
	{
		if (arr[j] <= pivot)
		{
			++i;
			T temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	T temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return i + 1;
}

template<typename T,size_t N>
int Sort::partition_down(T(&arr)[N], int low, int high)
{
	T pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; ++j)
	{
		if (arr[j] >= pivot)
		{
			++i;
			T temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	T temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return i + 1;
}

template<typename T,size_t N>
void Sort::mergeSort(T(&arr)[N], bool up)
{
	int length = get_array_length(arr);
	if (up)
	{
		mergeSort_up(arr, 0, length - 1);
	}
	else
	{
		mergeSort_down(arr, 0, length - 1);
	}
}

template<typename T,size_t N>
void Sort::mergeSort_up(T(&arr)[N], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort_up(arr, l, m);
		mergeSort_up(arr, m + 1, r);
		merge_up(arr, l, m, r);
	}
}

template<typename T,size_t N>
void Sort::mergeSort_down(T(&arr)[N], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort_down(arr, l, m);
		mergeSort_down(arr, m + 1, r);
		merge_down(arr, l, m, r);
	}
}

template<typename T,size_t N>
void Sort::merge_up(T(&arr)[N], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	T* L = new T[n1];
	T* R = new T[n2];

	for (int i = 0; i < n1; ++i)
	{
		L[i] = arr[l + i];
	}

	for (int j = 0; j < n2; ++j)
	{
		R[j] = arr[m + 1 + j];
	}

	int i = 0, j = 0, k = l;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			++i;
		}
		else
		{
			arr[k] = R[j];
			++j;
		}
		++k;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		++i;
		++k;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		++j;
		++k;
	}

	delete[] L;
	delete[] R;
}

template<typename T,size_t N>
void Sort::merge_down(T(&arr)[N], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	T* L = new T[n1];
	T* R = new T[n2];

	for (int i = 0; i < n1; ++i)
	{
		L[i] = arr[l + i];
	}

	for (int j = 0; j < n2; ++j)
	{
		R[j] = arr[m + 1 + j];
	}

	int i = 0, j = 0, k = l;

	while (i < n1 && j < n2)
	{
		if (L[i] >= R[j])
		{
			arr[k] = L[i];
			++i;
		}
		else
		{
			arr[k] = R[j];
			++j;
		}
		++k;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		++i;
		++k;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		++j;
		++k;
	}

	delete[] L;
	delete[] R;
}

template<typename T,size_t N>
void Sort::heapSort(T(&arr)[N], bool up)
{
	int length = get_array_length(arr);
	if (up)
	{
		heapSort_up(arr, length);
	}
	else
	{
		heapSort_down(arr, length);
	}
}

template<typename T,size_t N>
void Sort::heapSort_up(T(&arr)[N], int n)
{
	for (int i = n / 2 - 1; i >= 0; --i)
	{
		heapify_up(arr, n, i);
	}

	for (int i = n - 1; i > 0; --i)
	{
		T temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		heapify_up(arr, i, 0);
	}
}

template<typename T,size_t N>
void Sort::heapSort_down(T(&arr)[N], int n)
{
	for (int i = n / 2 - 1; i >= 0; --i)
	{
		heapify_down(arr, n, i);
	}

	for (int i = n - 1; i > 0; --i)
	{
		T temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		heapify_down(arr, i, 0);
	}
}

template<typename T,size_t N>
void Sort::heapify_up(T(&arr)[N], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
	{
		largest = left;
	}

	if (right < n && arr[right] > arr[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		T temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;

		heapify_up(arr, n, largest);
	}
}

template<typename T,size_t N>
void Sort::heapify_down(T(&arr)[N], int n, int i)
{
	int smallest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] < arr[smallest])
	{
		smallest = left;
	}

	if (right < n && arr[right] < arr[smallest])
	{
		smallest = right;
	}

	if (smallest != i)
	{
		T temp = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = temp;

		heapify_down(arr, n, smallest);
	}
}

template<typename T,size_t N>
void Sort::countingSort(T(&arr)[N], bool up)
{
	int n = get_array_length(arr);
	if (up)
	{
		countingSort_up(arr, n);
	}
	else
	{
		countingSort_down(arr, n);
	}
}

template<typename T,size_t N>
void Sort::countingSort_up(T(&arr)[N], int n)
{
	T maxVal = getMax(arr, n);
	T minVal = getMin(arr, n);
	int range = maxVal - minVal + 1;

	int* count = new int[range]();

	for (int i = 0; i < n; ++i)
	{
		++count[arr[i] - minVal];
	}

	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (count[i] > 0)
		{
			arr[index++] = i + minVal;
			--count[i];
		}
	}

	delete[] count;
}

template<typename T,size_t N>
void Sort::countingSort_down(T(&arr)[N], int n)
{
	T maxVal = getMax(arr, n);
	T minVal = getMin(arr, n);
	int range = maxVal - minVal + 1;

	int* count = new int[range]();

	for (int i = 0; i < n; ++i)
	{
		++count[arr[i] - minVal];
	}

	int index = 0;
	for (int i = range - 1; i >= 0; --i)
	{
		while (count[i] > 0)
		{
			arr[index++] = i + minVal;
			--count[i];
		}
	}

	delete[] count;
}

template<typename T,size_t N>
void Sort::radixSort(T(&arr)[N], bool up)
{
	int n = get_array_length(arr);
	if (up)
	{
		T maxVal = getMax(arr, n);
		for (int exp = 1; maxVal / exp > 0; exp *= 10)
		{
			radixSort_up(arr, n, exp);
		}
	}
	else
	{
		T minVal = getMin(arr, n);
		for (int exp = 1; minVal / exp > 0; exp *= 10)
		{
			radixSort_down(arr, n, exp);
		}
	}
}

template<typename T,size_t N>
void Sort::radixSort_up(T(&arr)[N], int n, int exp)
{
	T* output = new T[n];
	int count[10] = { 0 };

	for (int i = 0; i < n; ++i)
	{
		++count[(arr[i] / exp) % 10];
	}

	for (int i = 1; i < 10; ++i)
	{
		count[i] += count[i - 1];
	}

	for (int i = n - 1; i >= 0; --i)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		--count[(arr[i] / exp) % 10];
	}

	for (int i = 0; i < n; ++i)
	{
		arr[i] = output[i];
	}

	delete[] output;
}

template<typename T,size_t N>
void Sort::radixSort_down(T(&arr)[N], int n, int exp)
{
	T* output = new T[n];
	int count[10] = { 0 };

	for (int i = 0; i < n; ++i)
	{
		++count[(arr[i] / exp) % 10];
	}

	for (int i = 8; i >= 0; --i)
	{
		count[i] += count[i + 1];
	}

	for (int i = n - 1; i >= 0; --i)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		--count[(arr[i] / exp) % 10];
	}

	for (int i = 0; i < n; ++i)
	{
		arr[i] = output[i];
	}

	delete[] output;
}

template<typename T,size_t N>
void Sort::shellSort(T(&arr)[N], bool up)
{
	int n = get_array_length(arr);
	if (up)
	{
		shellSort_up(arr, n);
	}
	else
	{
		shellSort_down(arr, n);
	}
}

template<typename T,size_t N>
void Sort::shellSort_up(T(&arr)[N], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; ++i)
		{
			T temp = arr[i];
			int j = i;
			while (j >= gap && arr[j - gap] > temp)
			{
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = temp;
		}
	}
}

template<typename T,size_t N>
void Sort::shellSort_down(T(&arr)[N], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; ++i)
		{
			T temp = arr[i];
			int j = i;
			while (j >= gap && arr[j - gap] < temp)
			{
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = temp;
		}
	}
}



template<typename T,size_t N>
T Sort::getMax(T(&arr)[N], int n)
{
	T maxVal = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] > maxVal)
		{
			maxVal = arr[i];
		}
	}
	return maxVal;
}

template<typename T,size_t N>
T Sort::getMin(T(&arr)[N], int n)
{
	T minVal = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] < minVal)
		{
			minVal = arr[i];
		}
	}
	return minVal;
}
