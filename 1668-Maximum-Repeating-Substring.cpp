class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int maxi=0;
        string x=word;

        while(sequence.find(x) != string::npos)
        {
            maxi++;
            x += word;
        }
        return maxi;
    }
};