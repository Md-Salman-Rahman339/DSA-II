#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Activity{
    int id, start, finish;
};

bool compare_asc_finish(Activity a, Activity b){
    return a.finish<b.finish;
}

vector<Activity> ActivitySelection(vector<Activity> scheduled){
    //Sort based on finish time (Asc order)
    sort(scheduled.begin(), scheduled.end(),compare_asc_finish);

    //Initialize
    vector<Activity> selected;
    selected.push_back(scheduled[0]);
    int last_finish = scheduled[0].finish;

    //Iterate through all activities to select optimal activities
    for(int i=1; i<scheduled.size();i++){
        if(scheduled[i].start>=last_finish){
            selected.push_back(scheduled[i]);
            last_finish = scheduled[i].finish;
        }
    }

    //Return selected activities
    return selected;
}

int main(){
    vector<Activity> scheduled = {
        {1, 1, 2},
        {2, 3, 4},
        {3, 0, 6},
        {4, 5, 7},
        {5, 8, 9}
    };

    //Call ActivitySelection
    vector<Activity> selected = ActivitySelection(scheduled);

    //print selected
    cout<<"Total selected activities "<<selected.size()<<endl;
    for(int i=0; i<selected.size();i++){
        cout<<"A"<<selected[i].id<<" "<<selected[i].start<<" "<<selected[i].finish<<endl;
    }
}

