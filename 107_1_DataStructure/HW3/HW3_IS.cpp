#include <iostream>
using namespace std;

void insertion_sort(int* arr, int amount);

int main(){
    int amount, *arr, i;
    cin >> amount;
    arr = new int[amount];
    for(i=0;i<amount;i++){
        cin >> arr[i];
    }
    insertion_sort(arr, amount);
    delete(arr);
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
        for(int i=0;i<amount;i++){
            cout << arr[i] << ((i==amount-1)?'\n':' ');
        }
    }
}

