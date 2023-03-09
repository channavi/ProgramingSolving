#include <iostream>
#include <map>
using namespace std;

int romanToInt(string s) {
    map<char, int> romanToIntMap;
    romanToIntMap['I'] = 1;
    romanToIntMap['V'] = 5;
    romanToIntMap['X'] = 10;
    romanToIntMap['L'] = 50;
    romanToIntMap['C'] = 100;
    romanToIntMap['D'] = 500;
    romanToIntMap['M'] = 1000;

    int result = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i > 0 && romanToIntMap[s[i]] > romanToIntMap[s[i - 1]]) {
            result += romanToIntMap[s[i]] - 2 * romanToIntMap[s[i - 1]];
        }
        else {
            result += romanToIntMap[s[i]];
        }
    }
    return result;
}

int main() {
    string romanNumeral;
    cout << "Enter a Roman numeral: ";
    cin >> romanNumeral;
    int result = romanToInt(romanNumeral);
    if (result == 0) {
        cout << "Invalid Roman numeral";
    }
    else {
        cout << "The integer value of " << romanNumeral << " is " << result;
    }
    return 0;
}