//made by Hyungjin Bang

#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

void readFile(ifstream &inFile, string &inputString, int &inputNum);
void makeVector(deque<char> &inputDeque, string &inputString);
void permutationForward(deque<char> &inputDeque);
void permutationBackward(deque<char> &inputDeque);
void writeAns(ofstream &outFile, deque<char> &inputDeque,deque<char> &tempAns, int inputNum);

int main() {
    ifstream inFile("permutation.inp");
    ofstream outFile("permutation.out");

    string inputString;
    int inputNum;

    deque<char> inputDeque;
    deque<char> tempAns;

    readFile(inFile, inputString, inputNum);
    makeVector(inputDeque, inputString);
    tempAns = inputDeque;
    writeAns(outFile, inputDeque,tempAns,inputNum);
    return 0;
}

void readFile(ifstream &inFile, string &inputString, int &inputNum) {
    inFile >> inputString;
    inFile >> inputNum;
}

void makeVector(deque<char> &inputDeque, string &inputString) {
    for (char i : inputString) {
        inputDeque.push_back(i);
    }
}

void permutationForward(deque<char> &inputDeque) {
    deque<char> tempDeque;
    int count = 0;
    auto iter = inputDeque.begin();
    for (int i = inputDeque.size()-1;i>0;i--) {
        count++;
        if (inputDeque[i]>inputDeque[i-1]) {
            for (int j = inputDeque.size()-1;j>0;j--) {
                if (inputDeque[j]>inputDeque[i-1]) {
                    swap(inputDeque[j],inputDeque[i-1]);
                    for (int k = 0; k < count;k++) {
                        tempDeque.push_back(inputDeque.back());
                        inputDeque.pop_back();
                    }
                    for (int k = 0; k < count;k++) {
                        inputDeque.push_back(tempDeque.front());
                        tempDeque.pop_front();
                    }
                    for (int k = 0; k < inputDeque.size(); k++) {
                    }
                    return;
                }
            }
        }
    }
}

void permutationBackward(deque<char> &inputDeque) {
    deque<char> tempDeque;
    int count = 0;
    auto iter = inputDeque.begin();
    for (int i = inputDeque.size()-1;i>0;i--) {
        count++;
        if (inputDeque[i]<inputDeque[i-1]) {
            for (int j = inputDeque.size()-1;j>0;j--) {
                if (inputDeque[j]<inputDeque[i-1]) {
                    swap(inputDeque[j],inputDeque[i-1]);
                    for (int k = 0; k < count;k++) {
                        tempDeque.push_back(inputDeque.back());
                        inputDeque.pop_back();
                    }
                    for (int k = 0; k < count;k++) {
                        inputDeque.push_back(tempDeque.front());
                        tempDeque.pop_front();
                    }
                    for (int k = 0; k < inputDeque.size(); k++) {
                    }
                    return;
                }
            }
        }
    }
}

void writeAns(ofstream &outFile, deque<char> &inputDeque,deque<char> &tempAns, int inputNum) {
    int chk = 0;
    for (int i = 0; i < inputNum; i++) {
        permutationBackward(tempAns);
    }
    for (int i = 0; i < inputDeque.size();i++) {
        if (inputDeque[i]==tempAns[i]) {
            chk++;
        }
    }
    if (chk == inputDeque.size()) {
        cout << "none" << endl;
        outFile << "none" << endl;
    }
    else {
        for (int i = 0; i < inputDeque.size();i++) {
            cout << tempAns[i] << " ";
            outFile << tempAns[i];
        }
        cout << endl;
        outFile << endl;
    }
    chk = 0;
    tempAns = inputDeque;
    for (int i = 0; i < inputNum; i++) {
        permutationForward(tempAns);
    }
    for (int i = 0; i < inputDeque.size();i++) {
        if (inputDeque[i]==tempAns[i]) {
            chk++;
        }
    }
    if (chk == inputDeque.size()) {
        cout << "none" << endl;
        outFile << "none" << endl;
    }
    else {
        for (int i = 0; i < inputDeque.size();i++) {
            cout << tempAns[i] << " ";
            outFile << tempAns[i];
        }
        cout << endl;
        outFile << endl;
    }
}