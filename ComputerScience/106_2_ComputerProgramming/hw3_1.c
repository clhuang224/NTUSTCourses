//河內塔
#include <stdio.h>
void hanoi(unsigned int n, char home, char temp, char target); //宣告河內塔函式（參數為層數、各柱名稱）
int main(){
    unsigned int amount; //宣告層數的變數

    printf("%s", "Enter the amount(>=1): "); //讓使用者輸入層數
    scanf("%u", &amount);
	hanoi(amount, '1', '2', '3'); //呼叫函式
}

void hanoi(unsigned int n, char home, char temp, char target){

	if (n > 0){
		hanoi(n-1, home, target, temp); //在hanoi(n)中，前半的內容類似於hanoi(n-1)，但是temp和target相反
		printf("Disk%u: Peg%c -> Peg%c\n", n, home, target); //最大的disk會在所有過程的最中間由起點移至終點 
		hanoi(n-1, temp, home, target); //後半的內容也類似於hanoi(n-1)，但是home和temp相反
	}

}
