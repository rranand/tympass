#include <iostream>
#include <string.h>
using namespace std;

#define size 4

void print_path(int graph[][size], string cities[size]) {
    cout << endl;
	for (int i=0;i<size;i++) {
		for (int j=0;j<size;j++) {
			cout << "Path between " << cities[i] << " and " << cities[j] << " is " << graph[i][j] << endl;
		}
		cout << endl;
	}
	
	for (int i=0;i<size;i++) {
		for (int j=0;j<size;j++) {
			cout << graph[i][j] << "  ";
		}
		cout << endl;
	}
}

void calculate(int graph[][size], string cities[size]) {
    
    int path[size][size];
    
    for (int i=0; i<size;i++) {
        for (int j=0;j<size;j++) {
            
            path[i][j] = graph[i][j];
        }
    }
    
    for (int i=0; i<size;i++) {
        for (int j=0;j<size;j++) {
            for (int k=0;k<size;k++) {
                
                path[i][j] = path[i][j] or (path[j][i] and path[i][k]);
                
            }
        }
    } 
    
    print_path(path, cities);
    
}

int main() {
    
    string cities[size];
    
    cout << "Enter " << size << " cities:" << endl;
    for (int i=0; i<size;i++){
        cout << "Enter city: ";
        cin >> cities[i];
    }
    int press;
    int graph[size][size];
    cout << "Want to give input press 1 or for default input press 2:";
    cin >> press;
    
    switch (press) {
        case 1:
            for (int i=0;i<size;i++) {
        		for (int j=0;j<size;j++) {
        			cout << "Enter path between " << i << " and " << j << ":";
        			cin >> graph[i][j];
        		}
        	}
            calculate(graph,cities);
            break;
        case 2:
            int graph_al[][size]= { {1, 1, 0, 1}, 
                            {0, 1, 1, 0}, 
                            {0, 0, 1, 1}, 
                            {0, 0, 0, 1}  };
            cout << endl;
            print_path(graph_al, cities);
            cout << endl << "Calculating Path:" << endl;
            calculate(graph_al, cities);
            break;
    }
	
	return 0;
}




/*
OUTPUT:

Enter 4 cities:
Enter city: Pune
Enter city: Patna
Enter city: Goa
Enter city: Nagpur
Want to give input press 1 or for default input press 2:2


Path between Pune and Pune is 1
Path between Pune and Patna is 1
Path between Pune and Goa is 0
Path between Pune and Nagpur is 1

Path between Patna and Pune is 0
Path between Patna and Patna is 1
Path between Patna and Goa is 1
Path between Patna and Nagpur is 0

Path between Goa and Pune is 0
Path between Goa and Patna is 0
Path between Goa and Goa is 1
Path between Goa and Nagpur is 1

Path between Nagpur and Pune is 0
Path between Nagpur and Patna is 0
Path between Nagpur and Goa is 0
Path between Nagpur and Nagpur is 1

1  1  0  1  
0  1  1  0  
0  0  1  1  
0  0  0  1  

Calculating Path:

Path between Pune and Pune is 1
Path between Pune and Patna is 1
Path between Pune and Goa is 0
Path between Pune and Nagpur is 1

Path between Patna and Pune is 1
Path between Patna and Patna is 1
Path between Patna and Goa is 1
Path between Patna and Nagpur is 0

Path between Goa and Pune is 0
Path between Goa and Patna is 1
Path between Goa and Goa is 1
Path between Goa and Nagpur is 1

Path between Nagpur and Pune is 1
Path between Nagpur and Patna is 0
Path between Nagpur and Goa is 1
Path between Nagpur and Nagpur is 1

1  1  0  1  
1  1  1  0  
0  1  1  1  
1  0  1  1  
*/
