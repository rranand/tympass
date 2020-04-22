#include <iostream>
using namespace std;

int main() {
  int vertex, temp=0, minDis = 0, count=0;
  cout << "Enter total number of cornors: ";
  cin >> vertex;
  int distance[vertex][vertex];

  cout << "If distance does not exists between two paths as directed then enter 0/n";
  for(int i=0; i<vertex;i++) {
    for(int j=0; j<vertex;j++) {
      cout << "Enter distance between " << i+1 << " and " << j+1 << ": ";
      cin >> distance[i][j];
    }
  }
  
  int tempMax =9999, currentV=0;
  while (vertex>count) {

    for(int i=0; i<vertex;i++) {
      if (distance[currentV][i]==0) {
        continue;
      } else {
        if (minDis+distance[currentV][i]<tempMax) {
          tempMax = minDis+distance[currentV][i];
          temp= i;
        }
      }
      minDis = tempMax;
      currentV = temp;
    }
    count++;
  }
  cout << "Minimum Distance: " << minDis;
  return 0;
}
