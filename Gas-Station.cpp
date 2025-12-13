1class Solution {
2public:
3    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
4        int n=gas.size();
5        int tolGas=0;
6        int tolCost=0;
7        bool flag=false;int idx=-1;
8
9        for(int i=0;i<n;i++)
10        {
11            if(gas[i]-cost[i]<0 && tolGas< abs(gas[i]-cost[i]))
12            {
13                tolCost+=(gas[i]-cost[i])+tolGas;
14                flag=false;tolGas=0;
15            }
16            else
17            {
18                tolGas += (gas[i]-cost[i]);
19                if(!flag)
20                {
21                    idx=i;flag=true;
22                }
23            }
24        }
25
26        if(tolGas >= abs(tolCost)) return idx;
27        return -1;
28    }
29};