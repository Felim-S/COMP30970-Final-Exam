#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <unordered_map>
#include <climits>
#include <complex>
#include <map>
using namespace std;

struct union_find {
    vector<int> parent;
    union_find(int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};

int main(){

    int tests;
    cin >> tests;

    while(tests--){

        int N, M;
        cin >> N >> M;

        int startX, startY;
        cin >> startX >> startY;

        int totalBeepers;
        cin >> totalBeepers;

        vector<pair<int,int>> beepers;
        beepers.push_back({startX, startY});
        for(int i = 0; i < totalBeepers; i++){
            int a,b;
            cin >> a >> b;
            beepers.push_back({a,b});
        }
        
        // calculate the distance between all the beepers
        vector<vector<int>> distanceMatrix(totalBeepers+1, vector<int>(totalBeepers+1, 0));
        for(int i = 0; i < totalBeepers+1; i++){
            for(int j = 0; j < totalBeepers+1; j++){
                auto[x1,y1] = beepers[i];
                auto[x2,y2] = beepers[j];

                int dist = abs(x2 - x1) + abs(y2 - y1);

                distanceMatrix[i][j] = dist;
                distanceMatrix[j][i] = dist;
            }
        }

        // // calculate the adjacency list
        // vector<vector<int>> adj(N, vector<int>(M, 0));
        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < M; j++){
        //         if(distanceMatrix[i][j] != 0){
        //             adj[i].push_back(j);
        //         }
        //     }
        // }

        // debug
        cout << "\nDistances Matrix (input given):\n";
        for(int i = 0; i < totalBeepers+1; i++){
            for(int j = 0; j < totalBeepers+1; j++){
                cout << (distanceMatrix[i][j]) << " ";
            }
            cout << "\n";
        }
        // cout << "\nAdjacency List:\n";
        // for(int i = 0; i < N; i++){
        //     cout << (i+1) << " is connected to: ";
        //     for(int j = 0; j < adj[i].size(); j++){
        //         cout << (adj[i][j] + 1) << " ";
        //     }
        //     cout << "\n";
        // }

        vector<tuple<int, int, int>> edges;
        for(int i = 0; i < totalBeepers+1; i++){
            for(int j = 0; j < totalBeepers+1; j++){
                edges.push_back({distanceMatrix[i][j], i, j});
            }
        }

        /* Kruskal's algorithm */

        // minimal spanning tree
        vector<pair<int,int>> T;

        union_find D = union_find(totalBeepers+1);

        sort(edges.begin(), edges.end());
        
        for(int i = 0; i < edges.size(); i++){
            auto curr = edges[i];
            double weight = get<0>(curr);
            double a = get<1>(curr);
            double b = get<2>(curr);

            //cout << weight << " " << a+1 << " " << b+1 << "\n";

            if(D.find(a) != D.find(b)){
                T.push_back({a,b});
                D.unite(a,b);
            }
        }

        // necessary for final output (i think)
        sort(T.begin(), T.end());

        // sum all the edges
        double sum = 0;
        for(auto edge : T){
            sum += distanceMatrix[edge.first][edge.second];
        }

        cout << sum << "\n";

        for(auto p : T){
            cout << p.first << " " << p.second << "\n";
        }
    }

    return 0;
}