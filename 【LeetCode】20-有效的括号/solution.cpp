class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        for(int i=0;i<s.size();i++){
            if(s[i]=='['||s[i]=='{'||s[i]=='('){
                str.push(s[i]);
            }else{
                if(str.empty())return false;
                if(s[i]==']'&&str.top()!='[')return false;
                if(s[i]=='}'&&str.top()!='{')return false;
                if(s[i]==')'&&str.top()!='(')return false;
                str.pop();
            }
        }
        return str.empty();
    }
};
