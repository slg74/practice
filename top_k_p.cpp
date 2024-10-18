#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }
        
        auto comp = [&freq_map](int a, int b) {
            return freq_map[a] > freq_map[b];
        };
        
        std::priority_queue<int, std::vector<int>, decltype(comp)> pq(comp);
        
        for (const auto& pair : freq_map) {
            pq.push(pair.first);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        std::vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    
    Solution solution;
    std::vector<int> result = solution.topKFrequent(nums, k);
    
    std::cout << "The " << k << " most frequent elements are: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
