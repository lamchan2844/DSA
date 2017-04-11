#pragma once
typedef bool Status;
const int LH = 1;	//左高
const int EH = 0;	//等高
const int RH = -1;	//右高
typedef struct BiTNode
{
	int data;
	int bf;
	BiTNode *lchild, *rchild;
} BiTNode, *BiTree;