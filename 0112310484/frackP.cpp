#include<bits/stdc++.h>
using namespace std;


struct Item{
    int id,weight,value;
    double ratio;
};

bool compare_desc_ratio(Item a,Item b){
    return a.ratio>b.ratio;
}


double Fractionalknapsack(vector<Item> items,int W){
    for(int i =0;i<items.size();i++){
        items[i].ratio=items[i].value/items[i].weight;
    }
    sort(items.begin(),items.end(),compare_desc_ratio);
    double total_value=0.0;
    int remaining=W;
    for(int i=0;i<items.size();i++){
        if(remaining==0){
            break;
        }
        int take=min(items[i].weight,remaining);
        double fraction =double(take)/items[i].weight;
        total_value=total_value+fraction*items[i].value;
        remaining=remaining-take;

    }
    return total_value;
}
int main(){
    int w=50;
    vector<Item>items={
        {1,10,60},
        {2,20,100},
        {3,30,120}
    };
    double result=Fractionalknapsack(items,w);
    cout<<result<<endl;
}