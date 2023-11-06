// hw 13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

//Создайте класс «Комплексное число» - Complex. Класс должен содержать несколько конструкторов.
//Класс должен иметь возможность вводить и выводить комплексные числа посредством перегруженных операций >> и << .
//Перегрузите операции + , -, != , == , (). Используйте обычную и дружественную перегрузку

class Complex
{
private:
	int x, y;
	friend ostream& operator << (ostream& os, const Complex& complex);
	friend istream& operator >> (std::istream& in, Complex& complex);

public:
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }


	Complex()
	{
		x = y = 0;
	}

	Complex(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	Complex operator + (const Complex& other)
	{
		Complex temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;

		return temp;
	}

	Complex operator - (const Complex& other)
	{
		Complex temp;
		temp.x = this->x - other.x;
		temp.y = this->y - other.y;

		return temp;
	}

	bool operator ==(const Complex& other)
	{
		return this->x == other.x && this->y == other.y;
	}

	bool operator !=(const Complex& other)
	{
		return !(this->x == other.x && this->y == other.y);
	}

	void print()
	{
		cout << x;
		cout << endl;
		cout << y;
	}
};

ostream& operator << (ostream& os, const Complex& complex)
{
	return os << complex.x << " " << complex.y;
}

istream& operator >> (istream& in, Complex& complex)
{
	int x, y;
	in >> x >> y;
	complex.setX(x);
	complex.setY(y);

	return in;
}

int main()
{
	setlocale(LC_ALL, "ru");

	Complex a(5, 1);
	Complex b(9, 3);

	Complex c;

	c = a + b;
	cout << c << endl;

	c = a - b;
	cout << c << endl;

	Complex d(0, 0);
	cout << "\nВведите два числа: ";
	cin >> d;
	cout << d;
}
