#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<iterator>
#include <numeric>

using namespace std;


/* Теория */

//template<typename it>
//void PrintRange(it Begin, it End) {
//    for (auto i = Begin; i != End; i++)
//        cout << *i << ' ';
//    cout << endl;
//}
//
//int main()
//{
//    //vector <int> num = { 1,6,-4,13,-19 };
//
//    //auto it = partition(begin(num), end(num), [](const int tmp) { // функция перебрасывает в начало контейнера элементы
//    //    return tmp < 0;                                           // которые удовлетворяют условию
//    //    });                                                       // итератор указывает на первый элемент, который не удовлетворяет условию
//    //PrintRange(begin(num), end(num));
//
//    
//
//
//
//
//
//    return 0;
//}
//

/* ДЗ_1 */

//template <typename T>
//void RemoveDuplicates(vector<T>& elements);
//
//int main() {
//    vector<int> v1 = { 6, 4, 7, 6, 4, 4, 0, 1 };
//    RemoveDuplicates(v1);
//    for (int x : v1) {
//        cout << x << " ";
//    }
//    cout << endl;
//
//    vector<string> v2 = { "C", "C++", "C++", "C", "C++" };
//    RemoveDuplicates(v2);
//    for (const string& s : v2) {
//        cout << s << " ";
//    }
//    cout << endl;
//    return 0;
//}
//
//template <typename T>
//void RemoveDuplicates(vector<T>& elements) {
//    sort(begin(elements), end(elements));
//    auto it = unique(begin(elements), end(elements));
//    elements.erase(it, elements.end());
//}



/* ДЗ_2 */

//template<class T>
//void PrintRange(vector<T> v) {
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i] << ' ';
//	}
//	cout << endl;
//}
//
//void Kombination(size_t a) {
//	vector<int> tmp(a);
//	for (int i = 0; i < a; i++) {
//		tmp[i] = i + 1;
//	}
//	sort(rbegin(tmp), rend(tmp));
//
//	do  {
//		PrintRange(tmp);
//	} while (prev_permutation(tmp.begin(), tmp.end()));
//}
//
//int main() {
//	size_t N;
//	cin >> N;
//	Kombination(N);
//
//	return 0;
//}



/* ДЗ_3 */

enum class Gender {
    FEMALE,
    MALE
};

struct Person {
    int age;  // возраст
    Gender gender;  // пол
    bool is_employed;  // имеет ли работу
};



template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
    if (range_begin == range_end) {
        return 0;
    }
    vector<typename InputIt::value_type> range_copy(range_begin, range_end);
    auto middle = begin(range_copy) + range_copy.size() / 2;
    nth_element(
        begin(range_copy), middle, end(range_copy),
        [](const Person& lhs, const Person& rhs) {
            return lhs.age < rhs.age;
        }
    );
    return middle->age;
}

void PrintStats(vector<Person> persons) {

    if (persons.begin() == persons.end()) return;

    cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl; // возвращаем ф от всех людей

    auto it = partition(persons.begin(), persons.end(), [](const Person& element) { // от женщин
        return (element.gender == Gender::FEMALE);
        });
    cout << "Median age for females = " << ComputeMedianAge(persons.begin(), it) << endl;

    auto it2 = partition(persons.begin(), persons.end(), [](const Person& element) { // от мужчин
        return (element.gender == Gender::MALE);
        });
    cout << "Median age for males = " << ComputeMedianAge(persons.begin(), it2) << endl;

    auto it3 = partition(persons.begin(), persons.end(), [](const Person& element) { // от занятых женщин
        return (element.gender == Gender::FEMALE) && (element.is_employed == true);
        });
    cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), it3) << endl;

    auto it4 = partition(persons.begin(), persons.end(), [](const Person& element) { // от безработынх женщин
        return ((element.gender == Gender::FEMALE) && (element.is_employed == false));
        });
    cout << "Median age for unemployed females = " << ComputeMedianAge(persons.begin(), it4) << endl;

    auto it5 = partition(persons.begin(), persons.end(), [](const Person& element) { // от занятых мужчин
        return (element.gender == Gender::MALE) && (element.is_employed == true);
        });
    cout << "Median age for employed males = " << ComputeMedianAge(persons.begin(), it5) << endl;

    auto it6 = partition(persons.begin(), persons.end(), [](const Person& element) { // от безработынх мужчин
        return (element.gender == Gender::MALE) && (element.is_employed == false);
        });
    cout << "Median age for unemployed males = " << ComputeMedianAge(persons.begin(), it6) << endl;
}

int main() {
    vector<Person> persons = {
        {31, Gender::MALE, false},
        {40, Gender::FEMALE, true},
        {24, Gender::MALE, true},
        {20, Gender::FEMALE, true},
        {80, Gender::FEMALE, false},
        {78, Gender::MALE, false},
        {10, Gender::FEMALE, false},
        {55, Gender::MALE, true},
    };
    PrintStats(persons);
    return 0;
}
