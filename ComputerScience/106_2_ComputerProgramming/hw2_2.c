//輸入五個數字，印出相應的星號橫條圖
#include <stdio.h>
int main(){
	unsigned int number[5], i, j;

	printf("請輸入五個0-30的整數：\n");

    for (i = 0; i < 5; i++) //輸入五個數字
        scanf("%u", &number[i]);

	for (i = 0; i <5; i++){ //印出五行字
		for (j = 0; j < number[i]; j++){ //每行依據輸入的數字決定星星的數量
			printf("*");
		}
		printf("\n");
	}
}
