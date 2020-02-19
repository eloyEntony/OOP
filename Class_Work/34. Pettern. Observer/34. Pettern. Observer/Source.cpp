#include<iostream>
#include<string>
#include<list>
using namespace std;

/*
Створити програму з використанням патерну Спостерігач(Observer).
Предмет спостереження – курс долару(чи євро). Спостерігачі – клієнти(банк, брокер). При
збільшенні(зменшенні) курсу спостерігачі продають(купляють) валюту.
*/


class Iobserver {
public:
	virtual ~Iobserver() {};
	virtual void Update(const string &message_from_subject) = 0;
};

class Imessage {
public:
	virtual ~Imessage() {};
	virtual void Attach(Iobserver *observer) = 0;
	virtual void Detach(Iobserver *observer) = 0;
	virtual void Notify() = 0;
};

class Message : public Imessage {
private:
	list<Iobserver *> list_observer_;
	string message_;
public:
	virtual ~Message() {
		cout << " Goodbye, I was the Subject.\n";
	}
	void Attach(Iobserver *observer) override {
		list_observer_.push_back(observer);
	}
	void Detach(Iobserver *observer) override {
		list_observer_.remove(observer);
	}
	void Notify() override {
		list<Iobserver *>::iterator iterator = list_observer_.begin();
		HowManyObserver();
		while (iterator != list_observer_.end()) {
			(*iterator)->Update(message_);
			++iterator;
		}
	}
	void CreateMessage(std::string message = "Empty") {
		this->message_ = message;
		Notify();
	}
	void HowManyObserver() {
		cout << " There are " << list_observer_.size() << " observers in the list.\n";
	}	
	void SomeBusinessLogic() {
		this->message_ = "change message message";
		Notify();
		cout << " I'm about to do some thing important\n";
	}

};

class Observer : public Iobserver {
private:
	string message_from_subject_;
	Message &message_;
	static int static_number;
	int number;

public:
	Observer(Message &message) : message_(message) {
		this->message_.Attach(this);
		cout << " Hi i'm the Observer" << ++Observer::static_number << endl;
		this->number = Observer::static_number;
	}
	virtual ~Observer() {};

	void Update(const string &message_from_subject) override{
		message_from_subject_ = message_from_subject;
		Print();
	}

	void Remove_me_from_the_list(){
		message_.Detach(this);
		cout << " Observer " << number << " remove from list" << endl;
	}

	void Print() {
		cout << " Observer " << this->number << " a new message is available -> " << this->message_from_subject_ << endl;
	}
};

int Observer::static_number = 0;

int main()
{

	Message *message = new Message;

	Observer *observer1 = new Observer(*message);

	message->CreateMessage("30.3 $");



	delete observer1;
	delete message;


	system("pause");
	return 0;
}