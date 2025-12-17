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

    for(int i = 0; i < n - 2; i++){
        rotate3(start, i, i+2);
        
        // for(int i = 0; i < n; i++){
        //     cout << start[i] << " ";
        // }
        // cout << "\n";

        if(start == end){
            cout << "Possible";
            return 0;
        }

        for(int j = i+1; j < n - 2; j++){
            rotate3(start, j, j+2);

            // for(int i = 0; i < n; i++){
            //     cout << start[i] << " ";
            // }
            // cout << "\n";

            if(start == end){
                cout << "Possible";
                return 0;
            }
        }
    }

    cout << "Impossible";

    return 0;
}