#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

struct Command
{
	virtual ~Command () = default;
	virtual void execute () const = 0;
};

/* <<Interface for smart bulb>> */
struct ISmartBulb {
	virtual void dim () = 0;
	virtual void light () = 0;
	virtual void on () = 0;
	virtual void off () = 0;
};

struct HavelsBulb : ISmartBulb {
	virtual void dim (){
		std::cout << "Diming the havels light bulb" << std::endl;
	}
	virtual void light (){
		std::cout << "Increasing intensity of havels light bulb" << std::endl;
	}
	virtual void on (){
		std::cout << "Switch on havels light bulb" << std::endl;
	}
	virtual void off (){
		std::cout << "Switch off havels light bulb" << std::endl;
	}
};

struct PhillipsBulb : ISmartBulb {
	virtual void dim (){
		std::cout << "Diming the phillips light bulb" << std::endl;
	}
	virtual void light (){
		std::cout << "Increasing intensity of phillips light bulb" << std::endl;
	}
	virtual void on (){
		std::cout << "Switch on phillips light bulb" << std::endl;
	}
	virtual void off (){
		std::cout << "Switch off phillips light bulb" << std::endl;
	}
};

/* Invoker */
/* Interface for any command 
		Remote Interface : 
		[* - on off twinkle]
*/
struct ConfigurableRemote {
	ISmartBulb* smartbulb;
	ConfigurableRemote (ISmartBulb* smartbulb) : smartbulb (smartbulb) {}
	void OnBtn () {
		smartbulb->on();
	}
	void OffBtn () {
		smartbulb->off();
	}
	void DimBtn () {
		smartbulb->dim();
	}
	void LightBtn () {
		smartbulb->light();
	}
	void TwinkleBtn () {
		std::cout << "Start of twinkling ...\n" << std::endl;
		for (int i=0;i<10;i++) {
			if (i&1) smartbulb->light();
			else smartbulb->dim();
		}
		std::cout << "\nEnd of twinkling ..." << std::endl;
	}
};