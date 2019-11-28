
#include <bits/stdc++.h>
using namespace std;
typedef struct{
    int words;
    int types ;  // ������ �ǹ��� ?
    list<string> wordList;
} MyStatement;

list <MyStatement> Book;

void ShowTitle();
void printHelp();
void printStatement(MyStatement statement);
void Command();
void readBook(string fileName);
void find_pword();
void find_command();

int main(){
    readBook("CrimePunish.txt");  //������ ������ ��������� �о����
    ShowTitle();              //���α׷� Ÿ��Ʋ�� �����
    Command();               //����ڷκ��� ��ɾ �о ó����
    return 0;
}

void ShowTitle(){
    cout<<endl<<"[List�� �̿��� Book �м� ���α׷�]------------------------------"<<endl;
    cout<<"<CrimePunish.txt> : ��ü ������ ���� : "<<Book.size()<<endl<<endl;
    printHelp();
    cout<<"-------------------------------------------------------------------------------"<<endl;
} // end of printProgram()

void printHelp(){
    cout<<"[����]"<<endl;
    cout<<" 1) help         : ���� ���"<< endl;
    cout<<" 2) quit         : ���α׷� ����"<< endl;
    cout<<" 3) pline �ٹ�ȣ : CrimePunish���� �ش� �ٹ�ȣ(1���� ����)�� ������ ���"<<endl;
    cout<<" 4) pword i  j   : i��° ���忡�� j��° �ܾ�." << endl;
    cout<<" 5) find pword   : word�� �����ϰ� �ִ� ���� ��ȣ ��� ���"<< endl;
    cout<<" 6) insert k ~~~ : k �ڿ� ���� ����"<< endl;
} // end of printHelp( )

void printStatement(MyStatement statement){ //list<string>�� ������ ����ϴ� �Լ�
    cout<< "Statement: " ;
    for(auto w :statement.wordList ){ cout << w << " " ; }
} // end of printStaement( )

void Command(){ //����ڷκ��� ��ɾ �Է¹޾� ó���ϴ� �Լ�
    while(true){
        string command = "";
        cout << endl << ">>";
        cin >> command;
        if(command == "quit") break; // quit�� ������ loop�� �ߴ��Ѵ�.
        else if(command == "help")   printHelp();
        else if(command == "pline") {
            int line;
            cin>> line;
            if(line <= 0 ) cout<<" �߸��� �ٹ�ȣ �Դϴ�."<<endl;
            else{
                MyStatement mystate ;
                list<string> myList ;
                auto it = Book.begin() ;
                advance(it, line-1) ;
                mystate = *it ;
                myList = mystate.wordList;
                for(auto s : myList) cout << s << " " ;
            }
        } // end of  if(command == "pline")
        else if(command == "pword" )  { find_pword(); }
        else if(command == "find"  )  { find_command(); }
        else if(command == "insert")  { cout << " insert�� ����� �� " ; }
        else{ 	cout<< " Oh! �߸��� ��ɾ��Դϴ�. help�� Ȯ���ϼ���."<<endl; 	}
    } // end of while()

} // end of Command( )


void readBook(string fileName){
    ifstream documentIfs(fileName.c_str());
    string word;
    MyStatement ms;
    while(!documentIfs.eof()){
        documentIfs>>word;
        if(word == "#"){ //������ ���� ���
            Book.push_back(ms);
            ms.wordList.clear();
        }
        else ms.wordList.push_back(word);

        if(documentIfs.eof())break;
    }
    documentIfs.close();
} // end of readBook()

void find_pword() {
    int input_i, input_j;
    cin >> input_i >> input_j;

    if(input_i <= 0 ) cout<<" �߸��� �ٹ�ȣ �Դϴ�."<<endl;
    else{
        MyStatement mystate ;
        list<string> myList ;
        auto it = Book.begin() ;
        advance(it, input_i-1) ;
        mystate = *it ;
        myList = mystate.wordList;
        auto word = myList.begin();
        int list_size = myList.size();
        if(input_j>list_size) {
            cout <<" ������ ���̸� �ʰ��մϴ�."<<endl;
        }
        else if (input_j<=0) {
            cout <<" �ùٸ� input �� �ƴմϴ�." <<endl;
        }
        else {
            cout << input_i << " ��° ������ " << input_j << " ��° �ܾ�� ";
            advance(word,input_j -1);
            cout << *word << " �Դϴ�.";
        }
    }
}

void find_command() {
    string input_word;
    cin >> input_word;
    cout << input_word << endl;
    MyStatement mystate ;
    list<string> myList ;
    auto it = Book.begin() ;
    int counter = 1;
    int chk =0;
    while (it != Book.end()) {
        mystate = *it ;
        myList = mystate.wordList;
        auto word = myList.begin();
        int list_size = myList.size();
        for (int i = 0; i < list_size;i++) {
            if (input_word == *word) {
                cout << counter <<" ";
                chk++;
            }
            advance(word,1);
        }
        advance(it, 1) ;
        counter++;
    }
    if (chk==0) {
        cout << " ã�� �ܾ �����ϴ�."<<endl;
    }
    else {
        cout << " ��° ���忡 �ְ� �� "<< chk << " �� ���Խ��ϴ�."<< endl;
    }
}
