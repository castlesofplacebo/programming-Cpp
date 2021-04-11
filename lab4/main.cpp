#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//вариант 22 : C, F
//Реализовать все указанные интерфейсы (абстрактные базовые классы) для классов (согласно варианту):
//C. Равносторонний треугольник
//F. Параллелограмм

//Функционал системы:
//- Хранение множества фигур
//- Динамическое добавление фигур пользователем. (через консоль)
//- Отобразить все фигуры.
//- Суммарная площадь всех фигур.
//- Суммарный периметр всех фигур.
//- Центр масс всей системы.
//- Память, занимаемая всеми экземплярами классов.
//- Сортировка фигур между собой по массе.

// Интерфейс "Геометрическая фигура".
class IGeoFig {
public:
    [[nodiscard]] virtual double square() const = 0;// Площадь.

    [[nodiscard]] virtual double perimeter() const = 0;// Периметр.
};

// Вектор
class CVector2D {
public:
    double x, y;

    CVector2D () {
        x = 0;
        y = 0;
    }

    CVector2D (double x_, double y_) {
        x = x_;
        y = y_;
    }

    CVector2D operator+ (const CVector2D& current) const {
        return {x + current.x, y + current.y};
    }

    CVector2D operator- (const CVector2D& current) const {
        return {x - current.x, y - current.y};
    }

    CVector2D operator* (const double t) const {
        return {x * t, y * t};
    }

    double operator* (const CVector2D& current) const {
        return x * current.x + y * current.y;
    }

    CVector2D operator/ (const double k) const {
        return {x / k, y / k};
    }

};

// Интерфейс "Физический объект".
class IPhysObject {
public:
    [[nodiscard]] virtual double mass() const = 0; // Масса, кг.

    [[nodiscard]] virtual CVector2D position() const = 0;// Координаты центра масс, м.

    virtual bool operator== ( const IPhysObject& ob ) const = 0;// Сравнение по массе.

    virtual bool operator< ( const IPhysObject& ob ) const = 0;// Сравнение по массе.
};

// Интерфейс "Отображаемый"
class IPrintable {
public:
    virtual void draw() const = 0;// Отобразить на экране (выводить в текстовом виде параметры фигуры).
};

// Интерфейс для классов, которые можно задать через диалог с пользователем.
class IDialogInitiable {
public:
    virtual void initFromDialog() = 0;// Задать параметры объекта с помощью диалога с пользователем.
};

// Интерфейс "Класс"
class IBaseCObject {
public:
    [[nodiscard]] virtual const char* classname() const = 0;// Имя класса (типа данных).

    [[nodiscard]] virtual unsigned int size() const = 0;// Размер занимаемой памяти.
};

class IFigure :
        public IGeoFig,
        public IPhysObject,
        public IPrintable,
        public IDialogInitiable,
        public IBaseCObject
{
public:
    virtual ~IFigure() = default;
};

class equilateralTriangle : public  IFigure {
public:
    const char* name = "Equilateral Triangle";
    CVector2D x, y, z;
    double len{};

    equilateralTriangle () = default;

    equilateralTriangle (CVector2D x, CVector2D y, CVector2D z)
    : x(x),
    y(y),
    z(z)
    {
        len = sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
    }

    [[nodiscard]] double square () const override {
        return len * sqrt(3) / 2;
    }

    [[nodiscard]] double perimeter () const override {
        return len * 3;
    }

    [[nodiscard]] double mass () const override {
        return this->square();
    }

    [[nodiscard]] CVector2D position () const override {
        CVector2D cur;
        cur.x = (x.x + y.x + z.x) / 3;
        cur.y = (x.y + y.y + z.y) / 3;
        return cur;
    }

    bool operator== (const IPhysObject& current) const override {
        return this->mass() == current.mass();
    }

    bool operator< (const IPhysObject &current) const override {
        return this->mass() < current.mass();
    }

    void draw () const override {
        cout << "Name of figure : " << name << '\n';
        cout << "Mass : " << mass() << '\n';
        cout << "Length of side : " << len << '\n';
        cout << "Position : 1) x = " << x.x << "; y = " << x.y << '\n'
                << "Position : 2) x = " << y.x << "; y = " << y.y << '\n'
                << "Position : 3) x = " << z.x << "; y = " << z.y << '\n';
    }

    void initFromDialog () override {
        double a, b, l;
        cout << "Enter points of equilateral triangle (in (x, y) format): x, y, z : \n";
        cin >> a >> b;
        x = CVector2D(a, b);

        cin >> a >> b;
        y = CVector2D(a, b);

        cin >> a >> b;
        z = CVector2D(a, b);

        len = sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));

        cout << "Done" << '\n';
    }

    [[nodiscard]] unsigned int size() const override {
        return sizeof(*this);
    }

    [[nodiscard]] const char* classname () const override {
        return "Equilateral Triangle";
    }
};

