class Solution {
public:
    char repeatedCharacter(string s) {
        list<char> l;

        for (int i = 0; i < s.size(); i++) {
            auto it = find(l.begin(), l.end(), s[i]);

            if (it != l.end()) {
                return s[i];
            } else {
                l.push_back(s[i]);   // Store the character
            }
        }

        return '\0';    // Won't execute for valid inputs
    }
};