#ifdef ONLINE_JUDGE
    #include<bits/stdc++.h>
    using namespace std;
    #define debug(...) 42
#else
    #include "cp_debug.h"
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

bool contains(initializer_list<int> ls, int item){
    for(auto list_item: ls){
        if(list_item == item)
            return 1;
    }
    return 0;
}

struct rec{
    int d,m,y,c;

    bool is_year_leap(){
        return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
    }

    bool is_before(const rec& another){
        if(this->y != another.y) {
            if(this->d == 31 && this->m == 12 && another.d == 1 && another.m == 1)
                return 1;
            return 0;
        }
        else if(this->m != another.m){
            if(this->d >= 28){
                if(this->d == 28 && this->m == 2 && !is_year_leap() && another.d == 1 && another.m == 3){
                    return 1;
                }
                else if(this->d == 29 && this->m == 2 && is_year_leap() && another.d == 1 && another.m == 3){
                    return 1;
                }
                else if(this->d == 30 && contains({4,6,9,11}, this->m) && another.d == 1 && another.m == this->m + 1){
                    return 1;
                } 
                else if(this->d == 31 && contains({1,3,5,7,8,10,12}, this->m) && another.d == 1 && another.m == this->m + 1){
                    return 1;
                } 
                
            }
            return 0;
        }
        return this->d < another.d;
    }
};

string  pr(rec item){
    stringstream sss;
    sss<<"{"<<item.d<<' '<<item.m<<' '<<item.y<<' '<<item.c<<' '<<"}";
    return sss.str();
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin>>n && n!= 0){
        int total_c = 0, days = 0;
        rec prev,next;
        cin>>prev.d>>prev.m>>prev.y>>prev.c;
        for(int i=1; i<n; ++i){
            cin>>next.d>>next.m>>next.y>>next.c;
            if(prev.is_before(next))
                total_c += next.c - prev.c, ++days;
            prev = next;
        }
        cout<<days<<' '<<total_c<<'\n';
    }
}
