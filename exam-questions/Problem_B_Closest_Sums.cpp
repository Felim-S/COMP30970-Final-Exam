#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <unordered_map>
#include <climits>
using namespace std;

int main(){

    int n,m;
    vector<string> cases;

    int index = 1;

    while(cin >> n){
        cases.push_back("Case " + to_string(index++) + ":");
        vector<int> ns;
        vector<int> ms;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            ns.push_back(x);
        }
        cin >> m;
        for(int i = 0; i < m; i++){
            int x;
            cin >> x;
            ms.push_back(x);
        }

        // find all possible sums of ns
        vector<int> sums;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                sums.push_back(ns[i] + ns[j]);
            }
        }

        for(int i = 0; i < m; i++){
            // find the closest one
            int closestSum = INT_MAX;
            for(int j = 0; j < sums.size(); j++){
                if( (abs(ms[i] - sums[j])) < (abs(ms[i] - closestSum)) ){
                    closestSum = sums[j];
                }
            }

            string result = "Closest sum to " + to_string(ms[i]) + " is " + to_string(closestSum) + ".";

            cases.push_back(result);
        }
    }

    for(int i = 0; i < cases.size(); i++){
        cout << cases[i] << "\n";
    }

    return 0;
}