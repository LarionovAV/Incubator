#pragma once
#include "Incubator.h"
template <class T>
class IncubatorBuilder {
protected:
	T* product;
public:
	virtual void Reset() = 0;
	virtual void SetTempAnalizator() = 0;
	virtual void SetWetAnalizator() = 0;
	virtual void SetTempRegulator() = 0;
	virtual void SetWetRegulator() = 0;
	virtual T* GetProduct() = 0;
};

class ConcretteIncubatorBuilder1 : public IncubatorBuilder<Incubator>{
private:
	Incubator *product;
public:
	ConcretteIncubatorBuilder1() {
		product = new Incubator();
	}
	void Reset() {
		delete product;
		product = new Incubator();
	}

	void SetTempAnalizator() {
		product->SetTempAnalizator(new TemperatureAnalizator());
	}
	void SetTempRegulator() {
		product->SetTempRegulator(new TemperatureRegulator());
	}
	void SetWetAnalizator() {
		product->SetWetAnalizator(new WetAnalizator());
	}
	void SetWetRegulator() {
		product->SetWetRegulator(new WetRegulator());
	}

	Incubator* GetProduct() {
		return product;
	}
};

class ConcretteIncubatorBuilder2 : public IncubatorBuilder<Incubator> {
public:
	ConcretteIncubatorBuilder2() {
		product = new Incubator();
	}
	void Reset() {
		delete product;
		product = new Incubator();
	}

	void SetTempAnalizator() {
		product->SetTempAnalizator(new Dinamic(new Lamp(new TemperatureAnalizator())));
	}
	void SetTempRegulator() {
		product->SetTempRegulator(new TemperatureRegulator());
	}
	void SetWetAnalizator() {
		product->SetWetAnalizator(new Dinamic(new WetAnalizator()));
	}
	void SetWetRegulator() {
		product->SetWetRegulator(new WetRegulator());
	}

	Incubator* GetProduct() {
		return product;
	}
};