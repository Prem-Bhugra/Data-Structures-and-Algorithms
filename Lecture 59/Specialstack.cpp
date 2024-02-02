#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;
void print(stack<int>st){
    if(st.empty()){
        return;
    }
    int num=st.top();
    st.pop();
    print(st);
    cout<<num<<" ";
    st.push(num);
}
//Approach 1
void min_stack(stack<int> st,stack<int> &mins){
    if(st.size()==1){
        mins.push(min(INT_MAX,st.top()));
        return;
    }
    int num=st.top();
    st.pop();
    min_stack(st,mins);
    mins.push(min(num,mins.top()));
}
int Min(stack<int> st){
    stack<int> mins;
    min_stack(st,mins);
    return mins.top();
}
//TC=O(1)
//SC=O(n)
//Approach 2
class MinStack {
public:
    stack<long long int> st;
    long long int mini; 
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else{
            if(val<mini){
                long long int value = (val-mini) + val;
                st.push(value);
                mini=val;
            }
            else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        long long int curr = st.top();
        st.pop();
        if(curr<mini){
            long long int value = (mini - curr) + mini;
            mini = value;
        }
    }
    
    long long int top() {
        if(st.empty()){
            return -1;
        }
        long long int curr=st.top();
        if(curr<mini){
            return mini;
        }
        else{
            return curr;
        }
    }
    
    long long int getMin() {
        if(st.empty()){
            return -1;
        }
        return mini;
    }
};
//TC=O(1)
//SC=O(1)
int main(){
    cout<<"Aproach 1"<<endl;
    stack<int> st;
    st.push(5);
    st.push(3);
    st.push(8);
    st.push(2);
    st.push(4);
    print(st);
    cout<<endl;
    cout<<Min(st)<<endl;
    st.pop();
    st.pop();
    print(st);
    cout<<endl;
    cout<<Min(st)<<endl;
    cout<<"Aproach 2"<<endl;
    MinStack st2;
    st2.push(5);
    st2.push(3);
    st2.push(8);
    st2.push(2);
    st2.push(4);
    cout<<st2.top()<<" "<<st2.st.top()<<endl;
    cout<<st2.getMin()<<endl;
    st2.pop();
    cout<<st2.top()<<" "<<st2.st.top()<<endl;
    st2.pop();
    cout<<st2.getMin()<<endl;    
}