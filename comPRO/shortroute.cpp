#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define ll     long long int



int main()
{
    
    int t;
    cin>>t;
    int n,m;
    while(t--)
    {
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }
        
        int ans1[n];
        int ans2[n];
        int c[n];
        
        int index1=0;
        int index2=0;
        
        
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                index1 = i;
            }
            
            if(index1!=0 && index1<=i)
            {
                ans1[i] = abs(index1-i);
            }else{
                ans1[i] = -1;
            }
        }
        
        for(int i=n;i>=1;i--){
            if(a[i]==2){
                index2 = i;
            }
            
            if(index2!=0 && index2>=i)
            {
                ans2[i] = abs(index2-i);
            }else{
                ans2[i] = -1;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
           if(ans1[i]!=-1 && ans2[i]!=-1)
            {
                c[i] = std::min(ans1[i],ans2[i]);
                
            }else if(ans1[i]==-1 && ans2[i]!=-1){
                
                    c[i] = ans2[i];
                
            }else if(ans2[i]==-1 && ans1[i]!=-1){
                
                    c[i] = ans1[i];
                
            }
            else{
                c[i]=-1;
            } 
        }
        
        // for(int i=1;i<=n;i++){
        //     cout<<ans1[i]<<" ";
        // }
        // cout<<"\n";
        // for(int i=1;i<=n;i++){
        //     cout<<ans2[i]<<" ";
        // }
        // cout<<"\n";
        // for(int i=1;i<=n;i++){
        //     cout<<c[i]<<" ";
        // }
        // cout<<"\n";
        
        
        for(int i=1;i<=m;i++)
        {
            cout<<c[b[i]]<<" ";
            
        }
        
        cout<<"\n";
        
    }
    
    return 0;
}   