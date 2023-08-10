#include"sortlib.h"
#include<iostream>
Sort sort;
/// <summary>
/// 测试：					up			down
/// 测试： bubbleSort		pass		pass
/// 测试： countingSort		pass		pass
/// 测试： heapSort			pass		pass
/// 测试： insertionSort	pass		pass
/// 测试： mergeSort		pass		pass
/// 测试： quickSort		pass		pass
/// 测试： radixSort		pass		pass
/// 测试： selectionSort	pass		pass
/// 测试： shellSort		pass		pass
/// </summary>
/// <returns></returns>
int main()
{
	auto a[] = { 1,5,3,4 };
	std::cout << "a.length=" << sort.get_array_length(a) << std::endl;
	//sort.bubbleSort(a, false);
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
