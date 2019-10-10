//made by   HyungJin Bang
//date      2019.09.26
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <tuple>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> inputVector);

void parkChk(vector<int> &inputVector, ifstream &inFile, int &flag, int &cars_Now);

void parkIn(vector<int> &inputVector, int car, int &flag, int &cars_Now);

void parkOut(vector<int> &inputVector, int car, int &flag, int &cars_Now);

void expand(vector<int> &inputVector);

vector<int> shrink(vector<int> &inputVector);

void makeFlag(vector<int> &inputVector, int &flag);

void car_In(vector<int> &inputVector);

void car_Out(vector<int> &inputVector);

int main() {
    ifstream inFile("parking.inp");
    ofstream outFile("parking.out");

    int slotNum;
    inFile >> slotNum;

    int carNum;
    inFile >> carNum;
    vector<int> parkingLot;
    parkingLot.reserve(slotNum);
    int flag = 0;
    int cars_Now = 0;
    while (carNum > 0) {
        parkChk(parkingLot,inFile, flag, cars_Now);
        carNum--;
    }
    printVector(parkingLot);
    for (int i = 0; i < parkingLot.size(); i++) {
        if (parkingLot[i] != 0) {
            outFile << i+1 << " " <<parkingLot[i] << "\n";
        }
    }
    return 0;
}

void printVector(vector<int> inputVector) {
    for (int i = 0; i < inputVector.size(); i++) {
        if (inputVector[i] != 0) {
            cout << i+1 << "\t" <<inputVector[i] << "\n";
        }
    }
    cout << endl;
}

void parkChk(vector<int> &inputVector, ifstream &inFile, int &flag, int &cars_Now) {
    int car;
    inFile >> car;
    if (car > 0) {
        if (cars_Now == inputVector.capacity()) {
            expand(inputVector);
            flag = cars_Now;
        }
        parkIn(inputVector, car, flag, cars_Now);
    }
    else {
        car = car*-1;
        parkOut(inputVector,car,flag,cars_Now);
        if (cars_Now == (inputVector.capacity()/3)) {
            inputVector = shrink(inputVector);
            flag = cars_Now;
        }
    }
}

void parkIn(vector<int> &inputVector, int car, int &flag, int &cars_Now) {
    if (flag == inputVector.size()) {
        inputVector.push_back(car);
        flag++;
    }
    else {
        for (int i = 0; i < inputVector.size();i++) {
            if (inputVector[i] == 0) {
                inputVector[i] = car;
                break;
            }
        }
    }
    cars_Now++;
}

void parkOut(vector<int> &inputVector, int car, int &flag, int &cars_Now) {
    for (int i = 0; i<inputVector.size();i++) {
        if (car == inputVector[i]) {
            inputVector[i] = 0;
            cars_Now--;
        }
    }
    makeFlag(inputVector, flag);
}

void expand(vector<int> &inputVector) {
    inputVector.resize(inputVector.capacity() * 2);
}

vector<int> shrink(vector<int> &inputVector) {
    int vectorSize = inputVector.capacity() / 2;
    vector<int> outputVector;
    outputVector.reserve(vectorSize);
    //
    for (int i= 0; i< inputVector.size();i++) {
        if (inputVector[i]!=0) {
            outputVector.push_back(inputVector[i]);
        }
    }
    outputVector.resize(vectorSize);
    return outputVector;
}

void makeFlag(vector<int> &inputVector, int &flag) {
    for (int i = 0; i < inputVector.capacity();i++) {
        if (inputVector[i] == 0) {
            flag = i;
            break;
        }
    }
}
