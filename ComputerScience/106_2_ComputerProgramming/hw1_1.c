#include <stdio.h>

//輸入三個整數，計算總和、乘積、平均、最大值、最小值 
int main() {
	
 	int number, sum = 0, product = 1, max, min, average;
 	unsigned char counter;
 	
	printf("Enter three different integers: ");
 	
	//執行三次 
	for (counter = 0; counter < 3; counter += 1) {

		scanf("%d", &number);//輸入數字
		
		sum += number; //將數字加入sum
		product *= number; //將數字乘入product 
		
		//第一個數字是最大值也是最小值 
		if (counter == 0) {
			max = number;
			min = number;
		
		//之後的數字比原本的最大(小)值大(小)則為最大(小)值 
		} else {
			if (number > max) 
				max = number;
			if (number < min) 
				min = number;
		}
	}

	//計算平均
	average = sum / 3;

	//印出結果
	printf("Sum is %d\n", sum);
	printf("Average is %d\n", average);
	printf("Product is %d\n", product);
	printf("Smallest is %d\n", min);
	printf("Largest is %d\n", max);

 }