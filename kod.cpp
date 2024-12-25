#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

// Перевірка входження точки в помаранчеву область (завдання 1, варіант 32)
bool isInOrangeFigure(double x, double y, double r) {
    // Помаранчева область: ліва половина кола (x <= 0) + частина правого квадрата (x > 0 && y >= 0 && x <= r && y <= r)
    double distanceToCenter = sqrt(x * x + y * y);
    return (x <= 0 && distanceToCenter <= r) || (x > 0 && y >= 0 && x <= r && y <= r);
}

// Завдання 1: Обчислення кількості точок у фігурі
void task1() {
    double r;
    int n;

    cout << "Введіть радіус кола: ";
    cin >> r;
    if (r <= 0) {
        cout << "Помилка! Радіус має бути додатнім числом." << endl;
        return;
    }

    cout << "Введіть кількість точок: ";
    cin >> n;
    if (n <= 0) {
        cout << "Помилка! Кількість точок має бути натуральним числом." << endl;
        return;
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        double x, y;
        cout << "Введіть координати точки " << (i + 1) << " (x, y): ";
        cin >> x >> y;

        if (isInOrangeFigure(x, y, r)) {
            count++;
        }
    }

    cout << "Кількість точок у помаранчевій області: " << count << endl;
}

// Завдання 2: Обчислення значення виразу з табл. 2 (варіант 15)
void task2() {
    double x;
    int n;

    cout << "Введіть значення x: ";
    cin >> x;
    if (x < -1 || x > 1) {
        cout << "Помилка! x має бути в межах [-1, 1]." << endl;
        return;
    }

    cout << "Введіть натуральне число n: ";
    cin >> n;
    if (n <= 0) {
        cout << "Помилка! n має бути натуральним числом." << endl;
        return;
    }

    double result = 0.0;
    double numerator = 1.0;
    double denominator = 1.0;

    cout << fixed << setprecision(15);

    cout << "Елементи послідовності:\n";
    for (int i = 1; i <= n; ++i) {
        numerator *= (2 * i - 1);
        denominator *= (2 * i);
        double term = (pow(-1, i + 1) * numerator * pow(x, 2 * i - 1)) / denominator;
        result += term;

        // Виведення кожного третього для парних n або кожного четвертого для непарних
        if ((n % 2 == 0 && i % 3 == 0) || (n % 2 != 0 && i % 4 == 0)) {
            cout << "Елемент " << i << ": " << term << endl;
        }
    }

    cout << "Значення виразу: " << result << endl;
}

// Завдання 3: Дослідження ряду на збіжність (варіант 37)
double seriesTerm(int n) {
    return pow(-1, n + 1) / (n * log(n + 1));
}

void task3() {
    const double e = 1e-7; // точність
    const double g = 1e3; // межа розбіжності
    const int M = 100;    // крок виведення результатів
    const int maxIterations = 1000000; // максимальна кількість ітерацій

    int n = 2; // Початок з другого члена ряду
    double sum = 0.0;

    cout << fixed << setprecision(15);
    while (n <= maxIterations) {
        double currentTerm = seriesTerm(n);

        if (fabs(currentTerm) < e) {
            cout << "Ряд збігається на " << n << "-й ітерації.\n";
            break;
        }

        if (fabs(currentTerm) > g) {
            cout << "Ряд розбігається на " << n << "-й ітерації.\n";
            break;
        }

        sum += currentTerm;

        if (n % M == 0) {
            cout << "Ітерація " << n << ", поточна сума: " << sum << "\n";
        }

        n++;
    }

    cout << "Кінцева сума ряду: " << sum << endl;
    cout << "Кількість ітерацій: " << n << endl;
}

// Меню програми
int main() {
    int choice;

    do {
        cout << "\nОберіть завдання:\n";
        cout << "1 - Завдання 1 (точки у фігурі)\n";
        cout << "2 - Завдання 2 (обчислення виразу)\n";
        cout << "3 - Завдання 3 (дослідження ряду)\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 0:
                cout << "Вихід з програми...\n";
                break;
            default:
                cout << "Помилка! Оберіть завдання з меню." << endl;
        }
    } while (choice != 0);

    return 0;
}
