// нед2.дз.ИспользФреймворка.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

/*дз1. Квадратичная функция*/
//#include <iostream>
//#include <map>
//#include <set>
//#include <sstream>
//#include <stdexcept>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//template <class T>
//ostream& operator << (ostream& os, const vector<T>& s) {
//    os << "{";
//    bool first = true;
//    for (const auto& x : s) {
//        if (!first) {
//            os << ", ";
//        }
//        first = false;
//        os << x;
//    }
//    return os << "}";
//}
//
//template <class T>
//ostream& operator << (ostream& os, const set<T>& s) {
//    os << "{";
//    bool first = true;
//    for (const auto& x : s) {
//        if (!first) {
//            os << ", ";
//        }
//        first = false;
//        os << x;
//    }
//    return os << "}";
//}
//
//template <class K, class V>
//ostream& operator << (ostream& os, const map<K, V>& m) {
//    os << "{";
//    bool first = true;
//    for (const auto& kv : m) {
//        if (!first) {
//            os << ", ";
//        }
//        first = false;
//        os << kv.first << ": " << kv.second;
//    }
//    return os << "}";
//}
//
//template<class T, class U>
//void AssertEqual(const T& t, const U& u, const string& hint = {}) {
//    if (t != u) {
//        ostringstream os;
//        os << "Assertion failed: " << t << " != " << u;
//        if (!hint.empty()) {
//            os << " hint: " << hint;
//        }
//        throw runtime_error(os.str());
//    }
//}
//
//void Assert(bool b, const string& hint) {
//    AssertEqual(b, true, hint);
//}
//
//class TestRunner {
//public:
//    template <class TestFunc>
//    void RunTest(TestFunc func, const string& test_name) {
//        try {
//            func();
//            cerr << test_name << " OK" << endl;
//        }
//        catch (exception& e) {
//            ++fail_count;
//            cerr << test_name << " fail: " << e.what() << endl;
//        }
//        catch (...) {
//            ++fail_count;
//            cerr << "Unknown exception caught" << endl;
//        }
//    }
//
//    ~TestRunner() {
//        if (fail_count > 0) {
//            cerr << fail_count << " unit tests failed. Terminate" << endl;
//            exit(1);
//        }
//    }
//
//private:
//    int fail_count = 0;
//};
//
///*решение квадратичной функции*/
//
//int GetDistinctLinRoot(double b, double c) {
//    if (b == 0) return 0;
//    else return 1;
//}
//
//int GetDistincrKv(double a, double c) {
//    if (c == 0) return 1;
//    else {
//        if (c < 0) return 2;
//        else return 0;
//    }
//}
//
//int GetDistinctRealRootCount(double a, double b, double c) {
//    // Вы можете вставлять сюда различные реализации функции,
//    // чтобы проверить, что ваши тесты пропускают корректный код
//    // и ловят некорректный
//    if (a == 0) return GetDistinctLinRoot(b, c);
//    else {
//        if (b == 0) return GetDistincrKv(a, c);
//        else {
//            double Det = b*b - 4*a*c;
//            if (Det > 0) return 2;
//            else if (Det == 0) return 1;
//            else return 0;
//        }
//    }
//}
//
///*юнит-тесты*/
//
//void UnitTest1() {
//    AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0, "test 1.1");
//    AssertEqual(GetDistinctRealRootCount(0, 1, 0), 1, "test 1.2");
//    AssertEqual(GetDistinctRealRootCount(1, 0, 0), 1, "test 1.3");
//    AssertEqual(GetDistinctRealRootCount(1, 0, 1), 0, "test 1.4");
//    AssertEqual(GetDistinctRealRootCount(3, 1, 1), 0, "test 1.5");
//    AssertEqual(GetDistinctRealRootCount(3, 5, 1), 2, "test 1.6");
//    AssertEqual(GetDistinctRealRootCount(4, 4, 1), 1, "test 1.7");
//    AssertEqual(GetDistinctRealRootCount(-1, -1, -1), 0, "test 1.8");
//}
//
//
//int main() {
//    TestRunner runner;
//    runner.RunTest(UnitTest1, "UnitTest1");
//    // добавьте сюда свои тесты
//    return 0;
//}






