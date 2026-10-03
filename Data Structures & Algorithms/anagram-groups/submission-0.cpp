class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mappedWord;
        for(string str: strs){
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            // if(mappedWord.find(sortedStr) == mappedWord.end()){
            //     mappedWord[sortedStr] = new vector<string>();
            // }
            mappedWord[sortedStr].push_back(str);
        }
        vector<vector<string>> output;
        for(auto& [str, group]: mappedWord){
            output.push_back(group);
        }
        return output;
    }
};
