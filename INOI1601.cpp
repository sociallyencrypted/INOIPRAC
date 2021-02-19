#include <bits/stdc++.h>
using namespace std;
const int N=1e5+1;
vector <int> rel[N];
vector <int> a(N);
int ans=0;
bool visited[N];
void dfs(int node, int mx){
	visited[node]=true;
	mx=max(mx, a[node]);
	ans=max(ans,mx-a[node]);
	for (auto x: rel[node]){
		if (!visited[x]){
			dfs(x,mx);
		}
	}
}

int main() {
	int n;
	cin >> n;
	a.clear();
	int hojo=0;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		if (x!=-1){
			rel[i].push_back(x);
			rel[x].push_back(i);
			}
		else{
			hojo=i;
		}
	}
	dfs(hojo,a[hojo]);
	cout<<ans;
	return 0;
}
