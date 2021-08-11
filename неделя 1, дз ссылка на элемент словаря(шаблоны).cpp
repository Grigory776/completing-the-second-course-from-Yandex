// неделя 1, дз ссылка на элемент словаря(шаблоны).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include<map>

using namespace std;

template <typename Key, typename Value>
Value& GetRefStrict(const map<Key, Value>& p, Key isk);

int main()
{
    try {
        map<int, string> m = { {0, "value"} };
        string& item = GetRefStrict(m, 1);
        item = "newvalue";
        cout << m[0] << endl; // выведет newvalue
    }
    catch (runtime_error e) {
        cout << e.what() << endl;
    }
    return 0;
}

template <typename Key, typename Value>
Value& GetRefStrict(const map<Key, Value>& p, Key isk) {
    for (const auto& item : p) {
        if (item.first == isk)
            return (Value&)item.second;
    }
    throw  runtime_error("runtime_error");
}
