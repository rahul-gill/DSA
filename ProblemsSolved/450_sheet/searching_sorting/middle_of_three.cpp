#include<bits/stdc++.h>
using namespace std;

int middle(int A, int B, int C){


    if(A>B){ //1
        if(B>C) return B; //2
        else if(A>C) return C; //3
        else return A;
    }
    else{ //1
        if(B<C) return B; //2
        else if(A<C) return C; //3
        else return A;

    }
    return -1;

}
