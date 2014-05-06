//handleSignals.cc
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
using namespace std;

int interruptCount=0, quitCount=0, stopCount=0;

void sig_handler(int signum){
    switch(signum){
        default: printf("Received signal %d\n", signum);
        
        case SIGINT:{
            ++interruptCount;
            printf("I");
            fflush(stdout);
            return;
        }
        case SIGQUIT:{
            ++quitCount;
            printf("Q");
            fflush(stdout);
            return;
        }
        case SIGTSTP:{
            ++stopCount;
            printf("S");
            fflush(stdout);
            if(stopCount==3){
                cout << endl << "Interrupt: " << interruptCount << endl;
                cout << "Quit: " << quitCount << endl;
                cout << "Stop: " << stopCount << endl;
                return;
            }
            else{
                signal(SIGTSTP, SIG_DFL);
                raise(SIGTSTP);
                return;
            }
        }
        case SIGCONT:{
            signal(SIGTSTP, sig_handler);
            return;
        }
    }
    
}
void init_signal_handlers(){
    signal(SIGINT, sig_handler);
    signal(SIGQUIT, sig_handler);
    signal(SIGTSTP, sig_handler);
    signal(SIGCONT, sig_handler);
}
int main(){
    // Turn off output buffering here if you like
    setbuf(stdout, NULL);

    init_signal_handlers();
    while (stopCount<=2){
        printf("X");
        fflush(stdout);
        usleep(50000); //sleep for .05 second on unix system
    }
}