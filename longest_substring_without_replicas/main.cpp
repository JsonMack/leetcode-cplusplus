//
// Created by Jason MacKeigan on 2022-05-10.
//
//Problem: Given a string s, find the length of the longest substring without repeating characters.

// Iterate across the string
// establish a set of ascii codes for comparison
// increment a counter, and compare each char in the string to see if it is contained within set

#include <string>
#include <map>
#include <iostream>

using std::map, std::max, std::string;

class Solution {

public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        string current;

        unsigned long max = 0;

        unsigned long current_size = 0;

        for (unsigned long index = 0; index < s.length(); index++) {
            char character = s[index];

            auto existing = current.find(character);

            if (existing != string::npos) {
                if (current_size > max) {
                    max = current_size;
                }
                current = current.substr(existing + 1) + character;
                current_size = current.size();
            } else {
                current_size++;
                current += character;
            }
        }
        return std::max((int) current_size, (int) max);
    }
};

int main() {
    Solution solution;

    int max = solution.lengthOfLongestSubstring("aabaab!bb");

    std::cout << "Max: " << max << std::endl;
}