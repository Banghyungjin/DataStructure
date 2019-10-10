//made by   HyungJin Bang
//date      2019.09.18
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

vector <tuple<long long,long long>> ReadPoly(vector <tuple<long long,long long>>input1, ifstream &inFile);
vector <tuple<long long,long long>> MultiplyPoly(vector <tuple<long long,long long>>input1, vector <tuple<long long,long long>>input2, vector <tuple<long long,long long>>input3);
vector <tuple<long long,long long>> CheckPoly(vector <tuple<long long,long long>>input1);
void PrintPoly(vector <tuple<long long,long long>> inputPoly);
bool sortbysec(const tuple<long long, long long>& a, const tuple<long long, long long>& b);
void WriteAnswer(vector <tuple<long long,long long>>input, ofstream &outFile);

int main() {
    ifstream inFile("polymult.inp");
    ofstream outFile("polymult.out");
    vector <tuple<long long,long long>> inputMat1;
    vector <tuple<long long,long long>> inputMat2;
    vector <tuple<long long,long long>> tempAnsMat;
    vector <tuple<long long,long long>> ansMat;
    int numOfPoly;
    inFile >> numOfPoly;

    if(numOfPoly == 0) {
        outFile << "0" << endl <<"0 0";
        return 0;
    }

    inputMat1 = ReadPoly(inputMat1, inFile);

    if (numOfPoly == 1) {
        sort(inputMat1.begin(), inputMat1.end(), sortbysec);
        inputMat1 = CheckPoly(inputMat1);
        WriteAnswer(inputMat1,outFile);
        return 0;
    }

    inputMat2 = ReadPoly(inputMat2, inFile);
    tempAnsMat = MultiplyPoly(inputMat1,inputMat2,tempAnsMat);
    tempAnsMat = CheckPoly(tempAnsMat);
    numOfPoly -= 2;

    while (numOfPoly > 0) {
        inputMat1.clear();
        inputMat2.clear();
        inputMat1 = tempAnsMat;
        tempAnsMat.clear();
        inputMat2 = ReadPoly(inputMat2, inFile);
        tempAnsMat = MultiplyPoly(inputMat1,inputMat2,tempAnsMat);
        numOfPoly--;
    }

    sort(tempAnsMat.begin(), tempAnsMat.end(), sortbysec);
    tempAnsMat = CheckPoly(tempAnsMat);
    WriteAnswer(tempAnsMat,outFile);
    return 0;
}

vector <tuple<long long,long long>> ReadPoly(vector <tuple<long long,long long>>input1, ifstream &inFile) {
    int polyCount;
    inFile >> polyCount;
    long long tupleX, tupleY;

    while (polyCount > 0) {
        inFile >> tupleX;
        inFile >> tupleY;
        tuple<long long,long long> t(tupleX, tupleY);
        input1.push_back(t);
        polyCount--;
    }

    return input1;
}

vector <tuple<long long,long long>> MultiplyPoly(vector <tuple<long long,long long>>input1, vector <tuple<long long,long long>>input2, vector <tuple<long long,long long>>input3) {
    long long tupleX, tupleY;
    for (int i = 0; i < input1.size();i++) {
        for (int j = 0; j < input2.size();j++) {
            tupleX = (get<0>(input1[i]))*(get<0>(input2[j]));
            tupleY = (get<1>(input1[i]))+(get<1>(input2[j]));
            tuple<long long,long long> t(tupleX, tupleY);
            input3.push_back(t);
        }
    }
    return input3;
}

void PrintPoly(vector <tuple<long long,long long>> inputPoly) {
    for (int i = 0; i < inputPoly.size(); i ++) {
        if (get<0>(inputPoly[i]) != 0) {
            cout << get<0>(inputPoly[i]) << "\t" << get<1>(inputPoly[i])<<endl;
        }
    }
}

vector <tuple<long long,long long>> CheckPoly(vector <tuple<long long,long long>>input1) {
    vector<tuple<long long,long long>> outputVector;
    for (int i = 0; i < input1.size(); i++) {
        if (outputVector.size() < 1) {
            outputVector.push_back(input1[i]);
        }
        else if (get<1>(outputVector.back()) == get<1>(input1[i])) {
            long long tupleX = get<0>(outputVector.back()) + get<0>(input1[i]);
            long long tupleY = get<1>(outputVector.back());
            tuple<long long,long long> t(tupleX, tupleY);
            outputVector.pop_back();
            outputVector.push_back(t);
        }
        else {
            outputVector.push_back(input1[i]);
        }
    }
    return outputVector;
}

void WriteAnswer(vector <tuple<long long,long long>>input, ofstream &outFile) {
    int answerCount = 0;
    for (int i = input.size()-1;i>=0; i--) {
        if (get<0>(input[i]) != 0) {
            answerCount++;
        }
    }
    outFile << answerCount << endl;
    for (int i = input.size()-1;i>=0; i--) {
        if (get<0>(input[i]) != 0) {
            outFile << get<0>(input[i]) << " " << get<1>(input[i])<<endl;
        }
    }
    if (answerCount == 0) {
        outFile << "0 0" << endl;
    }
}

bool sortbysec(const tuple<long long, long long>& a, const tuple<long long, long long>& b) {
    return (get<1>(a) < get<1>(b));
}