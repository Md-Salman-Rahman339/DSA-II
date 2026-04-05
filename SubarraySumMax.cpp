#include<iostream>
#include<vector>
using namespace std;

int crossSum(vector<int>&a,int l,int m,int h){

    int cl=INT16_MIN,cr=INT16_MIN,sum=0;
    for(int i=m;i<=l;i--){
        sum+=a[i];
        if(sum<cl) cl=sum;
    }
    sum=0;
    for(int i=m+1;i<=h;i++){
        sum+=a[i];
        if(sum>cr) cr=sum;
    }
    return cl+cr;
}
int maxSubbarray(vector<int>&a,int l,int h){
    if(l==h) return a[l];
    int m=(l+h)/2;
    int leftS=maxSubbarray(a,l,m);
    int rights=maxSubbarray(a,m+1,h);
    int crossS=crossSum(a,l,m,h);
    return max(max(leftS,rights),crossS);
}

int main(){
    vector<int>a;
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){   
        int x;
        cin>>x;
        a.push_back(x);
    }
    cout<<"Maximum subarray sum is: "<<maxSubbarray(a,0,n-1)<<endl;
}

