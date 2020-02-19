#include<iostream>
#include<string>
using namespace std;
/*
Скласти програму Світлофор з використанням патерну Стан(State).
*/

class Traffic_lights;

class State {
protected:
	Traffic_lights * lights_;

public:
	virtual ~State(){}

	void Set_lights(Traffic_lights * lights) {
		this->lights_ = lights;
	}
	virtual void State1() = 0;
	/*virtual void State2() = 0;
	virtual void State3() = 0;*/
};


class Traffic_lights {
private:
	State *state_;

public:
	Traffic_lights(State *state) : state_(nullptr) {
		this->Transition(state);
	}

	~Traffic_lights() {
		delete state_;
	}

	void Transition(State *state) {
		cout << "\n Traffic lights: Transition to " << typeid(*state).name();
		if (this->state_ != nullptr)
			delete this->state_;
		this->state_ = state;
		this->state_->Set_lights(this);
	}

	void Reqest1() {
		this->state_->State1();
	}
	/*void Reqest2() {
		this->state_->State2();
	}
	void Reqest3() {
		this->state_->State3();
	}*/

};


class Grean_color : public State {
public:
	void State1()override {
		system("color 20");
		cout << "\n Traffic lights <-> GREAN" << endl;		
	}
	//void State2()override {}
	//void State3()override {}
};
class Yelow_color : public State {
public:
	//void State1()override {}
	void State1()override {
		system("color 60");
		cout << "\n Traffic lights <-> YELOW" << endl;		
	}
	//void State3()override {}
};

class Red_color : public State {
public:
	/*void State1()override {}
	void State2()override {}	*/
	void State1()override {
		system("color 40");
		cout << "\n Traffic lights <-> RED" << endl;		
	}
};

int main() {

	Traffic_lights *context = new Traffic_lights(new Grean_color);
	context->Reqest1();
	//context->Reqest2();
	//context->Reqest3();
	system("pause");

	context = new Traffic_lights(new Yelow_color);
	context->Reqest1();
    /*context->Reqest2();
	context->Reqest3()*/;
	system("pause");

	context = new Traffic_lights(new Red_color);
	context->Reqest1();
	/*context->Reqest2();
	context->Reqest3();*/
	delete context;

	system("pause");
	return 0;
}