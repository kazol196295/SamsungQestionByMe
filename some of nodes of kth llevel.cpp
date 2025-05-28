#include <bits/stdc++.h>
using namespace std;
int level=-1,sum=0;
void sum_(int k,string& s);
int main()
{
    string s;
    int k;
    cin >> k >> s;
    sum_( k, s);
}

void sum_(int k, string &s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')level ++;
        else if(s[i]==')')level--;
        else if(level==k)
        {
            int x=s[i]-'0';
            i++;
            while(s[i]>='0' && s[i]<='9')
            {
                int d= s[i]-'0';
                x=x*10+d;
                i++;
            }
            i--;
            sum+=x;
        }
    }
    cout << sum << endl;

}