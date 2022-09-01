#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> dp;

int solve(string &x, int y, int idx) {
  if (y < 0) return 1000;
  if (idx == x.length()) return (y == 0 ? 0 : 1000);

  if (dp[idx][y] != -1) return dp[idx][y];

  int ans = 1000;
  for (int i = idx; i < min(idx + 4, (int )x.length()); i++) {

    int num = stoi(x.substr(idx, i - idx + 1));
    
    ans = min(ans, solve(x, y - num, i + 1) + (i < x.length() - 1));

  }

  return dp[idx][y] = ans;
} 

int main() {
    cout<<"enter strings\n";
  string x; cin >> x;
  int y; cin >> y;
  int n = x.length();
  dp = vector<vector<int>> (n, vector<int> (y + 1, -1));
  int ans = solve(x, y, 0);
  if (ans == 1000) cout << -1;
  else cout << ans;
  return 0;
}