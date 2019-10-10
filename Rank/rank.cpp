#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef struct { string name ;  vector<int> report; }  Stud ;

bool myfun ( Stud a, Stud b);

void outclass( vector < Stud > Pclass , ofstream &outFile);

int main() {

    int i, N, score;
    string xname;
    Stud body;
    vector<Stud> Pclass;

    ifstream inFile("rank.inp");
    ofstream outFile("rank.out");

    inFile >> N;

    for (i = 0; i < N; i++) {
        inFile >> xname;
        body.name = xname;
        body.report.clear();
        int sum = 0;
        while (1) {
            inFile >> score;
            sum += score;
            if (score <= 0) break;
            else {
                body.report.push_back(score);
            }
        }

        sort(body.report.begin(), body.report.end());
        body.report.push_back(sum);
        Pclass.push_back(body);
    }
    sort(Pclass.begin(), Pclass.end(), myfun);
    outclass(Pclass,outFile);
}

bool myfun ( Stud a, Stud b) {
    if ((a.report.size())!=( b.report.size())) {
        return ((a.report.size())>( b.report.size())) ;
    }
    else if (a.report.size() == b.report.size()) {
        if ((a.report.back())!=( b.report.back())) {
            return ((a.report.back())>( b.report.back())) ;
        }
        else {
            for (int i = 0; i < a.report.size();i++) {
                if (a.report[i] != b.report[i]) {
                    return(a.report[i]>b.report[i]);
                }
            }
            return (a.name<b.name);
        }
    }
}

void outclass( vector < Stud > Pclass , ofstream &outFile){
    for(auto s : Pclass) {
        outFile << s.name << endl;
        cout << s.name ;
        for( auto t: s.report)
            cout << " " << t ;
        cout << endl;
    }
}
