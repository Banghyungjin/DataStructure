#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

void makeQueue(queue<int> &zosep);
void makeJump(queue<int> &zosep);
void writeAnswer(queue<int> &zosep);

int main() {
    queue<int> zosep;
    makeQueue(zosep);
    makeJump(zosep);
    writeAnswer(zosep);
    return 0;
}

void makeQueue(queue<int> &zosep) {
    ifstream inputFile("zosep.inp");
    int start, end;
    inputFile >> start >> end;
    for (int i = start; i <= end; i++) {
        zosep.push(i);
    }
    inputFile.close();
}

void makeJump(queue<int> &zosep) {
    while (zosep.size() != 1) {
        int front = zosep.front();
        int jump_counter = (front%3) + 1;
        zosep.pop();
        for (int i = 0; i < jump_counter ; i++) {
            int index = zosep.front();
            zosep.push(index);
            zosep.pop();
        }
    }
}

void writeAnswer(queue<int> &zosep) {
    ofstream outputFile("zosep.out");
    outputFile << zosep.front();
    outputFile.close();
}