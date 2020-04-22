#include <iostream>
using namespace std;

int main() {
  int vertex, temp=0, minDis = 0, count=0;
  cout << "Enter total number of cornors: ";
  cin >> vertex;
  int distance[vertex][vertex];
  int visited[vertex];
  for(int i=0;i<vertex;i++) {
    visited[i]=0;
  }

  cout << "If distance does not exists between two paths as directed then enter 0\n";
  for(int i=0; i<vertex;i++) {
    for(int j=0; j<vertex;j++) {
      cout << "Enter distance between " << i+1 << " and " << j+1 << ": ";
      cin >> distance[i][j];
    }
  }
  
  int currentV=0;
  while (vertex-1>count) {
    int tempMax =9999;
    visited[currentV] = 1;
    for(int i=0; i<vertex;i++) {
      if (distance[currentV][i]==0) {
        continue;
      }
      if (distance[currentV][i]<tempMax) {
        tempMax = distance[currentV][i];
        temp= i;
      }
    }
    minDis += tempMax;
    currentV = temp;
    count++;
  }
  cout << "Minimum Distance: " << minDis;
  return 0;
}
