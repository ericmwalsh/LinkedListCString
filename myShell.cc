//myShell.cc
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
using namespace std;
const int MAX_STRING_SIZE=2048;

int main(){
    int runCheck=0;
    while(runCheck<1){
        beginning:{
            cout << endl << "% ";
            char * newBuf = new char[MAX_STRING_SIZE];
            cin.getline(newBuf, MAX_STRING_SIZE);
            if(strncmp(newBuf, "exit", MAX_STRING_SIZE)==0) return 0;
            if(int processOne = fork() > 0){
                wait(NULL);
                goto beginning;
            }
            else if (processOne ==0){
                system(newBuf);
                return 0;
            }
        }
    }
    return 0;
}