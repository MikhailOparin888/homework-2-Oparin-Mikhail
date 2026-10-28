#include <iostream>
#include <cmath>

double f(double x, double y, double z) {
    if (x + y <= z || x + z <= y || y + z <= x) {
        return 0.0; 
    }
    double p = (x + y + z) / 2.0; 
    return std::sqrt(p * (p - x) * (p - y) * (p - z)); 
}

int main() {
    std::setlocale(LC_ALL, "Russian");

    double a, b, c, d, e, f_diag, g_diag;

    std::cout << "Введите длины сторон и диагоналей пятиугольника (a, b, c, d, e, f, g):\n";
    if (!(std::cin >> a >> b >> c >> d >> e >> f_diag >> g_diag)) {
        std::cerr << "Ошибка ввода данных!" << std::endl;
        return 1;
    }

    double area1 = f(a, b, f_diag);
    double area2 = f(f_diag, g_diag, c);
    double area3 = f(e, d, g);

    if (area1 == 0.0 || area2 == 0.0 || area3 == 0.0) {
        std::cout << "Ошибка: Из заданных отрезков невозможно составить указанные треугольники!\n";
    } else {
        double total_area = area1 + area2 + area3;
        std::cout << "\nПлощадь пятиугольника: " << total_area << std::endl;
    }

    return 0;
}
