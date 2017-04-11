/*
* @Author: Lin chen
* @Date:   2017-04-09 11:53:26
* @Last Modified by:   Lin Chen
* @Last Modified time: 2017-04-10 22:24:06
*/

/**
* 二叉排序树
*
*/

#include "BST.h"


/**
* [SearchBST 二叉查找树]
* @param  T   [树的根节点]
* @param  key [待查找的键]
* @param  f   [当前树的父节点]
* @param  p   [key所处的位置]
* @return     [是否查找到]
*/
Status BST::SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
	if (!T) {
		*p = f;
		return false;
	}
	else if (T->data == key) {
		*p = T;
		return true;
	}
	else if (key < T->data) {
		return SearchBST(T->lchild, key, T, p);
	}
	else {
		return SearchBST(T->rchild, key, T, p);
	}
}

/**
* [InsertBST 向二叉排序树中插入数据]
* @param  T   [二叉排序树的根节点]
* @param  key [插入的数据]
* @return     [是否已存在待插入的数据]
*/
Status BST::InsertBST(BiTree *T, int key)
{
	BiTree p, s;
	if (!SearchBST(*T, key, nullptr, &p)) {
		s = new BiTNode;
		s->data = key;
		s->lchild = s->rchild = nullptr;
		if (!p) {
			*T = s;
		}
		else if (key < p->data) {
			p->lchild = s;
		}
		else {
			p->rchild = s;
		}
		return true;
	}
	else {
		return false;
	}
}
/**
* [Delete 删除二叉排序树中的结点]
* @param  p [待删除的节点]
* @return   [是否删除成功]
*/
Status BST::Delete(BiTree *p)
{
	BiTree q, s;
	if ((*p)->lchild == nullptr) {
		q = (*p);
		*p = (*p)->rchild;
		delete q;
	}
	else if ((*p)->rchild == nullptr) {
		q = (*p);
		*p = (*p)->lchild;
		delete q;
	}
	else {
		q = *p;
		s = (*p)->lchild;
		while (s->rchild) {
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != *p) {
			q->rchild = s->lchild;
		}
		else {
			q->lchild = s->lchild;
		}
		delete s;
	}
	return true;
}

/**
* [DeleteBST 删除二叉排序树的元素]
* @param  T   [二叉排序树的根节点]
* @param  key [待删除的元素]
* @return     [是否存在待删除的元素]
*/
Status BST::DeleteBST(BiTree *T, int key)
{
	if (!(*T)) {
		return false;
	}
	else if (key == (*T)->data) {
		return Delete(T);
	}
	else if (key < (*T)->data) {
		return DeleteBST(&(*T)->lchild, key);
	}
	else {
		return DeleteBST(&(*T)->rchild, key);
	}
}