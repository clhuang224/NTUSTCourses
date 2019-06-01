#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Node{
	struct Node* left;
	struct Node* right;
	int data;
} Node;

void insert(Node** tree, int value);
void clean(Node** tree);
void preorder(Node* tree);
void postorder(Node* tree);
void mirror(Node** tree);
int height(Node* tree);
int total(Node* tree);
int external(Node* tree);
Node* max(Node* tree);
Node* min(Node* tree);
void del_l(Node** tree, int value);
void del_r(Node** tree, int value);

int main(){
	Node *tree1 = NULL, *tree2 = NULL;
	int amount, i, input, x, y;

	cin >> amount; // 輸入node數
	for(i=0;i<amount;i++){ // 輸入node值
		cin >> input;
		insert(&tree1, input);
		insert(&tree2, input);
	}

	cin >> x >> y; // 輸入x和y

	postorder(tree1); // 1.印出postorder
	cout << endl;

	mirror(&tree1); // 2.印出mirror的postorder
	postorder(tree1);
	cout << endl;
	mirror(&tree1);

	insert(&tree1, x); // 3.插入X後印出preorder
	insert(&tree2, x);
	preorder(tree1);
	cout << endl;

	cout << height(tree1) << endl; // 4.印出height

	cout << total(tree1) << endl; // 5.印出總node數

	cout << total(tree1)-external(tree1) << endl; // 6.印出internal node數

	cout << max(tree1)->data << endl; // 7.印出最大值

	cout << min(tree1)->data << endl; // 8.印出最小值

	del_l(&tree1, y); // 9.刪除y後印出兩種答案
	preorder(tree1);
	cout << endl;
	del_r(&tree2, y);
	preorder(tree2);


	clean(&tree1);
	clean(&tree2);

}

void insert(Node** tree, int value){ // 插入node
	if (*tree == NULL){
		*tree = (Node*)malloc(sizeof(Node));
		(*tree)->data = value;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
	} else {
		if (value >= (*tree)->data) {
			insert(&((*tree)->right), value);
		} else {
			insert(&((*tree)->left), value);
		} // end if
	} // end if
}

void clean(Node** tree){ // free所有node
	if (*tree != NULL){
		clean(&((*tree)->left));
		clean(&((*tree)->right));
		free(*tree);
		*tree = NULL;
	}
}

void preorder(Node* tree){ // 以preorder印出
	if (tree != NULL){
		cout << tree->data;
		if(tree->left != NULL){
			cout << ' ';
		}
		preorder(tree->left);
		if(tree->right != NULL){
			cout << ' ';
		}
		preorder(tree->right);
	}
}

void postorder(Node* tree){ // 以postorder印出
	if(tree != NULL){
		postorder(tree->left);
		if(tree->right != NULL && tree->left != NULL){
			cout << ' ';

		}
		postorder(tree->right);
		if(tree->right != NULL || tree->left != NULL){
			cout << ' ';
		}
		cout << tree->data;
	}
}

void mirror(Node** tree){ // 將樹左右顛倒
	Node* temp;
	if (*tree != NULL){
		mirror(&((*tree)->left));
		mirror(&((*tree)->right));
		temp = (*tree)->left;
		(*tree)->left = (*tree)->right;
		(*tree)->right = temp;
	}
}

int height(Node* tree){ // 計算height
	int left, right;
	if (tree == NULL){
		return 0;
	} else {
		left = height(tree->left);
		right = height(tree->right);
		if(left > right){
			return left + 1;
		} else {
			return right + 1;
		}
	}
}

int total(Node* tree){ // 計算總node數
	if (tree == NULL){
		return 0;
	} else if (tree->left == NULL && tree->right == NULL){
		return 1;
	} else {
		return 1 + total(tree->left) + total(tree->right);
	}
}

int external(Node* tree){ // 計算external node數
	if (tree == NULL){
		return 0;
	} else if (tree->left == NULL && tree->right == NULL){
		return 1;
	} else {
		return external(tree->left) + external(tree->right);
		}
}

Node* max(Node* tree){ // 找出最大值的指標
	if(tree != NULL){
		if(tree->right !=NULL){
			return max(tree->right);
		} else {
			return tree;
		}
	}
}

Node* min(Node* tree){ // 找出最小值的指標
	if(tree != NULL){
		if(tree->left !=NULL){
			return min(tree->left);
		} else {
			return tree;
		}
	}
}

void del_l(Node** tree, int value){
	Node* temp;
	if(*tree == NULL){ // 整個樹找不到value
		cout << "找不到Value" << endl;
	} else if (value < (*tree)->data ){ // 值比當下node大往右del
		del_l(&((*tree)->left), value);
	} else if (value > (*tree)->data ){ // 值比當下node小往左del
		del_l(&((*tree)->right), value);
	} else if ((*tree)->left != NULL && (*tree)->right != NULL){ // 找到有兩個小孩的值
		temp = max((*tree)->left); // 找出左子樹最大的node
		(*tree)->data = temp->data; // 把值先換成左子樹最大值
		del_l(&((*tree)->left), temp->data); //再把左子樹中最大值del掉
	} else {
		temp = (*tree);
		if((*tree)->left == NULL && (*tree)->right == NULL){ //找到沒小孩的值
			(*tree) = NULL;
		} else if ((*tree)->left != NULL){ // 只有左小孩的值
			*tree = ((*tree)->left);
		} else { // 只有右小孩的值
			*tree = ((*tree)->right);
		}
		free(temp);
	}
}
void del_r(Node** tree, int value){
	Node* temp;
	if(*tree == NULL){
		cout << "找不到Value" << endl;
	} else if (value < (*tree)->data){
		del_r(&((*tree)->left), value);
	} else if (value > (*tree)->data){
		del_r(&((*tree)->right), value);
	} else if ((*tree)->left != NULL && (*tree)->right != NULL){
		temp = min((*tree)->right);
		(*tree)->data = temp->data;
		del_r(&((*tree)->right), temp->data);
	} else {
		temp = (*tree);
		if((*tree)->left == NULL && (*tree)->right == NULL){
			(*tree) = NULL;
		} else if ((*tree)->left != NULL){
			*tree = (*tree)->left;
		} else {
			*tree = (*tree)->right;
		}
		free(temp);
	}
}
