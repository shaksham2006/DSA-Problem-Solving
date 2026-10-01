class Solution {
public:
    bool isValid(string str) {
        stack<char>st;
        for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            st.push(str[i]);
        } 
        else { // Closing bracket logic
            if (st.size() == 0) {
                return false;
            }
            // Check if top of stack matches the current closing bracket
            if ((st.top() == '(' && str[i] == ')') ||
                (st.top() == '{' && str[i] == '}') ||
                (st.top() == '[' && str[i] == ']')) {
                st.pop();
            } 
            else { // No match found
                return false;
            }
        }
    }
    // If stack is empty, all brackets were matched correctly
    return st.size() == 0;
}
        
    
};

    
