/*
* @Author: Lin Chen
* @Date:   2017-04-10 16:19:14
* @Last Modified by:   Lin Chen
* @Last Modified time: 2017-04-10 22:24:22
*/

#include "AVL.h"

/**
 * [AVL::InsertAVL 往AVL中插入节点]
 * @param  taller [description]
 * @return        [description]
 */
Status AVL::InsertAVL(BiTree *T, int key, Status *taller)
{
	if ((*T) == nullptr) {
		(*T) = new BiTNode;
		(*T)->data = key;
		(*T)->bf = EH;
		(*T)->lchild = (*T)->rchild = nullptr;
		*taller = true;
	} else {
		if ((*T)->data == key) {
			*taller = false;
			return false;
		}
		if (key < (*T)->data) {
			if (!InsertAVL(&(*T)->lchild, key, taller)) //如果已有此值
			{
				return false;
			}
			if (*taller) {
				switch ((*T)->bf) {
				case LH:	//原本左高，需左平衡
					LeftBalance(T);
					*taller = false;
					break;
				case EH:	//等高
					(*T)->bf = LH;
					*taller = true;
					break;
				case RH:	//右高，需右平衡
					(*T)->bf = EH;
					*taller = false;
					break;
				}
			}
		} else {
			if (!InsertAVL(&(*T)->rchild, key, taller)) //如果已有此值
			{
				return false;
			}
			if (*taller) {
				switch ((*T)->bf) {
				case LH:	//原本左高，需左平衡
					(*T)->bf = EH;
					*taller = false;
					break;
				case EH:	//等高
					(*T)->bf = RH;
					*taller = true;
					break;
				case RH:	//右高，需右平衡
					RightBalance(T);
					*taller = false;
					break;
				}
			}
		}
	}
	return true;
}

/**
 * [AVL::LeftBalance 使左树保持平衡]
 * @param  T [根节点]
 * @return   [成功标志]
 */
Status AVL::LeftBalance(BiTree *T)
{
	BiTree L, Lr;
	L = (*T)->lchild;
	switch (L->bf) {
	case LH:
		(*T)->bf = L->bf = EH;
		R_Rotate(T);
		break;
	case RH:	//双旋
		Lr = L->rchild;
		switch (Lr->bf) {
		case LH:
			(*T)->bf = RH;
			L->bf = EH;
			break;
		case EH:
			(*T)->bf = L->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;
			L->bf = EH;
			break;

		}
		Lr->bf = EH;
		L_Rotate(&(*T)->lchild);
		R_Rotate(T);
		break;


	}
}

/**
 * [AVL::RightBalance 使右树保持平衡]
 * @param  T [根节点]
 * @return   [成功标志]
 */
Status AVL::RightBalance(BiTree *T)
{
	BiTree R,Rl;
	R = (*T)->rchild;
	switch (R->bf) {
	case LH:
		Rl = R->lchild;
		switch(Rl->bf){
			case LH:
				(*T)->bf = EH;
				R->bf = RH;
				break;
			case EH:
				(*T)->bf = Rl->bf = EH;
				break;
				case RH:
				(*T)->bf = LH;
				R->bf = EH;
		}
		Rl->bf = EH;
		R_Rotate(&(*T)->rchild);
		L_Rotate(T);
		break;
	case RH:
		(*T)->bf = R->bf = EH;
		L_Rotate(T);
		break;

	}

}

/**
 * [AVL::R_Rotate 右旋]
 * @param P [旋转的根节点]
 */
void AVL::R_Rotate(BiTree *P)
{
	BiTree L;
	L = (*P)->lchild;
	(*P)->lchild = L->rchild;
	L->rchild = (*P);
	*P = L;
}

/**
 * [AVL::L_Rotate 左旋]
 * @param P [旋转的根节点]
 */
void AVL::L_Rotate(BiTree *P)
{
	BiTree R;
	R = (*P)->rchild;
	(*P)->rchild = R->lchild;
	R->lchild = (*P);
	*P = R;
}