#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int> maxi; //max heap
    priority_queue<int,vector<int>,greater<int>> mini; //min heap
    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);
    int n=maxi.size();
    for(int i=0;i<n;i++){
        cout<<maxi.top()<<endl;
        maxi.pop();
        }
    mini.push(1);
    mini.push(3);
    mini.push(2);
    mini.push(0);
    int m=mini.size();
    for(int i=0;i<m;i++){
        cout<<mini.top()<<endl;
        mini.pop();
        }
    cout<<maxi.empty()<<endl<<mini.empty()<<endl;
}