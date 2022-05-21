
#include <iostream>
#include <fstream>
#include <vector>

using std::cout;    using std::endl;
using std::string; using std::cin;

//read numbers from a file
void readNumbers() {
    // Create our ifstream and make it open the file
    std::ifstream in("res/numbers.txt");
    int num;
    // Something to store values we get from the stream

        // Extract next number from input
        

        // If input is in a fail state, either a value couldn't
        // be converted, or we are at the end of the file.

        //print whatever we read
    while (!in.eof()) {
        in >> num;
        if (in.fail())
            break;
        cout << num << endl;
    }
        
}

//read a single word at a time from a file
void readHaikuWord() {
    // Create our ifstream and make it open the file
    std::ifstream in("res/haiku.txt");
    string c;
     // Something to store values we get from the stream

        // Extract next word from input


        // If input is in a fail state, either a value couldn't
        // be converted, or we are at the end of the file.

        //print whatever we read
    while (!in.eof()) {
        in >> c;
        if (in.fail())
            break;
        cout << c << endl;
    }

}

void readHaikuLine() {
    // Create our ifstream and make it open the file
    std::ifstream in("res/haiku.txt");
    string line;
    // Something to store the lines as we get them form the stream

        // If input is in a fail state, either a value couldn't
        // be converted, or we are at the end of the file.

        //print whatever we read
    while (!in.eof()) {
        std::getline(in, line);
        if (in.fail())
            break;
        cout << line << endl;
    }

}



//function for us to play around with cin
void playground(){
    string line;
    std::ifstream in("res/haiku.txt");
    while(std::getline(in, line)){
        if(in.eof()){
        cout << "eof" << endl;
         // break;
        }
        else if (in.fail()) {
            cout << "fail" << endl;
            // break;
        }
        else cout << line << endl;
        // cout << in.eof() << in.fail() << endl;
    }
    cout << in.eof() << in.fail() << endl;

}

int main() {

    // playground();
    // cout << "==========================" << endl;
    readNumbers();
    cout << "==========================" << endl;
    readHaikuWord();
    cout << "==========================" << endl;
    readHaikuLine();
    return 0;
}


