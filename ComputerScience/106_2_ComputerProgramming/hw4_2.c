//洗牌並發牌
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *x, int *y);
void shuffle(int a[][13]);
void deal(int a[][13]);

int main(){
	int deck[4][13], i, j, k = 1;
	srand(time(NULL)); //利用當下時間抽種子

	for(i = 0; i < 4; i++){ //將1-52先放入4X13的二維陣列中
		for(j = 0; j < 13; j++)
			deck[i][j] = k++;
	}
	shuffle(deck); //洗牌
	deal(deck); //發牌
}

void swap(int *x, int *y){ //互換兩個值
	int temp = *x;
	*x = *y;
	*y = temp;
}

void shuffle(int a[][13]){
	int i, j, k, l;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 13; j++){ //依序並隨機選擇另一格的花色和數字，然後互換
			k = (rand()%4);
			l = (rand()%13);
			swap(&a[i][j], &a[k][l]);
		}
	}
}

void deal(int a[][13]){
	char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	char *face[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	int i, j, k = 1;

	while(k <= 52){
		for(i = 0; i < 4; i++){
			for(j = 0; j < 13; j++){
				if (a[i][j] == k){ //依序尋找值為1-52的陣列位置，並依照行列印出對應的文字
					printf("%5s of %-8s%c", face[j], suit[i], k % 2 == 0 ? '\n' : '\t');
					k++;
					j = 14;
					i = 5;
				}
			}
		}
	}
}
