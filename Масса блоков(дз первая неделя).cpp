// Масса блоков(дз первая неделя).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include<tuple>

using namespace std;

int main()
{
    int a, b, c, d, e, f;
    a = 4;
    b = 2;
    c = 7;
    d = 4;
    e = 3;
    f = 3;
    cout << (tie(a, b, c) < tie(d, e, f)) << endl;
   

    return 0;
}

/*дз по суммарной массе блоков*/

//uint64_t result = 0;
//uint64_t W, H, D;
//size_t N;
//cin >> N;
//uint64_t R;
//cin >> R;
//for (int i = 0; i < N; i++) {
//    cin >> W >> H >> D;
//    result += (R * W * H * D);
//}
//cout << result << endl;