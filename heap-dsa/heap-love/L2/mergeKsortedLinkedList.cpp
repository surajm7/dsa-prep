#include <bits/stdc++.h> 
using namespace std;

class compare{
    public:
    bool operator()(Node<int>*a,Node<int>*b){
        return a->data >b->data;
    }
};

