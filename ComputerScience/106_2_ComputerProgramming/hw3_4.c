//用The Sieve of Eratosthenes找出1-999間的質數
#include <stdio.h>
int main(){

	int list[1000] = {0}, i, j;

	for (i = 2; i < 1000; i++) //將陣列第2~999格設為1（0和1不是質數）
		list[i] = 1;

	for (i = 2; i < 1000; i++){ //由2開始，若格子內為一，就將該格的倍數都改為零
		if (list[i] == 1){
			for (j = i * 2; j < 1000; j += i) //j每次增加i即能找到下一個倍數
				list[j] = 0;
		}
	}

	printf("\nThe prime numbers between 1 and 999: \n");
	j = 0;

	for (i = 2; i < 1000; i++){ //印出格子內為一的格子即為1-999間的質數
		if (list[i] == 1){
            printf("%4d ", i);
            j++;
		}
        if (j == 10){ //每印出十個質數就換行
            printf("\n");
            j = 0;
        }
	}
}
