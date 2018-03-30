#include <iostream>
#include <sstream>
#include <utility>
#include "stdafx.h"
using namespace std;

void sort(float* st, int n, int left, int right) {
	int L = left;
	int M = L;
	int R = right;
	while (L <= R) {
		while (st[L] < st[M] && L < right)
			L++;
		while (st[R] > st[M] && R > left)
			R--;
		if (L <= R) {
			swap(st[L], st[R]);
			L++;
			R--;

		}
	}
	if (L < right) sort(st, n, L, right);
	if (R > left) sort(st, n, left, R);
}

void print_st(float *st, int n) {
	for (unsigned int i = 0; i < n; i++) {
		cout << st[i] << " ";
	}
}

bool str(float *st, int n)
{
	bool h = true;
	string t;
	getline(cin, t);
	istringstream stream(t);
	for (unsigned int i = 0; i<n; i++)
	{
		if (!(stream >> st[i]))
		{
			h = false;
			return false;
		}
	}
	return true;
}

int main() {

	int n, left, right;
	if (!(cin >> n)) {
		cout << "An error has occured while reading numbers from line";
		return -1;
	}
	cin.get();
	float *st = new float[n];
	if (str(st, n)) {
		sort(st, n, 0, n - 1);
		print_st(st, n);
	}
	else {
		cout << "An error has occured while reading numbers from line";
	}
	delete[] st;
	return 0;
}