/* дз2. Класс Персон*/

//#include <iostream>
//#include <map>
//#include <ostream>
//#include <random>
//#include <set>
//#include <sstream>
//#include <stdexcept>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//template <class T>
//ostream& operator<<(ostream& os, const vector<T>& s) {
//    os << "{";
//    bool first = true;
//    for (const auto& x : s) {
//        if (!first) {
//            os << ", ";
//        }
//        first = false;
//        os << x;
//    }
//    return os << "}";
//}
//
//template <class T>
//ostream& operator<<(ostream& os, const set<T>& s) {
//    os << "{";
//    bool first = true;
//    for (const auto& x : s) {
//        if (!first) {
//            os << ", ";
//        }
//        first = false;
//        os << x;
//    }
//    return os << "}";
//}
//
//template <class K, class V>
//ostream& operator<<(ostream& os, const map<K, V>& m) {
//    os << "{";
//    bool first = true;
//    for (const auto& kv : m) {
//        if (!first) {
//            os << ", ";
//        }
//        first = false;
//        os << kv.first << ": " << kv.second;
//    }
//    return os << "}";
//}
//
//template <class T, class U>
//void AssertEqual(const T& t, const U& u, const string& hint = {}) {
//    if (t != u) {
//        ostringstream os;
//        os << "Assertion failed: " << t << " != " << u;
//        if (!hint.empty()) {
//            os << " hint: " << hint;
//        }
//        throw runtime_error(os.str());
//    }
//}
//
//void Assert(bool b, const string& hint) { AssertEqual(b, true, hint); }
//
//class TestRunner {
//public:
//    template <class TestFunc>
//    void RunTest(TestFunc func, const string& test_name) {
//        try {
//            func();
//            cerr << test_name << " OK" << endl;
//        }
//        catch (exception& e) {
//            ++fail_count;
//            cerr << test_name << " fail: " << e.what() << endl;
//        }
//        catch (...) {
//            ++fail_count;
//            cerr << "Unknown exception caught" << endl;
//        }
//    }
//
//    ~TestRunner() {
//        if (fail_count > 0) {
//            cerr << fail_count << " unit tests failed. Terminate" << endl;
//            exit(1);
//        }
//    }
//
//private:
//    int fail_count = 0;
//};
//
//void TestPredefinedLastNameFirst() {
//    Person person;
//
//    person.ChangeLastName(1965, "Sergeeva");
//    person.ChangeFirstName(1967, "Polina");
//
//    AssertEqual(person.GetFullName(1964), "Incognito");
//    AssertEqual(person.GetFullName(1966), "Sergeeva with unknown first name");
//    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");
//}
//
//void TestPredefined() {
//    Person person;
//
//    person.ChangeFirstName(1965, "Polina");
//    person.ChangeLastName(1967, "Sergeeva");
//
//    AssertEqual(person.GetFullName(1964), "Incognito");
//    AssertEqual(person.GetFullName(1966), "Polina with unknown last name");
//    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");
//
//    person.ChangeFirstName(1969, "Appolinaria");
//    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");
//    AssertEqual(person.GetFullName(1969), "Appolinaria Sergeeva");
//    AssertEqual(person.GetFullName(1970), "Appolinaria Sergeeva");
//
//    person.ChangeLastName(1968, "Volkova");
//    AssertEqual(person.GetFullName(1967), "Polina Sergeeva");
//    AssertEqual(person.GetFullName(1968), "Polina Volkova");
//    AssertEqual(person.GetFullName(1969), "Appolinaria Volkova");
//
//}
//
//int main() {
//    TestRunner runner;
//    runner.RunTest(TestPredefined, "TestPredefined");
//    runner.RunTest(TestPredefinedLastNameFirst, "TestPredefinedLastNameFirst");
//    return 0;
//}




