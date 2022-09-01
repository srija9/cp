#include <bits/stdc++.h>
using namespace std;
 
#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll             long long int
#define mod            1000000007
#define inf            1e18
#define endl           "\n"
#define mid(l,r)       (l+(r-1)/2)
#define loop(i,a,b)    for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
 
void init_code(){
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

bool isOperator(char c)
{
    if(c == '+' || c == '-' || c == '*')
    {
        return true;
    }
    else
        return false;
}

int precedence(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*')
        return 2;
    
    return 0;
}

string infixtoprefix(stack<char> s, string infix)
{
    string prefix;
    reverse(infix.begin(), infix.end());

    // cout<<infix;
    // cout<<infix.length()<<endl;

    for(int i=0; i<infix.length(); i++) {
        if(infix[i] == '(') {
            infix[i] = ')';
        }
        else if(infix[i]==')')
        {
            infix[i] = '(';
        }
    }
    int flag = 1;

    for(int i=0; i<infix.length(); i++){
        
        cout<<infix[i]<<endl;
        if(isdigit(infix[i]))
        {
            int num = 0, start=i, end;
            prefix += infix[i];
            // while(isdigit(infix[i]))
            // {
            //     //num = num*10 + (infix[i] - 48);
            //     prefix += infix[i];
            //     //cout<<prefix<<endl;
            //     i++;
            // }
            end = i;
            // for(int p = end; p>=start; p++){
            //   num = num*10 + (infix[p] - 48);
            //    prefix += infix[p];
            // }
        }
        else if(infix[i] == '(') {

            s.push(infix[i]);
        }
        else if(infix[i] == ')') {
            if(infix[i-1] == '(')
            {
                prefix = "invalid";
                flag = 0;
            }
            while((s.top() != '(') && (!s.empty())) {
                prefix += s.top();
                s.pop();
            }
            if(s.top() == '(') {
                s.pop();
            }
        }
        else if(isOperator(infix[i])) {
            cout<<prefix<<endl;
            if(isOperator(infix[i-1]))
            {
                prefix = "invalid";
                flag = 0;
            }
            if(s.empty())
            {
                s.push(infix[i]);
            }
            else {
                if(precedence(infix[i]) > precedence(s.top())) {
                    s.push(infix[i]);
                }
                else if(precedence(infix[i]) == precedence(s.top())) {
                    s.push(infix[i]);
                }
                else {
                    while((!s.empty()) && (precedence(infix[i] < precedence(s.top())))) {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }

        if(flag == 0)
        {
            break;
        }
        
    }

    while(!s.empty()) {
        prefix += s.top();
        s.pop();
    }

    if(flag == 1){
       reverse(prefix.begin(), prefix.end()); 
    }

   
   return prefix;    
}
 
int main()
{
init_code();
string infix, prefix;
stack<char> stack;
cout<<"hi\n";
cin>>infix;
prefix = infixtoprefix(stack, infix);
cout<<prefix;
cout<<"bye\n";

 
return 0;
}