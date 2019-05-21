#include <stdio.h>
#include <math.h>

//輸入身高體重，計算BMI 
int main(){

	float height, weight, bmi;

	printf("Enter your weight in kilograms: ");
	scanf("%f", &weight); //輸入體重（公斤） 
	printf("Enter your height in centimeters: ");
	scanf("%f", &height); //輸入身高（公分） 

	bmi = weight / pow(height / 100, 2.0); //BMI = 體重除以身高（公尺）的平方 

	printf("\nYour BMI is %f\n\n", bmi);

	printf("BMI VALUES"); //BMI對照表 
	printf("%-14s%21s", "\nUnderweight:", "less than 18.5"); 
	printf("%-14s%21s", "\nNormal:", "between 18.5 and 24.9");
	printf("%-14s%21s", "\nOverweight:", "between 25 and 29.9");
	printf("%-14s%21s", "\nObese:", "30 or greater");

}