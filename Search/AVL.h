#pragma once
#include "BiTNode.h"
/**
 * 平衡二叉树
 * Self-Balanceing Binary Search Tree/Height-Balanced Binary Search Tree
 * Algorithm by G.M.Adelson-Velskii & E.M.Landis
 * program by chenlin
 */
class AVL{
public:
	Status InsertAVL(BiTree *T,int key,Status *taller);
	Status LeftBalance(BiTree *T);
	Status RightBalance(BiTree *T);
	void R_Rotate(BiTree *T);
	void L_Rotate(BiTree *T);

};