/*Дана последовательность целых чисел a1...an и натуральное число k, такое что для любых i, j: если j >= i + k, то a[i] <= a[j].
Требуется отсортировать последовательность. 
Последовательность может быть очень длинной. 
Время работы O(n * log(k)). Доп. память O(k). Использовать слияние.*/
/*Рассмотрим a[0] a[k] a[2*k] .... a[s1*k],s*k<=n   где s максимальное что s*k<=n
             a[1] a[1+k].....      a[1+s2*k],1+s*k<=n ...
              a[i] a[i+k] . .. .a[i+k*]
             a[k-1] . ....        a[k-1+t*k],k-1+s2*k<=n 
             унас K осортированных массивов ,воспользуемся k путевым слиянием  */
#include<iostream>
#include<vector>

using std::vector;
using std::swap;
using std::cin;
class S {
public:
	int key;
	int index;

};
void  SiftDown(S a, vector<S>&heap,int size)
{
	int p = 0, t = 0;
	heap[0].key = a.key;
	heap[0].index = a.index;
	while ((t == 0) && (2 * p + 1 < size))
	{
		if (2 * p + 2 < size)
		{
			if (heap[2 * p + 1].key > heap[2 * p + 2].key)
			{
				if (heap[p].key > heap[2 * p + 2].key)
				{
					swap(heap[p], heap[2 * p + 2]);
					p = 2 * p + 2;
				}
				else
					t = 1;
			}
			else
			{
				if (heap[p].key > heap[2 * p + 1].key)
				{
					swap(heap[p], heap[2 * p + 1]);
					p = 2 * p + 1;
				}
				else
					t = 1;
			}

		}
		else

			if (heap[p].key > heap[2 * p + 1].key)
			{
				swap(heap[p], heap[2 * p + 1]);
				p = 2 * p + 1;
			}
			else
				t = 1;
	}


}
void buildheap(vector<S>&heap, S a,int &size)
{
	int p = size;
	heap[size].key= a.key;
	heap[size].index = a.index;
	int t = 0;
	while ((t == 0)&&(p>0))
	{
		if (heap[(p - 1) / 2].key > a.key)
		{
			swap(heap[p], heap[(p - 1) / 2]);
			p = (p - 1) / 2;
		}
		else
			t = 1;

	}
	++size;
}
void Sort(vector<S>&heap, vector<S>a,int &size,int k)
{
	int t = size;
	int l = k;
	while (t > 0)
	{
		std::cout << heap[0].key << " ";
		if (heap[0].index + k < size)
		{
			SiftDown(a[heap[0].index + k], heap, l);
		}
		else
		{
			SiftDown(heap[l - 1], heap, l-1);
			--l;

		}
		t--;

	}

}
int main()
{
	int n, k;
	cin >> n >> k;
	vector<S>a(n);
	vector<S>heap(k);
	int size = 0, b;
	for (int i = 0; i < n; ++i)
	{
		cin >> b;
		a[i].key = b;
		a[i].index = i;
		if (i < k)
		{
			buildheap(heap, a[i], size);
		}

	}
	Sort(heap, a, n, k);
	return 0;
}
