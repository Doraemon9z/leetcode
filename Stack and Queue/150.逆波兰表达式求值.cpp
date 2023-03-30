/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long long nums1 = st.top();
                st.pop();
                long long nums2 = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(nums2 + nums1);
                if (tokens[i] == "-") st.push(nums2 - nums1);
                if (tokens[i] == "*") st.push(nums2 * nums1);
                if (tokens[i] == "/") st.push(nums2 / nums1);
            }
            else {
                st.push(stoll(tokens[i]));
            }
        }
        int result = st.top();
        st.pop();
        return result;
    }
};
// @lc code=end

