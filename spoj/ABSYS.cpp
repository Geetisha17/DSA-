#include <iostream>
#include<string>
using namespace std;

bool allDigits(const std::string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    // Write C++ code here
    int t;
    cin>>t;
    
    while(t--)
    {
        string op1,ps,op2,eq,op3;
        cin>>op1>>ps>>op2>>eq>>op3;
        
        if(allDigits(op1) && allDigits(op2))
        {
            int ans = stoi(op1) + stoi(op2);
            cout<<op1<<" + "<<op2<<" = "<<to_string(ans)<<endl;
        }
        
        else if(allDigits(op1) && allDigits(op3))
        {
            int ans = stoi(op3)-stoi(op1);
            cout<<op1<<" + "<<to_string(ans)<<" = "<<op3<<endl;
        }
        
        else if(allDigits(op2) && allDigits(op3))
        {
            int ans = stoi(op3)-stoi(op2);
            cout<<to_string(ans)<<" + "<<op2<<" = "<<op3<<endl;
        }
    }
    return 0;
}