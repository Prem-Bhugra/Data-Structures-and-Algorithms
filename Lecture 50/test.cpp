#include<iostream>
#include<vector>
using namespace std;
void solve(vector<vector<int>> &ans,vector<int> output,int index,int n,int k){
        if(index>n){
            if(output.size()==k){
            ans.push_back(output);
            }
            return;
        }
        solve(ans,output,index+1,n,k);
        output.push_back(index);
        solve(ans,output,index+1,n,k);
    }
vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(ans,output,1,n,k);
        return ans;
    }
int main(){
    vector<vector<int>> ans=combine(4,2);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}