#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cstddef>
#include <sstream>
#include <windows.h>

using namespace std;

int main()
{
    system("adb devices");
    system("adb shell \"wm size | grep Override\" >tmp");
    string data;
    ifstream dat;
    dat.open("tmp");
    getline(dat,data);

    data = data.substr(data.find_last_of(" ")+1);
    int x,y;
    x=atoi(data.substr(0,data.find_last_of("x")).c_str());
    y=atoi(data.substr(data.find_last_of("x")+1).c_str());

    stringstream ss;
    ss<<(y/2);
    string x1 = ss.str();
    ss.str("");
    ss<<x;
    string y1 = ss.str();

    data ="adb shell \"input touchscreen swipe 0 " + y1 + " " + x1 + " " + y1 +" \"";
    cout<<"Using command: "<<data<<endl;
    cout<<"Ctrl+C to abort"<<endl;
    int seconds = 300;
    cout<<endl;

    while(1){
        system(data.c_str());
        while(seconds > 0){
                cout<<"\r"<<"Waiting "<<seconds<<" more seconds before spinning...       ";
                seconds -=1;
                Sleep(1000);
        }
        cout<<" Spinning..."<<endl;
        seconds = 300;

    }
    return 0;
}
