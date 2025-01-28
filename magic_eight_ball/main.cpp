#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    srand(time(0));

    string question;

    while(question != "Q"){
        cout << "Ask a question (enter Q to quit):" << endl;
        //cin >> question;
        getline(cin, question);

        if(question == "Q")
            break;
        
        int r = rand() % 3;

        if(r == 0){
            cout << "yes" << endl;
        } else if(r == 1){
            cout << "no" << endl;
        } else {
            cout << "maybe" << endl;
        }
    }
    /*
    switch(r){
        case 0:
            cout << "yes" << endl;
            break;
        case 1:
            cout << "no" << endl;
            break;
        default:
            cout << "maybe" << endl;
    }
    */
    return 0;
}