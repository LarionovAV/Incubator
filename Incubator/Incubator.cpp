#include "pch.h"
#include <conio.h>
#include "Builder.h"
#include "Factory.h"

int main() {

	//LR3
	/*
	ProxyRegulator *pr = new ProxyRegulator(new WetRegulator());
	do {
		pr->ChangeParametr();
	} while (_getch() == 32);
	*/
	// LR4
	/*
	cout << "-----------Decorator-----------" << endl;
	Device *dev1 = new WetAnalizator();
	Device *dec1 = new Lamp(dev1);
	Device *dec2 = new Dinamic(dec1);

	cout << dev1->getDescription() << endl;
	dev1->DoAction();
	cout << "-------------------------------" << endl;
	cout << dec1->getDescription() << endl;
	dec1->DoAction();
	cout << "-------------------------------" << endl;
	cout << dec2->getDescription() << endl;
	dec2->DoAction();
	
	cout << "---------Decorator End---------" << endl << endl << endl;

	cout << "------------Adapter------------" << endl;
	Adapter *adp = new Adapter(new Barometr());
	adp->CheckParametr();
	cout << "----------Adapter End----------" << endl << endl << endl;

	cout << "-----------Composite-----------" << endl;
	Tray *composite = new Tray(500);
	Slot *s1 = new SingleEggSlot();
	Slot *s2 = new SingleEggSlot();
	Slot *s3 = new SingleEggSlot();
	Slot *s4 = new SingleEggSlot();
	Slot *s5 = new SingleEggSlot();
	s1->AddEgg(new HenEgg());
	s2->AddEgg(new TurkeyEgg());
	s3->AddEgg(new DuckEgg());
	s4->AddEgg(new HenEgg());
	s5->AddEgg(new DuckEgg());
	Tray *c1 = new Tray(240);
	Tray *c2 = new Tray(200);

	composite->AddSlot(c1);
	composite->AddSlot(s2);
	composite->AddSlot(c2);

	c1->AddSlot(s1);
	c1->AddSlot(s3);
	c1->AddSlot(s4);
	c2->AddSlot(s5);
	
	cout << ">>>Before sort<<<" << endl << endl << endl;
	IIterator<Slot*> *it = composite->CreateIterator();
	while (it->HasNext())
	{
		it->Next()->Display();
	}
	cout << ">>>After sort<<<" << endl << endl << endl;
	for (Slot* slot : it->SortCollection()) {
		slot->Display();
	}
	cout << "---------Composite End---------" << endl << endl << endl;
	*/

	// LR6
	/*
	cout << "----------Singleton----------" << endl;
	ExternalEnvironment *ex = ExternalEnvironment::getInstance(SEASON_FALL);
	ex->DisplaySeason();
	ex = ExternalEnvironment::getInstance(SEASON_SPRING);
	ex->DisplaySeason();
	cout << "--------Singleton End--------" << endl << endl;

	cout << "----------Prototype----------" << endl;
	Device *d1, *d2;
	d1 = new TemperatureAnalizator(10);
	cout << d1->getDescription() << endl;
	d2 = d1->Clone();
	cout << d2->getDescription() << endl;
	cout << "--------Prototype End--------" << endl << endl;

	cout << "-----------Builder-----------" << endl;
	IncubatorBuilder<Incubator> *b1 = new ConcretteIncubatorBuilder1();
	IncubatorBuilder<Incubator> *b2 = new ConcretteIncubatorBuilder2();

	b1->SetTempAnalizator();
	b1->SetTempRegulator();
	b1->SetWetAnalizator();
	b1->SetWetRegulator();

	b2->SetTempAnalizator();
	b2->SetTempRegulator();
	b2->SetWetAnalizator();
	b2->SetWetRegulator();

	cout << "********Builder1 product********" << endl;
	b1->GetProduct()->PrintInfo();
	cout << endl;
	cout << "********Builder2 product********" << endl;
	b2->GetProduct()->PrintInfo();
	cout << "---------Builder End---------" << endl << endl;

	cout << "------Abstract factory------" << endl;
	AbstractFactory *fac1 = new WetFactory();
	AbstractFactory *fac2 = new TemperatureFactory();
	cout << "*** Wet factory ***" << endl;
	fac1->CreateAnalizator()->PrintInfo();
	fac1->CreateRegulator()->PrintInfo();
	cout << "*** Temperature factory ***" << endl;
	fac2->CreateAnalizator()->PrintInfo();
	fac2->CreateRegulator()->PrintInfo();
	cout << "----Abstract factory End----" << endl << endl;
	*/
	//LR7
/*
	TemperatureAnalizator *ta = new TemperatureAnalizator();
	ta->DoAction();
	ta->ChangeStatement(DEVICE_ON);
	ta->DoAction();
	Snapshot* snp = ta->TakeSnapshot();
	ta->ChangeStatement(DEVICE_BROKEN);
	ta->DoAction();

	snp->Restore();
	ta->DoAction();

	Parametr* t = new Temperature(10, ta);
	t->ChangeParametr();
	*/

	//LR8
//Создадим инкубатор
	Incubator *inc = new Incubator();
	inc->SetTempAnalizator(new TemperatureAnalizator());
	inc->SetTempRegulator(new TemperatureRegulator());
	inc->SetWetAnalizator(new WetAnalizator());
	inc->SetWetRegulator(new WetRegulator());
//Установим фиктивную влажность
	Parametr *p = new Wet(50);
//Отправим вручную сообщение от наблюдаемого параметра
//Тем самым создадим и выполним команду включения
	((WetAnalizator*)(inc->GetWetAnalizator()))->Update(p);
//Зададим новое значение влажности
	p->setValue(85);
// Снова отправим сообщение от наблюдаемого объекта
// Тем самым создадим и выполним команду выключения
	((WetAnalizator*)(inc->GetWetAnalizator()))->Update(p);
//Выберем стратегию
	((Regulator*)(inc->GetTemperatureRegulator()))->SetMode(new NonStop());
	inc->GetTemperatureRegulator()->DoAction();
	
	system("pause");
	return 0;
}
