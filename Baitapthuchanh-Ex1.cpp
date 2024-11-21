#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        unordered_map<int, int> count_map;
        
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            count_map[arr[i]]++;
        }
        
        int max_count = 0;
        for (const auto& entry : count_map) {
            max_count = max(max_count, entry.second);
        }
        
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (count_map[arr[i]] == max_count && find(result.begin(), result.end(), arr[i]) == result.end()) {
                result.push_back(arr[i]);
            }
        }
        
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

