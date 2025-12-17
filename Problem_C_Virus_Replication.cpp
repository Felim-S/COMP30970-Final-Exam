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
#include <set>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string before, after;
    cin >> before >> after;

    int total = 0;
    for(int i = 0; i < before.length() && i < after.length(); i++){
        if(before[i] != after[i]){
            total++;
            for(int j = i+1; j < after.length(); j++){
                if(before[i] != after[j]){
                    i = j - 1;
                    break;
                }
            }
        }
    }

    cout << total;

    return 0;
}