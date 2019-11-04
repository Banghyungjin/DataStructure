#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

void Make_list(list<int>& card_list, int num_of_cards);
int Read_command(ifstream &inputFile, list<int>&card_list);
void Shuffle(list<int>& card_list);
void Cut(list<int>& card_list, int start, int end);
void Write_answer(ofstream &outFile, list<int>& card_list, int num_of_cards);

int main() {
    ifstream inputFile("shuffle.inp");
    ofstream outputFile("shuffle.out");

    int num_of_cards;
    int num_of_works;
    list<int> card_list;

    inputFile >> num_of_cards >> num_of_works;
    Make_list(card_list, num_of_cards);
    for (int i = 0; i<num_of_works;i++) {
        Read_command(inputFile, card_list);
    }
    Write_answer(outputFile,card_list,num_of_cards);
    return 0;
}

void Make_list(list<int>& card_list, int num_of_cards) {
    for (int i = 0; i< num_of_cards; i++) {
        card_list.push_back(i+1);
    }
}

int Read_command(ifstream &inputFile, list<int>&card_list) {
    string command;
    int answer = 0;
    inputFile >> command;
    if (command == "Shuffle") {
        Shuffle(card_list);
    }
    else if (command == "Cut") {
        int start;
        int end;
        inputFile >> start >> end;
        Cut(card_list,start,end);
    }
    return answer;
}

void Shuffle(list<int>& card_list) {
    auto iter_start = card_list.begin();
    auto iter_end = card_list.begin();
    int index = card_list.size()/2;
    advance(iter_end,index);
    list<int> temp_list;
    temp_list.splice(temp_list.end(),card_list, card_list.begin(),iter_end);
    for (int i = 0; i< index; i++) {
        card_list.splice(card_list.end(), temp_list, temp_list.begin());
        card_list.splice(card_list.end(), card_list, card_list.begin());
    }
}

void Cut(list<int>& card_list, int start, int end) {
    auto iter_start = card_list.begin();
    auto iter_end = card_list.begin();
    advance(iter_start, start-1);
    advance(iter_end, end);
    card_list.splice(card_list.end(),card_list, iter_start, iter_end);
}

void Write_answer(ofstream &outFile, list<int>& card_list, int num_of_cards) {
    auto start = card_list.begin();
    auto end = card_list.end();
    auto middle = card_list.begin();
    advance(middle, (num_of_cards/2)-1);
    outFile << *start <<" " << *middle << " " << card_list.back();
}