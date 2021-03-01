#include<bits/stdc++.h>


using namespace std;


int parse_table[6][6] =      {{0,-1,-1,0,-1,-1},
                     {-1,1,-1,-1,2,2},
                     {3,-1,-1,3,-1,-1},
                     {-1,5,4,-1,5,5},
                     {6,-1,-1,7,-1,-1}};
stack <char> s;
vector<string> rules;
string t="EXTYF";
string non_terminal = "i+*()$";
string production_rules[] ={"ETX","X+TX","XZ","TFY","Y+FY","YZ","Fi","F(E)"};



bool isAccepted(string str){
    for(int i=0;;){
        if(s.top() == char(str[i]) && str[i] == '$') return true;
        else if(s.top()== char(str[i]))
        {   //cout<<s.top()<<"\n";
            s.pop();
            i++;
        }
        else{
            int x = t.find(s.top());
            
            int rn = pt[x][non_terminal.find(str[i])];
            if(rn == -1)
            return false;
            else{
                string p = production_rules[rn];
                rules.push_back(p);
                s.pop();
                if(p[1] != 'Z')
                for(int j = p.length()-1;j>0;j--)
                s.push(p[j]);
            }
        }
    }
}

int main(){
        s.push('$');
        s.push(production_rules[0][0]);
        cout<<"*************************************************"<<"\n";
        cout<<"Enter Input:"<<"\n";
        string s; cin>>s;

        if(isAccepted(s+'$'))
        {
            cout<<"ACCEPTED"<<"\n"<<"steps:"<<"\n";
            cout<<"*************************************************"<<"\n";
            for(int i = 0; i<rules.size(); i++)
            {
                string str = rules[i];
                cout<<i<<". ";
                cout<<str[0]<<"->"<<str.substr(1)<<"\n";
            }
        }
        else 
        cout<<"Reject"<<"\n";
}

