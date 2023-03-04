#include<bits/stdc++.h>
using namespace std;

int guessNumber(int finalNumber, vector<string>& operations){
    int n=operations.size()-1;
    int ans=finalNumber;
    for(int i=n;i>=0;i--){
        string s=operations[i];
        string temp=s.substr(4);
        int s2=stoi(temp);
        if(s[2]=='^'){
            float root=1.0/s2;
            ans=pow(ans,root);
        }
        if(s[2]=='*') ans=ans/s2;
        if(s[2]=='/') ans=ans*s2;
        if(s[2]=='-') ans=ans+s2;
        if(s[2]=='+') ans=ans-s2;
    }
    return ans;
}

int main(){
    int finalNumber = 2500;
    vector<string> operations = {"X + 10", "X - 5", "X * 5", "X ^ 2"};

    int actualNumber = guessNumber(finalNumber, operations);
    cout << actualNumber << endl;
    return 0;
}
