//將電話區碼轉成int，八碼轉成long並印出
#include <stdio.h>
#include <string.h>
int main(){
	char input[20] = {0}, phone[9], temp[3] = {0}, *p;
	int area;
	long number;
	
	printf("Enter a phone number: ");
	scanf("%s", input); //使用者輸入電話號碼
	
	strncat(temp, &input[1], 2); //將第二和第三個字元放入temp
	sscanf(temp, "%d", &area); //從temp讀出int存入area
	strncat(phone, &input[4], 4); //將input的第五~八碼存入phone
	strncat(phone, &input[9], 4); //將input的第十~十三碼接在phone後面
	sscanf(phone, "%ld", &number); //將phone轉成long存在number裡
	
	printf("\nArea code: %02d\nPhone number: %08ld", area, number); //印出結果
	
}

/*
//將電話區碼轉成int，八碼轉成long並印出
#include <stdio.h>
#include <string.h>
int main(){
	char input[20] = {0}, phone[9];
	int area;
	long number;
	
	printf("Enter a phone number: ");
	scanf("%s", input); //使用者輸入電話號碼

	sscanf(&input[1], "%d", &area); //從temp讀出int存入area
	sscanf(&input[4], "%[^-]", phone); //將input的第五~八碼存入phone
	sscanf(&input[9], "%s", &phone[4]); //將input的第十~十三碼接在phone後面
	sscanf(phone, "%ld", &number); //將phone轉成long存在number裡
	
	printf("\nArea code: %02d\nPhone number: %08ld", area, number); //印出結果
	
}
*/