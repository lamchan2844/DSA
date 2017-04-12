/*
* @Author: Lin Chen
* @Date:   2017-04-12 14:26:14
* @Last Modified by:   Lin Chen
* @Last Modified time: 2017-04-12 17:39:33
*/

/**
 * 散列表主函数
 * 测试数据
12
12 67 56 12 25 37 22 22 15 47 48 34
6
12 55 5 47 25 32

 */
#include <iostream>
#include "HashTable.h"
using namespace std;
int main()
{
	HashTable ht(12);
	int n;
	cin>>n;
	vector<int > vect(n);
	for(int i = 0;i<n;i++)
	{
		cin>>vect[i];
		ht.InsertHash(vect[i]);
	}
	cin>>n;
	int tmp;
	for (int i = 0; i < n; ++i)
	{
		cin>>tmp;
		if(ht.SearchHash(tmp))
			cout<<"find it\n";
		else
			cout<<"cannot find it\n";
	}
	while(true);
	return 0;
}