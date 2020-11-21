#include <bits/stdc++.h>
using namespace std;


struct Mo {
    using F = function<void(int,int&)>;

    struct Query { 
        int left, right;
        Query(int left_, int right_) : left(left_), right(right_) {}
    };

    private:
    vector<Query> queries;
    vector<int> order;
    int width, nl, nr;
    F ExpandL, ExpandR, ShrinkL, ShrinkR;
    vector<int> ans;
    int value = 0;

    const function<bool(int,int)> 
    compare_order = [&](int i, int j) {
        if(queries[i].left/width != queries[j].left/width) return queries[i].left < queries[j].left;
        else if((queries[i].right/width) & 1) return queries[i].right > queries[j].right;
        else return queries[i].right < queries[j].right;
    };

    public:
    Mo(int n_, F ExpandL_, F ExpandR_, F ShrinkL_, F ShrinkR_) : 
        width(sqrt(n_)), nl(0), nr(0), 
        ExpandL(ExpandL_), ExpandR(ExpandR_), ShrinkL(ShrinkL_), ShrinkR(ShrinkR_) {}
    Mo(int n_, F Expand_, F Shrink_) : Mo(n_, Expand_, Expand_, Shrink_, Shrink_) {}

    int operator[] (int i) { return ans[i]; }

    //[l,r) ]
    void AddQuery(int l, int r){ queries.push_back(Query(l,r)); }

    //(N√N)
    void Build(){
        order.resize(queries.size());
        ans.assign(queries.size(), 0);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(),order.end(), compare_order);
        for(int id : order) Process(id);
    }

    void Process(int id){
        while(nl > queries[id].left) ExpandL(--nl, value);
        while(nr < queries[id].right) ExpandR(nr++, value);
        while(nl < queries[id].left) ShrinkL(nl++, value);
        while(nr > queries[id].right) ShrinkR(--nr, value);
        ans[id] = value;
    }

};
auto Expand = [&](int i, int &v) {};
auto Shrink = [&](int i, int &v) {};



int n,q;

int main(){



    struct Query { int left, right; };

    int ans[q];
    vector<Query> queries(q);
    vector<int> order(n);
    int width, nl, nr, value;

    width = sqrt(n);
    nl = nr = value = 0;

    auto Expand = [&](int i) {};
    auto Shrink = [&](int i) {};

    auto compare_order = [&](int i, int j) {
        if(queries[i].left/width != queries[j].left/width) return queries[i].left < queries[j].left;
        else if((queries[i].right/width) & 1) return queries[i].right > queries[j].right;
        else return queries[i].right < queries[j].right;
    };

    iota(order.begin(), order.end(), 0);
    sort(order.begin(),order.end(), compare_order);
    for(int id : order){
        while(nl > queries[id].left) Expand(--nl);
        while(nr < queries[id].right) Expand(nr++);
        while(nl < queries[id].left) Shrink(nl++);
        while(nr > queries[id].right) Shrink(--nr);
        ans[id] = value;
    }



    return 0;
}