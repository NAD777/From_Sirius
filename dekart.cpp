#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <iomanip>


#define F first
#define S second

using namespace std;

const int N = 1e5;


struct  Node {
	int sum, x, y;
	Node * l, * r;
	Node (int key) {
		x = sum = key;
		y = rand();
		l = r = nullptr;
	}
	Node (Node * root) {
		sum = root->sum;
		x = root->x;
		y = root->y;
		l = root->l;
		r = root->r;
	}
};

#define pNN pair <Node *, Node *>

int get_sum(Node * root) {
	return (root ? root->sum : 0);
}

void recalc(Node * root) {
	if (root == nullptr) {
		return;
	}
	root->sum = root->x + get_sum(root->l) + get_sum(root->r); 
}

pNN split(Node * root, int key) {
	if (root == nullptr) {
		return make_pair(nullptr, nullptr);
	}
	if (root->x > key) {
		Node * R = new Node(root);
		pNN res = split(root->l, key);
		R->l = res.S;
		Node *  L = res.F;
		recalc(L);
		recalc(R);
		return make_pair(L, R);
	} else {
		Node * L = new Node(root);
		pNN res = split(root->r, key);
		L->r = res.F;
		Node * R = res.S;
		recalc(L);
		recalc(R);
		return make_pair(L, R);
	}
}

Node * merge(Node * L, Node * R) {
	if (L == nullptr) {
		return R;
	}
	if (R == nullptr) {
		return L;
	}
	if (R->y > L->y) {
		Node * root = new Node(R);
		root->l = merge(L, root->l);
		recalc(root);
		return root;
	} else {
		Node * root = new Node(L);
		root->r = merge(root->r, R);
		recalc(root);
		return root;
	}
}

Node * add(Node * root, int key) {
	Node * new_root = new Node (key);
	pNN res = split(root, key);
	return merge(res.F, merge(new_root, res.S));
}

Node * del(Node * root, int key) {
	pNN res = split(root, key);
	pNN res1 = split(res.F, key - 1);
	return merge(res1.F, res.S);
}

int query(Node * root, int l, int r) {
	pNN res = split(root, r);
	pNN res1 = split(res.F, l - 1);
	return get_sum(res1.S);
}


signed main(){

	return 0;
}

