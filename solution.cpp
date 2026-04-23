
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

using namespace std;

uint64_t sum_of_proper_divisors(uint64_t n) {
    if (n <= 1) return 0;
    
    uint64_t sum = 1; // 1 is always a proper divisor for n > 1
    uint64_t sqrt_n = static_cast<uint64_t>(sqrt(n));
    
    for (uint64_t i = 2; i <= sqrt_n; ++i) {
        if (n % i == 0) {
            uint64_t divisor = i;
            uint64_t complement = n / i;
            
            if (divisor == complement) {
                sum += divisor; // Perfect square, add only once
            } else {
                sum += divisor + complement;
            }
        }
    }
    
    return sum;
}

bool is_perfect_number(uint64_t n) {
    if (n <= 1) return false;
    return sum_of_proper_divisors(n) == n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m;
    cin >> m;
    
    vector<uint64_t> numbers(m);
    for (int i = 0; i < m; ++i) {
        cin >> numbers[i];
    }
    
    for (int i = 0; i < m; ++i) {
        cout << (is_perfect_number(numbers[i]) ? 1 : 0) << '\n';
    }
    
    return 0;
}
