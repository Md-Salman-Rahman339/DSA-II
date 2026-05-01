#include<bits/stdc++.h>
using namespace std;

struct Item{
    int id, volume, hazard;
    double ratio;
};

bool compare_asc_ratio(Item a, Item b){
    return a.ratio < b.ratio;
}


pair<double, vector<pair<int,double>>> MinHazard(vector<Item> items, int W){

  
    for(int i = 0; i < items.size(); i++){
        items[i].ratio = (double) items[i].hazard / items[i].volume;
    }


    sort(items.begin(), items.end(), compare_asc_ratio);

    double total_cost = 0.0;
    int remaining = W;

    vector<pair<int,double>> taken;


    for(int i = 0; i < items.size(); i++){
        if(remaining == 0) break;

        int take = min(items[i].volume, remaining);
        double fraction = (double)take / items[i].volume;

        total_cost += fraction * items[i].hazard;
        remaining -= take;

        taken.push_back({items[i].id, (double)take});
    }

    return {total_cost, taken};
}

int main(){

    vector<Item> items;
    int n, W;

    cout << "Enter number of containers and tank capacity: ";
    cin >> n >> W;

    cout << "Enter volume and hazard cost:\n";

    for(int i = 0; i < n; i++){
        Item temp;
        cin >> temp.volume >> temp.hazard;
        temp.id = i + 1;
        items.push_back(temp);
    }

    auto result = MinHazard(items, W);

    double total_cost = result.first;
    vector<pair<int,double>> selected = result.second;

    // Output
    cout << fixed << setprecision(2);
    cout << "Minimum Hazard Cost = " << total_cost << endl;

    for(int i = 0; i < selected.size(); i++){
        cout << "Container " << selected[i].first
             << ": " << selected[i].second << " liters" << endl;
    }

    return 0;
}