#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    
    while (t--) {
        cin >> n;
        vector<int> arr(n);
        vector<int> count(30001, 0);  // 
        
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            count[arr[i]]++;
        }
        
        int max_count = 0;
        for (int i = 0; i < 30001; ++i) {
            max_count = max(max_count, count[i]);
        }
        
        vector<bool> printed(30001, false);  
        for (int i = 0; i < n; ++i) {
            if (count[arr[i]] == max_count && !printed[arr[i]]) {
                cout << arr[i] << " ";
                printed[arr[i]] = true;
            }
        }
        cout << endl;
    }
    return 0;
}

