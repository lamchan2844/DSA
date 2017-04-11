#pragma once
#include "BiTNode.h"
class BST{
public:
	Status SearchBST(BiTree T, int key, BiTree f, BiTree *p);
	Status InsertBST(BiTree *T, int key);
	Status Delete(BiTree *p);
	Status DeleteBST(BiTree *T, int key);
};