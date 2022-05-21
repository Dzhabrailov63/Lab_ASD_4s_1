#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

template<typename T>
void my_swap(T& a, T& b)
{
	T t = a;
	a = b;
	b = t;
}

struct stats
{
	size_t comparison_count = 0;
	size_t copy_count = 0;
};

bool cmp_el(int a, int b, size_t& x)
{
	++x;
	return a > b;
}


stats ins_sort(vector<int>& m)
{
	stats rez;

	for (int i = 1; i < m.size(); i++)
	{
		int k = i;

		while (k != 0 && cmp_el(m[k - 1], m[k], rez.comparison_count))
		{
			my_swap(m[k - 1], m[k]);
			--k;

			rez.copy_count++;
		}
	}

	return rez;
}
stats shell_sort(vector<int>& m)
{
	stats rez;
	int d = m.size() / 2;

	while (d != 0)
	{
		for (int i = d; i < m.size(); i++)
		{
			int k = i;

			while (k >= d && cmp_el(m[k - d], m[k], rez.comparison_count))
			{
				my_swap(m[k - d], m[k]);
				k -= d;

				rez.copy_count++;
			}
		}

		d /= 2;
	}

	return rez;
}



stats shell_sort_arr(int* m, int n)
{
	stats rez;
	int d = n / 2;

	while (d != 0)
	{
		for (int i = d; i < n; i++)
		{
			int k = i;

			while (k >= d && cmp_el(m[k - d], m[k], rez.comparison_count))
			{
				my_swap(m[k - d], m[k]);
				k -= d;

				rez.copy_count++;
			}
		}

		d /= 2;
	}

	return rez;
}

int main()
{
	//vector<int> m = { 1, 1, 7, 3, 5, 4, 3, 4, 6, 9 };
	//vector<int> m = {0, 1,2,3,4,5,6,7,8,9 };
	//vector<int> m = {9, 8, 7 ,6, 5, 4, 3, 2, 1 , 0 };
	int t1, t2;

	vector<int> m(100000);

	//int n = 100000;

	//int* m = new int [n];



	for (int i = 0; i < m.size(); i++) m[i] = rand();

	t1 = clock();

	//stats rez = ins_sort(m);	
	  //stats rez = shell_sort_arr(m, n);

	sort(m.begin(), m.end());
	t2 = clock();

	cout << t2 - t1 << endl;

	//for (int x : m) cout << x << " ";
	//cout << endl << endl;

	//cout << rez.comparison_count << endl;
	//cout << rez.copy_count       << endl;
}

