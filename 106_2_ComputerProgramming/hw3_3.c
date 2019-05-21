// 使用計算兩個數字的最小公倍數的函式找出(23, 483)、(61, 17)和(19, 82)的最小公倍數

#include <stdio.h>
int gcd(int x, int y);
int lcm(int x, int y);

int main(){ //使用函式，印出結果
	printf("The least common multiple of (23, 483) is %d\n", lcm(23, 483));
	printf("The least common multiple of (61, 17) is %d\n", lcm(61, 17));
	printf("The least common multiple of (19, 82) is %d\n", lcm(19, 82));
}

int gcd(int x, int y){ //用輾轉相除法找出兩數的最大公因數
	while (x && y){ //反覆直到其中一數為零 
		x %= y; //相互取餘數（x < y也沒關係，x還是等於x）
		if (x) //避免x為零，對0取餘數會錯誤
			y %= x;
	} return (x + y); //直接傳回x+y就不用判斷哪個是零哪個是解答
}

int lcm(int x, int y){ //用兩數相乘再除以最大公因數找出最小公倍數
	return (x * y / gcd(x, y));
}
