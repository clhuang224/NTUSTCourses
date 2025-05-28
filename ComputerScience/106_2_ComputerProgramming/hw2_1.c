//使用者輸入要比較幾個數字，然後輸入各數字後，印出最大值

#include <stdio.h>
int main(){
	int value, max, number, i;

	printf("Enter the number of integers you want to compare: ");
	scanf("%u", &number); //使用者輸入欲比較幾個數字

	printf("Enter the integers you want to compare: ");
	scanf("%u", &max); //第一個輸入的數字先被視為最大值

	for (i = 1; i < number; i++){ //之後每個數字如果比max大，會成為新的最大值
		scanf("%u", &value);
		if (value > max)
			max = value;
	}

	printf("The maximum is %u.\n", max); //印出最大值

}
