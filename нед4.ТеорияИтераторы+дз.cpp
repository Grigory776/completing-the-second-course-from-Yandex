// нед4.ТеорияИтераторы+дз.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

/*теория*/
void PrintRange(vector<string>::iterator begin, vector<string>::iterator end);

template<typename it>
void PrintRange1(it begin, it end);


/*дз1*/
void PrintVectorPart(const vector<int>& numbers);

/*дз2*/
template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border);

/*дз3*/
vector<string> SplitIntoWords(const string& s) {
    vector<string> res;

    auto beg = begin(s);
    auto it = find(beg, end(s), ' ');
    
    do  {
        it = find(beg, end(s), ' ');
        res.push_back({ beg,it });
        if (it!=end(s))
        beg = ++it;
    } while (it != end(s));

    return res;
}

int main()
{
    /*теория . блок 1*/

    //set<string> names = { "Ivan","Gorg","Katia" };
    //auto/*итератор, адрес*/ result = find_if(begin(names), end(names), [](const string& str) {
    //    return str[1] == 'o';
    //    });
    //cout << *result << endl << endl;
    //PrintRange1(begin(names), end(names));

    /*дз 1*/
    //PrintVectorPart({ 6, 1, 8, -5, 4 });
    //cout << endl;
    //PrintVectorPart({ -6, 1, 8, -5, 4 });  // ничего не выведется
    //cout << endl;
    //PrintVectorPart({ 6, 1, 8, 5, 4 });
    //cout << endl;

    /*дз 2*/

    /*for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;

    string to_find = "Python";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;*/



    /*дз 3*/
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;



    return 0;
}







void PrintRange(vector<string>::iterator begin, vector<string>::iterator end) {
    for (auto it = begin; it != end; it++) {

        cout << *it << endl;
    }
}

template<typename it>
void PrintRange1(it begin, it end) {
    for (auto i = begin; i != end; i++) {
        cout << *i << endl;
    }
}

void PrintVectorPart(const vector<int>& numbers) {

    auto it = find_if(begin(numbers), end(numbers), [](const int tmp) {
        return tmp < 0;
        });

    while (it != begin(numbers)) {
        --it;
        cout << *it << ' ';
    }

}


/*дз2*/
template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {

    vector<T> res;

    auto it = end(elements);
    for (auto i = begin(elements); i != end(elements); i++) {
        if (*i > border) {
            it = i;
            break;
        }
    }

    for (auto i = it; i != end(elements); i++) {
        res.push_back(*i);
    }
    return res;
}