#include <iostream>
#include <string>
using namespace std;
//1. Клиентский код должен создавать объекты, ничего не зная об
//их классе, или о том, какие данные они содержат.
//2. Классы создаваемых объектов определяются во время 
//выполнения(например, при динамической загрузке).
//3. Экземпляры класса могут пребывать в не очень большом
//количестве состояний, поэтому может оказаться значительно 
//удобнее создать несколько прототипов и клонировать их вместо
//прямого создания экземпляра класса.

/*  * Это абстрактный базовый класс Device.
* Он определяет функцию Clone, которая составляет
* основу паттерна Prototype */
class Device {
private: //название устройства 
	string name;
public:
	//конструктора 
	Device() : Device("Unknown device") {}
	Device(string dname) { SetName(dname); }
	//вспомогательные функции 
	string GetName() const { return name; }
	void SetName(string dname) { name = dname; }
	//Чисто виртуальная функция
	//Она будет использоваться для создания копий 
	virtual Device* Clone() const = 0;
	//отображение данных
	void Show() const {
		cout << "\nName is\n" << GetName() << "\n";
	}
};
/* * Конкретный потомок устройства класс Car */
class Car : public Device {
private:
	//свойства машины 
	string manufacturer;
	string description;
	string color;
	int year;
public: //конструктора
	Car() :Car("No information", "No description", "No color", 0)
	{
		SetName("Car");
	}
	Car(string cmanufacturer, string cdescription, string ccolor, int cyear);
public:
	//вспомогательные функции 
	int GetYear()const { return year; }
	string GetManufacturer()const { return manufacturer; }
	string GetDescription()const { return description; }
	string GetColor()const { return manufacturer; }
	void SetYear(int cyear) { year = cyear; }
	void SetManufacturer(string cmanufacturer) { manufacturer = cmanufacturer; }
	void SetColor(string ccolor) { color = ccolor; }
	void SetDescription(string cdescription) { description = cdescription; }
	//реализация виртуальной функции в потомке
	Device* Clone()const;
	void Show() const;
};
//реализация конструктора
Car::Car(string cmanufacturer, string cdescription, string ccolor, int cyear) {
	SetName("Car");
	SetManufacturer(cmanufacturer);
	SetDescription(cdescription);
	SetColor(ccolor); SetYear(cyear);
}
//функция клонирования
Device* Car::Clone() const {
	Car* tempCar = new Car();
	/* Обратите внимание!
	* При при работе с динамической памятью нужно
	* определить конструктор копирования, конструктор
	* переноса и перегрузить оператор =   */
	*tempCar = *this;
	return tempCar;
}
//Отображение на экран данных 
void Car::Show() const {
	Device::Show();
	cout << "\nDescription of car is\n" <<GetDescription() << "\n"; 
	cout << "\nManufacturer of car is\n";
	cout << GetManufacturer() << "\n";
	cout << "\nYear of car is\n" << GetYear() << "\n";
	cout << "\nColor of car is\n" << GetColor() << "\n";
}
int main2() {
	//Введем данные 
	string manufacturer; 
	cout << endl << "Input manufacturer of car:" << endl; 
	std::getline(std::cin, manufacturer); 
	string description; 
	cout << "Input description of car:" << endl;
	std::getline(std::cin, description); 
	string color;
	cout << "Input color of car:" << endl;
	std::getline(std::cin, color);
	int year;
	cout << "Input year of car:" << endl;
	cin >> year;
	//создадим объект 
	Car c(manufacturer, description, color, year); 

	c.Show(); cout << "Let's clone!\nLet's prototype!" << endl; 
	//клонируем объект
	Car* copy = (Car*)c.Clone(); 
	copy->Show(); 
	
	Car* copy2 = new Car(c);//вызов конструктора копирования
	//удаляем клонированный объект
	delete copy;
	return 0;
}

