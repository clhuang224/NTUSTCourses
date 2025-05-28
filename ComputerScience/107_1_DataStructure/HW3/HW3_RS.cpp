#include <iostream>
#include <cmath>
using namespace std;

typedef struct Node{
	struct Node* next;
	int value;
} Node;

void radix_sort(int* arr, int amount);
int maximun(int* arr, int amount);
int number_of_digit(int value);
void insert_list(int value, Node** present);
void del_list(Node** present);

int main(){
    int amount, *arr, i;
    cin >> amount;
    arr = new int[amount];
    for(i=0;i<amount;i++){
        cin >> arr[i];
    }
    radix_sort(arr, amount);
    delete(arr);
}

void radix_sort(int* arr, int amount){
    int j, digit, max = maximun(arr, amount), nop=number_of_digit(max), pass = 0;
    Node *bucket[10]={0}, *temp;
    while(pass < nop-1){
        for(int i = 0; i < amount; i++){
            if(number_of_digit(arr[i])<pass+1){
                digit = 0;
            } else{
                digit = (arr[i]%(int)pow(10, pass + 1))/(int)pow(10,pass);
            }
            insert_list(arr[i], &(bucket[digit]));
            j = 0;
            for(int k=0;k<10;k++){
                temp = bucket[k];
                while(temp != NULL){
                    arr[j]=temp->value;
                    j++;
                    temp = temp->next;
                }


            }
        }
        for(int k=0;k<amount;k++){
                cout << arr[k] << ((k==amount-1)? '\n':' ');
            }
        for(int k = 0; k<10;k++){
            del_list(&(bucket[k]));
        }
        pass++;
    }
}

int maximun(int* arr, int amount){
    int max = arr[0];
    for(int i = 1; i < amount; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int number_of_digit(int value){
    int number = 1;
    while (value != 0)
    {
        value /= 10;
        number++;
    }
    return number;
}

void insert_list(int value, Node** present){
    Node *temp;
    if(*present == NULL){
                *present = new Node;
                (*present)->value = value;
                (*present)->next = NULL;
    } else {
        temp = (*present);
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new Node;
        temp = temp->next;
        temp->value = value;
        temp->next = NULL;
    }
}

void del_list(Node** present){
    Node* temp;
    if((*present) != NULL){
        while((*present)->next != NULL){
            temp = *present;
            *present = (*present)->next;
            delete(temp);
        }
        delete(*present);
        *present = NULL;
    }
}
