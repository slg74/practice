#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroups;
    
    for (const string& s : strs) {
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end());
        anagramGroups[sortedStr].push_back(s);
    }
    
    vector<vector<string>> result;
    for (const auto& group : anagramGroups) {
        result.push_back(group.second);
    }
    
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<vector<string>> groupedAnagrams = groupAnagrams(strs);
    
    for (const auto& group : groupedAnagrams) {
        for (const string& s : group) {
            cout << s << " ";
        }
        cout << endl;
    }
    
    return 0;
}
