#include <bits/stdc++.h>
using namespace std;

// 1. Write a recursive function to calculate the nth term of the Fibonacci sequence.
// long long grains(int n){
//     if(n==1) return 1;
//     return 2 * grains(n-1);
// }

// long long total(int n){
//     if(n==1) return 1;
//     return grains(n)+total(n-1);
// }

// 2. Write a recursive function to calculate the number of different orders in which n players

// int different_order(int n){
//     if(n==1) return 1;
//     return n * different_order(n-1);
// }


// 3. Write a recursive function to calculate the height of a tower of n blocks, where each block is half the size of the previous one, and the total number of blocks needed to build the tower.
// int tower_hight(int n){
//     if(n==1) return 1;
//     return 2 * tower_hight(n-1);
// }

// int total_blocks(int n){
//     if(n==1) return 1;
//     return tower_hight(n)+total_blocks(n-1);
// }

// 4. Write a recursive function to calculate the number of ways to climb a staircase of n steps, where you can climb either 1 or 2 steps at a time.
// int ways(int n){
//     if(n<=1) return 1;
//     return ways(n-1)+ways(n-2);
// }


int sum(int n){
    if(n==0) return 0;
    return n+ sum(n-1);
}
int main(){
    int n;
    cin>>n;
    // cout<<grains(n)<<endl;
    // cout<<total(n)<<endl;

    // cout<<"Number of players: "<<n<<endl;
    // cout<<"NUmber of different orders : "<<different_order(n)<<endl;

    // cout<<"Tower hight: "<<tower_hight(n)<<endl;
    // cout<<"Total blocks: "<<total_blocks(n)<<endl;
    // cout<<ways(n)<<endl; 
    cout<<sum(n)<<endl;
}