class Solution {
    bool isDup(string &s1,string &s2)
    {
        int arr[26]={0};

        for(char ch:s1)
        {
            if(arr[ch-'a']>0) return true;

            arr[ch-'a']++;
        }

        for(auto it:s2)
        {
            if(arr[it-'a']>0) return true;
        }
        return false;
    }
    int helper(int i,int n,string temp,vector<string>&nums,unordered_map<string,int>mp)
    {
        //base case
        if(i>=n) return temp.length();

        if(mp.find(temp)!=mp.end()) return mp[temp];
        int in=0;int ex=0;
        if(isDup(nums[i],temp))
        {
            ex = helper(i+1,n,temp,nums,mp);
        }
        else{
            ex = helper(i+1,n,temp,nums,mp);
            in = helper(i+1,n,temp+nums[i],nums,mp);
        }

        return mp[temp]= max(in,ex);
    }
public:
    int maxLength(vector<string>& arr) {
        unordered_map<string,int>mp;
        string temp="";
        int n=arr.size();
        return helper(0,n,temp,arr,mp);
    }
};