#include <stdio.h>

//判斷回文 
int main(){
	
	int number, dig1, dig2, dig4, dig5;
	
	printf("Enter a 5-digit integer: ");
	scanf("%d", &number); //輸入數字 

	dig1 = number / 10000; //除以一萬以後，剩下第一個數字 
	dig2 = (number % 10000) /1000; //取餘數後剩下後四位數，除以一千剩下第二個數字 
	dig4 = (number % 100) / 10; //取餘數後剩下後兩位數，除以十剩下第四個數字 
	dig5 = number % 10; //取餘數後剩下第五個數字 
	
	if (dig1 == dig5 && dig2 == dig4) //如果第一個數字和第五個相同，且第二個數字和第四個相同則為回文 
		printf("The number is a palindrome.");
	else
		printf("The number is NOT a palindrome.");
}