class parallelogram : public  IFigure {
public:
    const char* name = "Parallelogram";
    CVector2D w, x, y, z;
    double aLen{}, bLen{};

    parallelogram () = default;

    parallelogram (CVector2D w, CVector2D x, CVector2D y, CVector2D z)
    : w(w)
    , x(x)
    , y(y)
    , z(z)
    {
        aLen = sqrt((x.x - w.x) * (x.x - w.x) + (x.y - w.y) * (x.y - w.y));
        bLen = sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
    }

    [[nodiscard]] double square () const override {
        return abs((w - x) * (y - x));
    }

    [[nodiscard]] double perimeter () const override {
        return 2 * (aLen + bLen);
    }

    [[nodiscard]] double mass () const override {
        return this->square();
    }

    [[nodiscard]] CVector2D position () const override {
        return (y + w) / 2;
    }

    bool operator== (const IPhysObject& current) const override {
        return this->mass() == current.mass();
    }

    bool operator< (const IPhysObject &current) const override {
        return this->mass() < current.mass();
    }

    void draw () const override {
        cout << "Name of figure : " << name << '\n';
        cout << "Mass : " << mass() << '\n';
        cout << "Length of sides : first = " << aLen << "; second = " << bLen << '\n';
    }

    void initFromDialog () override {
        double a, b, l;
        cout << "Enter points of parallelogram (in (x, y) format): w, x, y, z : \n";
        cin >> a >> b;
        w = CVector2D(a, b);

        cin >> a >> b;
        x = CVector2D(a, b);

        cin >> a >> b;
        y = CVector2D(a, b);

        cin >> a >> b;
        z = CVector2D(a, b);

        aLen = sqrt((x.x - w.x) * (x.x - w.x) + (x.y - w.y) * (x.y - w.y));
        bLen = sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));

        cout << "Done" << '\n';
    }

    [[nodiscard]] unsigned int size() const override {
        return sizeof(*this);
    }

    [[nodiscard]] const char* classname () const override {
        return "Parallelogram";
    }
};


int main() {
    unsigned int count;
    vector <IFigure*> current;
    /*examples for tiangle
    -3 3
     0 -3
     3 3*/

    /*examples for parallelogram
     1 1
     3 1
     4 4
     6 4 */

    cout << "Enter the count of fugures : \n";
    cin >> count;

    for (unsigned int i = 0; i < count; ++i) {
        cout << "Enter the number to add the fugure : \n"
                "1 - Equilateral Triangle\n"
                "2 - Parallelogram\n";
        int numb;
        cin >> numb;
        if (numb == 1)
            current.push_back(new equilateralTriangle());
        else
            current.push_back(new parallelogram());
        current.back()->initFromDialog();
    }

    cout << "Reflection of figures : \n";
    count = 0;
    for (auto i : current) {
        ++count;
        cout << count << ") " << i->classname() << '\n';
        i->draw();
        cout << '\n';
    }

    cout << "Summ of figures squares : \n";
    double sum = 0.0;
    for (auto i : current) {
        sum += i->square();
    }
    cout << sum << '\n';

    cout << "Perimetr of figures squares : \n";
    double per = 0.0;
    for (auto i : current) {
        per += i->perimeter();
    }
    cout << per << '\n';

    cout << "Allocated memory : \n";
    sum = 0;
    for (auto i : current) {
        sum += i->size();
    }
    cout << sum << '\n';

    cout << "Centers of figures : \n";
    CVector2D res (0, 0);
    sum = 0.0;
    for (auto i : current) {
        double mas = i->mass();
        sum += mas;

        CVector2D posit = i->position();
        res = res +  posit * mas;
    }
    res = res / sum;
    cout << "x = " <<res. x << "; y = " << res.y << '\n';

    cout << "Sort figures : \n";
    vector <double> masArray(current.size() - 1);

    for (auto i : current) {
        masArray.push_back(i->mass());
    }
    size_t n = current.size();
    bool f = true;
    while (f) {
        f = false;
        for (unsigned int i = 0; i < (n - 1); i++) {
            if (masArray[i] > masArray[i+1]) {
                f = true;
                swap (masArray[i], masArray[i + 1]);
            }
        }
    }
    for (double i : masArray) {
        cout << i << '\t';
    }

    for (auto i : current) {
        delete i;
    }

    return 0;
}