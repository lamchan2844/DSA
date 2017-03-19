#pragma once
#include <iostream>
template <typename T>
class SortKing
{
public:
	SortKing(){};
	~SortKing(){};
	bool less(T& a, T& b){ return a<b; };
	void exchange(T *arr, int lo, int hi);
	int findMax(T* arr, int lo, int hi);
	int findMin(T* arr, int lo, int hi);
	void printArr(T* arr, int lo, int hi);
	void SelectionSort(T *arr, int lo, int hi);
	void InsertSort(T* arr, int lo, int hi);
	void ShellSort(T* arr, int lo, int hi);
	int binSearch(T* arr, int lo, int hi, const T value);
	void MergeSort(T *arr, int lo, int hi);
	void merge(T*arr, int lo, int mi, int hi);
	void MergeSortBU(T *arr, int lo, int hi);
	void QuickSort(T *arr, int lo, int hi);
	void QuickSort_Insert(T *arr, int lo, int hi);
	int partition(T *arr, int lo, int hi);
	void QuickSort_3Way(T* arr, int lo, int hi);

};
template <typename T>
void SortKing<T>::exchange(T *arr, int lo, int hi){
	T tmp = arr[lo];
	arr[lo] = arr[hi];
	arr[hi] = tmp;
}
template <typename T>
int SortKing<T>::findMax(T* arr, int lo, int hi){
	T tmp = arr[lo];
	int flag = lo;
	for (lo = lo + 1; lo<hi; lo++){
		if (less(tmp, arr[lo])){
			flag = lo;
			tmp = arr[lo];
		}
	}
	return flag;
}
template <typename T>
int SortKing<T>::findMin(T* arr, int lo, int hi){
	T tmp = arr[lo];
	int flag = lo;
	for (lo = lo + 1; lo<hi; lo++){
		if (!less(tmp, arr[lo])){
			flag = lo;
			tmp = arr[lo];
		}
	}
	return flag;
}
template <typename T>
void SortKing<T>::printArr(T* arr, int lo, int hi)
{
	for (lo; lo<hi; lo++)
	{
		std::cout << arr[lo] << ", ";
	}
	std::cout << "\n";
}
/*
* 选择排序，O(n^2)
*/
template <typename T>
void SortKing<T>::SelectionSort(T* arr, int lo, int hi)
{
	for (int k = lo; k<hi; k++)
	{
		exchange(arr, k, findMin(arr, k, hi));
	}
}

/*
* 若查找到value，则返回value位置，否则返回不大于value的最靠右位置。
*/
template <typename T>
int SortKing<T>::binSearch(T* arr, int lo, int hi, const T value)
{
	int m = lo;
	while (lo<hi){
		m = (lo + hi) / 2;
		if (arr[m]<value)
			lo = m + 1;
		else if (arr[m]>value)
			hi = m;
		else
			return m;
	}
	return hi - 1;
}
/*
* 插入排序 O(n^2) 比选择排序要快
*/
template <typename T>
void SortKing<T>::InsertSort(T* arr, int lo, int hi)
{
	int tmp;
	int pos;
	for (int i = lo + 1; i<hi; i++)
	{
		tmp = arr[i];
		pos = binSearch(arr, lo, i, arr[i]);
		for (int j = i; j>pos; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[pos + 1] = tmp;
	}
}

template <typename T>
void SortKing<T>::ShellSort(T *arr, int lo, int hi)
{
	int len = hi - lo;
	int h = 1;
	while (h<len / 3)	h = 3 * h + 1;	//3可变
	while (1 <= h)
	{
		for (int i = h; i<hi; i++)
		{
			for (int j = i; j >= h&&less(arr[j], arr[j - h]); j -= h)
				if (less(arr[j], arr[j - h]))
					exchange(arr, j, j - h);
		}
		h /= 3;
	}
}

template <typename T>
void SortKing<T>::MergeSort(T *arr, int lo, int hi)
{
	if (hi - lo < 2)
		return;
	int mi = (lo+hi)/2;
	MergeSort(arr, lo,mi);
	MergeSort(arr, mi,hi);
	merge(arr, lo, mi, hi);
}

template <typename T>
void SortKing<T>::merge(T* arr, int lo, int mi, int hi)
{
	T * A = arr + lo;
	int Len_Left = mi - lo;
	T* Left = new T[Len_Left];
	for (int i = 0;i<Len_Left;Left[i] = A[i++]);
	int Len_Right = hi - mi;
	T * Right = arr + mi;
	for(int i =0,j = 0,k = 0;j<Len_Left;)
	{
		if (!less(Right[k],Left[j])||(k >= Len_Right))
			A[i++] = Left[j++];
		if (less(Right[k],Left[j])&&k<Len_Right)
			A[i++] = Right[k++];
	}
	delete []Left;
}

/*
* 自底向上归并排序，适用于链表
*/
template <typename T>
void SortKing<T>::MergeSortBU(T* arr, int lo, int hi)
{
	int sz = 1;
	int len = hi-lo;

	while(sz<len){
	for(int i = lo;i<len-sz;i+=sz*2)
	{
		merge(arr,i,i+sz,(i+sz*2<=len?i+sz*2:len));
	}
		sz = 2 * sz;
	}
	
}

template <typename T>
void SortKing<T>::QuickSort(T* arr, int lo, int hi)
{
	if( hi - lo < 2)
		return;
	int mi = partition(arr, lo, hi);
	QuickSort(arr, lo, mi);
	QuickSort(arr, mi+1, hi); 
}

/*
* 将数组分成以value为界的两部分，使得左边部分比value小，右边比value大
*/
template <typename T>
int SortKing<T>::partition(T* arr, int lo, int hi)
{
	T value = arr[lo];
	int i = lo,j = hi;
	while(true)
	{
		while(less(arr[++i],value))
			if(i==hi)	break;
		while(less(value,arr[--j]))
			if(j==lo)	break;
		if(i>=j)	break;
		exchange(arr, i, j);
	}
	exchange(arr,lo,j);
	return j;
}

/*
* 当数组规模降低到M长度，则转而使用插入排序
*/
template <typename T>
void SortKing<T>::QuickSort_Insert(T* arr, int lo, int hi)
{
	int M = 8;
	if( hi - lo <= M)
	{
		InsertSort(arr, lo, hi);
		return;
	}
	int mi = partition(arr, lo, hi);
	QuickSort_Insert(arr, lo, mi);
	QuickSort_Insert(arr, mi+1, hi); 
}

/*
* 此改进算法应用于对重复数字较多的序列进行排序
*/
template <typename T>
void SortKing<T>::QuickSort_3Way(T* arr, int lo, int hi)
{
	if(hi - lo<2)	return;
	int lt = lo, i = lo+1, gt = hi;
	int value = arr[lo];
	while(i<gt)
	{
		if(less(arr[i],value))	exchange(arr, lt++, i++);
		else if (less(value,arr[i]))	exchange(arr, --gt, i);
		else i++;
	}
	QuickSort_3Way(arr, lo, lt);
	QuickSort_3Way(arr, gt, hi);
}