/*Фреймворк на калькулятор рациональных дробей*/

//#include <iostream>
//#include<fstream>
//#include <sstream>
//#include<set>
//#include<map>
//#include<vector>
//#include<stdexcept>
//using namespace std;
//
//int NOD(int a, int b) {
//
//    while ((a > 0) && (b > 0))
//    {
//        if (a > b)
//            a %= b;
//        else
//            b %= a;
//    }
//    return a + b;
//}
//
//int NOK(int a, int b) {
//    return a * b / NOD(a, b);
//}
//
//
//class Rational {
//public:
//    Rational() {
//        p = 0;
//        q = 1;
//    }
//
//    void sokr(int& a, int& b) {
//        if ((a == 0) || (b == 0)) { // определение знака
//            a = 0;
//            b = 1;
//        }
//        else {
//            int tmp = a;
//            int tmp1 = b;
//            a = abs(tmp) / NOD(abs(tmp), abs(tmp1));
//            b = abs(tmp1) / NOD(abs(tmp), abs(tmp1));
//            if (((tmp < 0) && (tmp1 > 0)) || ((tmp > 0) && (tmp1 < 0))) {
//                a = -a;
//            }
//        }
//
//    }
//
//    Rational(int numerator, int denominator) {
//
//        if (denominator <= 0) throw invalid_argument("Invalid argument");
//        sokr(numerator, denominator);
//        p = numerator;
//        q = denominator;
//
//    }
//
//    int Numerator() const {
//        return p;
//    }
//
//    int Denominator() const {
//        return q;
//    }
//
//    bool operator==(const Rational& b) const {
//        if ((p == b.p) && (q == b.q))
//            return true;
//        return false;
//    }
//    bool operator!=(const Rational& b) const {
//        if ((p != b.p) || (q != b.q))
//            return true;
//        return false;
//    }
//    Rational& operator+(const Rational& b) {
//
//        int n = NOK(q, b.q);
//        p = p * (n / q) + b.p * (n / b.q);
//        q = n;
//        sokr(p, q);
//        return *this;
//    }
//
//    Rational& operator-(const Rational& b) {
//        int n = NOK(q, b.q);
//        p = p * (n / q) - b.p * (n / b.q);
//        q = n;
//        sokr(p, q);
//        return *this;
//    }
//    Rational& operator*(const Rational& b) {
//        p = p * b.p;
//        q = q * b.q;
//        sokr(p, q);
//        return *this;
//    }
//    Rational& operator/(const Rational& b) {
//        p = p * b.q;
//        q = q * b.p;
//        if (q == 0) throw  invalid_argument("Division by zero");
//        sokr(p, q);
//        return *this;
//    }
//
//    friend istream& operator>>(istream& in, Rational& R)
//    {
//
//        int t1 = R.p;
//        int t2 = R.q;
//        if (in) {
//            in >> t1;
//            in.ignore(1);
//            in >> t2;
//        }
//        R = Rational(t1, t2);
//
//        return in;
//    }
//    friend ostream& operator<<(ostream& out, const Rational& R)
//    {
//        out << R.p << "/" << R.q;
//        return out;
//    }
//
//    friend bool operator<(const Rational& a, const Rational& b) {
//        int zn = a.q;
//        int i1 = a.p;
//        int i2 = b.p;
//        if (a.q != b.q) {
//            zn = NOK(a.q, b.q);
//            i1 = a.p * (zn / a.q);
//            i2 = b.p * (zn / b.q);
//        }
//        if (i1 < i2) {
//            return true;
//        }
//        else return false;
//
//
//    }
//
//private:
//    int p;
//    int q;
//};
//
//
///* юнит - тесты */
//template <class T>
//ostream& operator << (ostream& os, const vector<T>& s) {
//    os << "{";
//    bool first = true;
//    for (const auto& x : s) {
//        if (!first) {
//            os << ", ";
//        }
//        first = false;
//        os << x;
//    }
//    return os << "}";
//}
//
//template <class T>
//ostream& operator << (ostream& os, const set<T>& s) {
//    os << "{";
//    bool first = true;
//    for (const auto& x : s) {
//        if (!first) {
//            os << ", ";
//        }
//        first = false;
//        os << x;
//    }
//    return os << "}";
//}
//
//template <class K, class V>
//ostream& operator << (ostream& os, const map<K, V>& m) {
//    os << "{";
//    bool first = true;
//    for (const auto& kv : m) {
//        if (!first) {
//            os << ", ";
//        }
//        first = false;
//        os << kv.first << ": " << kv.second;
//    }
//    return os << "}";
//}
//
//template<class T, class U>
//void AssertEqual(const T& t, const U& u, const string& hint = {}) {
//    if (t != u) {
//        ostringstream os;
//        os << "Assertion failed: " << t << " != " << u;
//        if (!hint.empty()) {
//            os << " hint: " << hint;
//        }
//        throw runtime_error(os.str());
//    }
//}
//
//void Assert(bool b, const string& hint) {
//    AssertEqual(b, true, hint);
//}
//
//class TestRunner {
//public:
//    template <class TestFunc>
//    void RunTest(TestFunc func, const string& test_name) {
//        try {
//            func();
//            cerr << test_name << " OK" << endl;
//        }
//        catch (exception& e) {
//            ++fail_count;
//            cerr << test_name << " fail: " << e.what() << endl;
//        }
//        catch (...) {
//            ++fail_count;
//            cerr << "Unknown exception caught" << endl;
//        }
//    }
//
//    ~TestRunner() {
//        if (fail_count > 0) {
//            cerr << fail_count << " unit tests failed. Terminate" << endl;
//            exit(1);
//        }
//    }
//
//private:
//    int fail_count = 0;
//};
//
//
//void Tests() {
//    {
//        AssertEqual(Rational().Numerator(), 0, "Constr!");
//        AssertEqual(Rational().Denominator(), 1, "Constr!");
//    }
//    {
//        AssertEqual(Rational(2, 3).Numerator(), 2, "Constr!");
//        AssertEqual(Rational(2, 3).Denominator(), 3, "Constr!");
//    }
//    {
//        AssertEqual(Rational(-2, -3).Numerator(), 2, "Constr!");
//        AssertEqual(Rational(-2, -3).Denominator(), 3, "Constr!");
//    }
//    {
//        AssertEqual(Rational(6, 9).Numerator(), 2, "Constr!");
//        AssertEqual(Rational(6, 9).Denominator(), 3, "Constr!");
//    }
//    {
//        AssertEqual(Rational(2, -3).Numerator(), -2, "Constr!");
//        AssertEqual(Rational(2, -3).Denominator(), 3, "Constr!");
//    }
//    {
//        AssertEqual(Rational(0, 6).Numerator(), 0, "Constr!");
//        AssertEqual(Rational(0, 6).Denominator(), 1, "Constr!");
//    }
//    {
//        AssertEqual(Rational(3, -6).Numerator(), -1, "Constr!");
//        AssertEqual(Rational(3, -6).Denominator(), 2, "Constr!");
//    }
//    {
//        AssertEqual(Rational(0, -6).Numerator(), 0, "Constr!");
//        AssertEqual(Rational(0, -6).Denominator(), 1, "Constr!");
//    }
//    {
//        AssertEqual(Rational(0, -1).Numerator(), 0, "Constr!");
//        AssertEqual(Rational(0, -1).Denominator(), 1, "Constr!");
//    }
//    {
//        AssertEqual(Rational(13, 17).Numerator(), 13, "Constr!");
//        AssertEqual(Rational(13, 17).Denominator(), 17, "Constr!");
//    }
//    {
//        AssertEqual(Rational(1, -1).Numerator(), -1, "Constr!");
//        AssertEqual(Rational(1, -1).Denominator(), 1, "Constr!");
//    }
//    {
//        AssertEqual(Rational(-1, -1).Numerator(), 1, "Constr!");
//        AssertEqual(Rational(-1, -1).Denominator(), 1, "Constr!");
//    }
//    {
//        AssertEqual(Rational(1, 1).Numerator(), 1, "Constr!");
//        AssertEqual(Rational(1, 1).Denominator(), 1, "Constr!");
//    }
//    {
//        AssertEqual(Rational(-2147483647, -2147483647).Numerator(), 1, "Constr!");
//        AssertEqual(Rational(-2147483647, -2147483647).Denominator(), 1, "Constr!");
//    }
//    {
//        AssertEqual(Rational(-2147483647, 2147483647).Numerator(), -1, "Constr!");
//        AssertEqual(Rational(-2147483647, 2147483647).Denominator(), 1, "Constr!");
//    }
//    {
//        AssertEqual(Rational(2147483647, 2147483647).Numerator(), 1, "Constr!");
//        AssertEqual(Rational(2147483647, 2147483647).Denominator(), 1, "Constr!");
//    }
//
//}
//
//
//
//int main() {
//
//    TestRunner runner;
//    // добавьте сюда свои тесты
//    runner.RunTest(Tests,"test");
//
//    
//
//    return 0;
//}







