#include<bits/stdc++.h>
using namespace std;

#define maxN 100

class SegmentTree{
private:
    int n, segTree[4*maxN];
    inline int leftChild(int indx){ return indx<<1; }
    inline int rightChild(int indx){ return indx<<1 | 1; }

    void build(vector<int> arr, int tIndex=1, int tLeft=0, int tRight=-1) {
        if(tRight == -1) tRight = n-1;

        printf("[%d:%d] %d\n",tLeft,tRight,tIndex);
        if (tLeft == tRight) {  //in terminal node just do it
            segTree[tIndex] = arr[tLeft];
        } else {    //build the left and right child recursively and using them update the current node
            int tMid = (tLeft + tRight) / 2;
            build(arr, leftChild(tIndex), tLeft, tMid);
            build(arr, rightChild(tIndex), tMid+1, tRight);
            segTree[tIndex] = segTree[leftChild(tIndex)] + segTree[rightChild(tIndex)];
        }
    }

public:
    SegmentTree(vector<int> arr){
        n = arr.size();
        build(arr);
    }

    int sumQuery(int tIndex, int tLeft, int tRight, int qLeft, int qRight) {
        if (qLeft > qRight) 
            return 0;
        if (qLeft == tLeft && qRight == tRight) {   //tree segment same as query segment
            return segTree[tIndex];

        }
        //else just do the recursive thing
        int tMid = (tLeft + tRight) / 2;
        return sumQuery(leftChild(tIndex), tLeft, tMid, qLeft, min(qRight, tMid))
            + sumQuery(rightChild(tIndex), tMid+1, tRight, max(qLeft, tMid+1), qRight);
    }

    void updateQuery(int tIndex, int tLeft, int tRight, int arrPos, int newVal) {
        if (tLeft == tRight) {
            segTree[tIndex] = newVal;//reached to the terminal
        } else {
            int tMid = (tLeft + tRight) / 2;
            if (arrPos <= tMid)
                updateQuery(leftChild(tIndex), tLeft, tMid, arrPos, newVal);
            else
                updateQuery(rightChild(tIndex), tMid+1, tRight, arrPos, newVal);
            segTree[tIndex] = segTree[leftChild(tIndex)] + segTree[rightChild(tIndex)];
        }
    }

};
int main(){
    vector<int> arr{1,2,3,4,5,6,7,8,9};
    SegmentTree tree(arr);
    return 0;
}