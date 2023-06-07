#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman= {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int len = s.length();
        int val = 0, prev = -1;
        /*for(int i = 0; i < len; i++) {
            int v = roman[s[i]];
			//cout << v << endl;

            if(i != 0) {
                if(v > roman[s[prev]]) {
					val = val > v ? val - v : v - val;
                    //val = val - v;// - roman[s[prev]];
					cout << "val" << val << endl;
				} else {
					val = v + val; //+ roman[s[prev]];
					cout << "val" << val << endl;
				}
            } else {
				val = v;
				cout << "val" << val << endl;
			}

            prev = i;
        }*/

		/*for(int i = len - 1; i >= 0; i--) {
			int v = roman[s[i]];

			if(i == len - 1) {
				val = val + roman[s[i]];
			} else if(roman[s[i]] < roman[s[prev]]) {
				val = val - roman[s[i]];
			} else {
				val = val + roman[s[i]];
			}

			prev = i;
		}*/

		for(int i=0;i<s.size();i++){
			if(roman[s[i]]<roman[s[i+1]]){
				//for cases such as IV,CM, XL, etc...
				val=val-roman[s[i]];
			}
			else{
				val=val+roman[s[i]];
			}
		}

        return val;
    }
};

int main() {
	Solution s;

	string input = "III";
	/*cout << "Enter Roman Value:";
	cin >> input;*/

	//int value = s.romanToInt("CMV");
	int value = s.romanToInt(input);
	cout << "Value:" << value << endl;
	input = "CMV";
	value = s.romanToInt(input);
	cout << "Value:" << value << endl;
	input = "LVIII";
	value = s.romanToInt(input);
	cout << "Value:" << value << endl;
	input = "MCMXCIV";
	value = s.romanToInt(input);
	cout << "Value:" << value << endl;
	return 0;
}
