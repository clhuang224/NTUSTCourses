#include <iostream>
using namespace std;
#define MAX 40

void push(int stack[], int* top, int value);
int pop(int stack[], int* top);
void display(int stack[], int top);
int peek(int stack[], int top);
void in_to_post(char infix[], char postfix[]);
void reverse(char input[], char output[]);
void in_to_pre(char infix[], char prefix[]);

int main(){
	char infix[MAX] = {0}, postfix[MAX] = {0}, prefix[MAX] = {0};
	int i = 0;

	cout << "請輸入中序式：";
	cin >> infix; //輸入infix

	cout << endl << "====Infix to Postfix====" << endl;
	in_to_post(infix, postfix);
	cout << endl;

	cout << "====Infix to Prefix====" << endl;
	in_to_pre(infix, prefix);

	cout << endl << endl << "====Result====" << endl;

	cout << "Infix:   " << infix << endl;
	cout << "Postfix: " << postfix << endl;
	cout << "Prefix:  " << prefix << endl;

}
void push(int stack[], int* top, int value){
	if(*top == MAX - 1){
		cout << "Stack overflow" << endl;
	} else {
		(*top)++;
		stack[*top] = value;
	}
}
int pop(int stack[], int* top){
	int value;
	if(*top == -1){
		return -1;
	} else {
		value = stack[*top];
		(*top)--;
		return value;
	}
}
void display(int stack[], int top){ //印出stack
	int i;
	if(top == -1){
		cout << ' ';
	} else {
		for(i = 0; i <= top; i++){
			cout << (char)stack[i];
		}
	}
}
int peek(int stack[], int top){ //return stack的top
	if(stack[top] == -1){
		return -1;
	} else {
		return stack[top];
	}
}
void in_to_post(char infix[], char postfix[]){ //中序轉成後序
	int stack[MAX] = {0};
	int top = -1, i = 0, last, j = 0, temp = 0;

	cout << "Scanned\t\tStack\t\tPostfix" << endl;

	while(infix[i] != '\0'){ //STEP 1
		i++;
	}
	last = i;
	infix[i] = ')';
	i = 0;

	push(stack, &top, '('); // STEP 2

	cout << "\t\t"; //-------
	display(stack, top); //-------
	cout << endl;

	while(infix[i] != '\0'){ //STEP 3

		cout << infix[i] << "\t\t"; //-------

		switch(infix[i]){
			case '(': //遇到(就push
				push(stack, &top, '(');
				break;
			case ')': //遇到)就一直pop到Postfix，遇到(停止，不放(
				temp = pop(stack, &top);
				while(temp != '('){
					postfix[j] = temp;
					j++;
					temp = pop(stack, &top);
				}
				break;
			case '+':
			case '-':
				temp = peek(stack, top);
				while (temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '%') {
					postfix[j] = pop(stack, &top);
					j++;
					temp = peek(stack, top);
				}
				push(stack, &top, infix[i]);
				break;
			case '*':
			case '/':
			case '%':
				temp = peek(stack, top);
				while (temp == '*' || temp == '/' || temp == '%') {
					postfix[j] = pop(stack, &top);
					j++;
					temp = peek(stack, top);
				}
				push(stack, &top, infix[i]);
				break;
			default: //遇到其餘英數直接放postfix
				postfix[j] = infix[i];
				j++;
				break;
		}
		i++;

		display(stack, top);
		cout << "\t\t" << postfix << endl;
	}

	infix[last] = '\0';
}
void in_to_pre(char infix[], char prefix[]){ //中序轉成前序
	int i = 0, j = 0;
	char temp1[MAX] = {0}, temp2[MAX] = {0};

	reverse(infix, temp1); //STEP 1
	while(temp1[i] != '\0'){
		if(temp1[i] == '('){
			temp1[i] = ')';
		} else if(temp1[i] == ')'){
			temp1[i] = '(';
		}
		i++;
	}
	cout << "STEP 1: " << infix << "  ->  " << temp1 << endl;
	cout << "STEP 2: " << endl;
	in_to_post(temp1, temp2); //STEP 2
	reverse(temp2, prefix); //STEP 3
	cout << "STEP 3: " << temp2 << "  ->  " << prefix << endl;
}
void reverse(char input[], char output[]){ //把一個array反過來放在另一個array
	int i = 0, j = 0;

	while(input[i] != '\0'){ //找出最後一個項目
		i++;
	}
	i--;
	for(i; i >= 0; i--){ //倒著放到另一個array
		output[j] = input[i];
		j++;
	}
}
