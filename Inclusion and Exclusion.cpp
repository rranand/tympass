#include <iostream>
#include <string.h>

using namespace std;

#define size 20

struct info {
	string name;
	int roll;
};

class pass_it {
  public:
    int count;
    info* arr= new info[size];
};

pass_it* two_union(info *arr1, info *arr2, int size1, int size2) {
    cout << "Taking union:" << endl;
	int flag=0;
	int count=0;
	info* arr3 = new info[size];
	for (int i=0;i<size1; i++) {
		arr3[count] = arr1[i];
		count++;			
	}

	for (int i=count; i< size1+size2;i++) {
		for (int j=0; j< size1;j++) {
			if (arr1[j].roll == arr2[i-size1].roll) {
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
    cout << "Elements are : " << endl; 
	for (int i=0; i<count; i++) {
		cout << "Name: " << arr3[i].name << "----- Roll:" << arr3[i].roll << endl;
		cout << "--------------------------" << endl;
	}
	cout << endl;
  pass_it *pass;
  pass->count = count;
  pass->arr= arr3;
	return pass;
}

/*
info* three_union(info *arr1, info *arr2, info *arr3, int size1, int size2, int size3) {
	cout << "Taking union:" << endl;
	int size5,size6;
	info *arr5 = two_union(arr1,arr2,size1,size2);
	info *arr6 = two_union(arr2,arr3,size2,size3);
	int flag=0, count=0;
	info* arr4 = new info[size];
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
	cout << "Elements are : " << endl; 
	for (int i=0; i<count; i++) {
		cout << "Name: " << arr4[i].name << "----- Roll:" << arr4[i].roll << endl;
		cout << "--------------------------" << endl;	
	}
	cout << endl;
	return arr4;
}*/


pass_it* two_intersection(info *arr1, info *arr2, int size1, int size2) {
	cout << "Taking intersection:" << endl;
	int flag=0,count=0;
	info* arr3 = new info[size];
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
	cout << "Elements are : " << endl; 
	for (int i=0; i<count; i++) {
		cout << "Name: " << arr3[i].name << "----- Roll:" << arr3[i].roll << endl;
		cout << "--------------------------" << endl;		
	}
	cout << endl;
	pass_it *pass;
  pass->count = count;
  pass->arr= arr3;
	return pass;
}


int three_intersection(info *arr1, info *arr2, info *arr3, int size1, int size2, int size3) {
	cout << "Taking intersection:" << endl;
	int flag=0,count=0;
	info* arr4 = new info[size];
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
	}/*
	cout << "Elements are : " << endl; 
	for (int i=0; i<count; i++) {
		cout << "Name: " << arr4[i].name << "----- Roll:" << arr4[i].roll << endl;
		cout << "--------------------------" << endl;		
	}
	cout << endl;*/
	return count;
}


info* give_input(int num) {
	cout << "Enter Details of students:" << endl;
	info* arr = new info[size];
	for (int i=0; i<num;i++) {
		cout << "Enter name: ";
		cin >> arr[i].name;
		cout << "Enter roll: ";
		cin >> arr[i].roll;
	}
	return arr;
	
}

int main() {
	int num_cleared_hr, num_cleared_tech, num_cleared_vc;
	
	cout << "Enter number of students who cleared HR round: ";
	cin >> num_cleared_hr;
	info *cleared_hr=give_input(num_cleared_hr);
	
	cout << "Enter number of students who cleared technical round: ";
	cin >> num_cleared_tech;
	info *cleared_tech=give_input(num_cleared_tech);

	cout << "Enter number of students who cleared VC round: ";
	cin >> num_cleared_vc;
	info *cleared_vc=give_input(num_cleared_vc);
	
	pass_it *uni_ab=two_union(cleared_hr, cleared_tech, num_cleared_hr, num_cleared_tech);
	pass_it *uni_bc=two_union(cleared_hr, cleared_vc, num_cleared_hr, num_cleared_vc);
	pass_it *uni_ca=two_union(cleared_vc, cleared_tech, num_cleared_vc, num_cleared_tech);
	
	pass_it *int_ab=two_intersection(cleared_hr, cleared_tech, num_cleared_hr, num_cleared_tech);
	pass_it *int_bc=two_intersection(cleared_hr, cleared_vc, num_cleared_hr, num_cleared_vc);
	pass_it *int_ca=two_intersection(cleared_vc, cleared_tech, num_cleared_vc, num_cleared_tech);
	cout << endl;

  cout << "No. of elements in all set: " <<  num_cleared_hr+num_cleared_tech +num_cleared_vc-(int_ab->count+ int_bc->count+ int_ca->count- three_intersection(int_ab->arr, int_bc->arr, int_ca->arr, int_ab->count, int_bc->count, int_ca->count)) << endl;

	return 0;
}
