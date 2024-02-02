#include<iostream>
#include<stack>
using namespace std;
//A string with valid parentheses only always has even length
bool isValid(string s) {
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(st.empty()==false && st.top()=='{' && s[i]=='}'){
            st.pop();
            continue;
        }
        else if(st.empty()==false && st.top()=='[' && s[i]==']'){
            st.pop();
            continue;
        }
        else if(st.empty()==false && st.top()=='(' && s[i]==')'){
            st.pop();
            continue;
        }
        st.push(s[i]);
    }
    if(st.empty()){
        return true;
    }
    return false;
}
int main(){
    string parenthesis;
    cin>>parenthesis;
    cout<<isValid(parenthesis)<<endl;
}