#include<vector>
#include<queue>
using namespace std;

int primes_algo(vector<pair<int,int>> adj[],int n){

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	vector<int> vis(n,0);
	pq.push({0,0});//wt , node
	int ans = 0;
	while(!pq.empty()){
		int wt = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if(vis[node] == 1)continue;
		vis[node] = 1;
		ans+=wt;
		for(auto &it : adj[node]){
			int adjnode = it.first;
			int adjnodewt = it.second;
			if(!vis[adjnode]){
				pq.push({adjnodewt,adjnode});
			}
		}
	}
	return ans;
}
