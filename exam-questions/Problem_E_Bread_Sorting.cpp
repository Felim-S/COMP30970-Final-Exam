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

void rotate3(vector<int>& nums, int i){
    int lastNum = nums[i+2];
    nums[i+2] = nums[i+1];
    nums[i+1] = nums[i];
    nums[i] = lastNum;
}

bool tryRotations(vector<int>& start, vector<int> end, int i){
    if(start == end){ return true; }
    if(i >= start.size()){ return false; }

    vector<int> original = start;

    rotate3(start, i);

    return (tryRotations(start, end, i+1) || tryRotations(original, end, i+1));
}

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

    if(tryRotations(start, end, 0)){
        cout << "Possible";
    } else{
        cout << "Impossible";
    }

    return 0;
}