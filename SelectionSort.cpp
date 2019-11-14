#include <iostream>
using namespace std;

void swap(int *min,int *max) {
    int temp=*min;
    *min=*max;
    *max=temp;
}

void sort(int arr[],int n) {
    int j,min;
    for(int i=0;i<n-1;i++) {
        min=i;
        for(j=i+1;j<n;j++) {
            if (arr[j]<arr[min]) {
                min=j;
            }
        }
        swap(&arr[min],&arr[i]);
    }    
}

int main() {
    int n;
    cout << "Enter number of numbers:";
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cout << "Enter elements in array:";
        cin >> arr[i];       
    }
    cout << "Display elements before sort: ";
    for(int i=0;i<n;i++) {
        cout << arr[i] << "\t";       
    }
    sort(arr,n);
    cout << endl << "Display elements after sort:\t";
    for(int i=0;i<n;i++) {
        cout << arr[i] << "\t";       
    }
    return 0;   
}


/*
OUTPUT:-

Enter number of numbers:4
Enter elements in array:90
Enter elements in array:12
Enter elements in array:91
Enter elements in array:3
Display elements before sort: 90	12	91	3	
Display elements after sort:	3	12	90	91
*/
