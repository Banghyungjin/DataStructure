/*	Name: HyeongJin Bang
	Date: 2019.09.10
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>

#define NUM_OF_SEAT 3
#define NUM_OF_TOILET 4

using namespace std;
ifstream inFile("2.inp");

struct Seat {
    int index;
    int axisX;
    int axisY;
    double distance_to_stage;
    double distance_to_toi1;
    double distance_to_toi2;
    double distance_to_toi3;
    double distance_to_toi4;
    double chk;
};

bool compare1(const Seat &s1, const Seat &s2);
bool compare2(const Seat &s1, const Seat &s2);
bool compare3(const Seat &s1, const Seat &s2);
bool compare4(const Seat &s1, const Seat &s2);
bool compare5(const Seat &s1, const Seat &s2);
double calc_distance(int x1, int y1, int x2, int y2);

int main() {
    int x_of_stage, y_of_stage;
    inFile >> x_of_stage;
    inFile >> y_of_stage;
    int concert_stage[x_of_stage][y_of_stage];
    int stage_loc[2];
    inFile >> stage_loc[0];
    inFile >> stage_loc[1];
    int toilet_loc[NUM_OF_TOILET][2];
    for (int i = 0; i < NUM_OF_TOILET; i++) {
        inFile >> toilet_loc[i][0];
        inFile >> toilet_loc[i][1];
    }
    int seat_loc[NUM_OF_SEAT][2];
    for (int i = 0; i < NUM_OF_SEAT; i++) {
        inFile >> seat_loc[i][0];
        inFile >> seat_loc[i][1];
    }

    cout << "x_of_stage = " << x_of_stage << endl;
    cout << "y_of_stage = " << y_of_stage << endl;
    cout << "stage_loc = "   << stage_loc[0] << " " << stage_loc[1] << endl;
    cout << "toilet_loc" << endl;
    for (int i = 0; i < 4; i++) {
        cout << toilet_loc[i][0] << " " << toilet_loc[i][1] << endl;
    }
    cout << endl;
    cout << "seats_loc" << endl;
    for (int i = 0; i < 3; i++) {
        cout << seat_loc[i][0] << " " << seat_loc[i][1] << endl;
    }
    cout << endl << endl;
    struct Seat s_Array[x_of_stage*y_of_stage];
    int counter = 0;
    for (int i = 0; i< x_of_stage; i++) {
        for (int j = 0; j< y_of_stage; j++) {
            s_Array[counter].axisX = i+1;
            s_Array[counter].axisY = j+1;
            s_Array[counter].distance_to_stage = calc_distance(s_Array[counter].axisX,s_Array[counter].axisY,stage_loc[0],stage_loc[1]);
            s_Array[counter].distance_to_toi1 = calc_distance(s_Array[counter].axisX,s_Array[counter].axisY,toilet_loc[0][0],toilet_loc[0][1]);
            s_Array[counter].distance_to_toi2 = calc_distance(s_Array[counter].axisX,s_Array[counter].axisY,toilet_loc[1][0],toilet_loc[1][1]);
            s_Array[counter].distance_to_toi3 = calc_distance(s_Array[counter].axisX,s_Array[counter].axisY,toilet_loc[2][0],toilet_loc[2][1]);
            s_Array[counter].distance_to_toi4 = calc_distance(s_Array[counter].axisX,s_Array[counter].axisY,toilet_loc[3][0],toilet_loc[3][1]);
            s_Array[counter].chk = s_Array[counter].distance_to_stage * s_Array[counter].distance_to_toi1 * s_Array[counter].distance_to_toi2 * s_Array[counter].distance_to_toi3 * s_Array[counter].distance_to_toi4;
            //cout << s_Array[counter].axisX << "\t" << s_Array[counter].axisY << "\t" << s_Array[counter].distance_to_stage << "\t" <<
        //s_Array[counter].distance_to_toi1 << "\t" <<
        //s_Array[counter].distance_to_toi2 << "\t" <<
        //s_Array[counter].distance_to_toi3 << "\t" <<
        //s_Array[counter].distance_to_toi4 << "\t" <<  endl;
            counter++;
            }

    }
    sort (s_Array, s_Array+(x_of_stage*y_of_stage-1),compare5);
    sort (s_Array, s_Array+(x_of_stage*y_of_stage-1),compare4);
    sort (s_Array, s_Array+(x_of_stage*y_of_stage-1),compare3);
    sort (s_Array, s_Array+(x_of_stage*y_of_stage-1),compare2);
    sort (s_Array, s_Array+(x_of_stage*y_of_stage-1),compare1);

    int index = 1;


    for (int i = 0; i < x_of_stage*y_of_stage; i++) {
        if (s_Array[i].chk != 0) {
            s_Array[i].index = index;
            index ++;
        }
        else {
            s_Array[i].index = -1;
        }
        ///*
        cout << s_Array[i].axisX << "\t" << s_Array[i].axisY << "\t" << s_Array[i].distance_to_stage << "\t" <<
        s_Array[i].distance_to_toi1 << "\t" <<
        s_Array[i].distance_to_toi2 << "\t" <<
        s_Array[i].distance_to_toi3 << "\t" <<
        s_Array[i].distance_to_toi4 << "\t" <<
        s_Array[i].index << "\t" <<
        s_Array[i].chk << "\t" <<  endl;
        //*/
    }
    ofstream outFile("concert.out");
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < x_of_stage*y_of_stage; j++) {
            if (s_Array[j].axisX == seat_loc[i][0] && s_Array[j].axisY == seat_loc[i][1]) {
                cout << s_Array[j].index << "\t";
                outFile << s_Array[j].index << " ";
            }
        }
    }
    cout << endl;

    return 0;
}

double calc_distance(int x1, int y1, int x2, int y2) {
    return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}

bool compare1(const Seat &s1, const Seat &s2) {
    if (s1.distance_to_stage < s2.distance_to_stage) {
        return true;
    }
    else if (s1.distance_to_stage == s2.distance_to_stage) {
        return s1.distance_to_toi1<s2.distance_to_toi1;
    }
    else
        return false;
}

bool compare2(const Seat &s1, const Seat &s2) {
    if (s1.distance_to_toi1 < s2.distance_to_toi1) {
        return true;
    }
    else if (s1.distance_to_toi1 == s2.distance_to_toi1) {
        return s1.distance_to_toi2<s2.distance_to_toi2;
    }
    else
        return false;
}

bool compare3(const Seat &s1, const Seat &s2) {
    if (s1.distance_to_toi2 < s2.distance_to_toi2) {
        return true;
    }
    else if (s1.distance_to_toi2 == s2.distance_to_toi2) {
        return s1.distance_to_toi3<s2.distance_to_toi3;
    }
    else
        return false;
}

bool compare4(const Seat &s1, const Seat &s2) {
    if (s1.distance_to_toi3 < s2.distance_to_toi3) {
        return true;
    }
    else if (s1.distance_to_toi3 == s2.distance_to_toi3) {
        return s1.distance_to_toi4<s2.distance_to_toi4;
    }
    else
        return false;
}

bool compare5(const Seat &s1, const Seat &s2) {
    if (s1.distance_to_toi4 < s2.distance_to_toi4) {
        return true;
    }
    else
        return false;
}
