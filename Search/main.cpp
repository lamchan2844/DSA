/*
* @Author: Lin Chen
* @Date:   2017-04-10 12:24:47
* @Last Modified by:   Lin Chen
* @Last Modified time: 2017-04-10 22:24:43
*/

/**
* 测试数据
* line 1:插入的数量
* line 2:插入的数字
* line 3:查找的数量
* line 4:查找的数字
* line 5:删除的数量
* line 6:删除的数字
* line 7:查找的数量
* line 8:查找的数字
10
62 88 58 47 35 73 51 99 37 93
10
62 33 52 48 35 73 55 67 -10 100
10
62 33 52 48 35 73 55 67 -10 100
10
62 33 58 48 35 73 55 67 -10 93
10
1 2 3 4 5 6 7 8 9 10
10
4 20 6 11 3 5 17 9 8 10

*/
#include <iostream>
#include "BST.h"
#include "AVL.h"
using namespace std;

int main() {
	BST bst;
	int n;
	cin >> n;
	int num;
	BiTree T = NULL;
	BiTree p = NULL;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		bst.InsertBST(&T, num);
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (bst.SearchBST(T, num, NULL, &p)) {
			cout << "find the num in this BST" << endl;
		}
		else {
			cout << "cannot find the num in this BST" << endl;
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (bst.DeleteBST(&T, num)) {
			cout << "Delete " << num << " done!" << endl;
		}
		else {
			cout << "cannot Delete " << num << ", because the num not in this BST" << endl;
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (bst.SearchBST(T, num, NULL, &p)) {
			cout << "find the num in this BST" << endl;
		}
		else {
			cout << "cannot find the num in this BST" << endl;
		}
	}

	AVL avl;
	bool taller;
	T = NULL;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		avl.InsertAVL(&T, num, &taller);
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (bst.SearchBST(T, num, NULL, &p)) {
			cout << "find the num in this BST" << endl;
		}
		else {
			cout << "cannot find the num in this BST" << endl;
		}
	}

	return 0;
}