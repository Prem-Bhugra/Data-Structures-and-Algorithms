#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    int i=0;
    float ans = 0;
    cin >> n;
    while (n!=0){
        int bit=n&1;
        ans+=(bit*(pow(10,i)));
        n=n>>1;
        i++;
    }
    cout << ans;
}