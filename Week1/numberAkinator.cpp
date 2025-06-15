#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//variables
int theNumber = rand() % 101;
int inBetween1 = rand() % 99;
int inBetween2 = rand() % 101;
//the initial guessing prompt
int initGuess() {
cout<<"Is the number between "<<inBetween1<<" and "<<inBetween2<<"? Y/N: "<<endl;
check()
}
//the guessing prompt
int guess() {
cout<<"Is the number between "<<inBetween1<<" and "<<inBetween2<<"? Y/N: "<<endl;
check();
}
//if user fails to guess
int failGuess() {
cout<<"The number is not in between "<<inBetween1<<" and "<<inBetween2<<endl;
int prevInBetween1 = inBetween1;
int prevInBetween2 = inBetween2;
int inBetween1 = rand() % 99;
int inBetween2 = rand() % 101;
cout<<"Is the number between "<<inBetween1<<" and "<<inBetween2<<"? Y/N: "<<endl;
}
//the guessing logic
int check() {
if(theNumber>=inBetween1 and theNumber<=inBetween2) {
cout<<"The number is in between "<<inBetween1<<" and "<<inBetween2<<endl;
int prevInBetween1 = inBetween1;
int prevInBetween2 = inBetween2;
int inBetween1 = rand() % 99 - prevInBetween1;
int inBetween2 = rand() % 101 - prevInBetween2;
guess;
}
else {
failGuess();
}
}
//main
int main() {
cout<<"Number guessing game - CPP Practice Week 1"<<endl;
initGuess();
}
