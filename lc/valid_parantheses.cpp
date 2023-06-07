#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool valid = true;
        stack<char> brackets;
        int len = s.length();

        for(int i = 0; i < len; i++) {
			//cout << s[i] << endl;
            if(s[i] == '{' || s[i] == '[' || s[i] == '(') {
                brackets.push(s[i]);
            } else if(s[i] == '}' || s[i] == ']' || s[i] == ')') {
				if(!brackets.empty()) {
					char c = brackets.top();
					brackets.pop();
					//cout << "c:" << c << endl;
					if((s[i] == '}' && c == '{') || (s[i] == ']' && c == '[') || (s[i] == ')' && c == '(')) {
						continue;
					} else {
						valid = false;
						break;
					}
				} else {
					valid = false;
					break;
				}
            }
        }

		if(!brackets.empty()) {
			valid = false;
		}

        return valid;
    }
};

int main() {

	Solution s;

	bool isValid = s.isValid("{}");
	cout << isValid << endl;

	isValid = s.isValid("(){}[]");
	cout << isValid << endl;

	isValid = s.isValid("{]");
	cout << isValid << endl;
	
	isValid = s.isValid("(");
	cout << isValid << endl;

	isValid = s.isValid("]");
	cout << isValid << endl;

	isValid = s.isValid("](){}");
	cout << isValid << endl;

	isValid = s.isValid("[(){}");
	cout << isValid << endl;

	isValid = s.isValid("[(){}]");
	cout << isValid << endl;
	
	return 0;
}
