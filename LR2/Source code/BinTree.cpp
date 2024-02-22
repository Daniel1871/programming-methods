/*!
	\file
	\brief Файл реализации методов класса бинарного дерева BinTree.
*/
#include "BinTree.h"

void BinTree::deleteBinTree(BinNode *node){
	if(node){
		deleteBinTree(node->left);
		deleteBinTree(node->right);
		delete node;
	}
}

bool BinTree::find(const string &key){
	BinNode *node = root; // Текущий узел дерева
	while(node && node->key != key){
		if(key < node->key) node = node->left;
		else node = node->right;
	} 
	return node != NULL;
}

void BinTree::insert(Military data){
	if(root == NULL){ root = new BinNode(data); return; }

	string key = data.getFullName();
	BinNode *node = root; // Текущий узел дерева

	while(true){
		if(key <= node->key){ // Идем в левое поддерево
			if(node->left == NULL){ node->left = new BinNode(data); break; }
			node = node->left;
		} else{ // Идем в правое поддерево
			if(node->right == NULL){ node->right = new BinNode(data); break; }
			node = node->right;
		}
	}
}
