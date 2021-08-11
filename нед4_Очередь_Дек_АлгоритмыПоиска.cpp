// нед4_Очередь_Дек_АлгоритмыПоиска.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
//#include<deque> // библеотека дека
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <exception>

using namespace std;

//template<class T>
//void PrintRange(const T& tmp) {
//    for (int i = 0; i < tmp.size(); i++) {
//        cout << tmp[i] << ' ';
//    }
//    cout << endl;
//}
//
//int main()
//{
//    //deque<int> d = { 1,2,3,4,5 };
//    //PrintRange(d);
//
//
//    //d.push_back(6); // добавление и удаление с конца дека
//    //PrintRange(d);
//    //d.pop_back();
//    //PrintRange(d);
//
//    //cout << "=================================" << endl;
//
//    //d.push_front(0); // добавление и удаление с начала дека
//    //PrintRange(d);
//    //d.pop_front();
//    //PrintRange(d);
//
//
//    /* Алгоритмы поиска */
//
//
//    
//    return 0;
//}


/* ДЗ_1 */

//set<int>::const_iterator FindNearestElement(
//    const set<int>& numbers,
//    int border);
//// set<int>::const_iterator —
//// тип итераторов для константного множества целых чисел
//
//int main() {
//    set<int> numbers = { 1, 4, 6 };
//    cout <<
//        *FindNearestElement(numbers, 0) << " " <<
//        *FindNearestElement(numbers, 3) << " " <<
//        *FindNearestElement(numbers, 5) << " " <<
//        *FindNearestElement(numbers, 6) << " " <<
//        *FindNearestElement(numbers, 100) << endl;
//
//    set<int> empty_set;
//
//    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
//    return 0;
//}
//
//set<int>::const_iterator FindNearestElement(
//    const set<int>& numbers,
//    int border) {
//
//    if (numbers.size() == 0) return numbers.end();
//
//    auto tmp = numbers.lower_bound(border);
//
//    if (tmp == numbers.end()) return --numbers.end();
//
//    if (tmp == numbers.begin()) return numbers.begin();
//
//    if ((*tmp - border >= border - *(prev(tmp)))) return prev(tmp);
//
//    return tmp;
//}


///* ДЗ_2 */
//
////template <typename RandomIt>
////pair<RandomIt, RandomIt> FindStartsWith(
////    RandomIt range_begin, RandomIt range_end,
////    char prefix);
//
//template <typename RandomIt>
//pair<RandomIt, RandomIt> FindStartsWith(
//    RandomIt range_begin, RandomIt range_end,
//    const string& prefix);
//
//
//int main() {
//    const vector<string> sorted_strings = { "moscow", "motovilikha", "murmansk" };
//
//    const auto mo_result =
//        FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
//    for (auto it = mo_result.first; it != mo_result.second; ++it) {
//        cout << *it << " ";
//    }
//    cout << endl;
//
//    const auto mt_result =
//        FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
//    cout << (mt_result.first - begin(sorted_strings)) << " " <<
//        (mt_result.second - begin(sorted_strings)) << endl;
//
//    const auto na_result =
//        FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
//    cout << (na_result.first - begin(sorted_strings)) << " " <<
//        (na_result.second - begin(sorted_strings)) << endl;
//
//    return 0;
//}
//
////template <typename RandomIt>
////pair<RandomIt, RandomIt> FindStartsWith(
////    RandomIt range_begin, RandomIt range_end,
////    char prefix) {
////
////    string t;
////    t.push_back(prefix);
////    auto it = lower_bound(range_begin, range_end, t);
////    t[0] = t[0] + 1;
////    auto it2 = lower_bound(range_begin, range_end, t);
////
////    return { it,it2 };
////
////}
//
//
//template <typename RandomIt>
//pair<RandomIt, RandomIt> FindStartsWith(
//    RandomIt range_begin, RandomIt range_end,
//    const string& prefix) {
//
//    string tmp = prefix;
//
//    auto it = lower_bound(range_begin, range_end, tmp);
//    tmp[tmp.size() - 1] += 1;
//    auto it2 = lower_bound(range_begin, range_end, tmp);
//
//    return { it,it2 };
//}





/* ДЗ_3 */


void CraftArifmVir() {

	int x;
	cin >> x;

	size_t N;
	cin >> N;

	char command;
	int tmp;
	string res = to_string(x);

	for (int i = 0; i < N; i++) {
		cin >> command >> tmp;

		if (command == '+') {
			res.insert(res.begin(), '(');
			
			res += ") + " + to_string(tmp);
		}

		else if (command == '-') {
			res.insert(res.begin(), '(');

			res += ") - " + to_string(tmp);
		}

		else if (command == '*') {
			res.insert(res.begin(), '(');

			res += ") * " + to_string(tmp);
		}

		else if (command == '/') {
			res.insert(res.begin(), '(');

			res += ") / " + to_string(tmp);
		}

		else {
			throw invalid_argument("Nevernii znack");
		}

	}

	cout << res << endl;
}

int main() {
	CraftArifmVir();

	return 0;
}