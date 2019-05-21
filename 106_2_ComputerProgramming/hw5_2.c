//使用者選擇想要大寫還是小寫字母的ASCII value，並印到檔案中
#include <stdio.h>
int main(){
	int input = 2, i;
	FILE* fp;

	printf("%s%s%s","Enter 0 for lowercase,", //使用者輸入想要大寫還是小寫的文件
					" 1 for uppercase,",
					" others for nothing: ");
	scanf("%d", &input);

	if(input == 0){ //輸入0，輸出小寫的ASCII value
		fp = fopen("values.dat", "w"); //以寫入的模式打開values.dat
		fprintf(fp,"Character  ASCII value\n");
		for(i = 97; i <= 122; i++){
			fprintf(fp,"%5c%13d\n", i, i);
		}
		fclose(fp); //關檔
		printf("The lowercase are in values.dat\n");
	} else if(input == 1){ //輸入1，輸出大寫的ASCII value
		fp = fopen("values.dat", "w"); //開檔
		fprintf(fp,"Character  ASCII value\n");
		for(i = 65; i <= 90; i++){
			fprintf(fp,"%5c%13d\n", i, i);
		}
		fclose(fp); //關檔
		printf("The uppercase are in values.dat\n");
	} else { //輸入其他數字或字母則無效
		printf("Nothing happened.\n");
	}

}
