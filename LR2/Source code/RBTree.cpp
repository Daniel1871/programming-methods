/*!
	\file
	\brief Файл реализации методов класса красно-черного дерева RBTree.
*/
#include "RBTree.h"

RBTree::RBTree(){
	Military data;
	nil = new RBNode(data, Color::BLACK, nil, nil, nil);
	root = nil;
}

void RBTree::leftRotate(RBNode* x){ // Левосторонний поворот
	RBNode *y = x->right;
	
	x->right = y->left;
	if(y->left != nil) y->left->parent = x;
	
	y->parent = x->parent;
	if(x->parent == nil) root = y; // Если x был корнем
	else if(x->parent->left == x) x->parent->left = y; // Не корень, но левый потомок
	else x->parent->right = y; // Не корень, но правый потомок
		
	x->parent = y;
	y->left = x;
}

void RBTree::rightRotate(RBNode* x){ // Правосторонний поворот
	RBNode *y = x->left;
	
	x->left = y->right;
	if(y->right != nil) y->right->parent = x;
	
	y->parent = x->parent;
	if(x->parent == nil) root = y; // Если x был корнем
	else if(x->parent->left == x) x->parent->left = y; // Не корень, но левый потомок
	else x->parent->right = y; // Не корень, но правый потомок
	
	x->parent = y;
	y->right = x;
}
    
RBNode* RBTree::insertBST(RBNode* parent, RBNode* start, Military data){
	string key = data.getFullName();
	if(start == nil){ // Случай нулевого начала: пустое дерево или нулевой лист, заменяемый на новый элемент
		start = new RBNode(data, Color::RED, nil, nil, parent);
		if(parent == nil) root = start; // Пустое дерево
		else{ // nil в листе дерева
			if(key <= parent->key) parent->left = start;
			else parent->right = start;
		}
	} else{
		if(key <= start->key) return insertBST(start, start->left, data);
		else return insertBST(start, start->right, data);
	}
	return start;
}
    
void RBTree::insert(Military data){
	RBNode* z = insertBST(nil, root, data);
	while(z->parent->color == Color::RED){
		if(z->parent->parent->left == z->parent){ // Если родитель левый потомок деда
			if(z->parent->parent->right->color == Color::RED){ // Случай 1: дядя красный
				z->parent->color = Color::BLACK;
				z->parent->parent->color = Color::RED;
				z->parent->parent->right->color = Color::BLACK;
				z = z->parent->parent; // часть уже просмотрели, двигаемся выше
			} else{ // Теперь рассматриваем черного дядю
				if(z->parent->right == z){ // Если z - правый ребенок родителя. Случай 2.
					z = z->parent;
					leftRotate(z);
				} // Случай 3
				z->parent->color = Color::BLACK;
				z->parent->parent->color = Color::RED;
				rightRotate(z->parent->parent);
			}
		} else{ // Симметричные случаям выше случаи, но родитель - правый потомок деда
			if(z->parent->parent->left->color == Color::RED){ // Случай 1
				z->parent->color = Color::BLACK;
				z->parent->parent->color = Color::RED;
				z->parent->parent->left->color = Color::BLACK;
				z = z->parent->parent;
			} else{
				if(z->parent->left == z){ // Случай 2
					z = z->parent;
					rightRotate(z);
				} // Случай 3
				z->parent->color = Color::BLACK; 
				z->parent->parent->color = Color::RED;
				leftRotate(z->parent->parent);
			}
		}
	}
	root->color = Color::BLACK; // Корень должен быть черным
}

bool RBTree::find(const string &key){
	RBNode *node = root; // Текущий узел дерева
	while(node != nil && node->key != key){
		if(key < node->key) node = node->left;
		else node = node->right;
	} 
	return node != nil;
}
