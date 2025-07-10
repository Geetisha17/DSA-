class Solution {
    vector<int> lfe(vector<int>&arr)
    {
        stack<int>st;
        vector<int>ans(arr.size());
        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();

            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> rfe(vector<int>&arr)
    {
        stack<int>st;
        vector<int>ans(arr.size());

        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            
                st.pop();
            
            if(st.empty()) ans[i]=arr.size();
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>a = lfe(arr);
        vector<int>b = rfe(arr);

        long long sum=0;int mod=1e9+7;
        for(int i=0;i<arr.size();i++)
        {
            long long left = i - a[i];   
            long long right = b[i] - i;
            sum = (sum + (left * right % mod) * (arr[i] % mod) % mod) % mod;
        }
        return sum%mod;
    }
};