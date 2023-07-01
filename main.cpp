#include <iostream>
#include <string>

class Animal {
private:
	std::string metabolism_level;
	std::string body_temperature_dependency;
	std::string skin_covering;
	std::string type_of_breath;
	int heart_chamber_count;
public:
	Animal(std::string metabolism_level,
			std::string body_temperature_dependency,
			std::string skin_covering,
			std::string type_of_breath,
			int heart_chamber_count) 
	{
		this -> metabolism_level = metabolism_level;
		this->body_temperature_dependency = body_temperature_dependency;
		this->skin_covering = skin_covering;
		this->type_of_breath = type_of_breath;
		this->heart_chamber_count = heart_chamber_count;
	}
	~Animal() {};
public:
	virtual void voice() = 0;
protected:	
	void get_a_data() {
		std::cout << "Metabolism level: " << this->metabolism_level << ";" << std::endl;
		std::cout << "Body temperature: " << this->body_temperature_dependency << ";" << std::endl;
		std::cout << "Skin cover: " << this->skin_covering << ";" << std::endl;
		std::cout << "Breath: " << this->type_of_breath << ";" << std::endl;
		std::cout << "Heart: " << this->heart_chamber_count << "-chambered;" << std::endl;
	}
};


class Mammal : public Animal {
private:
	std::string family;
public:
	Mammal(std::string family) : Animal("high", "independent", "fur", "only lungs", 4) {
		this->family = family;
	}
	~Mammal() {};
protected:
	void get_m_data() {
		std::cout << "Family : " << this->family << ";" << std::endl;
		this->get_a_data();
	}
};

class Lion : public Mammal {
private:
	std::string type;
public:
	Lion(std::string type) : Mammal("feline") {
		this->type = type + " lion";
	}
	void voice() override {
		std::cout << "I'm roaring." << std::endl;
	};
	~Lion() {};
	void get_data() {
		std::cout << "Type : " << this->type << ";" << std::endl;
		this->get_m_data();
		this->voice();
	}
};



int main() {

	Lion l("white");
	l.get_data();

	return 0;
}