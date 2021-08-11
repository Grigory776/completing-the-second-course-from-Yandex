// нед5_Наследование_Полиморфизм.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


//#include <iostream>
//
//using namespace std;
//
//struct Fruit {
//    int health = 0;
//};
//
//struct Apple: public Fruit {
//    Apple() {
//        health = 10;
//    }
//};
//
//
//
//int main()
//{
//    cout << "hello, world!!!" << endl;
//    
//
//    return 0;
//}
//


//#include<iostream>
//
//using namespace std;
//
//class Animal {
//public:
//    // ваш код
//    Animal(const string& t) : Name(t) {
//
//    }
//
//    const string Name;
//};
//
//
//class Dog: public Animal {
//public:
//    // ваш код
//    Dog(const string& t) : Animal(t) {
//
//    }
//
//    void Bark() {
//        cout << Name << " barks: woof!" << endl;
//    }
//};
//
//
//int main() {
//    Dog d1("le chien");
//    d1.Bark();
//
//    return 0;
//}




/* ДЗ_2 */


//#include <iostream>
//#include<string>
//
//using namespace std;
//
//void SendSms(const string& number, const string& message);
//void SendEmail(const string& email, const string& message);
//
//class INotifier {
//public:
//	virtual void Notify(const string& message) = 0;
//};
//
//class SmsNotifier: public INotifier {
//public:
//	SmsNotifier (const string& tmp): number(tmp){}
//
//	void Notify(const string& message) override {
//		SendSms(number, message);
//	}
//
//private:
//	string number;
//};
//
//class EmailNotifier : public INotifier {
//public:
//	EmailNotifier(const string& tmp) : email(tmp) {}
//
//	void Notify(const string& message) override {
//		SendEmail(email, message);
//	}
//
//private:
//	string email;
//};
//
//void Notify(INotifier& notifier, const string& message) {
//	notifier.Notify(message);
//}
//
//int main() {
//	SmsNotifier sms{ "+7-495-777-77-77" };
//	EmailNotifier email{ "na-derevnyu@dedushke.ru" };
//
//	Notify(sms, "I have White belt in C++");
//	Notify(email, "And want a Yellow one");
//	return 0;
//}
//
//
//void SendSms(const string& number, const string& message) {
//	cout << "Send '" << message << "' to number " << number << endl;
//}
//
//void SendEmail(const string& email, const string& message) {
//	cout << "Send '" << message << "' to e-mail " << email << endl;
//}



///* ДЗ_3 */
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <memory>
//#include <sstream>
//#include <iomanip>
//#include <math.h>
//
//using namespace std;
//
//class Figure {
//public:
//    virtual string Name() = 0;
//    virtual double Perimeter() = 0;
//    virtual double Area() = 0;
//};
//
//class Triangle : public Figure {
//public:
//    Triangle(size_t t1, size_t t2, size_t t3) :  a(t1), b(t2), c(t3) {
//    }
//
//    string Name() {
//        return "TRIANGLE";
//         }
//
//    double Perimeter() { return a + b + c; }
//
//    double Area(){
//        double pp = this->Perimeter() / 2;
//        return sqrt(pp * (pp - a) * (pp - b) * (pp - c));
//    }
//
//private:
//    double a, b, c;
//   
//};
//
//class Rect : public Figure {
//public:
//    Rect( size_t t1, size_t t2) : a(t1), b(t2) {
//    }
//
//    string Name() {
//        return "RECT";
//    }
//
//    double Perimeter() { return (a + b) * 2; }
//
//    double Area() {
//        return a * b;
//    }
//
//private:
//    double a, b;
//    
//};
//
//class Circle : public Figure {
//public:
//    Circle( size_t t1) : r(t1) {
//    }
//
//    string Name() {
//        return "CIRCLE";
//    }
//
//    double Perimeter() { return 2 * 3.14 * r; }
//
//    double Area() {
//        return 3.14 * r * r;
//    }
//
//private:
//    double r;
//   
//};
//
//shared_ptr <Figure> CreateFigure( istream& is) {
//    string figure;
//    is >> figure;
//    if (figure == "TRIANGLE") {
//        size_t a, b, c;
//        is >> a >> b >> c;
//
//        
//        shared_ptr<Triangle> tr_ptr(make_shared<Triangle>(a,b,c));
//        return tr_ptr;
//    }
//
//    else if (figure == "RECT") {
//        size_t a, b;
//        is >> a >> b;
//
//        shared_ptr<Rect> tr_ptr(make_shared<Rect>(a, b));
//        return tr_ptr;
//    }
//
//    else if (figure == "CIRCLE") {
//        size_t r;
//        is >> r;
//
//        shared_ptr<Circle> tr_ptr(make_shared<Circle>(r));
//        return tr_ptr;
//    }
//
//    else return nullptr;
//
//}
//
//int main() {
//
//    
//    vector<shared_ptr<Figure>> figures;
//    for (string line; getline(cin, line); ) {
//        istringstream is(line);
//
//        string command;
//        is >> command;
//        if (command == "ADD") {
//            // Пропускаем "лишние" ведущие пробелы.
//            // Подробнее об std::ws можно узнать здесь:
//            // https://en.cppreference.com/w/cpp/io/manip/ws
//            is >> ws;
//            figures.push_back(CreateFigure(is));
//        }
//        else if (command == "PRINT") {
//            for (const auto& current_figure : figures) {
//                cout << fixed << setprecision(3)
//                    << current_figure->Name() << " "
//                    << current_figure->Perimeter() << " "
//                    << current_figure->Area() << endl;
//            }
//        }
//    }
//   
//
//    return 0;
//}
//


/* ДЗ_4 */

/*Рефакторим код*/

#include <iostream>
#include <string>
#include <vector>


using namespace std;

ostream& kost() {
    cout << "Student: ";
    return cout;
}

class Person {
public:
    Person(const string& n, const string& p):Name(n),Profession(p){}

    virtual void Walk(const string& destination) {
        cout << Profession << ": " << Name << " walks to: " << destination << endl;
    }

    const string Name, Profession;
};

class Student: public Person {
public:

    Student(const string& name,const string& favouriteSong) : Person(name, "Student"), FavouriteSong(favouriteSong) {}
    

    void Learn() {
         kost() << Name << " learns" << endl;
    }

    void Walk(const string& destination) {
         kost() << Name << " walks to: " << destination << endl;
         kost() << Name << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() {
         kost() << Name << " sings a song: " << FavouriteSong << endl;
    }

private:
   const string FavouriteSong;
};


class Teacher: public Person {
public:

    Teacher(const string& name, const string& subject) : Person(name, "Teacher"), Subject(subject) {}
        
    void Teach() {
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }

private:
    const string Subject;
};


class Policeman: public Person {
public:
    Policeman(const string& name) : Person(name, "Policeman") {}
        

    void Check(Person& p) {
        cout << Profession << ": " << Name << " checks " << p.Profession
            << ". " << p.Profession << "n's name is: " << p.Name << endl;
    }
    
};


void VisitPlaces( Person& t, const vector<string>& places) {
    for (const auto& p : places) {
        t.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, { "Moscow", "London" });
    p.Check(s);
    VisitPlaces(s, { "Moscow", "London" });
    return 0;
}
