#include <iostream>
#include "Ratio.h"

int main() {
    // Створення об'єктів Ratio
    Ratio num1(2, 3);
    Ratio num2(-1, 2);
    {
        Ratio num5(-1, 2), num6(0, 2);
    }
    
    //Використання GetCurrentCount для підрахунки об'єктів які існують на дани час
    std::cout << "Total Count: " << Ratio::GetCurrentCount() << std::endl;
    // Використання ToString для перетворення об'єкта в рядок (логіювання)
    std::cout << "Current Ratio (num1): " << num1.ToString() << std::endl;
    std::cout << "Current Ratio (num2): " << num2.ToString() << std::endl;

    // Використання FromString для створення нового об'єкта (парсинг)
    const char* str = "Numerator: 3, Denominator: 4";
    Ratio num3 = Ratio::FromString(str);
    std::cout << "Created Ratio (num3): " << num3.ToString() << std::endl;
    
    //Використання GetTotalCount для підрахунки об'єктів які існують на дани час
    std::cout << "Total Count: " << Ratio::GetTotalCount() << std::endl;
    return 0;
}
