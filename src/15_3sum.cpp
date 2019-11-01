//
// Created by Oleksyshyn oleksii on 01.11.19.
//



/*
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 *
 * The solution set must not contain duplicate triplets.
 *
 * Solution -- hash map, complexity -- O(n^2) in time
 * */


#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
    struct hash{
        size_t operator()(const vector<int>& iterable) const {
            size_t result = std::hash<int>()(iterable[0]);

            for (int i = 1; i < iterable.size(); ++i){
                result ^= std::hash<int>()(iterable[i]);
            }

            return result;
        }
    };

public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        const int n = nums.size();

        unordered_map<int, vector<pair<int, int>>> pairs_and_sum;
        unordered_set<vector<int>, hash> set_of_results;

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
};