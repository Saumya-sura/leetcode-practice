#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0; // endWord must be in list

        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // (word, steps)
        dict.erase(beginWord);  // mark as visited

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord) return steps;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == original) continue;
                    word[i] = ch;

                    if (dict.find(word) != dict.end()) {
                        q.push({word, steps + 1});
                        dict.erase(word); // avoid revisiting
                    }
                }
                word[i] = original; // restore
            }
        }
        return 0; // not found
    }
};
