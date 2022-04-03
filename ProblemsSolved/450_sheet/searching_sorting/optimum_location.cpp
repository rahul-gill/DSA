#include<bits/stdc++.h>
using namespace std;


/**
 * You are given a straight line on a 2D plane in the form of (ax + by + c = 0) and an array of points of the form (Xi, Yi). 
 * Your task is to find a point on the given line for which the sum of distances from this point to the given array/list of points is minimum.
 */

#define EPS 1e-6

struct Point{
    int x,y;
    Point(int x, int y): x(x), y(y) {}
};

struct Line {
    int a, b, c;
    Line(int a, int b, int c) : a(a), b(b), c(c) {}
};

double theDistance(const double& pointX, const vector<vector<int>>& points,const Line& line){
    double dist = 0;

    double pointY = -1 * (line.c + line.a * pointX) / line.b; 


    for(auto pt: points)
        dist +=  sqrt( (pointX - pt[0]) * (pointX - pt[0]) + (pointY - pt[1]) * (pointY - pt[1]) )  ;   
        // cout<< pointX << ' ' << pointY << ' ' << dist << '\n';

    return dist;
}

double optimumDistance(int a, int b, int c, vector<vector<int>> &points, int n){
    double low = -1e6, high = 1e6;
    Line line(a,b,c);

    while (high - low > EPS){

        // cout<<"High-low: " << high << ' ' << low << '\n';

        double mid1 = low + (high - low) / 3, mid2 = high - (high - low) / 3;

        double dist1 = theDistance(mid1, points, line);
        double dist2 = theDistance(mid2, points, line);

        if(dist1 < dist2)
            high = mid2;
        else 
            low = mid1;
    }

    return theDistance((low + high) / 2, points, line);
}




int main(){
    vector<vector<int>> points = {
        { -3, -2 }, { -1, 0 }, { -1, 2 }, { 1, 2 }, { 3, 4 }
    };
    cout<<optimumDistance(1,-1,-3, points, 5);
}
