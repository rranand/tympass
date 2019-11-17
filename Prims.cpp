#include <iostream>
using namespace std;

#define max 10000
#define size 20

/*
At first creating prims class has been created. In contructor, user will input vertex, arms along with the source and destination vertex as well as its weight
To remove garbage from each array, two for loops are used. Afterwards user will input the  src, des and weight.
*/

class prims {
	public:
		int vertex,arms;
		int weight[size][size],dis[size],p[size],visited[size];
		//Creating required variables to store data from user using constructor
		prims() {
			cout << "Enter number of vertex: ";
			cin >> vertex;
			cout << "Enter total number of arms: ";
			cin >> arms;
			for (int i=1;i<=vertex;i++) {
				dis[i]=max;
				visited[i]=p[i]=0;
				for (int j=1;j<=vertex;j++) {
					weight[i][j]=0;
				}
			}
			int v1,v2,w;
			for (int i=1;i<=arms;i++) {
				cout << "Enter source, destination vertex and weight: ";
				cin >> v1 >> v2 >> w;
				weight[v1][v2]=weight[v2][v1]=w;
			}
		}
		
		void calculate();
};

/*
In below function, for 0 vertex weight(distance) is assigned i.e zero as well as in visited array 1 is stored showing first vertex is used, we can't use it further 
While loop will check all vertex input by the user is covered or not
For loop will assign the distance from the weight array into dis array(distance) only if weight is non zero as well as must be unvisited vertex
Now the main part, afterwards it will check for the unvisited vertex and check for the minimum weight between two arms if found it will store it in min_cost from dis array and mark that vertex visited
so, it cant be visited again and increase the count. 
Now we have the shortest possible route in dis array to calculate the minimum cost to cover all vertex, for loop used to sum all elements in dis array as well as it store its sum in the min_cost array.
*/


void prims::calculate() {
	int count=1,min_cost=0,cur=1;
	visited[cur]=1;
	dis[cur]=0;
	while (vertex!=count) {
		for (int i=1;i<=vertex;i++) {
			if (weight[cur][i]!=0) {
				if (visited[i]==0) {
					if (dis[i]>weight[cur][i]) {
						dis[i]=weight[cur][i];
						p[i]=cur;
					}
				}
			}
		}
		
		min_cost=max;
		for (int i=1;i<=vertex;i++) {
			if (visited[i]==0) {
				if (dis[i]<min_cost) {
					min_cost=dis[i];
					cur=i;
				}
			}
		}
		visited[cur]=1;
		count++;
	}
	
	min_cost=0;
	cout << "DIS:" << endl;
	for (int i=1;i<=vertex;i++) {
		min_cost+=dis[i];
	}
	cout << "Minimum Cost " << min_cost << endl;
};

/*
object is created and calculate function is called in the class.
*/
int main() {
	prims ini;
	ini.calculate();
	return 0;
}
