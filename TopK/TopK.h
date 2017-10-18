#pragma once

#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;


void AdjustDown(vector<int>& heap, int root)
{
	int parent = root;
	int child = (parent * 2) + 1;

	while (child < heap.size())
	{
		if (child + 1 < heap.size() && heap[child + 1] < heap[child])
			++child;

		if (heap[child] < heap[parent])
		{
			swap(heap[child], heap[parent]);
			parent = child;
			child = (parent * 2) + 1;
		}
		else
			break;
	}
}

void TopK(const vector<int>& v, size_t k)
{
	assert(k < v.size());
	vector<int> topk;
	topk.reserve(k);

	for (int i = 0; i < k; i++)
	{
		topk.push_back(v[i]);//����reserveֻ���ٿռ�size��û�����󣬲���ʹ��[]
	}
	//����С�� K*lg(K)
	for (int i = ((k - 2) >> 1); i >= 0; --i)
	{
		AdjustDown(topk, i);
	}
	
	//(N-K)*lg(K)
	for (size_t i = k; i < v.size(); ++i)
	{
		if (topk[0] < v[i])
		{
			topk[0] = v[i];
			AdjustDown(topk, 0);
		}
	}

	for (size_t i = 0; i < topk.size(); i++)
	{
		cout << topk[i] << " ";
	}
}