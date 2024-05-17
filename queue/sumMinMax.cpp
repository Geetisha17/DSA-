#include <algorithm>
#include <iostream>
#include<stack>
#include <vector>
#include<queue>
using namespace std;

int solve(int *arr,int n,int k)
{
    deque<int>maxi(k);
    deque<int>mini(k);

    for(int i=0;i<k;i++){
        
        while(!maxi.empty() && arr[maxi.front()] <= arr[i])
        maxi.pop_back();

        while(!mini.empty() && arr[mini.front()] >= arr[i])
        mini.pop_back();

        mini.push_back(i);
        maxi.push_back(i);
    }

    int ans=0;
    for(int i=k;i<n;i++){

        ans += arr[maxi.front()] + arr[mini.front()];

        while(i-maxi.front() >= k)
        maxi.pop_front();

        while(i-mini.front() >= k)
        mini.pop_front();

        while(!maxi.empty() && arr[maxi.front()] <= arr[i])
        maxi.pop_back();

        while(!mini.empty() && arr[mini.front()] >= arr[i])
        mini.pop_back();

        mini.push_back(i);
        maxi.push_back(i);
    }
    ans += arr[maxi.front()] + arr[mini.front()];
    return ans;
}

int main()
{
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;


    return 0;
}