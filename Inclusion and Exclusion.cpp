#include <iostream>
#include <string.h>

using namespace std;

#define size 20

struct info {
	string name;
	int roll;
};

info *two_union(info arr1[size], info arr2[size], int size1, int size2) {
    cout << "Taking union of A and B:" << endl;
	int flag=0;
	int count=0;
	static info arr3[size];
	for (int i=0;i<size1; i++) {
		arr3[count] = arr1[i];
		count++;			
	}

	for (int i=count; i< size1+size2;i++) {
		for (int j=0; j< size1;j++) {
			if (arr1[j].roll == arr3[i-size1].roll) {
                flag=1;
		        break;
            }
	    }
    	if (flag==0) {
    		arr3[count] = arr2[i-size1];
    		count++;
    	}		
    	flag=0;		
	}
    cout << "Elements are : "; 
	for (int i=0; i<count; i++) {
		cout << "Name: " << arr3[i].name << "----- Roll:" << arr3[i].roll << endl;
		cout << "--------------------------" << endl;
	}
	cout << endl;
	return arr3;
}


info *three_union(info arr1[size], info arr2[size], info arr3[size], int size1, int size2, int size3) {
	cout << "Taking union of A, B and C:" << endl;
	int size5,size6;
	info *arr5 = two_union(arr1,arr2,size1,size2);
	info *arr6 = two_union(arr2,arr3,size2,size3);
	int flag=0, count=0;
	static info arr4[size];
	for (int i=0;i<size5; i++) {
		arr4[count] = arr5[i];
		count++;			
	}
	for (int i=count; i< size5+size6; i++) {
		for (int j=0; j< size5; j++) {
    		if (arr4[i-size5].roll == arr5[size5].roll) {
				flag=1;
				break;
			}
		}
		if (flag==0) {
			arr4[count] = arr4[i-size5];
			count++;
		}
		flag=0;
	}
	cout << "Elements are : "; 
	for (int i=0; i<count; i++) {
		cout << "Name: " << arr4[i].name << "----- Roll:" << arr4[i].roll << endl;
		cout << "--------------------------" << endl;	
	}
	cout << endl;
	return arr4;
}


info *two_intersection(info arr1[size], info arr2[size], int size1, int size2) {
	cout << "Taking intersection of A and B:" << endl;
	int flag=0,count=0;
	static info arr3[size];
	for (int i=0; i< size1; i++) {
		for (int j=0; j< size2; j++) {
			if (arr1[i].roll == arr2[j].roll) {
				flag=1;
				break;
			}
		}
		if (flag==1) {
			arr3[count] = arr1[i];
			flag=0;
			count++;
		}
	}
	cout << "Elements are : "; 
	for (int i=0; i<count; i++) {
		cout << "Name: " << arr3[i].name << "----- Roll:" << arr3[i].roll << endl;
		cout << "--------------------------" << endl;		
	}
	cout << endl;
	return arr3;
}


info *three_intersection(info arr1[size], info arr2[size], info arr3[size], int size1, int size2, int size3) {
	cout << "Taking intersection of A, B and C:" << endl;
	int flag=0,count=0;
	static info arr4[size];
	for (int i=0; i< size1; i++) {
		for (int j=0; j< size2; j++) {
			for (int k=0; k< size3; k++) {
				if (arr1[i].roll == arr2[j].roll and arr2[j].roll==arr3[k].roll) {
					flag=1;
					break;
				}
			}
		}
		if (flag==1) {
			arr4[count] = arr1[i];
			flag=0;
			count++;
		}
	}
	cout << "Elements are : "; 
	for (int i=0; i<count; i++) {
		cout << "Name: " << arr4[i].name << "----- Roll:" << arr4[i].roll << endl;
		cout << "--------------------------" << endl;		
	}
	cout << endl;
	return arr4;
}


info *give_input(int num) {
	cout << "Enter Details of students:" << endl;
	static info arr[size];
	for (int i=0; i<num;i++) {
		cout << "Enter name: ";
		cin >> arr[i].name;
		cout << "Enter roll: ";
		cin >> arr[i].roll;
	}
	return arr;
}


void give_output(int num, info *cleared) {
	cout << "Entered Details of students:" << endl;
	for (int i=0; i<num;i++) {
		cout << "Name: " << cleared[i].name << "----- Roll:" << cleared[i].roll << endl;
		cout << "--------------------------" << endl;		
	}
}

int main() {
	int num;
	cout << "Enter number of students: ";
	cin >> num;
	info *cleared=give_input(num);
	give_output(num, cleared);
    	return 0;
}
