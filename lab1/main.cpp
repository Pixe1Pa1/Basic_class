#include <iostream>
#include "Ratio.h"

int main() {
    // ��������� ��'���� Ratio
    Ratio num1(2, 3);
    Ratio num2(-1, 2);
    {
        Ratio num5(-1, 2), num6(0, 2);
    }
    
    //������������ GetCurrentCount ��� ��������� ��'���� �� ������� �� ���� ���
    std::cout << "Total Count: " << Ratio::GetCurrentCount() << std::endl;
    // ������������ ToString ��� ������������ ��'���� � ����� (���������)
    std::cout << "Current Ratio (num1): " << num1.ToString() << std::endl;
    std::cout << "Current Ratio (num2): " << num2.ToString() << std::endl;

    // ������������ FromString ��� ��������� ������ ��'���� (�������)
    const char* str = "Numerator: 3, Denominator: 4";
    Ratio num3 = Ratio::FromString(str);
    std::cout << "Created Ratio (num3): " << num3.ToString() << std::endl;
    
    //������������ GetTotalCount ��� ��������� ��'���� �� ������� �� ���� ���
    std::cout << "Total Count: " << Ratio::GetTotalCount() << std::endl;
    return 0;
}
