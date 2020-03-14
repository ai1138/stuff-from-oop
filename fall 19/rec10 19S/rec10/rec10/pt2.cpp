#include <iostream>
#include <vector>
using namespace std;

class Instrument
{
public:
	virtual void makeSound() const = 0;
	virtual void play() const = 0;

private:

};
void Instrument::makeSound() const
{
	cout << "To make a sound... ";
}
class Brass :public Instrument
{
public:
	Brass(const unsigned size) :size(size) {}
	void makeSound() const
	{
		Instrument::makeSound();
		cout << " blow on a mouthpiece of size " << size;
	}
private:
	const unsigned size;
};

class Trombone :public Brass
{
public:
	Trombone(const unsigned size) :Brass(size) {};
	void play()const
	{
		cout << "BLAT" << endl;
	}

private:

};

class Trumpet :public Brass
{
public:
	Trumpet(const unsigned size) :Brass(size) {};
	void play()const
	{
		cout << "Toot" << endl;
	}
private:
};

class String :public Instrument
{
public:
	String(const unsigned pitch) :pitch(pitch) {}
	void makeSound()const
	{
		Instrument::makeSound();
		cout << "bow a string with pitch " << pitch << endl;
	}
private:
	const unsigned pitch;
};

class Violin :public String
{
public:
	Violin(const unsigned pitch) : String(pitch) {}
	void play()const
	{
		cout << "Screech" << endl;
	}
private:
};

class Cello :public String
{
public:
	Cello(const unsigned pitch) : String(pitch) {}
	void play()const
	{
		cout << "Squawk" << endl;
	}
private:
};

class Precussion :public Instrument
{
public:
	Precussion() = default;
	void makeSound()const
	{
		Instrument::makeSound();
		cout << " hit me!" << endl;
	}
private:
};

class Drum :public Precussion
{
public:
	Drum() :Precussion() {}
	void play()const
	{
		cout << "Boom" << endl;
	}
private:
};

class Cymbal :public Precussion
{
public:
	Cymbal() :Precussion() {}
	void play()const
	{
		cout << "Crash" << endl;
	}
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
	void playing() const
	{
		 instr->play();
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
	}
private:
	vector<Instrument*> bin;
};
class Orch
{
public:

private:
	vector<Musician* const> players;
};



int main() 
{
	// The initialization phase

	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone(4);
	Trumpet trpt(12);
	Violin violin(567);

	MILL mill;
	mill.receiveInstr(trpt);
	mill.receiveInstr(violin);
	mill.receiveInstr(tbone);
	mill.receiveInstr(drum);
	mill.receiveInstr(cello);
	mill.receiveInstr(cymbal);

	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orch orch;

	// THE SCENARIO

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(bob);

	//The orchestra performs
	cout << "orch performs\n";
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr(mill.loanOut());
	orch.addPlayer(sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr(mill.loanOut());

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr(mill.loanOut());
	orch.addPlayer(mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr(*ralph.giveBackInstr());

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr(mill.loanOut());
	orch.addPlayer(jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr(mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(ralph);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	// bob gets an instrument from the MIL2
	bob.acceptInstr(mill.loanOut());

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr(mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(morgan);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

} // main

