#include<bits/stdc++.h>
using namespace std;
float calculatePercentile(int totalStudents,vector<int>& marks,int yourScore){
    float percentile;
    int index;
    auto it=find(marks.begin(),marks.end(),yourScore);
    if(it!=marks.end()){
        index=it-marks.begin();
    }
    float temp=index/(float)totalStudents;
    percentile=temp*100;
    return percentile;
}
string getEligibleStudents(int totalStudents,vector<string> students,vector<int>& marks,vector<string>& examResults,int totalMarks,float requiredPercentile){
    string result;
    map<int,float> map;
    vector<int> copyMarks=marks;
    sort(copyMarks.begin(),copyMarks.end());
    for(int i=0;i<marks.size();i++){
        if(examResults[i]=="Passed"){
            map[marks[i]]=calculatePercentile(totalStudents,copyMarks,marks[i]);
            if(map[marks[i]]>=requiredPercentile){
                result.append(students[i]);
                result.append(" ");
            }
        }
    }
    return result;
}
int main(){
    int totalStudents = 7;
    int totalMarks = 1000;
    float requiredPercentile = 50;
    vector<int> marks = {800, 300, 750, 760, 680, 790, 640};
    vector<string> students = { "Kartik", "Devang", "Pari", "Ketan", "Sheetal", "Darshana", "Mohan" };
    vector<string> examResults = {"Passed", "Failed", "Passed", "Failed", "Passed", "Passed", "Passed"};
    string eligibleStudents = getEligibleStudents(totalStudents, students,marks, examResults, totalMarks, requiredPercentile);
    cout<<eligibleStudents<<endl;
    return 0;
}