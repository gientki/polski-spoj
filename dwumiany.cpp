#include <iostream>
#include <vector>

using namespace std;

long long binomial_coefficient(int n, int k) {
    if (k > n - k) {
        k = n - k;
    }
    
    long long result = 1;
    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    
    return result;
}

int main() {
    int T;
    cin >> T;  

    vector<long long> results;
    results.reserve(T);  

    for (int i = 0; i < T; ++i) {
        int n, k;
        cin >> n >> k;
        results.push_back(binomial_coefficient(n, k));
    }

    for (const auto& result : results) {
        cout << result << endl;
    }

    return 0;
}
