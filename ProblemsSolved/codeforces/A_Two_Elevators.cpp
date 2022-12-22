#ifdef ONLINE_JUDGE
    #include<bits/stdc++.h>
    using namespace std;
#else
    #include<cp_debug.h>
#endif

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int x = a-1, y = ((b > c) ? b-1 : 2*c-b-1);
        if(x < y)
            cout<<"1\n";
        else if(x > y)
            cout<<"2\n";
        else
            cout<<"3\n";
    }
}

