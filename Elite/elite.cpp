#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <stack>

using namespace std;

typedef tuple<int,int, int> employee;
bool Compare(employee a, employee b);
void ReadFile(vector<employee> &inputVector, ifstream &inFile);
void CheckVector(vector<employee> &inputVector, vector<int> &outputVector);
void WriteFile(vector<int> &outputVector, ofstream &outFile);

int main() {
    ifstream inFile("elite.inp");
    ofstream outFile("elite.out");
    vector<employee> tempVector;
    vector<int> ansVector;
    ReadFile(tempVector, inFile);
    CheckVector(tempVector,ansVector);
    WriteFile(ansVector,outFile);

    return 0;
}

bool Compare(employee a, employee b) {
    if (get<0>(a)!=get<0>(b)) {
        return get<0>(a) < get<0>(b);

    }
    else if (get<1>(a)!=get<1>(b)) {
        return get<1>(a) > get<1>(b);
    }
}

void ReadFile(vector<employee> &inputVector, ifstream &inFile) {
    int num_of_employee;
    inFile >> num_of_employee;
    employee inputPerson;
    int x, y;
    int z = 1;
    for (int i = 0; i < num_of_employee; i++) {
        inFile >> x >> y;
        inputPerson = make_tuple(x,y,z);
        z++;
        inputVector.push_back(inputPerson);
    }
    sort(inputVector.begin(),inputVector.end(),Compare);
}

void CheckVector(vector<employee> &inputVector, vector<int> &outputVector) {
    stack<employee> tempStack;
    for (int i = 0; i < inputVector.size(); i++) {
        if (tempStack.empty()) {
            tempStack.push(inputVector[i]);
        }
        else if (get<0>(tempStack.top()) < get<0>(inputVector[i]) &&
                get<1>(tempStack.top()) < get<1>(inputVector[i])) {
            while (!tempStack.empty()&&get<1>(tempStack.top()) < get<1>(inputVector[i])) {
                tempStack.pop();
            }
            tempStack.push(inputVector[i]);
        }
        else {
            tempStack.push(inputVector[i]);
        }
    }
    while (!tempStack.empty()) {
        outputVector.push_back(get<2>(tempStack.top()));
        tempStack.pop();
    }
    sort(outputVector.begin(),outputVector.end());
}

void WriteFile(vector<int> &outputVector, ofstream &outFile) {
    for (int i = 0; i < outputVector.size(); i++) {
        outFile << outputVector[i] << endl;
    }
}