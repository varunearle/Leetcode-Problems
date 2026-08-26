class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";

        // Check every substring
        for (int i = 0; i < n; i++) {
            int ones = 0;

            for (int j = i; j < n; j++) {
                if (s[j] == '1')
                    ones++;

                if (ones == k) {
                    string curr = s.substr(i, j - i + 1);

                    // Update if:
                    // 1. This is the first valid substring
                    // 2. It is shorter
                    // 3. Same length but lexicographically smaller
                    if (ans.empty() ||
                        curr.length() < ans.length() ||
                        (curr.length() == ans.length() && curr < ans)) {
                        ans = curr;
                    }
                }

                // More than k ones, so extending further won't help
                if (ones > k)
                    break;
            }
        }

        return ans;
    }
};