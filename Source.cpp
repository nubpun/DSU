#include <iostream>
#include <vector>
using namespace std;
const int N = 6;

vector<int> parent;
int find_parent(int v)
{
	if (v == parent[v])
		return v;
	return parent[v] = find_parent(parent[v]);
}
void make_set(int v)
{
	parent[v] = v;
}
void union_sets(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);
	if (rand() % 2 == 0)
		parent[a] = b;
	else
		parent[b] = a;	
}
bool find(int a, int b)
{
	return find_parent(a) == find_parent(b);
}
int main()
{
	parent.resize(N, -1);
	for (int i = 0; i < N; i++)
		make_set(i);

	union_sets(0, 1);
	union_sets(0, 2);

	cout << find(1, 2);
	return 0;
}