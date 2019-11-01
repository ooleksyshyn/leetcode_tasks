#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        const int n = nums.size();

        unordered_map<int, vector<pair<int, int>>> pairs_and_sum;
        unordered_set<vector<int>, int, vector_hash> set_of_results;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                pairs_and_sum[nums[i] + nums[j]].push_back(make_pair(i, j));
            }
        }

        for (int i = 0; i < n; ++i){
            for (const auto& pair : pairs_and_sum[0 - nums[i]]){
                if (pair.first != i && pair.second != i){
                    vector<int> one_more_pair = {nums[i], nums[pair.first], nums[pair.second]};
                    std::sort(one_more_pair.begin(), one_more_pair.end());
                    set_of_results.insert(one_more_pair);
                }
            }
        }

        vector<vector<int>> result;

        for (const auto& res : set_of_results){
            result.push_back(res);
        }

        return result;
    }

public:
    struct vector_hash{
        size_t operator()(const vector<int>& vec){
            size_t result = hash<int>()(vec[0]);
            for (size_t i = 1; i < vec.size(); ++i){
                result ^= hash<int>()(vec[i]);
            }

            return result;
        }
    };
};


int main() {
    Solution s;
    vector<int> x = {-1, 0, 1, 2, -1, -4};
    auto y = Solution::vector_hash{};
    vector<int> z = {1, 2, 3};
    std::cout << y(z);
    //std::cout << s.threeSum(x).size();
    /*for (const auto& result : s.threeSum(x)){
        for (auto el : result){
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }*/
    return 0;
}