#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargestElement(vector<int>& nums, int k) {
    priority_queue<int> maxHeap(nums.begin(), nums.end());
    for (int i = 1; i < k; ++i) {
        maxHeap.pop();
    }
    return maxHeap.top();
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    cout << findKthLargestElement(nums, k) << endl;

    cin >> n >> k;
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    cout << findKthLargestElement(nums, k) << endl;
    return 0;
}
