/*
  Abed Islam rec05.cpp
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Section
{
public:
	Section(Section& toCopy)
	{
		this->section = toCopy.section;
		this->timeSec = toCopy.timeSec;
		for (int i = 0; i < this->studentVec.size(); i++)
		{
			toCopy.studentVec.push_back(new Student(*this->studentVec[i]));
			toCopy.studentVec[i]->getGrades() = this->studentVec[i]->getGrades();

			
		}
	}
	~Section()
	{
		for (int i = 0; this->studentVec.size(); i++)
		{
			delete this->studentVec[i];
		}
	}
	Section() 
	{
		this->section = "does not have a section";
	}
	Section(string nameOfSection,string day,unsigned int time)
	{
		this->section = nameOfSection;
		this->timeSec = TimeSlot(day, time);
	}
	string getSection()
	{
		return this->section;
	}
	
	void addStudent(string name)
	{
		this->studentVec.push_back(new Student(name));
	}
	void changeGrade(string name, int grade, int week)
	{
		int index = 0;
		for (int i = 0; i < this->studentVec.size(); i++)
		{
			if (this->studentVec[i]->getName() == name)
			{
				index = i;
			}
		}
		this->studentVec[index]->changeGrade(grade,week);
	}
	friend ostream& operator <<(ostream& os,Section sec);


private:
	class TimeSlot
	{
	public:
		TimeSlot() {}
		TimeSlot(string day,unsigned int time)
		{
			this->day = day;
			this->time = time;
		}
		string getDay()
		{
			return this->day;
		}
		unsigned int getTime()
		{
			return this->time;
		}

	private:

		string day;
		unsigned int time;
	};
	class Student
	{
	public:
		Student() {}
		Student(string name)
		{
			this->name = name;
			this->grades = grades;
		}
		string getName()
		{
			return this->name;
		}
		vector<int> getGrades()
		{
			return this->grades;
		}
		void changeGrade(int grade, int week)
		{
			this->grades[week-1] = grade;
		}
	private:
		string name;
		vector<int> grades{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	};
	string section;
	vector<Student*> studentVec;
	TimeSlot timeSec;


};
class LabWorker
{
public:
	LabWorker() {}
	LabWorker(string name)
	{
		this->name = name;
	}
	LabWorker(string name, Section s)
	{
		this->name = name;
		this->sec = s;
	}
	void addSection(Section section)
	{
		this->sec = Section(section);
	}
	void addGrade(string name, int grade, int week) 
	{
		this->sec.changeGrade(name, grade, week);
	}
	friend ostream& operator <<(ostream& os, LabWorker rat);
	
private:
	string name;
	Section sec;
};
ostream& operator <<(ostream& os, Section sec);
// Test code
void doNothing(Section sec) { cout << sec << endl; }


int main() 
{

	cout << "Test 1: Defining a section\n";
	Section secA2("A2", "Tuesday", 16);
	cout << secA2 << endl;

	cout << "\nTest 2: Adding students to a section\n";
	secA2.addStudent("John");
	secA2.addStudent("George");
	secA2.addStudent("Paul");
	secA2.addStudent("Ringo");
	cout << secA2 << endl;

	cout << "\nTest 3: Defining a lab worker.\n";
	LabWorker moe( "Moe" );
	cout << moe << endl;

	cout << "\nTest 4: Adding a section to a lab worker.\n";
	 moe.addSection( secA2 );
	 cout << moe << endl;

	cout << "\nTest 5: Adding a second section and lab worker.\n";
	LabWorker jane( "Jane" );
	Section secB3( "B3", "Thursday", 11 );
	secB3.addStudent("Thorin");
	secB3.addStudent("Dwalin");
	secB3.addStudent("Balin");
	secB3.addStudent("Kili");
	secB3.addStudent("Fili");
	secB3.addStudent("Dori");
	secB3.addStudent("Nori");
	secB3.addStudent("Ori");
	secB3.addStudent("Oin");
	secB3.addStudent("Gloin");
	secB3.addStudent("Bifur");
	secB3.addStudent("Bofur");
	secB3.addStudent("Bombur");
	jane.addSection( secB3 );
	cout << jane << endl;
	/*
	cout << "\nTest 6: Adding some grades for week one\n";
	 moe.addGrade("John", 17, 1);  
	 moe.addGrade("Paul", 19, 1);  
	 moe.addGrade("George", 16, 1);  
	 moe.addGrade("Ringo", 7, 1);  
	 cout << moe << endl;

	cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
	moe.addGrade("John", 15, 3);  
	moe.addGrade("Paul", 20, 3);  
	moe.addGrade("Ringo", 0, 3);  
	moe.addGrade("George", 16, 3);  
	cout << moe << endl;
	*/

	cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
		<< "those students (or rather their records?)\n";

	cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
		<< "then make sure the following call works:\n";
	doNothing(secA2);
	cout << "Back from doNothing\n\n";

} // main


ostream& operator<<(ostream& os, LabWorker rat)
{
	os << rat.name << rat.sec;
	return os;

}

ostream& operator <<(ostream& os, Section sec)
{
	os << sec.getSection() << " "  << sec.timeSec.getDay() << " " << sec.timeSec.getTime();
	if (sec.studentVec.size() == 0)
	{
		os << "Student:" << "none";
	}
	else
	{
		for (int i = 0; i < sec.studentVec.size(); i++)
		{
			os << sec.studentVec[i]->getName() << endl;
			for (int j = 0; j < sec.studentVec[i]->getGrades().size(); j++)
			{
				os << sec.studentVec[i]->getGrades()[j] << endl;
			}
		}
	}
	return os;
}
