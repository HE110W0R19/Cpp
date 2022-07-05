#include <iostream>
//1. Система не должна зависеть от того, как в ней создаются и 
//компонуются объекты.
//2. Объекты, входящие в семейство, должны использоваться вместе.
//3. Система должна конфигурироваться одним из семейств объектов.
//4.Надо предоставить интерфейс библиотеки, не раскрывая её внутренней реализации

class Box {};
class SilverBox :public Box {};
class BlackBox :public Box {};

class Processor {};
class IntelProcessor : public Processor {};
class AmdProcessor :public Processor {};

class MainBoard {};
class MSIMainBord :public MainBoard {};
class AsusMainBord :public MainBoard {};

class Hdd {};
class SamsungHDD :public Hdd {};
class LGHDD :public Hdd {};

class Memory {};
class Ddr2Memory :public Memory {};
class DdrMemory : public Memory {};


//класс, описывающий компьютер  и его составляющие //

class PC {
	Box* box;
	Processor* processor;
	MainBoard* mainBoard;
	Hdd* hdd;
	Memory* memory;
public:
	PC() {
		box = NULL;
		processor = NULL;
		mainBoard = NULL;
		hdd = NULL;
		memory = NULL;
	}
	virtual ~PC() {
		if (box)
			delete box;
		if (processor)
			delete processor;
		if (mainBoard)
			delete mainBoard;
		if (hdd)
			delete hdd;
		if (memory)
			delete memory;
	}
	Box* GetBox() { return box; }
	void SetBox(Box* pBox) { box = pBox; }
	Processor* GetProcessor() { return processor; }
	void SetProcessor(Processor* pProcessor) {
		processor = pProcessor;
	}
	MainBoard* GetMainBoard() { return mainBoard; }
	void SetMainBoard(MainBoard* pMainBoard) {
		mainBoard = pMainBoard;
	}
	Hdd* GetHdd() { return hdd; }
	void SetHdd(Hdd* pHdd) { hdd = pHdd; }
	Memory* GetMemory() { return memory; }
	void SetMemory(Memory* pMemory) { memory = pMemory; }
};


/* * Интерфейс фабрики для создания конфигурации
* системного блока персонального компьютера */
class IPCFactory {
public: 
	virtual Box* CreateBox() = 0; 
	virtual Processor* CreateProcessor() = 0;
	virtual MainBoard* CreateMainBoard() = 0;
	virtual Hdd* CreateHdd() = 0; 
	virtual Memory* CreateMemory() = 0;
};


/* * Фабрика для создания "домашней" конфигурации
* системного блока персонального компьютера */
class HomePcFactory : public  IPCFactory {
public:
	Box* CreateBox() { return new SilverBox(); }
	Processor* CreateProcessor() { return new IntelProcessor(); }
	MainBoard* CreateMainBoard() { return new MSIMainBord(); }
	Hdd* CreateHdd() { return new SamsungHDD(); }
	Memory* CreateMemory() { return new Ddr2Memory(); }
};

/* * Фабрика для создания "офисной" конфигурации
* системного блока персонального компьютера */
class OfficePcFactory : public IPCFactory {
public:
	Box* CreateBox() { return new BlackBox(); }
	Processor* CreateProcessor() { return new AmdProcessor(); }
	MainBoard* CreateMainBoard() { return new AsusMainBord(); }
	Hdd* CreateHdd() { return new LGHDD(); }
	Memory* CreateMemory() { return new DdrMemory(); }
};
//class GamePcFactory : public IPCFactory {};
// класс конфигуратор 
class PcConfigurator {
	/* *  Фабрика составляющих персонального компьютера */
	IPCFactory* pcFactory;
public:
	PcConfigurator() { pcFactory = NULL; }
	virtual ~PcConfigurator() { if (pcFactory)   delete pcFactory; }
	IPCFactory* GetPCFactory() { return pcFactory; }
	void SetPCFactory(IPCFactory* pcCurrentFactory) { pcFactory = pcCurrentFactory; }
	/* *  Метод конфигурирования системного блока */
	void Configure(PC* pc) {
		pc->SetBox(pcFactory->CreateBox());
		pc->SetMainBoard(pcFactory->CreateMainBoard());
		pc->SetHdd(pcFactory->CreateHdd());
		pc->SetMemory(pcFactory->CreateMemory());
		pc->SetProcessor(pcFactory->CreateProcessor());
	}
};