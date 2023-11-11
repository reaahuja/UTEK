#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void uniqueNodes(string *allLinks, int listSize, string *&uniqueNodes,
                 int &numNodes);
void storeLinks(stringstream &inputLine, vector<string> &links, int &count);

void printMatrix(int **matrix, string *allNodes, int size);
int findIndex(string stringValue, string *allNodes, int size);
void matrixCreate(const string &input);

int main() {
  string userInput;
  cout << "Enter the input string: ";
  getline(cin, userInput);
  matrixCreate(userInput);

  return 0;
}

void matrixCreate(const string &input) {
  string *allNodes;
  vector<string> allLinks;
  stringstream inputLine(input);

  int listSize = 0;
  int size = 0;
  storeLinks(inputLine, allLinks, listSize);
  uniqueNodes(allLinks.data(), listSize, allNodes, size);

  int **matrix = new int *[size];
  for (int i = 0; i < size; ++i) {
    matrix[i] = new int[size];
  };

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      matrix[i][j] = 0;
    }
  }

  for (int i = 0; i < listSize - 1; i += 2) {
    string compareOne = allLinks[i];
    string compareTwo = allLinks[i + 1];
    int indexOne = findIndex(compareOne, allNodes, size);
    int indexTwo = findIndex(compareTwo, allNodes, size);

    matrix[indexOne][indexTwo]++;
  }

  printMatrix(matrix, allNodes, size);
}

int findIndex(string stringValue, string *allNodes, int size) {
  for (int i = 0; i < size; i++) {
    if (allNodes[i] == stringValue) {
      return i;
    }
  }

  return -1;
}

void printMatrix(int **matrix, string *allNodes, int size) {
  cout << "    ";
  // Print the node labels
  for (int i = 0; i < size; ++i) {
    cout << allNodes[i] << " ";
  }
  cout << endl;

  // Print a horizontal line
  for (int i = 0; i < (size * 2) + 3; ++i) {
    cout << "-";
  }
  cout << endl;

  // Print the adjacency matrix
  for (int i = 0; i < size; i++) {
    cout << allNodes[i] << " |";
    for (int j = 0; j < size; j++) {
      cout << " " << matrix[i][j];
    }
    cout << endl;
  }
}

void uniqueNodes(string *allLinks, int listSize, string *&uniqueNodes,
                 int &numNodes) {
  set<string> uniqueSet;

  for (int i = 0; i < listSize; ++i) {
    uniqueSet.insert(allLinks[i]);
  }

  numNodes = uniqueSet.size();

  uniqueNodes = new string[numNodes];

  copy(uniqueSet.begin(), uniqueSet.end(), uniqueNodes);
}

void storeLinks(stringstream &inputLine, vector<string> &links, int &count) {
  string input;

  while (inputLine >> input) {
    size_t len = input.size();
    size_t arrow = input.find("->");
    size_t arrowend = input.find(">");

    string sourceNode = input.substr(0, arrow);
    string targetNode = "a";

    if (input.find(",") != string::npos) {
      targetNode = input.substr(arrow + 2, len - arrowend - 2);
    } else {
      targetNode = input.substr(arrow + 2, len - arrowend - 1);
    }

    links.push_back(sourceNode);
    links.push_back(targetNode);
    count = count + 2;
  }
}
