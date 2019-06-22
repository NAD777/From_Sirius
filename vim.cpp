#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <iomanip>

using namespace std;

const int N = 1e5;
int a[N];

struct Tree {
	int sum;
	int l, r;
	Tree * left, * right;
	Tree (int sum, int l, int r) {
		this->sum = sum;
		this->l = l;
		this->r = r;
		left = right = nullptr;
	}
};

Tree * ver[N];

Tree * build(int L, int R) {
	Tree * node = new Tree(0, L, R);
	if (R == L + 1) {
		node->sum = a[L];
		return node;
	}
	int M = (R + L) / 2;
	node->left = build(L, M);
	node->right = build(M, R);
	node->sum = node->left->sum + node->right->sum;
	return node;
}

Tree * change(Tree * node, int ind, int x) {
	Tree * new_node = new Tree(node->sum, node->l, node->r);
	if (node->r == node->l + 1) {
		new_node->sum = x;
		return new_node;
	}
	if (node->left->r > ind) {
		new_node->right = node->right;
		new_node->left = change(node->left, ind, x);
	} else {
		new_node->left = node->left;
		new_node->right = change(node->right, ind, x);
	}
	new_node->sum = new_node->left->sum + new_node->right->sum;
	//cout << new_node->l << " " << new_node->r << " " << new_node->sum << "\n";
	return new_node;
}

int get_sum(Tree * node, int L, int R) {
	if (node->l >= R || node->r <= L) {
		return 0;
	}
	if (node->l >= L && node->r <= R) {
		return node->sum;
	}
	return get_sum(node->left, L, R) + get_sum(node->right, L, R);
}




signed main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}	
	ver[1] = build(0, n);
	int sz(1);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		char c;
		cin >> c;
		if (c == '+') {
			int num, ind, delta;
			cin >> num >> ind >> delta;
			sz++;
			ver[sz] = change(ver[num], ind - 1, delta);
		} else {
			int num, l, r;
			cin >> num >> l >> r;
			cout << get_sum(ver[num], l - 1, r) << "\n";
		}
	}
	return 0;
}

