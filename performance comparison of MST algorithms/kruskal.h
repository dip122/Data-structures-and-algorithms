#include<vector>
using namespace std;
class disjointset{
	vector<int> parent;
	vector<int> size;
	vector<int> rank;
	public:
	disjointset(int n){
		parent.resize(n+1);
		for(int i=0;i<=n;i++){
			parent[i] = i;
		}
		rank.resize(n+1,0);
		size.resize(n+1,1);
	}
	int findUpar(int node){
		if(parent[node] == node){
			return node;
		}
		return parent[node] = findUpar(parent[node]);
	}
	void make_union(int u,int v){
		int uu = findUpar(u);
		int uv = findUpar(v);
		if(rank[uu] > rank[uv]){
			parent[uv] = uu;
			size[uu]+=size[uv];
		}
		else if(rank[uu] < rank[uv]){
			parent[uu] = uv;
			size[uv]+=size[uu];
		}
		else if(rank[uu] == rank[uv]){
			parent[uu] = uv;
			size[uv]+=size[uu];
		}
	}
	int getsize(int node){
		int unode = findUpar(node);
		return size[unode];
	}
};

static bool cmp(vector<int>&a,vector<int>&b){
	return a[2] < b[2];
}

int kruskal_algo(vector<vector<int>>&edges,int n){

	sort(edges.begin(),edges.end(),cmp);
	int N = edges.size();//size of the edges vector
	//n is the number of nodes
	
	disjointset ds(n);
	int ans = 0;
	for(int i=0;i<edges.size();i++){
		int a = edges[i][0];
		int b = edges[i][1];
		int c = edges[i][2];
		if(ds.findUpar(a)!=ds.findUpar(b)){
			ans+=c;
			ds.make_union(a,b);
		}
	}
	return ans;
}
