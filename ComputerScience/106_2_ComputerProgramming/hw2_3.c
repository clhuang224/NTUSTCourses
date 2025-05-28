//印出1-256的二進位、八進位、十六進位

#include <stdio.h>
int binary(int x);

int main(){
	int number;

	printf("_Dec_______Bin___Oct___Hex_\n");

	for (number = 1; number <= 256; number++){  //用%d%o%x印出十進位、八進位和十六進位
		printf("%4d %9d %5o %5x\n", number, binary(number), number, number); //使用binary函式
	}

}

int binary(int x){ //用除以二的餘數將十進位數字轉成二進位的形式
    #include <math.h>
	int result = 0, r = 0, i = 0;
	while(x != 0){
		r = x % 2;
		result += r * pow(10, i); //第N次除出來的餘數會被放到第N位
		i++;
		x /= 2;
	}
	return result;
}
