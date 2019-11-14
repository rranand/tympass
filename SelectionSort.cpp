#include <iostream>
using namespace std;

/*
Here swapping is done, by creating a variable called temp by which swapping is done by using pointer.
*/

void swap(int *min,int *max) {
    int temp=*min;
    *min=*max;
    *max=temp;
}

/*
Here, we are creating non-return type function and passing an array in arr[] and size of array in 'n' variable. In this function, two for loops are initialize to tranverse in the array and while traversing we are checking for minimum value in array and storing its index in min variable and after each iteration, we swap the initial value of array with minimum value in the array 
*/
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

/*
Firstly take input from user how many numbers user want to store and creating that size of array and taking input from user afterwards, displaying of each elements in the array has been done. After that sorting function is called to sort the elements in the array. Finally printing of elements in array is done.
*/

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
