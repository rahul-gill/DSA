#include<bits/stdc++.h>
using namespace std;


unordered_set<string> lss1 =   {"1","2","3","5","7"};
unordered_set<string> lss2 =   {"11","13","17","23","31","37","53","71","73"};
unordered_set<string> lss3 =   {"113", "131", "137", "173", "311", "317"};

int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        string s;
        cin>>s;

        bool done1, done2, done3;
        string later_res1, later_res2;
        for(int i=0; i<s.size(); i++){
            cout<<"on i="<<i<<": ";////////////////
            if(lss1.find(string() + s[i]) == lss1.end()){
                if(s[i] != '1'){    
                    cout<<"1\n"<<s[i]<<'\n';
                    done1 = true;
                    cout<<"fors true"<<'\n';
                    break;
                }
            }else if(!done2 && i<s.size()-1 &&  lss2.find(s.substr(i,2)) == lss2.end()){
                cout<<"seoncd true\n";
                later_res1 =  s.substr(i,2) ;
                done2 = true;
            }else if(!done2 && !done3 && i<s.size()-2 &&  lss3.find(s.substr(i,3)) == lss3.end()){
                later_res2 =  s.substr(i,3);
                done3 = true;
            }
        }
        if(!done1){
            if(done2){
                cout<<"2\n"<<later_res1<<'\n';
            }else{
                cout<<"3\n"<<later_res2<<'\n';
            }
        }

        /*
         	2, 3, 5, 7, 
            11, 13, 17, 23, 31, 37, 53, 71, 73,
            113, 131, 137, 173, 311, 317,
        */

    }
}
