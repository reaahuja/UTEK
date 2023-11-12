
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define MAX_SIZE 1000

int calculateCost(const vector<int> &path, const vector<vector<int>> &dist) {
  int totalCost = 0;
  for (size_t i = 0; i < path.size() - 1; i++) {
    if (dist[path[i]][path[i + 1]] != 0) {
      totalCost += dist[path[i]][path[i + 1]];
    } else {
      totalCost = -1;
      break;
    }
  }
  // totalCost += dist[path.back()][path.front()];
  return totalCost;
}

int findMinimumCost(int n, const vector<vector<int>> &dist, int start,
                    int end) {
  int counter = 0;
  vector<int> path;
  for (int i = 0; i < n; i++) {
    path.push_back(i);
  }

  int minCost = INT_MAX;
  do {
    int currentCost = calculateCost(path, dist);
    if (path[0] == start && path[n - 1] == end && currentCost != -1) {
      cout << "current cost" << currentCost << endl;
      for (int i = 0; i < n; i++) {
        cout << path[i] << " ";
      }
      cout << endl;
      minCost = min(minCost, currentCost);
    }
    counter++;
  } while (next_permutation(path.begin(), path.end()) &&
           counter < n); //&& counter < n

  return minCost;
}

int main() {
  int n, start, end;
  cout << "Enter the number of nodes: ";
  cin >> n;

  vector<vector<int>> dist(n, vector<int>(n));
  cout << "Enter the cost matrix:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> dist[i][j];
    }
  }

  cout << "Enter the starting node";
  cin >> start;

  cout << "Enter the ending node";
  cin >> end;

  int cost = findMinimumCost(n, dist, start, end);
  cout << "The minimum cost is " << cost << endl;

  return 0;
}
