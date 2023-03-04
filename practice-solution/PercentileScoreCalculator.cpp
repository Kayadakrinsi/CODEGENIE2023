#include<bits/stdc++.h>
using namespace std;

float calculatePercentile(int totalStudents,vector<int>& marks,int yourScore){
    float percentile;
    sort(marks.begin(),marks.end());
    int index;
    auto it=find(marks.begin(),marks.end(),yourScore);
    if(it!=marks.end()){
        index=it-marks.begin();
    }
    float temp=index/(float)totalStudents;
    percentile=temp*100;
    return percentile;
}

int main(){
    int totalStudents = 7;
    vector<int> marks = {800, 300, 950, 760, 680, 490, 640};
    int yourScore = 760;
    float percentileScore = calculatePercentile(totalStudents,marks,yourScore);
    cout<<percentileScore<<endl; 
    return 0;
}
