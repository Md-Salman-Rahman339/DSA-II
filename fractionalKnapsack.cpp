#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
    int id, weight, value;
    double ratio;
};

bool compare_desc_ratio(Item a, Item b){
    return a.ratio > b.ratio;
}

//W => Knapsack Capacity
double FractionalKnapsack(vector<Item> items, int W){
    //Step 1: Ratio calculation and sort
    //calculate ratio=value/weight for every item
    for(int i=0; i<items.size();i++)
        items[i].ratio = items[i].value/items[i].weight;
    //sort based on ratio (Desc order)
    sort(items.begin(), items.end(), compare_desc_ratio);
    //Step 2: Initialize
    double total_value =0.0;
    int remaining = W;
    //Step 3: Iterate
    for(int i=0; i<items.size();i++){
        if(remaining==0)
            break;
        int take = min(items[i].weight, remaining);
        double fraction = (double) take/items[i].weight;
        total_value = total_value + fraction*items[i].value;
        remaining = remaining - take;
    }
    //Step 4: Return total value
    return total_value;
}

int main()
{
   int W = 50;

   vector<Item> items = {
       {1, 10, 60},
       {2, 20, 100},
       {3, 30, 120}
   };

   double result = FractionalKnapsack(items, W);

   cout << "Max total value = "<<result<<endl;
}

