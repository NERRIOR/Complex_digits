#include <iostream>
#include <format>
#include <string>
using namespace std;

class Complex 
{
public:
    double Re = 0;
    double Im = 0;
    string e;
    Complex(double Re, double Im) 
    {
        this->Re = Re;
        this->Im = Im;
    }
    // конструктор для задания комплексного числа при помощи строки
    Complex(string digit) 
    {
        // для поиска мнимой части
        string h = digit;
        // ищем действительную часть комплексного числа
        for (int i = 0; i < digit.length(); i++)
        {
            if (digit[i] == ' ')
            {
                this->Re = stod(digit.substr(0, i));
                h.erase(0, i + 3);
                break;
            }
        }
        // ищем мнимую часть комплексного числа
        for (int i = 0; i < h.length(); i++)
        {
            if (h[i] == 'i')
            {
                this->Im = stod(h.substr(0, i));
                break;
            }
        }
    }
    ~Complex() 
    {

    }
    // перегружаем оператор сложения для комплексных чисел 
    Complex operator+(const Complex other_digit) 
    {
        // действительные части комплексных чисел
        double Re_1 = this->Re;
        double Re_2 = other_digit.Re;
        // мнимые части комплексных чисел
        double Im_1 = this->Im;
        double Im_2 = other_digit.Im;
        // возвращаем результат сложения двух комплексных чисел
        Complex temporary = Complex(Re_1 + Re_2, Im_1 + Im_2);
        return temporary;
    }
    // перегружаем результат вычитания для комплексных чисел
    Complex operator-(const Complex other_digit) 
    {
        // действительные части комплексных чисел
        double Re_1 = this->Re;
        double Re_2 = other_digit.Re;
        // мнимые части комплексных чисел 
        double Im_1 = this->Im;
        double Im_2 = other_digit.Im;
        // возвращаем результат вычитания двух комплексных чисел
        Complex temporary = Complex(Re_1 - Re_2, Im_1 - Im_2);
        return temporary;
    }
    // перегружаем оператор умножения для комплексных чисел
    Complex operator*(const Complex other_digit) 
    {
        // действительные части комплексных чисел
        double Re_1 = this->Re;
        double Re_2 = other_digit.Re;
        // мнимые части комплексных чисел 
        double Im_1 = this->Im;
        double Im_2 = other_digit.Im;
        // Re_1 * Re_2 + Re_1 * Im_2 + Im_1 * Re_2 + Im_1 * Im_2
        // причем Im_1 * Im_2 будет вычитаться из действительной части 
        // считаем действительную часть числа
        double Re_product = Re_1 * Re_2 - Im_1*Im_2;
        // считаем мнимую часть числа 
        double Im_product = Re_1 * Im_2 + Im_1 * Re_2;
        // возвращаем результат умножения двух комплексных чисел
        Complex temporary = Complex(Re_product, Im_product);
        return temporary;
    }
    Complex operator/(const Complex other_digit) 
    {
        // действительные части комплексных чисел
        double Re_1 = this->Re;
        double Re_2 = other_digit.Re;
        // мнимые части комплексных чисел 
        double Im_1 = this->Im;
        double Im_2 = other_digit.Im;
        // считаем действительную часть числа
        double Re_division = (Re_1 * Re_2 + Im_1 * Im_2) / (pow(Re_2, 2) + pow(Im_2, 2));
        // считаем мнимую часть числа
        double Im_division = (Im_1 * Re_2 - Re_1 * Im_2) / (pow(Re_2, 2) + pow(Im_2, 2));
        Complex temporary = Complex(Re_division, Im_division);
        return temporary;
    }
    string toString()
    {
        // форматный вывод 
        if (this->Im < 0) 
        {
            return format("{}{}i", this->Re, this->Im);
        }
        else 
        {
            return format("{}+{}i", this->Re, this->Im);
        }
    }
};
// перегрузка оператора вывода в поток
ostream& operator<<(ostream &out, Complex &digit)
{
    return out << digit.toString();
}
int main()
{
    setlocale(LC_ALL, "ru");
    // создаем два комплексных числа
    Complex digit_1 = Complex(3.27, -2.34);
    Complex digit_2 = Complex(4, 5);
    // складываем два комплексных числа
    Complex sum = digit_1 + digit_2;
    // вычитаем два комплексных числа
    Complex difference = digit_1 - digit_2;
    // умножаем два комплексных числа
    Complex product = digit_1 * digit_2;
    // делим два комплексных числа друг на друга
    Complex division = digit_1 / digit_2;
    // задаем комплексное число при помощи строки(!вещественные числа через запятую, иначе отсекает хвост!)
    Complex str = Complex("12,342323 + -23,1345i");
    // вывод вещественного числа(с помощью метода toString())
    cout << str.toString() << endl;
    // вывод вещественного числа(с помощью перегрузки оператора <<) Данная строка не работает
    // =============================================================================================
    //cout << digit_1 + digit_2 << endl;*/
}

