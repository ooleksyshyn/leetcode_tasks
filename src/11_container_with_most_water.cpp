//
// Created by Oleksyshyn Oleksii on 31.10.19.
//

/*
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 *
 * Solution: two side approach -- O(n) in time, O(1) in memory
 */



#include <vector>


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