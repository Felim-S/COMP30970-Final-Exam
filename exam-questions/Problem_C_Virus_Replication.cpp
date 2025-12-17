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

    string longest = (before.length() > after.length() ? before : after);
    string shortest = (before.length() < after.length() ? before : after);

    int total = 0;
    for(int i = 0; i < shortest.length(); i++){
        if(shortest[i] != longest[i]){
            total++;
            for(int j = i+1; j < longest.length(); j++){
                if(shortest[i] != longest[j]){
                    i = j - 1;
                    break;
                }
            }
        }
    }

    cout << total;

    return 0;
}