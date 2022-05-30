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
	stats sum_rez1, sum_rez2;

	for (int cur_n = 1000; cur_n <= 10000; cur_n += 1000)
	{
		vector<int> m1(cur_n);
		vector<int> m2(cur_n);

		sum_rez1.comparison_count = 0;
		sum_rez1.copy_count = 0;

		sum_rez2.comparison_count = 0;
		sum_rez2.copy_count = 0;

		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < cur_n; i++)
			{
				m1[i] = rand();
				m2[i] = m1[i];
			}

			stats rez1 = ins_sort(m1);
			sum_rez1.comparison_count += rez1.comparison_count;
			sum_rez1.copy_count += rez1.copy_count;

			stats rez2 = shell_sort(m2);
			//cout << rez2.comparison_count << " " << rez2.comparison_count << endl;
			sum_rez2.comparison_count += rez2.comparison_count;
			sum_rez2.copy_count += rez2.copy_count;
		}

		cout << cur_n << endl;
		cout << "ins_sort(m1)" << endl;
		cout << "\t" << sum_rez1.comparison_count / 10.0f << endl;
		cout << "\t" << sum_rez1.copy_count / 10.0f << endl;

		cout << "shell_sort(m2)" << endl;
		cout << "\t" << sum_rez2.comparison_count / 10.0f << endl;
		cout << "\t" << sum_rez2.copy_count / 10.0f << endl;
	}
	
	////vector<int> m = { 1, 1, 7, 3, 5, 4, 3, 4, 6, 9 };
	////vector<int> m = {0, 1,2,3,4,5,6,7,8,9 };
	////vector<int> m = {9, 8, 7 ,6, 5, 4, 3, 2, 1 , 0 };
	//int t1, t2;

	//vector<int> m(100000);

	////int n = 100000;

	////int* m = new int [n];



	//for (int i = 0; i < m.size(); i++) m[i] = rand();

	//t1 = clock();

	////stats rez = ins_sort(m);	
	//  //stats rez = shell_sort_arr(m, n);
	//
}

