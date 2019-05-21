#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int wid_boundary(int data[], int size);
int wid_to_code(int data[], int size, char** code, int character_size, int boundary);
int code_to_char(char** code, int character_size, char* characters);
int weight(char character);
int cCheck(char* characters, int character_size);
int kCheck(char* characters, int character_size);

int main(){
	char filename[100] = {0}, *characters;
	FILE *fp;
	int size, character_size, i, data[150] = {0}, counter = 1, boundary;
	char **code;

	printf("Enter the filename: ");
	scanf("%s", filename);

	fp = fopen(filename, "r"); //讀檔
	fscanf(fp, "%d", &size);

	while(size != 0){ //data的寬度數量

		for(i = 0; i < size; i++){
			fscanf(fp, "%d", &data[i]); //把檔案的數字讀進data陣列
		}

		if((size + 1) % 6 == 0){
			boundary = wid_boundary(data, size);
			if(boundary > 0){
				character_size = (size + 1) / 6;
				code = (char**)malloc(sizeof(char*) * character_size);
				for(i = 0; i < character_size; i++)
					code[i] = (char*)malloc(sizeof(char) * 6);
				characters = (char*)malloc(sizeof(char) * (character_size + 1));

				if(wid_to_code(data, size, code, character_size, boundary) > 0){

					if(code_to_char(code, character_size, characters) > 0){
						if(cCheck(characters, character_size) < 0)
							printf("Case %d: bad C\n", counter);
						else{
							if(kCheck(characters, character_size) < 0)
								printf("Case %d: bad K\n", counter);
							else{
								printf("Case %d: ", counter);
								for(i = 1; i < character_size - 3; i++){
									printf("%c", characters[i]);
								}
								printf("\n");
							}
						}
					} else {
						printf("Case %d: bad code\n", counter);
					}
				} else {
					printf("Case %d: bad code\n", counter);
				}
				free(code); //清空code character和data
				free(characters);
				for(i = 0; i < size; i++)
					data[i] = 0;
			} else
				printf("Case %d: bad code\n", counter);
		} else {
			printf("Case %d: bad code\n", counter);
			for(i = 0; i < size; i++)
					data[i] = 0;
		}

		counter++; //進入下一筆資料
		fscanf(fp, "%d", &size);
	}
	fclose(fp);
}

int wid_boundary(int data[], int size){
	// return -1 數值超出範圍
	// return -2 找不到邊界
	// return avg 每個值都在邊界內
	int avg = 0, i, narrow_amount = 0;
	double a[4] = {0};

	for(i = 0; i < size; i++){
		if(data[i] < 1 || data[i] > 200) //判斷數值是否超出範圍
			return -1;
		avg += data[i];
	}
	avg /= size; //找出整筆資料的平均值

	for(i = 0; i < size; i++){
		//假設小於平均值的資料是narrow bar
		if(data[i] <= avg){ 
			a[0] += data[i];
			narrow_amount++;
		}
	}
    a[0] /= (double)narrow_amount;
	//假設narrow和wide bar的區間
    a[3] = a[0] * 2.10;
    a[2] = a[0] * 1.90;
    a[1] = a[0] * 1.05;
    a[0] = a[0] * 0.95;

	for(i = 0; i < size; i++){
		if(data[i] < a[0] || data[i] > a[3]
		   || (data[i] > a[1] && data[i] < a[2]))
			return -2; //超出區間
    }
	return avg;
}

int wid_to_code(int data[], int size, char **code, 

int character_size, int boundary){
	//return 1 順向轉
	//return 2 逆向轉
	//return -1 找不到開始/結束字元
	int i, j = 0, k = 0, min = data[0];
	char first[6] = {0}, last[6] = {0};

	for(i = 0; i < 5; i++){
		if(data[i] > boundary)
			first[i] = '1';
		else
			first[i] = '0';
	}
	for(i = size - 5; i < size; i++){
		if(data[i] > boundary)
			last[j] = '1';
		else
			last[j] = '0';
		j++;
	}

	j = 0;
	if (strcmp(first, "00110") == 0 && strcmp(last, "00110") == 0){
		for(i = 0; i < size; i++){
			if(data[i] > boundary)
				code[j][k] = '1';
			else
				code[j][k] = '0';
			k++;
			if(k > 4){
				code[j][5] = '\0';
				i++;
				j++;
				k = 0;
			}
		}
		return 1; //順向轉成code
	} else if(strcmp(first, "01100") == 0 && strcmp(last, "01100") == 0){
		j = character_size - 1;
		k = 4;
		for(i = 0; i < size; i++){
			if(data[i] > boundary)
				code[j][k] = '1';
			else
				code[j][k] = '0';
			k--;
			if(k < 0){
				code[j][5] = '\0';
				i++;
				j--;
				k = 4;
			}
		}
		return 2; //逆向轉成code
	} else {
		return -1; // 找不到S字元
	}
}

int code_to_char(char** code, int character_size, char* characters){
	//return 1 將code轉換成數字字串（包含C與K）
	//-1 含有不能轉換的code
	int i;
	for(i = 0; i < character_size; i++){
		if(strcmp(code[i],"10000") == 0){
			characters[i] = '0';
		} else if(strcmp(code[i],"10010") == 0){
			characters[i] = '1';
		} else if(strcmp(code[i],"00011") == 0){
			characters[i] = '2';
		} else if(strcmp(code[i],"10100") == 0){
			characters[i] = '3';
		} else if(strcmp(code[i],"01100") == 0){
			characters[i] = '4';
		} else if(strcmp(code[i],"11000") == 0){
			characters[i] = '5';
		} else if(strcmp(code[i],"00101") == 0){
			characters[i] = '6';
		} else if(strcmp(code[i],"01001") == 0){
			characters[i] = '7';
		} else if(strcmp(code[i],"10001") == 0){
			characters[i] = '8';
		} else if(strcmp(code[i],"00001") == 0){
			characters[i] = '9';
		} else if(strcmp(code[i],"00100") == 0){
			characters[i] = '-';
		} else if(strcmp(code[i],"00110") == 0){
			characters[i] = 'S';
		} else
			return -1; //存在不能轉換的code
	}
	characters[i] = '\0';
	return 1;
}

int weight(char character){
	if(character == '-')
		return 10;
	else
		return (character - '0');
}

int cCheck(char* characters, int character_size){
	int i, c = 0;

	for(i = 1; i < character_size - 3; i++){
		c += ((character_size - 4 - i) % 10 + 1) * weight(characters[i]);
	}
	c %= 11;
	if (c == (characters[character_size - 3] - '0')) //數字字元跟’0’的差距正好是數字的大小
		return 1;
	else
		return -1;
}

int kCheck(char* characters, int character_size){
	int i, k = 0;

	for(i = 2; i < character_size - 1; i++){
		k += ((character_size - 2 - i) % 9 + 1) * weight(characters[i-1]);
	}
	k %= 11;
	if (k == (characters[character_size - 2] - '0')) //數字字元跟’0’的差距正好是數字的大小
		return 1;
	else
		return -1;
}
