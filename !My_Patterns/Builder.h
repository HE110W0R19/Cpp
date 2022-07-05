#include <iostream>
#include <string>
#include <map>
using namespace std;
//1.Общий алгоритм построения сложного объекта не должен зависеть
//от специфики каждого из его шагов.
//2. В результате одного и того же алгоритма конструирования надо
// получить различные продукты.

//базовый класс для летального устройства
class Aircraft {
public:
	Aircraft(string);
	virtual ~Aircraft();
private:
	//тип летательного устройства
	string aircraftType;
	//хранилище информации об устройстве
	map<string, string> parts;
public:
	//получение информации о конкретной  части устройства 
	string GetPart(const string& key) {
		if (!CheckForPart(key)) {
			throw "There is no such key!";
		}
		return parts[key];
	}
	//установка значения для конкретной части устройства 
	void SetPart(const string& key, const string& value) {
		parts[key] = value;
	}
	//проверка на наличие части
	bool CheckForPart(const string& key)
	{
		return parts.find(key) != parts.end() ? true : false;
	}
	//отображение информации об летательном устройстве 
	void Show();
};
Aircraft::Aircraft(string type) { aircraftType = type; }
Aircraft::~Aircraft() { }
void Aircraft::Show() {
	cout << "\n====================\n";
	cout << "Aircraft Type:" << aircraftType << endl;
	cout << "Frame:" << parts["frame"] << endl;
	cout << "Engine:" << parts["engine"] << endl;
	cout << "Wheels:" << parts["wheels"] << endl;
	cout << "Doors:" << parts["doors"] << endl;
}

// абстрактный класс строителя 
class AircraftBuilder {
public:
	AircraftBuilder() {};
	virtual ~AircraftBuilder() {};
protected:
	Aircraft* aircraft;
public:
	Aircraft* GetAircraft() { return aircraft; }
	virtual void BuildFrame() = 0;
	virtual void BuildEngine() = 0;
	virtual void BuildWheels() = 0;
	virtual void BuildDoors() = 0;
	virtual void BuildWings() = 0;
};

//Класс строителя. Умеет создавать дельтапланы 
class HangGliderBuilder :public AircraftBuilder {
public:
	HangGliderBuilder();
	virtual ~HangGliderBuilder();
public:
	void BuildFrame();
	void BuildEngine();
	void BuildWheels();
	void BuildDoors();
	void BuildWings();
};
HangGliderBuilder::HangGliderBuilder() {
	aircraft = new Aircraft("Hang Glider");
}
HangGliderBuilder::~HangGliderBuilder() { delete aircraft; }
void HangGliderBuilder::BuildFrame() {
	aircraft->SetPart("frame", "Hang glider frame");
}
void HangGliderBuilder::BuildEngine() {
	aircraft->SetPart("engine", "no engine");
}
void HangGliderBuilder::BuildWheels() {
	aircraft->SetPart("wheels", "no wheels");
}
void HangGliderBuilder::BuildDoors() {
	aircraft->SetPart("doors", "no doors");
}
void HangGliderBuilder::BuildWings() {
	aircraft->SetPart("wings", "1");
}

//Класс строителя. Умеет создавать планеры 
class GliderBuilder : public AircraftBuilder {
public:
	GliderBuilder();
	virtual ~GliderBuilder();
public:
	void BuildFrame();
	void BuildEngine();
	void BuildWheels();
	void BuildDoors();
	void BuildWings();
};
GliderBuilder::GliderBuilder()
{
	aircraft = new Aircraft("Glider");
}
GliderBuilder::~GliderBuilder() { delete aircraft; }
void GliderBuilder::BuildFrame() {
	aircraft->SetPart("frame", "Glider frame");
}
void GliderBuilder::BuildEngine() {
	aircraft->SetPart("engine", "no engine");
}
void GliderBuilder::BuildWheels() {
	aircraft->SetPart("wheels", "1");
}
void GliderBuilder::BuildDoors() {
	aircraft->SetPart("doors", "1");
}
void GliderBuilder::BuildWings() {
	aircraft->SetPart("wings", "2");
}

/* класс директора умеет создавать конкретный продукт
с помощью строителя */
class AircraftConstructor {
	AircraftBuilder* _build;
public:
	AircraftConstructor();
	virtual ~AircraftConstructor();
	void Construct(AircraftBuilder* aircraftBuilder);
};
AircraftConstructor::AircraftConstructor() { }
AircraftConstructor::~AircraftConstructor() { }
void AircraftConstructor::Construct(AircraftBuilder* aircraftBuilder)
{
	aircraftBuilder->BuildFrame();
	aircraftBuilder->BuildEngine();
	aircraftBuilder->BuildWheels();
	aircraftBuilder->BuildDoors();
}
int main1() {
	try {
		AircraftBuilder* builder;
		//Создаем объект класса директора 
		AircraftConstructor* shop = new AircraftConstructor();
		//Создаем объект класса строителя.  
		//Этот объект умеет создавать дельтапланы 
		builder = new HangGliderBuilder();
		//сооружаем дельтаплан
		shop->Construct(builder);
		//показываем информацию о дельтаплане 
		builder->GetAircraft()->Show();
		//Создаем объект класса строителя.  
		//Этот объект умеет создавать планеры 
		delete builder;
		builder = new GliderBuilder();
		//сооружаем планер  
		shop->Construct(builder);
		//показываем информацию о планере
		builder->GetAircraft()->Show();
		delete builder;
		delete shop;
	}
	catch (char* str) { cout << endl << str << endl; }
	return 0;
}

