#include<bits/stdc++.h>
using namespace std;

int main()
{  
    string input,output1,output2,temp;
    int sizes[10] = {};
    char c;
    int n,j,l;
    cout<<"Enter the Parent Non-Terminal : ";
    cin>>c;
    input.push_back(c);
    output1 += input + "\'->";
    input += "->";
    output2+=input;
    cout<<"Enter the number of productions : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {   cout<<"Enter Production "<<i+1<<" : ";
        cin>>temp;
        sizes[i] = temp.size();
        input+=temp;
        if(i!=n-1)
            input += "|";
    }
    cout<<"Production Rule : "<<input<<endl;
    for(int i=0,k=3;i<n;i++)
    {
        if(input[0] == input[k])
        {
            cout<<"Production "<<i+1<<" has left recursion."<<endl;
            if(input[k] != '#')
            {
                for(l=k+1;l<k+sizes[i];l++)
                    output1.push_back(input[l]);
                k=l+1;
                output1.push_back(input[0]);
                output1 += "\'|";
            }
        }
        else
        {
            cout<<"Production "<<i+1<<" does not have left recursion."<<endl;
            if(input[k] != '#')
            {
                for(j=k;j<k+sizes[i];j++)
                    output2.push_back(input[j]);
                k=j+1;
                output2.push_back(input[0]);
                output2 += "\'|";
            }
            else
            {
                output2.push_back(input[0]);
                output2 += "\'";
            }}}
    output1 += "#";
    cout<<output2<<endl;
    cout<<output1<<endl;
    return 0;}