// Неделя 1 шаблоный функций.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;


//дз "Все в квадрат!"
template<typename T>
T Sqr(const T& v);

template<typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& v);

template<typename Key, typename Val>
map<Key, Val> Sqr(const map<Key, Val>& v);

template<typename T>
vector<T> Sqr(const vector<T>& v);

int main() {
	vector<int> v = { 1, 2, 3 };
	cout << "vector:";
	for (int x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}

template<typename T>
T Sqr(const T& v) {
	return v * v;
}

template<typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& v) {
	pair<First, Second> res;
	res.first = Sqr(v.first);
	res.second = Sqr(v.second);
	return res;
}

template<typename Key, typename Val>
map<Key, Val> Sqr(const map<Key, Val>& v) {
	map<Key, Val> res = v;
	for (auto& item : res) {
		item.second = Sqr(item.second);
	}
	return res;
}

template<typename T>
vector<T> Sqr(const vector<T>& v) {
	vector<T> res = v;
	for (auto& item : res) {
		item = Sqr(item);
	}
	return res;
}



















//код из теоритического материала

//template <typename First, typename Second> // Определение оператора умножения для любой пары из элементов одного типа
//pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First, Second>& p2) {
//    First f = p1.first * p2.first;
//    Second s = p1.second * p2.second;
//    return { {f},{s} };
//}
//
//template <typename T> // данное объявление означает, что тип подбирается автоматически
//T Sqr(T x) {
//    return x * x;
//}
//
//int main()
//{
//    /* pair<int, int> p1 = { 4,7 };
//     pair<float, int> p2 = { 5.5,5 };
//     pair <float, int> res;
//
//     res = Sqr(p2);
//     cout << res.first << " " << res.second << endl;*/
//
//    cout << max(string("abc"), string("def"));
//
//    return 0;
//}
