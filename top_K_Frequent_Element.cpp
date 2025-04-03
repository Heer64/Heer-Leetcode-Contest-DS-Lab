class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }
        priority_queue<pair<int, int>> maxHeap;
        for (auto& entry : frequencyMap) {
            maxHeap.push({entry.second, entry.first});
        }
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return result;
    }
};
