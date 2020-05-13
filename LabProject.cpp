#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int labSize = 4;

void display(string** labArray, int stations[]){
    cout << "Lab" <<  setw(10) << "stations" << endl;
    for (int i=0; i<labSize; i++){
        cout << i+1 << ")" << setw(4) << endl;
        for (int j=0; j < stations[i]; j++){
            cout << j+1 << ":" << labArray[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void logIn(string name, int labNum, int stationNum, string** labArray){
    labArray[labNum-1][stationNum-1] = name;
}

void logOut(string name, int labNum, int stationNum, string** labArray){
    labArray[labNum-1][stationNum-1] = "EMPTY";
}



int main() {
    string** labArray; //creates a 2d dynamic array
    labArray = new string * [labSize]; //creates pointers for the number of labs

    int stations[labSize];
    for  (int i=0; i<labSize; i++){
        cout << "How many stations do you want in lab " << i+1 << endl;
        cin >> stations[i];
        labArray[i] = new string[stations[i]]; //creates the rows of each lab
        for (int j=0; j<stations[i]; j++){
            labArray[i][j] = "EMPTY";
        }
    }
    display(labArray,stations);

    bool running = true;

    bool log;
    while (running) {
        string answer;
        string name;
        int labNum;
        int stationNum;
        cout << "Would you like to log in/out or exit program? (L/E) " << endl;
        cin >> answer;
        if (answer == "L"){
            log = true;
            while(log) {
                cout << "Would you like to log in or out? (I/O) " << endl;
                cin >> answer;
                cout << "What is your name? " << endl;
                cin >> name;
                cout << "What lab number? " << endl;
                cin >> labNum;
                cout << "What station number? " << endl;
                cin >> stationNum;
                if (answer == "I"){
                    logIn(name, labNum, stationNum, labArray);
                    display(labArray,stations);
                } else {
                    logOut(name, labNum, stationNum, labArray);
                    display(labArray,stations);
                }
                log = false;
            }
        } else if (answer == "E") {
            running = false;
        }
    }

    system("pause");
    cout << "END OF PROGRAM" << endl;
    return 0;
}

