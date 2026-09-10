#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChainOrder(const vector<int>& p) {
    const int n = p.size() - 1; 
    const int size = n + 1;

    vector<int> m(size * size, 0);

    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            const int j = i + L - 1;
            const int idx_ij = i * size + j; 
            
            m[idx_ij] = INT_MAX; 

            for (int k = i; k <= j - 1; k++) 
            {
                int cost = m[i * size + k] + m[(k + 1) * size + j] + p[i - 1] * p[k] * p[j];
                
                if (cost < m[idx_ij])
                {
                    m[idx_ij] = cost;
                }
            }
        }
    }
    
    return m[1 * size + n];
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr = {10, 20, 30, 40}; 
    cout << "Minimum number of multiplications is: " 
         << matrixChainOrder(arr) << "\n"; 
    return 0;
}
