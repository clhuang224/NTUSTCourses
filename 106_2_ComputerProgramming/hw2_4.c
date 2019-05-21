//判斷奇偶數
#include <stdio.h>
#include <stdbool.h>
int main(){

	int input = 0;
	bool isEven(int x); //宣告函式prototype

	printf("Enter an integer( -1 to end): ");
	scanf("%d", &input); //讓使用者輸入要判斷的數字，直到輸入-1結束程式
	while (input != -1){
		if (isEven(input)) //使用isEven判斷奇偶數
			printf("%d is even.\n", input);
		else
			printf("%d is odd.\n", input);
        scanf("%d", &input);
	}
}

bool isEven(int x){
	return (x % 2 == 0); //bool回傳1或0
}
