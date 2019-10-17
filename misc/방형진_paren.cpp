
#include <iostream>
#include <vector>
#include <stack>
using namespace std ;

int paren_value(char x){
    switch(x) {
        case '(': return( 1); break;
        case '[': return( 2); break;
        case '{': return( 3); break;
        case ')': return(-1); break;
        case ']': return(-2); break;
        case '}': return(-3); break;
        default : return(99); break;
    }
} // end of paren_value()

int main() {

    stack <int> mystack ;
    string str = "[(()){}]{()[]}";
    for (char c : str) {
        if (mystack.size() != 0&&paren_value(c) * -1 == mystack.top()) {
            mystack.pop();
            cout << "\n " << c << ": " << paren_value(c);
        }
        else {
            mystack.push(paren_value(c));
            cout << "\n " << c << ": " << paren_value(c);
        }
        //cout << "    top()= " << mystack.top() ;
    }
    if (mystack.empty())
        cout << "\nYES" << endl;
    else
        cout << "\nNO" << endl;

} // end of main()
