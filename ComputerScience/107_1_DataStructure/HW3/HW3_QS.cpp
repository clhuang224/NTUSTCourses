#include <iostream>
using namespace std;

void quick_sort(int* arr, int beg, int end, int amount);
int partition(int* arr, int beg, int end, int amount);
void swap(int* a, int* b);

int main(){
    int amount, *arr, i;
    cin >> amount;
    arr = new int[amount];
    for(i=0;i<amount;i++){
        cin >> arr[i];
    }
    quick_sort(arr, 0, amount-1, amount);
    delete(arr);
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
    for(i=0;i<amount;i++){
            cout << arr[i] << ((i == amount-1) ? '\n':' ');
    }
    return loc;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
