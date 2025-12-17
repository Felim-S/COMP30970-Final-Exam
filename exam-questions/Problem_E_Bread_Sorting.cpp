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

    int n;
    cin >> n;

    vector<int> start(n);
    vector<int> end(n);
    for(int i = 0; i < n; i++){
        cin >> start[i];
    }
    for(int i = 0; i < n; i++){
        cin >> end[i];
    }

    reverse(end.begin(), end.end());
    if(start == end){
        cout << "Impossible";
    } else{
        cout << "Possible";
    }

    return 0;
}