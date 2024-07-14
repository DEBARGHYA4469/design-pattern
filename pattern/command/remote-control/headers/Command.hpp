#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

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

struct Button {
	function <void ()> fcn;
	Button (function <void ()> fcn) : fcn (fcn) {}
	Button () = default;
	void setfcn (function <void ()> fcn) { this->fcn = fcn; }
	void onPress () { fcn(); }
};

struct ConfigurableRemote {
	ISmartBulb* smartbulb;
	Button *OnBtn, *OffBtn, *DimBtn, *LightBtn, *TwinkleBtn;

	ConfigurableRemote (ISmartBulb* smartbulb) : smartbulb (smartbulb) {
		OnBtn = new Button ();
		OffBtn = new Button ();
		DimBtn = new Button ();
		LightBtn = new Button ();
		TwinkleBtn = new Button ();
	}

};