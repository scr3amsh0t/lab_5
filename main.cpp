#include <fstream>
#include <iostream>

using namespace std;

template<class T> // ��������� ������
T* init_arr(const int &size) // ������������� ������� � ����������
{
	T* arr = new T[size];
	for (int i = 0; i < size; ++i)
	{
		cout << i + 1 << " �������: ";
		cin >> arr[i];
	}
	return arr;
}

template<class T>
T rand_num(T bounds[]) // ���������� ��������� T � �������� �� bounds[0] �� bounds[1]
{
	return bounds[0] + (T)rand() / ((T)RAND_MAX / (T)(bounds[1] - bounds[0]));
}

template<class T>
T* init_arr_rand(const int& size, T bounds[])  // ������������� ������� �������� size ���������� T � �������� �� bounds[0] �� bounds[1]
{
	T* arr = new T[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = rand_num<T>(bounds);
	}
	return arr;
}

template<class T> // ���������� �������� T, ������� �� ��������� n, � arr �������� _size
int* no_more_than_n_indexes(int& size_, T* arr, const int& size, T n)
{
	int* arr_ = new int[size];
	size_ = 0;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] <= n)
		{
			arr_[size_++] = i;
		}
	}
	return arr_;
}

int* no_more_than_n_indexes(int& size_, char* arr, const int& size, char n) // ���� ������������� ������� ���������� �������� char
{
	cout << "��� ������ ���� char ������� �� ������������" << endl;
	return nullptr;
}

char* init_arr_rand(const int& size, char bounds[]) // ���� ������������� ������� ������������� ������� �������� size char-��� � �������� �� bounds[0] �� bounds[1]
{
	char* arr = new char[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = bounds[0] + (rand() % (26 - ('z' - bounds[1])));
	}
	return arr;
}

template<class T>
void print_arr(const T* arr, const int& size) //������� ������ ������� �������� size �� ��������� T
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i];
		if (i != size - 1)
		{
			cout << ", ";
		}
		else {
			cout << endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "russian");
	int size1 = 2, size2 = 10, size3 = 10, size4;
	double bounds[] = { 2.4, 3.5 };
	char bounds3[] = { 'a', 'g' };
	double *arr2;
	int * arr1, *arr4;
	char* arr3;

	// �������� ������ ������������� ������� ����� ����� �� ���� int
	arr1 = init_arr<int>(size1);
	print_arr(arr1, size1);
	cout << endl;

	// �������� ������ ������������� ������� ���������� ���������� �� ���� double
	arr2 = init_arr_rand(size2, bounds);
	print_arr(arr2, size2);

	// �������� ������ ���������� �������� ��������� �� ����������� n �� ���� double
	double n;
	cout << "������� n ���� double: ";
	cin >> n;
	arr4 = no_more_than_n_indexes(size4, arr2, size2, n);
	print_arr(arr4, size4);
	cout << endl;

	// �������� ���� �������������� ������ ������������� ������� ���������� ���������� �� ���� char
	arr3 = init_arr_rand(size2, bounds3);
	print_arr(arr3, size3);

	// �������� ���� �������������� ������ ���������� �������� ��������� �� ����������� n �� ���� double
	char ch;
	cout << "������� n ���� char: ";
	cin >> ch;
	arr4 = no_more_than_n_indexes(size4, arr3, size3, ch);

	return 0;
}