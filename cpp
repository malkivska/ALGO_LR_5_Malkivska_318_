#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// Функція перевірки на коректність вхідних даних
bool isValid(double value) {
    return !isnan(value) && !isinf(value); // Без циклів
}

// Завдання 1: Кількість точок у помаранчевій фігурі
void task1_variant32() {
    double r; // Радіус кола
    cout << "Введіть радіус кола (r): ";
    cin >> r;

    if (r <= 0 || !isValid(r)) {
        cout << "Некоректне значення радіуса!" << endl;
        return;
    }

    int n; // Кількість точок для генерації
    cout << "Введіть кількість точок для перевірки: ";
    cin >> n;

    // Ініціалізуємо генератор випадкових чисел
    srand(time(0));

    int count = 0;
    for (int i = 0; i < n; ++i) {
        // Генеруємо випадкові координати точок в межах від -r до r
        double x = (rand() % (int)(2 * r * 1000)) / 1000.0 - r; // координата x
        double y = (rand() % (int)(2 * r * 1000)) / 1000.0 - r; // координата y

        // Умови для перевірки потрапляння в помаранчеву фігуру
        if (x >= 0 && y >= 0 && (x * x + y * y <= r * r)) {
            count++;
        }
    }

    cout << "Кількість точок, що потрапляють до помаранчевої фігури: " << count << endl;
}

// Завдання 2: Обчислення виразу
void task2() {
    double x;
    int n;
    cout << "Введіть x: ";
    cin >> x;
    cout << "Введіть n: ";
    cin >> n;

    if (!isValid(x) || n <= 0) {
        cout << "Некоректні дані!" << endl;
        return;
    }

    double result = 0.0;
    for (int i = 1; i <= n; ++i) {
        result += pow(x, 1.0 / (5 * i)) - x;
    }
    cout << "Результат обчислення: " << result << endl;

    // Додатковий вивід значень елементів
    cout << "Значення елементів: ";
    for (int i = 1; i <= n; ++i) {
        if ((n % 2 == 0 && i % 3 == 0) || (n % 2 != 0 && i % 4 == 0)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Завдання 3: Дослідження збіжності ряду
void task3() {
    double epsilon = 1e-7, g = 1e3, sum = 0.0;
    int n = 0;
    while (true) {
        double term = (pow(2, n) * 5 * 8 * (3 * n + 2)) / (pow(n, n) * tgamma(2 * n + 2));
        if (fabs(term) < epsilon || fabs(term) > g) break;
        sum += term;
        n++;

        // Вивід поточного значення після кожних 10 ітерацій
        if (n % 10 == 0) {
            cout << "Сума після " << n << " ітерацій: " << fixed << setprecision(15) << sum << endl;
        }
    }
    cout << "Загальна сума: " << fixed << setprecision(15) << sum << endl;
}

// Меню програми
void menu() {
    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Завдання 1 (Варіант 32 - помаранчеві фігури)\n";
        cout << "2. Завдання 2\n";
        cout << "3. Завдання 3\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1: task1_variant32(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 0: cout << "Вихід з програми.\n"; break;
            default: cout << "Некоректний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 0);
}

// Основна функція
int main() {
    menu();
    return 0;
}






