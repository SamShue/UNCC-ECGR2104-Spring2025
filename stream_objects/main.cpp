#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    string filename;

    for(int i = 0; i < argc; i++){
        string param(argv[i]);
        if(param == "--help"){
            cout << "Here are the instructions: " << endl;
        }

        if(param == "-i"){
            if(i + 1 < argc){
                filename = argv[i + 1];
            } else {
                cout << "No input file specified!" << endl;
                return 0;
            }
        }
    }

    /*
    ofstream outFile;
    outFile.open("example.txt");

    outFile << "Hello World!" << endl;
    outFile << "Another Line!" << endl;

    outFile.close();
    */
    ifstream inFile;
    inFile.open(filename);

    if(!inFile.is_open()){
        cout << "Unable to open file." << endl;
        return 0;
    }

    string text;
    while(!inFile.eof()){
        getline(inFile, text);
        cout << text << endl;
    }

    inFile.close();

    return 0;
}