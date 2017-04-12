#pragma once
#include <vector>
#include <set>

const bool SUCCESS = true;
const bool UNSUCCESS = false;
const int UNKEY = -23768;
/**
 * 
 */
typedef struct Node{
	int key;
	Node *next;
	Node() :key(UNKEY), next(nullptr){}
	Node(int i) :key(i), next(nullptr){}

}Node;

/**
 * 采用链地址法存储的散列表
 */
class HashTable {
private:
	int count;	//散列表表长
	std::vector < Node > _elem;	//散列表
public:
	HashTable(int m) : count(m),
		_elem(std::vector < Node>(count)){}
	void InsertHash(int key);
	bool SearchHash(int key);
	int getHash(int key);
};
/**
 * [HashTable::InsertHash 插入数据]
 * @param key [插入的数据]
 */
void HashTable::InsertHash(int key){
	int index = getHash(key);
	Node *node = &_elem[index];
	if (node->key == UNKEY)
	{
		node->key = key;
		return;
	}
	if (node->key == key){
		return;
	}
	while (node->next != nullptr)
	{
		if (node->next->key == key)
			return;
		node = node->next;
	}
	node->next = new Node(key);
}

/**
 * [HashTable::SearchHash 寻找数据]
 * @param  key [待寻找的数据]
 * @return     [是否存在]
 */
bool HashTable::SearchHash(int key){
	int index = getHash(key);
	Node *node = &_elem[index];
	if(node->key == key){
		return SUCCESS; 
	}
	while(node->next!=nullptr)
	{
		if(node->next->key == key)
			return SUCCESS;
		node = node->next;
	}
	return UNSUCCESS;
}

/**
 * [HashTable::getHash 计算哈希值]
 * @param  key [待插入或者寻找的数据]
 * @return     [哈希值]
 */
int HashTable::getHash(int key)
{
	return key%count;
}