/*Юнит-тесты для палиндромов*/
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint = "") {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
        catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

bool IsPalindrom(const string& a) {
    if (a.size() < 2)
        return true;

    for (size_t i = 0; i < a.size() / 2; i++)
        if (a[i] != a[a.size() - 1 - i])
            return false;
    return true;
}

void Tests() {
    /*t1*/
    string t1 = "faoag";
    AssertEqual(IsPalindrom(t1), 0, "t1");
    /*t2*/
    string t2 = "faoa f";
    AssertEqual(IsPalindrom(t2), 0, "t2");
    /*t3*/
    string t3 = "";
    AssertEqual(IsPalindrom(t3), 1, "t3");
    /*t4*/
    string t4 = "f";
    AssertEqual(IsPalindrom(t4), 1, "t4");
    /*t5*/
    string t5 = " aoa ";
    AssertEqual(IsPalindrom(t5), 1, "t5");
    /*t6*/
    string t6 = "a a";
    AssertEqual(IsPalindrom(t6), 1, "t6");
    /*t7*/
    string t7 = " f ";
    AssertEqual(IsPalindrom(t7), 1, "t7");
    /*t8*/
    string t8 = "gafaoofag";
    AssertEqual(IsPalindrom(t8), 0, "t8");
    /*t9*/
    string t9 = "gafooofag";
    AssertEqual(IsPalindrom(t9), 1, "t9");
    /*t10*/
    string t10 = "Gafooofag";
    AssertEqual(IsPalindrom(t10), 0, "t10");
    /*t11*/
    string t11 = "7afooofa7";
    AssertEqual(IsPalindrom(t11), 1, "t11");
    /*t12*/
    string t12 = "7777";
    AssertEqual(IsPalindrom(t12), 1, "t12");
    /*t13*/
    string t13 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    AssertEqual(IsPalindrom(t13), 1, "t13");
    /*t14*/
    string t14 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAaaa";
    AssertEqual(IsPalindrom(t14), 0, "t14");
    /*t15*/
    string t15 = "GafooofaG";
    AssertEqual(IsPalindrom(t15), 1, "t15");
    /*t16*/
    string t16 = "Gafooo1aG";
    AssertEqual(IsPalindrom(t16), 0, "t16");

    /*t17*/
    string t17 = "baobab";
    AssertEqual(IsPalindrom(t17), 0, "t17");

    /*t18*/
    string t18 = "level";
    AssertEqual(IsPalindrom(t18), 1, "t18");

    /*t19*/
    string t19 = "LeveL ,madam, LeveL";
    AssertEqual(IsPalindrom(t19), 1, "t19");

    /*20*/
    string t20 = "Hi, people, pochemy takoe ebnytoe zadanie";
    AssertEqual(IsPalindrom(t20), 0, "20");

}

int main() {
    TestRunner runner;
    runner.RunTest(Tests,"Testing");
    return 0;
}





