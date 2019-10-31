#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int head = 0;
        int tail = height.size() - 1;

        while (head < tail){
            if (min(height[head], height[tail]) * (tail - head) > maxArea){
                maxArea = min(height[head], height[tail]) * (tail - head);
            }

            if (height[head] <= height[tail]){
                ++head;
            } else {
                --tail;
            }
        }

        return maxArea;
    }
};

int main() {
    Solution s;
    vector<int> x = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << s.maxArea(x);
    return 0;
}