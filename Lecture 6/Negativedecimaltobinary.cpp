#include<iostream>
#include<math.h>
using namespace std;
int main(){
    long long int n;
    unsigned long long int i=0;
    unsigned long long int ans=0;
    cin >> n;
    n=pow(2,16)+n;
    while (n){
        int bit=n&1;
        ans=(bit*(pow(10,i)))+ans;
        n=n>>1;
        i++;
    }
    cout << ans;
}