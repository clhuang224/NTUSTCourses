//將十個隨機的小寫英文字母照順序放入鏈結串列中，再以大寫印出來

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct N{
	char letter;
    struct N *next;
};
typedef struct N Node; //寫好一個有兩格的結構，一格是字母，一格是指標


int main(){
	int i;
	Node *head, *newchar, *temp1, *temp2;

	srand(time(NULL));

	head = (Node*)malloc(sizeof(Node)); //先分配一個Node
	head -> letter = (rand() % 26) + 97; //隨機放入a~z
	head -> next = NULL; //指標放入NULL

	for(i = 0; i < 9; i++){

		newchar= (Node*)malloc(sizeof(Node)); //新開一個node
		newchar -> letter = (rand() % 26) + 97; //放入a~z

		if(newchar -> letter < head -> letter){ //如果新字母比head小，直接接在head前
			newchar -> next = head;
			head = newchar;
		} else { //如果新字母比head大→去找要接的地方
			temp1 = head;
			while (temp1 != NULL && newchar -> letter > temp1 -> letter){
				temp2 = temp1;
				temp1 = temp1 -> next;
			}
			newchar -> next = temp1;
			temp2 -> next = newchar;
		}
	}

	temp2 = head;
	while(temp2 != NULL){ //印出整個鏈結串列的大寫字母，並free掉整個串列
		printf("%c ", temp2 -> letter - 32);
		temp1 = temp2;
		temp2 = temp2 -> next;
		free(temp1);
	}
}
