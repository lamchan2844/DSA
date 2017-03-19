/*
* @Author: Administrator
* @Date:   2017-03-15 14:04:43
* @Last Modified by:   Administrator
* @Last Modified time: 2017-03-19 14:32:18
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "SortKindom.h"
#define random(x) (rand()%x)
const int LEN = 500;	//产生随机序列的长度
const int MAX = 1000;	//随机序列的最大值
const int COUNT = 10000;	//重复实验的次数
void printArr();
int * randomArr(int Max, int Num);
int main(){
	SortKing<int> King;
	int *arr;
	clock_t  start,stop;
	int choice;
	cout<<"1.运行所有的算法并计时\n2.测试单个算法\n";
	cin>>choice;
	switch(choice){
		case 1:
		cout<<"SelectionSort:"<<endl;
		start = clock();
		for(int i = 0;i<COUNT;i++)
		{
			srand((int)clock());
			arr = randomArr(MAX, LEN);
			King.SelectionSort(arr,0,LEN);
		}
		stop = clock();
		cout<<"time:"<<(double)(stop-start)<<" ms\n"<<endl;

		cout<<"InsertSort:"<<endl;
		start = clock();
		for(int i = 0;i<COUNT;i++)
		{
			srand((int)clock());
			arr = randomArr(MAX, LEN);
			King.InsertSort(arr,0,LEN);
		}
		stop = clock();
		cout<<"time:"<<stop-start<<" ms\n"<<endl;



		cout<<"ShellSort:"<<endl;
		start = clock();
		for(int i = 0;i<COUNT;i++)
		{
			srand((int)clock());
			arr = randomArr(MAX, LEN);
			King.ShellSort(arr,0,LEN);
		}
		stop = clock();
		cout<<"time:"<<stop-start<<" ms\n"<<endl;

		cout<<"MergeSort:"<<endl;
		start = clock();
		for(int i = 0;i<COUNT;i++)
		{
			srand((int)clock());
			arr = randomArr(MAX, LEN);
			King.MergeSort(arr,0,LEN);
		}
		stop = clock();
		cout<<"time:"<<stop-start<<" ms\n"<<endl;

		cout<<"MergeSortBU:"<<endl;
		start = clock();
		for(int i = 0;i<COUNT;i++)
		{
			srand((int)clock());
			arr = randomArr(MAX, LEN);
			King.MergeSortBU(arr,0,LEN);
		}
		stop = clock();
		cout<<"time:"<<stop-start<<" ms\n"<<endl;

		cout<<"QuickSort:"<<endl;
		start = clock();
		for(int i = 0;i<COUNT;i++)
		{
			srand((int)clock());
			arr = randomArr(MAX, LEN);
		//King.printArr(arr, 0, LEN);
			King.QuickSort(arr,0,LEN);
		}
		stop = clock();
		cout<<"time:"<<stop-start<<" ms\n"<<endl;

		cout<<"QuickSort_Insert:"<<endl;
		start = clock();
		for(int i = 0;i<COUNT;i++)
		{
			srand((int)clock());
			arr = randomArr(MAX, LEN);
			King.QuickSort_Insert(arr,0,LEN);
		}
		stop = clock();
	//King.printArr(arr, 0, LEN);
		cout<<"time:"<<stop-start<<" ms\n"<<endl;

		cout<<"QuickSort_3Way:"<<endl;
		start = clock();
		for(int i = 0;i<COUNT;i++)
		{
			srand((int)clock());
			arr = randomArr(MAX, LEN);
			King.QuickSort_3Way(arr,0,LEN);
		}
		stop = clock();
		cout<<"time:"<<stop-start<<" ms\n"<<endl;

		break;

		case 2:
		srand((int)clock());
		arr = randomArr(MAX, LEN);
		King.printArr(arr, 0, LEN);
		King.MergeSort(arr,0,LEN);
		King.printArr(arr, 0, LEN);
		break;
		default:
		return 0;
	}
	return 0;
}
int * randomArr(int Max, int Num)
{
	int *ret = new int[Num];
	for (int i = 0; i < Num; i++)
	{
		
		ret[i] = random(Max);
	}
	return ret;
}