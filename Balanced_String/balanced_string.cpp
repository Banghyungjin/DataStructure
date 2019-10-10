//made by HyungJin
//10-10-2019
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>

using namespace std;

int main() {
    int inputNum;
    cout << "Please input a number that is bigger than 0 you want or type -1 to quit" << endl;
    while (inputNum != -1) {
        cin >> inputNum;
        if (inputNum != -1) {
            cout << "Input number = " << inputNum << endl;
            int tempAns = (inputNum+1)/2;
            int ans = 1;
            while (tempAns>0) {
                ans = ans*2;
                ans = ans%16769023;
                tempAns--;
            }
            cout << ans << endl;
            cout << "Want some more?" << endl;
        }
    }
    cout << "As you wish" << endl;
    return 0;
}