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

set<long long> eratosthenes(long long n){
    vector<bool> isMarked(n+1, false);
    set<long long> primes;
    
    for(long long i = 2; i * i <= n; i++){
        if(!isMarked[i]){
            for(long long j = i * i; j <= n; j += i){
                isMarked[j] = true;
            }
        }
    }

    for(long long i = 2; i <= n; i++){
        if(!isMarked[i]){
            primes.insert(i);
        }
    }

    return primes;
}

bool isPrime(long long n) {
    if(n < 2) { return false; }
    if(n % 2 == 0) { return n == 2; }

    for(long long i = 3; i * i <= n; i += 2){
        if(n % i == 0) { return false; }
    }

    return true;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}