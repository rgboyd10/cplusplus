#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    string toLowerCase(string str) 
    {
        string result = str;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }
};
