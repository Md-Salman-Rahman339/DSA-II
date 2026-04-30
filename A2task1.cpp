#include<bits/stdc++.h>
using namespace std;

struct Activity{
    string name;
    int start,finish;
};

bool compare_asc_finish(Activity a,Activity b){
    return a.finish<b.finish;
}

vector<Activity>ActivitySelection(vector<Activity>scheduled){
    //Sort based on finish time (Asc order)
    sort(scheduled.begin(),scheduled.end(),compare_asc_finish);

    //Initialize
    vector<Activity>selected;
    selected.push_back(scheduled[0]);
    int last_finish = scheduled[0].finish;

    //Iterate through all activities to select optimal activities
    for(int i=1;i<scheduled.size();i++){
        if(scheduled[i].start>=last_finish){
            selected.push_back(scheduled[i]);
            last_finish = scheduled[i].finish;
        }
    }

    //Return selected activities
    return selected;
}

int main(){
     vector<Activity>scheduled;
     int n;
     cout<<"Enter number of activities: ";
     cin>>n;
        cout<<"Enter id, start time and finish time of activities: "<<endl;
        for(int i=0;i<n;i++){
            string name;
            int start,finish;
            cin>>name>>start>>finish;
            scheduled.push_back({name,start,finish});
        }
    vector<Activity>selected = ActivitySelection(scheduled);
    cout<<"Maximum Workshops: "<<selected.size()<<endl;
    cout<<"Selected Workshops: ";
    for(int i=0;i<selected.size();i++){
        cout<<" "<<selected[i].name <<" ";
    }        

return 0;
        }