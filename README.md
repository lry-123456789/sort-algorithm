# 排序算法(sort-algorithm) 
通过C++类构建的排序算法（Sorting algorithm made by C++ classes）
## 支持以下算法(support these algorithm）
|算法名称|升序|降序|
|:--:|:--:|:--:|
|bubbleSort|&#10004;|&#10004;|
|countingSort|&#10004;|&#10004;|
|heapSort|&#10004;|&#10004;|
|insertionSort|&#10004;|&#10004;|
|mergeSort|&#10004;|&#10004;|
|quickSort|&#10004;|&#10004;|
|radixSort|&#10004;|&#10004;|
|selectionSort|&#10004;|&#10004;|
|shellSoet|&#10004;|&#10004;|

##  提示 可以使用任意的数组类型传入，通过up = true参数可以调整数组排序方式
```C++
#include<iostream>
#include"sort.h"
Sort sort;
int main()
{
	int a[] = { 1,5,3,4 };
	sort.bubbleSort(a, false);            //以冒泡排序为例，第一个参数为数组传入参数，第二个参数传入为升序或降序(false 降序,true升序)
	//sort.countingSort(a, false);
	//sort.heapSort(a, false);
	//sort.insertionSort(a, false);
	//sort.mergeSort(a, false);
	//sort.quickSort(a, false);
	//sort.radixSort(a, false);
	//sort.selectionSort(a, false);
	//sort.shellSort(a, false);
	for (auto i = 0; i < sort.get_array_length(a); i++)
	{
		std::cout << a[i] << std::endl;
	}
}
```
