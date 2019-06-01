#include <iostream>
using namespace std;

typedef struct node{
	char v1;
	char v2;
	int weight;
	node* next;
} Node;

void kruskal(Node** queue, Node** mst, char* forest);
void insert(Node** list, char v1, char v2, int weight);
void clean(Node** list);
void print(Node* list);

int main(){
	int amount, weight;
	Node *queue = NULL, *mst = NULL;
	char v1, v2, forest[26]={0};

	cin >> amount;
	for(int i=0; i<amount; i++){
		cin >> v1 >> v2 >> weight;
		forest[v1-97] = v1; // forest陣列 0表示沒有這個vertex 其他值表示他所在的分類
		forest[v2-97] = v2;
		insert(&queue, v1, v2, weight);
	}
	
	kruskal(&queue, &mst, forest); // 使用kruskal algorithm

	print(mst); // 印出結果
	
	clean(&queue);
	clean(&mst);
}
void kruskal(Node** queue, Node** mst, char* forest){
	if(*queue != NULL){
		if(forest[(*queue)->v1-97] != forest[(*queue)->v2-97]){
			Node* temp = *queue;
			insert(&(*mst), temp->v1, temp->v2, temp->weight);
			*queue = (*queue)->next;
			delete(temp);

			temp = *mst;
			while(temp != NULL){
				for(int i=0; i<26; i++){
					if(i != temp->v2-97 && forest[i] == forest[temp->v2-97]){
						forest[i] = forest[temp->v1-97];
					}
				}
				forest[temp->v2-97] = forest[temp->v1-97];
				temp= temp->next;
			}
		} else {
			Node* temp = *queue;
			*queue = (*queue)->next;
			delete(temp);
		}
		kruskal(&(*queue), &(*mst), forest);
	}
	
}
void insert(Node** list, char v1, char v2, int weight){ // 依權重放入linked list
	if((*list) == NULL){
		*list = new Node;
		(*list)->v1 = v1;
		(*list)->v2 = v2;
		(*list)->weight = weight;
		(*list)->next = NULL;
	} else {
		Node *present = *list, *last = NULL;
		while(present != NULL && weight > present->weight){
			last = present;
			present = present->next;
		}
		Node* newNode = new Node;
		newNode->v1 = v1;
		newNode->v2 = v2;
		newNode->weight = weight;
		newNode->next = present;
		if(last != NULL){
			last->next = newNode;
		} else {
			*list = newNode;
		}
	}
}

void clean(Node** list){ // 清除linked list
	if (*list != NULL){
		clean(&((*list)->next));
		delete(*list);
		*list = NULL;
	}
}
void print(Node* list){ // 印出linked list
	if(list != NULL){
		cout << list->v1 << ' ' << list->v2 << ' ' << list->weight;
		cout << ((list->next == NULL) ? "" : "\n");
		print(list->next);
	}
}