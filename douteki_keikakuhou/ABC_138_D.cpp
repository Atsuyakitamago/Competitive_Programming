#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
int N, Q;
Graph G;

void dfs(int v, int p, vector<long long> &res) {
  if (p != -1) res[v] += res[p];
  for (auto e : G[v]) {
    if (e == p) continue;
    dfs(e, v, res);
  }
}

int main() {
  cin >> N >> Q;
  G.assign(N, vector<int>());
  for (int i = 0; i < N-1; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<long long> val(N, 0);
  for (int i = 0; i < Q; ++i) {
    int p, x;
    cin >> p >> x;
    --p;
    val[p] += x;
  }

  dfs(0, -1, val);
  
  for (auto v : val) cout << v << " ";
  cout << endl;
}