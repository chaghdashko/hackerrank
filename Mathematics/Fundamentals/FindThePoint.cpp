#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ostream>
#include <sstream>

using namespace std;

class Point {
  public:
    int x;
    int y;
    
    Point() : x(0), y(0) {}
    
    Point(int _x, int _y) : x(_x), y(_y) {}
    
    friend ostream& operator << (ostream &out, Point &point) {
        out << point.x << " " << point.y;
        return out;
    }
};

class PointPair {
  public:
    Point p;
    Point q;
    
    PointPair() {}
    PointPair(Point _p, Point _q) : p(_p), q(_q) {}
};

vector<PointPair> readPoints() {
    int n;
    cin >> n;
    
    /* Read remaining line ending character ('cin' does not read that) */
    string line;
    getline(cin, line);
    
    vector<PointPair> pointPairs(n);
    
    for (auto i = 0; i < n; i++) {
        getline(cin, line);
        //cout << "Line: " << line << endl;
        stringstream ss(line);
        
        string token;
        vector<int> v;
        while(ss >> token) {
            v.push_back(stoi(token));
        }
        
        //for (auto j = 0; j < v.size(); j++)
        //    cout << "Inside readPoints(): " << v[j] << endl;
        
        Point p(v[0], v[1]);
        Point q(v[2], v[3]);
        PointPair pair(p, q);
        pointPairs[i] = pair;
    }
    
    return pointPairs;
}

Point reflect(PointPair pair) {
    int rx, ry;
    
    if (pair.q.x > pair.p.x) {
        rx = pair.q.x + (pair.q.x - pair.p.x);
    } else {
        rx = pair.q.x - (pair.p.x - pair.q.x);
    }
    
    if (pair.q.y > pair.p.y) {
        ry = pair.q.y + (pair.q.y - pair.p.y);
    } else {
        ry = pair.q.y - (pair.p.y - pair.q.y);
    }
    
    Point r(rx, ry);
    
    return r;
}

int main() {
    vector<PointPair> pointPairs = readPoints();
    
    for (auto i = 0; i < pointPairs.size(); i++) {
        PointPair pointPair = pointPairs[i];
        Point reflection = reflect(pointPair);
        cout << reflection << endl;
    }
    
    return 0;
}

