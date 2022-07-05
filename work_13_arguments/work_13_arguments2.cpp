#include <iostream>
#include <random>
#include <string.h>
#include <vector>
#include <windows.h>
#include <map>
#include <queue>
#include <fstream>

std::random_device Rand;

class wheel_R
{
protected:
	uint16_t WheelR;
	wheel_R()
	{
		std::cout << "Enter wheel R: ";
		std::cin >> WheelR;
	}
	~wheel_R()
	{
		WheelR = NULL;
	}
};

class dors_col
{
protected:
	uint16_t DorsCol;
	dors_col()
	{
		std::cout << "Enter dor col: ";
		std::cin >> DorsCol;
	}
	~dors_col()
	{
		DorsCol = NULL;
	}
};

class engine_V
{
protected:
	std::string EngineV;
	engine_V()
	{
		std::cout << "Enter engine V: ";
		std::cin >> EngineV;
	}
	~engine_V()
	{
		EngineV = "";
	}
};

class body_type
{
protected:
	std::string BodyType;
	body_type()
	{
		std::cout << "Enter body type: ";
		std::cin >> BodyType;
	}
	~body_type()
	{
		BodyType = "";
	}
};

class max_weight
{
protected: 
	uint32_t max_wei;
	max_weight()
	{
		std::cout << "Enter max weight: ";
		std::cin >> max_wei;
	}
	~max_weight()
	{
		max_wei = NULL;
	}
};

class weight
{
protected:
	uint32_t Wgt;
	weight()
	{
		std::cout << "Enter weight: ";
		std::cin >> Wgt;
	}
	~weight()
	{
		Wgt = NULL;
	}
};

class car : public body_type, public dors_col,
	public engine_V, public wheel_R, public weight
{
protected:
	std::string Name; 
public:
	car()
	{
		std::cout << "Enter car name: ";
		std::cin >> Name;
	}
	void print() const
	{
		
		std::cout << "\nName: " << Name << std::endl;
		std::cout << "Body type: " << BodyType << std::endl;
		std::cout << "Engine V: " << EngineV << std::endl;
		std::cout << "Wheel R: " << WheelR << std::endl;
		std::cout << "Dors col: " << DorsCol << std::endl;
		std::cout << "Weight: " << Wgt << std::endl;
	}
	~car()
	{
		Name = "";
	}
};

class truck final : public car, public max_weight
{
public:
	void print_truck() const
	{
		print();
		std::cout << "Max weight: " << max_wei << std::endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	uint16_t car_col = 0;

	std::cout << "Enter car col: ";
	std::cin >> car_col;

	std::vector<car> my_cars;

	for (int i = 0; i < car_col; ++i)
	{
		std::cout << std::endl;
		my_cars.emplace_back();
	}

	for (int i = 0; i < car_col; ++i)
	{
		my_cars[i].print();
	}

	uint16_t truck_col;

	std::cout << std::endl;
	std::cout << "Enter truck col: ";
	std::cin >> truck_col;

	std::vector<truck> my_trucks;
	for (int i = 0; i < car_col; ++i)
	{
		std::cout << std::endl;
		my_trucks.emplace_back();
	}

	for (int i = 0; i < car_col; ++i)
	{
		my_trucks[i].print_truck();
	}
	
	system("pause");
	return 0;
}
