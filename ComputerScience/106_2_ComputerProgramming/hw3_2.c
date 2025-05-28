//1-1000終極密碼
#include <stdio.h>
#include <stdlib.h> //包含rand、srand
#include <time.h> //包含time
int main(){
	unsigned int target, guess = 0;
	char check = 'y';

	printf("%s","I have a number between 1 and 1000\nCan you guess my number?\n\nPlease type your first guess: ");

	while(check == 'y'){ //只要check還是y，遊戲會繼續進行

		srand(time(NULL)); //以時間作為random的種子
		target = (rand() % 1000) + 1; //題目範圍為1~1000

		while(guess != target){	//只要使用者還沒答對，就可以繼續猜
		scanf("%u", &guess);

			if (guess < target) //猜測小於答案則提示猜得太小
				printf("%s","Too low! Try again: ");
			else {
				if (guess > target) //猜測大於答案則提示猜得太大
					printf("%s","Too high! Try again: ");
				else{
					printf("%s","Excellent! You guessed the number.\nWould you like to play again (y or n)? ");
					scanf(" %c", &check); //猜對則詢問是否繼續（輸入y以外的東西都會結束）
                    if (check == 'y')
                        printf("%s", "\nPlease type your new guess: ");
				}
			}
		}

	}

}
