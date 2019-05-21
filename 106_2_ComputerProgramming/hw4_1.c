//將兩個以排序過的陣列排序後合在一起
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	char str1[100] = {0}, str2[100] = {0}, *temp, **p;
	double a1[20] = {0}, a2[20] = {0}, result[40] = {0};
	int i = 0, j = 0, k = 0, num1 = 0, num2 = 0;

	printf("\nEnter two arrays:\n");
	
	scanf("%[^\n]", str1); //掃入換行符號前的所有字元
    temp = strtok(str1, " "); //使用strtok將每個值切開
	for(i = 0; temp != NULL; i++){
		a1[i] = strtod(temp, NULL); //使用strtod將每一段字串轉為double
		num1++; //計算目前放入陣列的值有幾個
		temp = strtok(NULL, " ");
	}
	
	scanf("%*[\n]%[^\n]", str2); //兩個陣列用同樣的處理方式
	temp = strtok(str2, " ");
    for(i = 0; temp != NULL; i++){
		a2[i] = strtod(temp, NULL);
		num2++;
		temp = strtok(NULL, " ");
	}
	
	i = 0;
	while(i < num1 && j < num2){ //當陣列還有需要比較的值時
		if (a1[i] < a2[j]){
			result[k] = a1[i]; //將較小的值先放入result，並拿該陣列的下一個出來比較
			k++;
			i++;
		}
		else if(a1[i] > a2[j]){
			result[k] = a2[j];
			j++;
			k++;
		} else {
			result[k] = a1[i]; //如果大小一樣就放一個進result
			i++;
			j++;
		    k++; //用k紀錄result中有幾個值
		}
	}
	while (i < num1){ //跳出上面的迴圈後必須將值比較多的陣列剩下的值放入result
		result[k] = a1[i];
			i++;
			k++;
	} while (j < num2){
		result[k] = a2[j];
			j++;
			k++;
	}
	printf("\nThe new array is:\n");
	for(i = 0; i < k; i++){
		printf("%g ", result[i]); //用%g省略小數點後的零
	}
	printf("\n");
}
