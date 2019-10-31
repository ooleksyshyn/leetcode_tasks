//
// Created by Oleksyshyn Oleksii on 31.10.19.
//

/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 * Example 1:
 *
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * Example 2:
 *
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * Note:
 *
 * All given inputs are in lowercase letters a-z.
 *
 * Solution: vertical scan, complexity -- O(minSize * n) of time, O(1) of memory
 *
 * minSize -- minimal size of string in input, n -- amount of strings
 *
 * */


#include <vector>
#include <string>


using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        int minSize = strs[0].size();
        for (const auto& line : strs){
            if (line.size() < minSize){
                minSize = line.size();
            }
        }

        string result;
        for (int i = 0; i < minSize; ++i){
            char nextCharacter = strs[0][i];
            for (int j = 0; j < strs.size(); ++j){
                if (strs[j][i] != nextCharacter){
                    return result;
                }
            }

            result += nextCharacter;
        }
        return result;
    }
};