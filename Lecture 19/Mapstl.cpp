#include<iostream>
#include<map>
using namespace std;
int main(){
    map <int,string> m;
    m[1]="Prem";    
    m[2]="Simran";    
    m[13]="Uday";    
    m[5]="Sumit";
    m.insert({89,"Chutki"});
    for (auto i:m){
        cout<<i.first<<":"<<i.second<<endl;
    }
    cout<<m.count(13)<<endl<<m.count(90)<<endl;   
    m.erase(13);
    for (auto i:m){
        cout<<i.first<<":"<<i.second<<endl;
    }
}