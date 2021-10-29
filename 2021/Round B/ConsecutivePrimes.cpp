#include<bits/stdc++.h>
using namespace std;

bool isPrime(long long n){
    long long root = sqrt(n);
    for (long long i = 2; i <= root; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    
    for (int a = 0; a < t; a++){
        long long n;
        cin >> n;

        long long root = sqrt(n);
        int lowerPrimeCount = 0, upperPrimeCount = 0;
        set<long long> primes;

        for (long long i = root; i > 1; i--){
            if(isPrime(i)){
                lowerPrimeCount++;
                primes.insert(i);
            }
            if (lowerPrimeCount >= 2){
                break;
            }
        }
        
        for (long long i = root; i < n; i++){
            if(isPrime(i)){
                upperPrimeCount++;
                primes.insert(i);
            }
            if (upperPrimeCount >= 2){
                break;
            }
        }

        auto tmpItr = primes.begin();
        long long output = 0;

        for (auto itr = primes.begin(); itr != primes.end(); itr++){
            if (itr != primes.begin()){
                if ( (*itr) * (*tmpItr) <= n){
                    output = max(output, (*itr) * (*tmpItr));
                }
            }
            tmpItr = itr;
        }

        cout << "Case #" << a + 1 << ": " << output << endl;
    }
    return 0;
}