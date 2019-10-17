
#include <bits/stdc++.h>
using namespace std;
typedef struct { string name ;  vector<int> report; }  Stud ;

bool myfun ( Stud a, Stud b)   {
    if ((a.report.size())!=( b.report.size())) {
        return ((a.report.size())>( b.report.size())) ;
    }
    else if (a.report.size() == b.report.size()) {
        return ((a.report.back())>( b.report.back())) ;
    }
}

void outclass( vector < Stud > Pclass ){
    for(auto s : Pclass) {
        cout << "\n name= " << s.name ;
        for( auto t: s.report)
            cout << " " << t ;
    }
}

int main() {

    int i, N, score ;
    string xname ;
    Stud   body ;
    vector < Stud > Pclass ;

    ifstream in("rank01.txt");

    in >> N ; cout << "\n N= " << N ;

    for(i=0 ; i < N ; i++){
        in >> xname ; cout << "\n name= " << xname ;
        body.name = xname ;
        body.report.clear();
        int sum = 0;
        while(1){
            in >> score ;
            sum += score;
            if( score <= 0) break ;
            else {
                body.report.push_back( score ) ;
                cout << " " << score ;
            }
        } // end of while()
        sort( body.report.begin(),  body.report.end() ) ;
        body.report.push_back(sum);
        Pclass.push_back( body );
    } // end of for()

    cout << "\n\n After Sorting() ------ \n" ;
    sort( Pclass.begin(), Pclass.end(), myfun ) ;
    outclass( Pclass ) ;

} // end of main ( )
