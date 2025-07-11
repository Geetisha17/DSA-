class Solution {
    bool helper(int n,int index,int maxi,long long mid)
    {
        long long sum=0;

        int leftLen=index;
        if(mid > leftLen)
        {
            long long first =mid-1;
            long long last =mid-leftLen;
            sum += (first+last)*leftLen/2;
        }
        else{
            long long rem = mid-1;
            sum+=(rem*(rem+1))/2;
            sum += (leftLen-rem);
        }

        int rightLen=n-index-1;

        if(mid>rightLen)
        {
            long long first = mid-1;
            long long last = mid-rightLen;
            sum += (first+last)*rightLen/2;
        }else{
            long long rem = mid-1;
            sum+=(rem*(rem+1))/2;
            sum+=(rightLen-rem);
        }
        sum+=mid;
        return (sum<=maxi);
    }
public:
    int maxValue(int n, int index, int maxSum) {
        long long l=1;
        long long h=maxSum;
        long long ans=-1;
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(helper(n,index,maxSum,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return (int)ans;
    }
};