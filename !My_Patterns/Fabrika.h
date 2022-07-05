#include <iostream>
using namespace std;
//1. Класс не должен зависеть от конкретного типа 
//создаваемого продукта.
//2. Классу не известен конкретный тип продукта, который ему 
//надо создавать.
//3. Конкретные типы создаваемых продуктов могут / должны 
//определяться в подклассах.
/*
* Точка в трехмерном пространстве.
* Используется для определения положения. */
struct Point3D {
	int X; int Y; int Z;
};
/* * Вектор в трехмерном пространстве.
* Используется для определения направления. */
struct Vector3D {
	int X; int Y; int Z;
};
/* * Класс абстрактной пули. */
class AbstractBullet {
private:
	Point3D location;
	Vector3D direction;
	double caliber;
public:
	/* * Текущее положение пули */
	Point3D GetLocation() { return location; }
	void SetLocation(const Point3D& newLocation)
	{
		location = newLocation;
	}
	/* * Направление пули */
	Vector3D GetDirection() { return direction; }
	void SetDirection(const Vector3D& newDirection) {
		direction = newDirection;
	}
	/* * Калибр пули */
	double GetCaliber() { return caliber; }
	void SetCaliber(double newCaliber) { caliber = newCaliber; }
	/* * Начало движения пули. */
	void StartMovement() {
		// Реализация начала движения 
	}
	/* * Метод поражения цели.
	* Так как разные типы пуль поражают цель поразному,
	* то метод должен быть реализован в подклассах. */
	virtual void HitTarget(void* target) = 0;
	/* * Метод, реализующий движение пули.
	* Так как разные типы пуль имеют разную траекторию
	* движения, то метод должен быть реализован
	* в подклассах. */
	virtual void Movement() = 0;
};
/* * Класс пули для автоматического оружия. */
class AutomaticBullet : public AbstractBullet {
public:
	void HitTarget(void* target) {
		//реализация поражения цели target 
		cout << "Hit by automatic bullet\n";
	}
	void Movement() {
		//реализация алгоритма движения пули 
	}
};
/* * Класс пули для дробовика. */
class ShotgunBullet : public AbstractBullet {
public:
	void HitTarget(void* target) {
		//реализация поражения цели target 
		cout << "Hit by shotgun bullet\n";
	}
	void Movement() {
		//реализация алгоритма движения пули 
	}
};
/* * Класс абстрактного оружия */
class AbstractWeapon {
protected:
	/*  * Фабричный метод для создания пули.  */
	virtual AbstractBullet* CreateBullet() = 0;
private:
	Point3D location;
	Vector3D direction;
	double caliber;
public:
	/*  * Текущее положение оружия  */
	Point3D GetLocation() { return location; }
	void SetLocation(const Point3D& newLocation) {
		location = newLocation;
	}
	/*  * Направление оружия  */
	Vector3D GetDirection() { return direction; }
	void SetDirection(const Vector3D& newDirection) {
		direction = newDirection;
	}
	/*  * Калибр оружия  */
	double GetCaliber() { return caliber; }
	void SetCaliber(double newCaliber) { caliber = newCaliber; }  /*  * Метод, производящий выстрел.  * Возвращает экзепмляр созданной пули.  */
	AbstractBullet* Shoot() {
		//создание объекта пули с помощью фабричного метода
		AbstractBullet* bullet = CreateBullet();
		//настройка пули на текущие параметры оружия 
		bullet->SetCaliber(this->GetCaliber());
		bullet->SetLocation(this->GetLocation());
		bullet->SetDirection(this->GetDirection());
		//начать движение пули  
		bullet->StartMovement();
		//возвратить экземпляр пули  
		return bullet;
	}
};
/* * Класс автоматического оружия. */
class AutomaticWeapon : public AbstractWeapon {
public:
	AutomaticWeapon() { this->SetCaliber(20); }
protected:
	/*  * Реализация фабричного метода.
	* Создает экземпляр пули,
	* специфический для текущего типа оружия.  */
	AbstractBullet* CreateBullet() {
		return new AutomaticBullet();
	}
};
/* * Класс дробовика. */
class Shotgun :public AbstractWeapon
{
public:
	Shotgun() { this->SetCaliber(50); }
protected:
	/*  * Реализация фабричного метода.
	* Создает экземпляр пули,
	* специфический для текущего типа оружия.  */
	AbstractBullet* CreateBullet() { return new ShotgunBullet(); }
};




