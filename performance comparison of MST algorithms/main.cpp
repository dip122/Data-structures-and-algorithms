#include <bits/stdc++.h>
#include "kruskal.h"
#include "prime.h"

using namespace std;
using namespace std::chrono;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges;
    int E;
    cin >> E;
    for (int i = 0; i < E; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back({x, y, z});
    }

    // Measure time for Kruskal's algorithm
    auto start = high_resolution_clock::now();
    int ans1 = kruskal_algo(edges,n);
    auto end = high_resolution_clock::now();
    double time1 = duration_cast<duration<double>>(end-start).count();
    cout << "Time for Kruskal's Algorithm is : " << time1 << " seconds" << endl;

    // Prepare adjacency list for Prime's algorithm
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    // Measure time for Prime's algorithm
    start = high_resolution_clock::now();
    int ans2 = primes_algo(adj, n);
    end = high_resolution_clock::now();
    double time2 = duration_cast<duration<double>>(end - start).count();
    cout << "Time for Prime's Algorithm is : " << time2 << " seconds" << endl;

    return 0;
}

