#ifndef __UNIONFIND__
#define __UNIONFIND__

#include<iostream>
#include<vector>
using namespace std;

class UnionFind
{
public:
    UnionFind()
    {
        _setbit.resize();
    }
    
    int FindRoot(int x)
    {
        while(_setbit[x] >= 0)
        {
            x = _setbit[x];
        }

        return x;
    }

    void Union(int x,int y)
    {
        int Root1 = FindRoot(x);
        int Root2 = FindRoot(y);

        if(Root1 != Root2)
        {
            _setbit[Root1] += _setbit[Root2];
            _setbit[Root2] = Root1;
        }
    }

    int Size()
    {
        int count = 0;
        for(int i =0;i < _setbit.size();++i)
        {
            if(_setbit[i] > 0)
                ++count;
        }
        return count;
    }
private:
    vector<int> _setbit;
}

int Friend(int n,int m,int r[][])
{
    UnionFind un;
    const n = 5;
    int m = 3;
    int r[n][3] = {{1,2},{2,3},{4,5}};
    un.Union(n,m)
}
#endif
