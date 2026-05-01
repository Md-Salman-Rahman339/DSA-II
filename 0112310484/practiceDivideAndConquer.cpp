#include <bits/stdc++.h>
using namespace std;

// 1. Find the minimum and maximum element in an array using divide and conquer
// void findMinMax(int a[],int l,int h,int res[]){
//     if(l==h){
//         res[0]=a[l];
//         res[1]=a[l];
//         return;
//     }
//     if(l==h-1){
//         res[0]=min(a[l],a[h]);
//         res[1]=max(a[l],a[h]);
//     }

//     int mid=(l+h)/2;
//     int left_res[2],right_res[2];
//     findMinMax(a,l,mid,left_res);
//     findMinMax(a,mid+1,h,right_res);
//     res[0]=min(left_res[0],right_res[0]);
//     res[1]=max(left_res[1],right_res[1]);

// }


// 2.Merge Sort

// void merge(int a[],int l,int mid,int h){
// int n1=mid-l+1;
// int n2=h-(mid+1)+1;

// int left[n1],right[n2];
// for(int i=0;i<n1;i++){
//     left[i]=a[l+i];
// }
// for(int i=0;i<n2;i++){
//     right[i]=a[mid+1+i];
// }
// int i=0,j=0,k=l;
// while(i<n1 && j<n2){
//     if(left[i]<right[j]){
//         a[k++]=left[i++];
//     }
//     else{
//         a[k++]=right[j++];
//     }
// }

// while(j<n2){
//     a[k++]=right[j++];
// }
// while(i<n1){
//     a[k++]=left[i++];
// }
// }
// void mergeSort(int a[],int l,int h){
//     if(l==h){
//         return;
//     }
//     int mid=(l+h)/2;
//     mergeSort(a,l,mid);
//     mergeSort(a,mid+1,h);
//     merge(a,l,mid,h);
// }

// 3.Maximum subarray sum using divide and conquer

int crossSum(int a[],int l,int mid,int h){
    int sum=0,cl=INT16_MIN,cr=INT16_MIN;
    for(int i=mid;i>=l;i--){
        sum=sum+a[i];
        if(sum<cl){
            cl=sum;
        }
    }
    sum=0;
    for(int i=mid+1;i<=h;i++){
        sum=sum+a[i];
        if(sum<cr){
            cr=sum;
        }
    }
    return cl+cr;
}
int maxSubarray(int a[],int l,int h){
    if(l==h) return a[l];

    int mid=(l+h)/2;
    int leftS=maxSubarray(a,l,mid);
    int rightS=maxSubarray(a,mid+1,h);
    int crossS=crossSum(a,l,mid,h);
    return max(max(leftS,rightS),crossS);
}


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    // int res[2];
    // findMinMax(a,0,n-1,res);
    // cout<<"Min: "<<res[0]<<endl;
    // cout<<"Max: "<<res[1]<<endl;

    // mergeSort(a,0,n-1);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    cout<<maxSubarray(a,0,n-1)<<endl;
}