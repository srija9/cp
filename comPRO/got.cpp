#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,d,i;
    int count=0;
    cin>>n>>d;
    string p1[n],p2[n];

    int t[n];
    for(i=0; i<n; i++){
        cin>>p1[i]>>p2[i]>>t[i];
    }

    if(n == 1){
        count = 0;
    }
    for(i=1; i<n; i++)
    {
        for(int j=0; j<i; j++){
            if((p1[i] == p2[j]) and (p2[i] == p1[j])){
            if((t[i]-t[j]) > 0 and (t[i]-t[j]) <= d){
                count++;
              }
           }
        }
        
    }
    cout<<count<<"\n";
}