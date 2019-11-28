#include <iostream>
#include <fstream>
#include <cmath>
#include <list>
#include <string>

using namespace std;

void print_array(char** quad_array, int num_of_index);
char** read_array(int &index);
void divide(string &answer, char** quad_array,int axis_x,int axis_y, int size);
void write_answer(string answer);

int main() {
    int index;
    char** quad_array = read_array(index);
    string answer;
    divide(answer, quad_array,0,0,index);
    write_answer(answer);
    return 0;
}

void print_array(char** quad_array, int num_of_index) {
    for (int i = 0; i < num_of_index;i++) {
        for (int j =0; j < num_of_index; j++) {
            cout << quad_array[i][j];
        }
        cout << endl;
    }
}

char** read_array(int &index) {
    ifstream inputFile("quad.inp");
    int num_of_index;
    inputFile >> num_of_index;
    num_of_index = pow(2,num_of_index);
    index = num_of_index;
    char** quad_array = new char*[num_of_index];
    for (int i = 0; i < num_of_index;i++) {
        quad_array[i] = new char[num_of_index];
        for (int j =0; j < num_of_index; j++) {
            inputFile >> quad_array[i][j];
        }
    }
    inputFile.close();
    return quad_array;
}

void divide(string &answer, char** quad_array,int axis_x,int axis_y, int size) {
    if (size == 1) {
        if (quad_array[axis_x][axis_y] == '#') {
            answer += "1 ";
        }
        else {
            answer += "0 ";
        }
        return;
    }
    else {
        int counter = 0;
        for (int i = axis_y; i < axis_y+size;i++) {
            for (int j = axis_x; j < axis_x+size;j++) {
                if (quad_array[j][i] == '#') {
                    counter++;
                }
            }
        }
        if (counter == 0) {
            answer+="0 ";
        }
        else if(counter == size*size) {
            answer+="1 ";
        }
        else {
            answer+="2 ( ";
            divide(answer, quad_array, axis_x,axis_y+size/2,size/2);

            divide(answer, quad_array, axis_x,axis_y,size/2);
            divide(answer, quad_array, axis_x+size/2,axis_y,size/2);
            divide(answer, quad_array, axis_x+size/2,axis_y+size/2,size/2);
            answer+=") ";
        }
    }
}

void write_answer(string answer) {
    ofstream outFile("quad.out");
    outFile << answer;
    outFile.close();
}