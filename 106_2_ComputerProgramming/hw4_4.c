//計算4行文字中的詞數
#include <stdio.h>
#include <string.h>
int main(){
	char input[4][256]={0}, *temp;	//宣告字串要存放的空間及指標
	int i, counter = 0;

	printf("Enter 4 line of texts:\n");

	for(i = 0; i < 4; i++){
		scanf("%[^\n]", input[i]);	//將\n前的字元掃進input[i]
		temp = strtok(input[i], " ");	//將temp指向空白鍵前的第一個字元
		while(temp != NULL){	//當temp不等於NULL就執行
			counter++;	//每跑一次迴圈代表數了一個詞
			temp = strtok(NULL, " ");	//繼續讓temp指向下一個空白鍵前的第一個字元
		}
		if (i < 3)
            scanf("%*[\n]");	//跳過換行符號
	}
	printf("\nThere are %d words.", counter);
}
