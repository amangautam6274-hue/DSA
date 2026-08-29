 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool canWePlace(vector<int>& arr, int dist, int k) {
        int cnt = 1;
        int n = arr.size();
        int last = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] - last >= dist) {
                cnt++;
                last = arr[i];
            }
        }

        return cnt >= k;
    }

    int aggressiveCows(vector<int>& arr, int k) {

        int ans = 0;

        sort(arr.begin(), arr.end());

        int n = arr.size();

        int left = 1;
        int right = arr[n - 1] - arr[0];

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (canWePlace(arr, mid, k)) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> arr = {1, 2, 4, 8, 9};
    int k = 3;

    cout << obj.aggressiveCows(arr, k) << endl;

    return 0;
}