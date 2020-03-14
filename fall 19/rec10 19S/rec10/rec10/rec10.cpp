#include <iostream>
#include <vector>
using namespace std;

class Instrument
{
public:
	virtual void makeSound() const = 0;
	
private:

};
void Instrument::makeSound() const
{
	cout << "To make a sound... ";
}
class Brass:public Instrument
{
public:
	Brass(const unsigned size) :size(size) {}
	void makeSound() const
	{
		Instrument::makeSound();
		cout << " blow on a mouthpiece of size " << size << endl;
	}
private:
	const unsigned size;
};

class Trombone:public Brass
{
public:
	Trombone(const unsigned size) :Brass(size) {};

private:

};

class Trumpet :public Brass
{
public:
	Trumpet(const unsigned size) :Brass(size) {};
private:
};

class String:public Instrument
{
public:
	String(const unsigned pitch) :pitch(pitch) {}
	void makeSound() const
	{
		Instrument::makeSound();
		cout << "bow a string with pitch "<< pitch << endl;
	}
private:
	const unsigned pitch;
};

class Violin:public String
{
public:
	Violin(const unsigned pitch) : String(pitch) {}
private:
};

class Cello:public String
{
public:
	Cello(const unsigned pitch) : String(pitch) {}
private:
};

class Precussion:public Instrument
{
public:
	Precussion() = default;
	void makeSound() const
	{
		Instrument::makeSound();
		cout << " hit me!" << endl;
	}
private:
};

class Drum :public Precussion
{
public:
	Drum() :Precussion(){}
private:
};

class Cymbal :public Precussion
{
public:
	Cymbal() :Precussion() {}
private:
};

class Musician
{
public:
	Musician() : instr(nullptr) {}

	void acceptInstr(Instrument* instPtr) { instr = instPtr; }

	Instrument* giveBackInstr() {
		Instrument* result(instr);
		instr = nullptr;
		return result;
	}

	void testPlay() const {
		if (instr) instr->makeSound();
		else cerr << "have no instr\n";
	}

private:
	Instrument* instr;
};
class MILL
{
public:
	void receiveInstr(Instrument& inst)
	{
		inst.makeSound();
		for (size_t i = 0; i < bin.size(); i++)
		{
			if (bin[i] == nullptr)
			{
				bin[i] = &inst;
				return;
			}
		}
		bin.push_back(&inst);
	}
	void dailyTestPlay()
	{
		for (size_t i = 0; i < bin.size(); i++)
		{
			if (bin[i] != nullptr)
			{
				bin[i]->makeSound();
			}
		}
	}
	Instrument* loanOut()
	{
		Instrument* loan = nullptr;
		for (size_t i = 0; i < bin.size(); i++)
		{
			if (bin[i] != nullptr)
			{
				loan = bin[i];
				bin[i] = nullptr;
				return loan;

			}
		}
		return nullptr;
	}
private:
	vector<Instrument*> bin;
};


// PART ONE
int main() {

	cout << "Define some instruments ------------------------------------\n";
	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone(4);
	Trumpet trpt(12);
	Violin violin(567);

	//use the debugger to look at the mill
	cout << "Define the MILL --------------------------------------------\n";
	MILL mill;

	cout << "Put the instruments into the MILL --------------------------\n";
	mill.receiveInstr(trpt);
	mill.receiveInstr(violin);
	mill.receiveInstr(tbone);
	mill.receiveInstr(drum);
	mill.receiveInstr(cello);
	mill.receiveInstr(cymbal);

	cout << "Daily test -------------------------------------------------\n";
	cout << endl;
	cout << "dailyTestPlay()" << endl;
	mill.dailyTestPlay();
	cout << endl;

	cout << "Define some Musicians---------------------------------------\n";
	Musician harpo;
	Musician groucho;

	cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
	groucho.testPlay();
	cout << endl;
	groucho.acceptInstr(mill.loanOut());
	cout << endl;
	groucho.testPlay();
	cout << endl;
	cout << "dailyTestPlay()" << endl;
	mill.dailyTestPlay();

	cout << endl << endl;

	groucho.testPlay();
	cout << endl;
	mill.receiveInstr(*groucho.giveBackInstr());
	harpo.acceptInstr(mill.loanOut());
	groucho.acceptInstr(mill.loanOut());
	cout << endl;
	groucho.testPlay();
	cout << endl;
	harpo.testPlay();
	cout << endl;
	cout << "dailyTestPlay()" << endl;
	mill.dailyTestPlay();

	cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";

	//  fifth
	mill.receiveInstr(*groucho.giveBackInstr());
	cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
	mill.receiveInstr(*harpo.giveBackInstr());


	cout << endl;
	cout << "dailyTestPlay()" << endl;
	mill.dailyTestPlay();
	cout << endl;

	cout << endl;
}