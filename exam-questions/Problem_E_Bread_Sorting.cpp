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

void rotate3(vector<int>& nums, int i, int j){
    int lastNum = nums[j];
    nums[j] = nums[i+1];
    nums[i+1] = nums[i];
    nums[i] = lastNum;
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

    for(int i =)

    return 0;
}