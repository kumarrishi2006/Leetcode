
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> need;
        unordered_map<char, int> have;

        // Count letters needed
        for (int i = 0; i < ransomNote.size(); i++) {
            need[ransomNote[i]]++;
        }

        // Count letters available
        for (int i = 0; i < magazine.size(); i++) {
            have[magazine[i]]++;
        }

        // Compare frequencies
        for (auto i : need) {
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];

            if (fhave < fneed) {
                return false;
            }
        }

        return true;
    }
};

