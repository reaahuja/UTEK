
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>

using namespace std;
#define MAX_SIZE 1000

int findIndex(string stringValue, string *allNodes, int size);
string findValue(int value, string *allNodes, int size);
void uniqueNodes(const string& input_str, string*& uniqueNodes, int& numNodes);
void storeLinks(stringstream &inputLine, vector<string> &links, int (&numArray)[MAX_SIZE], int &count1, int &count);
int calculateCost(const vector<int>& path, const vector<vector<int> >& dist);
void findMinimumCost(int n, const vector<vector<int> >& dist, int start, int end, string *allNodes);



int main() {
    int n, start, end;
    string startChar, endChar, userInput; 
    vector<string> allLinks;
    string *allNodes;
    int listSize = 0;
  int count1 = 0;

    cout << "Starting intersection: ";
    cin >> startChar;
    // start = findIndex(startChar);

    cout << "Ending intersection:";
    cin >> endChar;
    // end = findIndex(endChar);

  int numArray[MAX_SIZE];
  string userInput;

    getline(cin, userInput);
    string copy = userInput;
    stringstream inputLine(copy);
  
    storeLinks(inputLine, allLinks, numArray, count1, listSize);
    uniqueNodes(userInput, allNodes, n);

    vector<vector<int> > dist(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = 0;
        }
    }

    for (int i = 0; i < listSize - 2; i += 2) {
        string compareOne = allLinks[i];
        string compareTwo = allLinks[i + 1];
        int indexOne = findIndex(compareOne, allNodes, n);
        int indexTwo = findIndex(compareTwo, allNodes, n);

        dist[indexOne][indexTwo] = std::stoi(allLinks[i+2]);
    }

    findMinimumCost(n, dist, start, end, allNodes);

    return 0;
}

int findIndex(string stringValue, string *allNodes, int size) {
  for (int i = 0; i < size; i++) {
    if (allNodes[i] == stringValue) {
      return i;
    }
  }

  return -1;
}

string findValue(int value, string *allNodes, int size) {
  for (int i = 0; i < size; i++) {
    if (i == value) {
      return allNodes[i];
    }
  }

  return "";
}

void storeLinks(stringstream &inputLine, vector<string> &links, int (&numArray)[MAX_SIZE], int &count1, int &count) {
  
string input;

while (inputLine >> input) {
  size_t len = input.size();
  size_t arrow = input.find("->");
  size_t arrowend = input.find(">");

  size_t bracket = input.find("(");

  string sourceNode = input.substr(0, arrow);
  string targetNode = "a";
  int numberNode = 0;

  // ($1)
  if (bracket == 0) {
    numberNode = stoi(input.substr(bracket + 1, len - 2));
    numArray[count1] = numberNode;
    count1++;
  } else {
    // no comma
    targetNode = input.substr(arrow + 2, len - arrowend - 1);
    links.push_back(sourceNode);
    links.push_back(targetNode);
    count = count + 2;
  }
}
}


void uniqueNodes(const string& input_str, string*& uniqueNodes, int& numNodes){
    set<string> uniqueSet;

    stringstream ss(input_str);
    string connection;

    while (getline(ss, connection, ',')){
        connection.erase(0, connection.find_first_not_of(" "));
        connection.erase(connection.find_last_not_of(" ") + 1);

        size_t arrow = connection.find("->");
        size_t openingParenthesis = connection.find("(", arrow);

        string sourceNode = connection.substr(0, arrow); 
        string targetNode = connection.substr(arrow + 2, openingParenthesis - arrow - 2);


        uniqueSet.insert(sourceNode);
        uniqueSet.insert(targetNode);
    }
    numNodes = uniqueSet.size();
    uniqueNodes = new string[numNodes];

    copy(uniqueSet.begin(), uniqueSet.end(), uniqueNodes); 
}


int calculateCost(const vector<int>& path, const vector<vector<int> >& dist) {
    int totalCost = 0;
    for (size_t i = 0; i < path.size() - 1; i++) {
        if (dist[path[i]][path[i + 1]] != 0){
            totalCost += dist[path[i]][path[i + 1]];
        }else{
            totalCost = -1;
            break;
        }

    }
    //totalCost += dist[path.back()][path.front()]; 
    return totalCost;
}

void findMinimumCost(int n, const vector<vector<int> >& dist, int start, int end, string *allNodes) {
    int counter = 0; 
    vector<int> path;
    vector<int> bestPath;
    for (int i = 0; i < n; i++) {
        path.push_back(i);
    }

    int minCost = INT_MAX;
    do {
        int currentCost = calculateCost(path, dist);
        if(path[0] == start && path[n-1] == end && currentCost != -1){
            minCost = min(minCost, currentCost);
            bestPath.assign(path.begin(), path.end());
        }
        counter++;
    } while (next_permutation(path.begin(), path.end()) && counter < n); //&& counter < n

    cout << "Best path:";
    for (int i = 0; i < n; i++){
        if (i == 0){
            cout << findValue(bestPath[i], allNodes, n) << "->";
        }else if(i == (n-1)){
            cout << findValue(bestPath[i], allNodes, n) << endl;
        }else{
            cout << findValue(bestPath[i], allNodes, n) << ", " << findValue(bestPath[i], allNodes, n) << "->";
        }

    }

    cout << "Cost: $" << minCost << endl;

}
