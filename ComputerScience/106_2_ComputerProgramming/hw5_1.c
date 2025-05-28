//使用者輸入unsigned int，輸出左右相反的bit
#include <stdio.h>
void reverseBits(unsigned int input);
void printBinary(unsigned int input);
int main(){
	unsigned int input, output;
	
	printf("Enter an integer:");
	scanf("%u", &input);
	
	reverseBits(input); //呼叫函式
}

void reverseBits(unsigned int input){ //將bit左右顛倒
	int i = 31;
	unsigned int result = 0; //00000000000000000000000000000000
	
	printf("\n=Before=\nNumber: %u\nBits: ", input); //輸出顛倒前的十進位及二進位數字
	printBinary(input);
	
	while(input > 0){
		result = result | (input & 1); //取input的末位放在result的末位 //00000000000000000000000000000001 or 0
		input >>= 1; //input除以2
		result <<= 1; //result向左移一格 //00000000000000000000000000000010 or 00
		i--; //扣掉已經移過的次數
	}
	if (i >= 0){
	    result <<= i; //當input中沒有剩下的1時，將result整個往左位移（等於右邊補上i個零）
	} else {
	    result >>= 1; //當input第一位是1時，result會多被左移一次，要移回來一格
	}
	
	printf("\n=After=\nNumber: %u\nBits: ", result); //輸出顛倒後的十進位及二進位數字
	printBinary(result);
}

void printBinary(unsigned int input){ //將十進位數字以二進位字串印出來
	char result[33] = "00000000000000000000000000000000";
	int i;
	unsigned int j = 2147483648; //1000000000000000000000000000000
	for(i = 0; i < 32; i++){
	    result[i] = ((input & j) >> (31-i) ) + 48; //取input的最左邊一位並右移到最右邊一位（一定是0或1），+48則為’0’或’1’，放入result對應的位置
	    j >>= 1; //下一迴圈取下一位
	}
	printf("%s\n" ,result);
}

/*
//使用者輸入unsigned int，輸出左右相反的bit
#include <stdio.h>
unsigned int reverseBits(unsigned int input);
void printBinary(unsigned int input);
int main(){
	unsigned int input, output;
	
	printf("Enter an integer:");
	scanf("%u", &input);
	
	printf("\n=Before=\nNumber: %u\nBits: ", input); //輸出顛倒前的十進位及二進位數字
	printBinary(input);	
	
	output = reverseBits(input); //呼叫函式
	
	printf("\n=After=\nNumber: %u\nBits: ", output); //輸出顛倒後的十進位及二進位數字
	printBinary(output);
}

unsigned int reverseBits(unsigned int input){ //將bit左右顛倒
	int i = 31;
	unsigned int result = 0; //00000000000000000000000000000000
	while(input > 0){
		result |= (input & 1); //取input的末位放在result的末位 //00000000000000000000000000000001 or 0
		input >>= 1; //input除以2
		result <<= 1; //result向左移一格 //00000000000000000000000000000010 or 00
		i--; //扣掉已經移過的次數
	}
	if (i >= 0){
	    result <<= i; //當input中沒有剩下的1時，將result整個往左位移（等於右邊補上i個零）
	} else {
	    result >>= 1; //當input第一位是1時，result會多被左移一次，要移回來一格
	}
	return result;
}

void printBinary(unsigned int input){ //將十進位數字以二進位字串印出來
	char result[33] = "00000000000000000000000000000000";
	int i;
	unsigned int j = 2147483648; //1000000000000000000000000000000
	for(i = 0; i < 32; i++){
	    result[i] = ((input & j) >> (31-i) ) + 48; //取input的最左邊一位並右移到最右邊一位（一定是0或1），+48則為’0’或’1’，放入result對應的位置
	    j >>= 1; //下一迴圈取下一位
	}
	printf("%s\n" ,result);
}

*/