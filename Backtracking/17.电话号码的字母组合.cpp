/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
    const string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> result;
    string s;
    void backtracking(const string& digits, int index) {
        if (index == digits.size()) {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);
            backtracking(digits, index + 1);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        s.clear();
        result.clear();
        if (digits.size() == 0) {
            return result;
        }
        backtracking(digits, 0);
        return result;
    }
};




// 版本二
// class Solution {
// private:
//         const string letterMap[10] = {
//             "", // 0
//             "", // 1
//             "abc", // 2
//             "def", // 3
//             "ghi", // 4
//             "jkl", // 5
//             "mno", // 6
//             "pqrs", // 7
//             "tuv", // 8
//             "wxyz", // 9
//         };
// public:
//     vector<string> result;
//     void getCombinations(const string& digits, int index, const string& s) { // 注意参数的不同
//         if (index == digits.size()) {
//             result.push_back(s);
//             return;
//         }
//         int digit = digits[index] - '0';
//         string letters = letterMap[digit];
//         for (int i = 0; i < letters.size(); i++) {
//             getCombinations(digits, index + 1, s + letters[i]);  // 注意这里的不同
//         }
//     }
//     vector<string> letterCombinations(string digits) {
//         result.clear();
//         if (digits.size() == 0) {
//             return result;
//         }
//         getCombinations(digits, 0, "");
//         return result;

//     }
// };
// @lc code=end

