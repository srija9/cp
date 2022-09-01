#include <bits/stdc++.h>
using namespace std;
 
#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll             long long int
#define mod             1000000007
#define inf            1e18
#define endl           "\n"
#define mid(l,r)       (l+(r-l)/2)
#define loop(i,a,b)    for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
 
void init_code(){
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


void findgcd(ll a[], ll n, vector<ll> &ar)
{
     ar[0] = a[0];

    for(ll i=1;i<n;i++)
    {
        ar[i] = gcd(ar[i-1],a[i]);

    }

}

void findleft(ll a[], ll n, vector<ll> &al)
{
    al[n-1] = a[n-1];
    for(ll i=n-2;i>=0;i--)
    {
        al[i] = gcd(al[i+1],a[i]);
    }
}

int main()
{
   init_code();

    ll t;
    cin>>t;
    ll n;

    while(t--)
    {
        cin>>n;

         ll a[n];
         ll min=0, max=0;ll c=0,q=0;
         bool modify = false;
         bool modione = false;
         bool moditwo = false;
         bool modithree = false;
         bool first = false;
         bool second = false;
         vector<ll> ar(n,0),al(n,0);
         for(ll i=0;i<n;i++)
         {
            cin>>a[i];

            if(a[i]>a[max])
            {
                max = i;
            }

            if(a[i]<a[min])
            {
                min = i;
            }
            
         }

         sort(a,a+n);

         findgcd(a,n,ar);
         findleft(a,n,al);

         for(ll j=0;j<n;j++)
         {
            cout<<a[j]<<" ";
         }
         cout<<'\n';
         for(ll j=0;j<n;j++)
         {
            cout<<ar[j]<<" ";
         }
         cout<<'\n';
         for(ll j=0;j<n;j++)
         {
            cout<<al[j]<<" ";
         }

         ll key1=1;

         if(min==max || n==1)
         {
            c = n;
         }
         else{

         if(ar[0]==ar[n-1])
         {
            //   key1=ar[0];
            //   a[n-1] = key1;
            modify = true;
         }
         else{

           cout<<"first e ";
              ll k;
              
              
              ll res;
            for(k=1;k<n;k++)
            {
                if(al[k]==ar[k])
                {
                    first = true;
                   cout<<"this ";
                    res = gcd(al[k+1],ar[k-1]);
                    if(res != al[k])
                    {
                        a[k]=res;
                        key1 = a[k];
                    }

                    if(res==al[k])
                    {
                        
                        a[n-1]=res;
                        key1 = a[n-1];
                    }

                    break;

                }

            }

            

            if(first==false)
            {
                cout<<"hi ";
                for(k=0;k<n-1;k++)
                {
                    //cout<<k<<" "<<ar[k]<<" ";
                    if(al[k]==ar[k+1])
                    {
                        second = true;
                        
                        if(k==0 )
                        {
                            //cout<<"first ee ";
                            //cout<<k<<" "<<ar[k]<<" ";
                            // a[k]=al[k+1];
                            // key1 = a[k];
                            modione = true;
                            break;
                        }

                        if(k==n-2)
                        {
                           //cout<<"first eee ";
                            //cout<<k<<" "<<ar[k]<<" ";
                            // a[k+1]=ar[k];
                            // key1 = a[k+1];
                            moditwo=true;
                            break;
                        }

                    }
                   

                }
            }

            if(second == false && first == false)
            {
                cout<<"second ";
                for(q=0;q<n;q++)
                {
                    
                    if(al[q]!=al[q+1] && al[q]==1)
                    {
                        cout<<q<<" "<<al[q]<<"\n";
                        modithree=true;
                        break;
                    }
                }
            }


         }

        //cout<<'\n';

         // for(ll j=0;j<n;j++)
         // {
         //    cout<<a[j]<<" ";
         // }

         if(first==true){
         for(ll i=0;i<n;i++)
         {
            a[i]=a[i]/key1;
            c+=a[i];
         }
             }

            ll sum1=0, sum2=0;
            if(modify==true)
           {
            ll last;
            last = a[n-1];
            //first = a[0];

            a[n-1]=a[0];
            for(ll i=0;i<n;i++)
            {
              //a[i]=a[i]/a[0];
              sum1+=a[i]/a[n-1];
            }

            a[n-1]=last;
            a[0]=al[1];

            for(ll i=0;i<n;i++)
            {
              //a[i]=a[i]/a[0];
              sum2+=a[i]/a[0];
            }

            c = std::min(sum1,sum2);
         }
         else{


         if(modione==true)
         {
            ll first;
            //last = a[n-1];
            first = a[0];

            a[0]=al[1];

            for(ll i=0;i<n;i++)
            {
              sum1+=a[i]/a[0];
            }

            a[0]=first;
            a[n-1]=1;
            for(ll i=0;i<n;i++)
            {
              sum2+=a[i]/a[n-1];
            }

            c = std::min(sum1,sum2);


         }
         else if(moditwo==true)
         {
            //ll last;
            //last = a[n-1];
            
            a[n-1]=ar[n-2];
            for(ll i=0;i<n;i++)
            {
              sum1+=a[i]/a[n-1];
            }

            a[n-1]=1;
            for(ll i=0;i<n;i++)
            {
              sum2+=a[i]/a[n-1];
            }

            c = std::min(sum1,sum2);

         }
         else if(modithree==true)
         {
            ll first;
            //last = a[n-1];
            first = a[0];
            cout<<q<<" value ";

           a[0]=al[1];

            for(ll i=0;i<n;i++)
            {
              sum1+=a[i]/a[0];
            }

            a[0]=first;
            a[n-1]=1;
            for(ll i=0;i<n;i++)
            {
              sum2+=a[i]/a[n-1];
            }

            c = std::min(sum1,sum2);


         }
        


         // for(ll i=0;i<n;i++)
         // {
         //    a[i]=a[i]/key1;
         //    c+=a[i];
         // }
     

         }

        //  for(ll i=0;i<n;i++)
        //  {
        //     a[i]=a[i]/key1;
        //     c+=a[i];
        //  }

         }




         
         cout<<c<<"\n";

    }

    return 0;
}