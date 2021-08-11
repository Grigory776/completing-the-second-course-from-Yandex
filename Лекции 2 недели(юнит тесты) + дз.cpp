// Лекции 2 недели(юнит тесты) + дз.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//#include <iostream>
//#include<cassert>
//
//using namespace std;
//
///* юнит-тесты */
//
//int sum(int a, int b) {
//    return a+b;
//}
//void testsum() {
//    assert(sum(3, 5) == 8);
//    assert(sum(2, 0) == 2);
//    cout << "Ok" << endl;
//}
//
//int main()
//{
//    testsum();
//
//    return 0;
//}

/*Фреймворк юнит-тестов*/
#include<iostream>
#include<cassert>
#include<exception>
#include<sstream>

using namespace std;

template<typename T, typename U>
void AssertEqual(const T& t, const U& u, const string& hint) { //Шаблоная функция сравнения двух переменных, hint - уникальная информация о сравнении
	if (t != u) {
		ostringstream os;
		os << "Assertion failed: " << t << " != " << u << " Hint: " << hint;
		throw runtime_error(os.str());
	}
}

int sum(int a, int b) {
	return a + b;
}

int main() {
	/*setlocale(LC_ALL, "rus");
	AssertEqual(sum(2, 2), 4, "Проверка функции суммы");*/


	cerr << "Hi" << endl;
	cout << "Hello " << endl;

	return 0;
}




