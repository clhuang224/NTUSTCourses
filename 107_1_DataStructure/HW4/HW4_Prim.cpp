#include <iostream>
using namespace std;

typedef struct node{
	char v1;
	char v2;
	int weight;
	node* next;
} Node;

void prim(Node** graph, char** start, Node** tree);
void insert(Node** list, char v1, char v2, int weight);
void clean(Node** list);
void print(Node* list);
void del(Node** list, char* visited);

int main(){
	int amount, weight;
	Node *graph = NULL, *tree = NULL;
	char v1, v2, *start;

	cin >> amount;
	for(int i=0; i<amount; i++){
		cin >> v1 >> v2 >> weight;
		insert(&graph, v1, v2, weight);
	}
	start = new char[amount+1];
	cin >> start[0];
	start[1] = '\0';
	
	prim(&graph, &start, &tree); // 使用prim algorithm
	print(tree); // 印出結果
	
	clean(&graph);
	clean(&tree);
	delete(start);
}

void prim(Node** graph, char** start, Node** tree){
	Node *fringe = NULL, *temp1, *temp2;
	for(int i=0; (*start)[i]!= '\0'; i++){
		temp1 = *graph;
		while(temp1 != NULL){ // 將與a相連的edge 放入fringe中
			if(temp1->v1 == (*start)[i] || temp1->v2 == (*start)[i]){
				insert(&(fringe), temp1->v1, temp1->v2, temp1->weight);
			}
			temp1 = temp1->next;
		}
	}
	if(fringe != NULL){
		temp1 = fringe;
		temp2 = temp1;
		while(temp1 != NULL){ // 找到fringe中weight最小的node
			if(temp1->weight < temp2->weight){
				temp2 = temp1;
			}
			temp1 = temp1->next;
		}
		insert(&(*tree), temp2->v1, temp2->v2, temp2->weight); // 將node放入tree
		for(int i=0; (*start)[i]!= '\0'; i++){ // 將已經接觸到的vertex放入start
			if(temp2->v1 == (*start)[i]){
				int j = i;
				while((*start)[j]!='\0'){
					j++;
				}
				(*start)[j] = temp2->v2;
				(*start)[j+1] = '\0';
				break;
			}
			if(temp2->v2 == (*start)[i]){
				int j = i;
				while((*start)[j]!='\0'){
					j++;
				}
				(*start)[j] = temp2->v1;
				(*start)[j+1] = '\0';
				break;
			}
		}
		del(&(*graph), *start); // 將已經用到及不能用的edge刪除
		clean(&fringe); // 清空fringe
		prim(&(*graph), &(*start), &(*tree)); // 做下一輪prim直到graph為NULL
	}
	clean(&fringe);
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
void del(Node** list, char* visited){ //刪掉不能用的edge
	int x = 0;
	if(*list != NULL){
		for(int i=0; visited[i]!='\0' && x == 0; i++){ // 找到兩邊vertex都已在樹中的edge並刪除
			for(int j=0; visited[j]!='\0' && x == 0; j++){
				if((*list)->v1 == visited[i] && (*list)->v2 == visited[j]){
					Node* temp = *list;
					*list = (*list)->next;
					delete(temp);
					x = 1;
				}
			}
		}
		if(x == 1){
            del(&(*list), visited);
		} else {
            del(&((*list)->next), visited);
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