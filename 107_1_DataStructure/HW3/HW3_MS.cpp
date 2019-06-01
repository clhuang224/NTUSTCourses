#include <iostream>
using namespace std;

void merge_sort(int* arr, int beg, int end);
void merge(int* arr, int beg, int mid, int end);

int main(){
    int amount, *arr, i;
    cin >> amount;
    arr = new int[amount];
    for(i=0;i<amount;i++){
        cin >> arr[i];
    }
    merge_sort(arr, 0, amount-1);
    delete(arr);
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
    if(n1 == 1){
        cout << left[0] << endl;
    }
    for(int j = 0; j < n2; j++){
        right[j] = arr[j+mid+1];
    }
    if(n2 == 1){
        cout << right[0] << endl;
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
    for(int i=beg;i<end+1;i++){
        cout <<  arr[i] << ((i==end)?'\n':' ');
    }
    delete(left);
    delete(right);
}
