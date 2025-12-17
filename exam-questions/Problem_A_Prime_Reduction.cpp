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

vector<long long> eratosthenes(long long n){
    vector<bool> isMarked(n+1, false);
    vector<long long> primes;
    
    for(long long i = 2; i * i <= n; i++){
        if(!isMarked[i]){
            for(long long j = i * i; j <= n; j += i){
                isMarked[j] = true;
            }
        }
    }

    for(long long i = 2; i <= n; i++){
        if(!isMarked[i]){
            primes.push_back(i);
        }
    }

    return primes;
}

bool isPrime(long long n, vector<long long> primes){
    return count(primes.begin(), primes.end(), n);
}

map<long long, long long> factor(long long N, vector<long long> primes) {
    map<long long, long long> factors;
    for(int i = 0; i < primes.size(); ++i){
        long long prime = primes[i], power = 0;
        while(N % prime == 0){
            power++;
            N /= prime;
        }
        if(power > 0){
            factors[prime] = power;
        }
    }
    if (N > 1) {
        factors[N] = 1;
    }
    return factors;
}

// bool isPrime(long long n) {
//     if(n < 2) { return false; }
//     if(n % 2 == 0) { return n == 2; }

//     for(long long i = 3; i * i <= n; i += 2){
//         if(n % i == 0) { return false; }
//     }

//     return true;
// }

pair<long long, long long> primeReduction(long long N, long long executions, vector<long long> primes){
    if(isPrime(N, primes)){
        return {N, executions + 1};
    }
    long long x = N;
    while(!isPrime(x, primes)){
        map<long long, long long> factors = factor(x, primes);
        x = 0;
        for(long long i = 0; i < factors.size(); i++){
            if(factors[i] > 0){
                x += i * factors[i];
            }
        }
        executions++;
    }
    return {x, executions + 1};
    
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        long long N;
        cin >> N;

        if(N == 4){ break; }

        vector<long long> primes = eratosthenes(N);

        pair<long long, long long> result = primeReduction(N, 0, primes);
        cout << result.first << " " << result.second << "\n"; 
    }

    return 0;
}