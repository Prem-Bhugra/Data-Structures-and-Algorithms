#include<iostream>
using namespace std;
int main(){
    int r;
    cin >> r;
    int i = 1;
    while (i <= r){
        int j = 1;
        while (j <= i){
            cout<< j << " ";
            j = j + 1;
        }
        cout<<"\n";
        i = i + 1;
    }
}