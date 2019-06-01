#include <iostream>
#include <time.h>
#include <cmath>
#include <cstdlib>
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
void quick_sort(int* arr, int beg, int end, int amount);
int partition(int* arr, int beg, int end, int amount);
void swap(int* a, int* b);
void insertion_sort(int* arr, int amount);
void merge_sort(int* arr, int beg, int end);
void merge(int* arr, int beg, int mid, int end);


int main(){
    int amount, *arr1, *arr2, *arr3, *arr4, i;
    double start, end;

    srand( time(NULL) );

    cin >> amount;
    arr1 = new int[amount];
    arr2 = new int[amount];
    arr3 = new int[amount];
    arr4 = new int[amount];
    for(i=0;i<amount;i++){
        arr1[i] = rand() % 10000000;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }
    start = clock();
    quick_sort(arr1, 0, amount-1, amount);
    end = clock();
    cout << endl << end-start<< endl;
    start = clock();
    merge_sort(arr2, 0, amount-1);
    end = clock();
    cout << end-start<< endl;
    start = clock();
    radix_sort(arr3, amount);
    end = clock();
    cout << end-start<< endl;
    start = clock();
    insertion_sort(arr4, amount);
    end = clock();
    cout << end-start<< endl;
    delete(arr1);
    delete(arr2);
    delete(arr3);
    delete(arr4);
}

void insertion_sort(int* arr, int amount){
    int temp, j;
    for(int k=1; k < amount; k++){
        temp = arr[k];
        j = k-1;
        while(temp <= arr[j] && j > -1){

            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}



void quick_sort(int* arr, int beg, int end, int amount){
    int loc;
    if(beg < end){
        loc = partition(arr, beg, end, amount);
        quick_sort(arr, beg, loc-1, amount);
        quick_sort(arr, loc+1, end, amount);
    }
}

int partition(int* arr, int beg, int end, int amount){
    int left = beg, right = end, loc = beg, flag = 0, i;
    while(flag == 0){
        while(arr[loc] <= arr[right] && loc != right){
            right = right - 1;
        }
        if(loc == right){
            flag = 1;
        } else if(arr[loc] > arr[right]){
            swap((&arr[loc]), &(arr[right]));
            loc = right;
        }
        if(flag == 0){
            while(arr[loc] >= arr[left] && loc != left){
            left = left + 1;
            }
            if( loc == left){
                flag = 1;
            } else if(arr[loc] < arr[left]){
                swap(&(arr[loc]), &(arr[left]));
                loc = left;
            }
        }
    }
    return loc;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge_sort(int* arr, int beg, int end){
    int mid;
    if(beg < end){
        mid = (beg + end)/2;
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, beg, mid, end);

    }

}

void merge(int* arr, int beg, int mid, int end){
    int i, j, k, n1 = mid-beg+1, n2 = end-mid;
    int *left = new int[n1], *right = new int[n2];
    for(int i=0; i < n1; i++){
        left[i] = arr[i+beg];
    }
    for(int j = 0; j < n2; j++){
        right[j] = arr[j+mid+1];
    }
    i = 0, j = 0, k = beg;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    if (i < n1){
        for(i; i < n1; i++){
            arr[k] = left[i];
            k++;
        }
    }
    if (j < n2){
        for(j; j < n2; j++){
            arr[k] = right[j];
            k++;
        }
    }
    delete(left);
    delete(right);
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
