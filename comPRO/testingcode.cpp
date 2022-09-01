#include <bits/stdc++.h>
using namespace std;

#define fast_io                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
#define ll long long int
#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define mid(l, r) (l + (r - 1) / 2)
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define looprev(i, a, b) for (int i = (a); i >= (b); i--)

void init_code()
{
  fast_io;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

vector<vector<int>> dp;

int min_pluses(string s, int target, int idx)
{
  if (target < 0)
    return 1000;
  if (idx == s.length())
    return (target == 0 ? 0 : 1000);

  if (dp[idx][target] != -1)
    return dp[idx][target];
  int ans = 1000;

  for (int i = idx; i < min(idx + 4, (int )s.length()); i++)
  {
    int num = stoi(s.substr(idx, i - idx + 1));
    ans = min(ans, min_pluses(s, target - num, i + 1) + (i < s.length() - 1));

  }

  return dp[idx][target] = ans;

}

int main()
{
  //init_code();
  string str;
  cin >> str;
  int index;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '=')
    {
      index = i;
    }
  }

  string s = str.substr(0, index);
  int target = stoi(str.substr(index + 1));
  dp = vector<vector<int>>(str.length(), vector<int>(target + 1, -1));
  int result = min_pluses(s, target, 0);
  if(result == 1000) result = -1;
  cout << result << endl;

  return 0;
}