#include <stdio.h>

//輸入工作時數和時薪，計算薪水 
int main(){
	
	int hours = 0;
	float rate, salary;
	
	printf("Enter # of hours worked (-1 to end) : ");
	scanf("%d", &hours); //輸入時數（輸入-1結束） 
	
	while (hours != -1){
			
		printf("Enter hourly rate of the worker ($00.00): ");
		scanf("%f", &rate); //輸入時薪 
		
		if (hours > 40) //超過40小時的時數以1.5倍算 
			salary = (hours * 1.5 - 20) * rate;  //化簡 (40 + (hours - 40) * 1.5) * rate 
		else 
			salary = hours * rate;
			
		printf("Salary is $%.2f",salary); //薪水取小數點後兩位 
		
		hours = -1; //結束迴圈 
	}
}