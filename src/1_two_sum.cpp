//
// Created by Oleksyshyn Oleksii on 31.10.19.
//


#include <vector>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){

        for (int i = 0; i < nums.size(); ++i){
            for (int j = 0; j < i; ++j) {
                if (nums[i] + nums[j] == target){
                    return {j, i};
                }
            }
        }

        return {-1, -1};
    }
};