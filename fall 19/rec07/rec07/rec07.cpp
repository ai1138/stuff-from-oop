/*
  rec07
  Starter Code for required functionality
  Yes, you may add other methods.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student;

class Course 
{
	friend ostream& operator<<(ostream& os, const Course& rhs);
public:
	// Course methods needed by Registrar
	Course(const string& courseName);
	const string& getName() const;
	bool addStudent(Student*);
	void removeStudentsFromCourse();

private:
	string name;
	vector<Student*> students;
};

class Student 
{
	friend ostream& operator<<(ostream& os, const Student& rhs);
public:
	// Student methods needed by Registrar
	Student(const string& name);
	const string& getName() const;
	bool addCourse(Course*);

	// Student method needed by Course
	void removedFromCourse(Course*);

private:
	string name;
	vector<Course*> courses;
};

class Registrar 
{
	friend ostream& operator<<(ostream& os, const Registrar& rhs);
public:
	Registrar();
	bool addCourse(const string&);
	bool addStudent(const string&);
	bool enrollStudentInCourse(const string& studentName,
		const string& courseName);
	bool cancelCourse(const string& courseName);
	void purge();

private:
	size_t findStudent(const string&) const;
	size_t findCourse(const string&) const;

	vector<Course*> courses;
	vector<Student*> students;
};

int main() 
{

	Registrar registrar;

	cout << "No courses or students added yet\n";
	cout << registrar << endl;

	cout << "AddCourse CS101.001\n";
	registrar.addCourse("CS101.001");
	cout << registrar << endl;

	cout << "AddStudent FritzTheCat\n";
	registrar.addStudent("FritzTheCat");
	cout << registrar << endl;

	cout << "AddCourse CS102.001\n";
	registrar.addCourse("CS102.001");
	cout << registrar << endl;

	cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
	registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
	cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
	registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
	cout << registrar << endl;

	cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
	cout << "Should fail, i.e. do nothing, "
		<< "since Bullwinkle is not a student.\n";
	registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
	cout << registrar << endl;

	cout << "CancelCourse CS102.001\n";
	registrar.cancelCourse("CS102.001");
	cout << registrar << endl;

	/*
	// [OPTIONAL - do later if time]
	cout << "ChangeStudentName FritzTheCat MightyMouse\n";
	registrar.changeStudentName("FritzTheCat", "MightyMouse");
	cout << registrar << endl;

	cout << "DropStudentFromCourse MightyMouse CS101.001\n";
	registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
	cout << registrar << endl;

	cout << "RemoveStudent FritzTheCat\n";
	registrar.removeStudent("FritzTheCat");
	cout << registrar << endl;
	*/

	cout << "Purge for start of next semester\n";
	registrar.purge();
	cout << registrar << endl;
}

ostream& operator<<(ostream& os, const Course& rhs)
{
	os << rhs.getName() << endl;
	if (rhs.students.size() == 0)
	{
		os << "no students in this course" ;
	}
	else
	{
		for (size_t i = 0; i < rhs.students.size(); i++)
		{
			os << rhs.students[i]->getName()<<endl;
		}
	}
	return os;
}

ostream& operator<<(ostream& os, const Student& rhs)
{
	os << rhs.getName() + ":" << endl;
	if (rhs.courses.size() == 0 )
	{
		os << "no courses" << endl;
	}
	else
	{
		for (size_t i = 0; i < rhs.courses.size(); i++)
		{
			os << rhs.courses[i]->getName()<<endl;
		}

	}
	return os;
}

ostream& operator<<(ostream& os, const Registrar& rhs)
{
	os << "courses:" << endl;
	for (size_t i = 0; i < rhs.courses.size(); i++)
	{
		os << *(rhs.courses[i]);
	}
	os << "students:" << endl;
	for (size_t i = 0; i < rhs.students.size(); i++)
	{
		os << *(rhs.students[i])<< endl;
	}
	return os;
}

Course::Course(const string& courseName)
{
	this->name = courseName;
}

const string& Course::getName() const
{
	return this->name;
}

bool Course::addStudent(Student* stu)
{
	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i] == stu)
		{
			return false;
		}
	}
	students.push_back(stu);
	return true;
}

void Course::removeStudentsFromCourse()
{
	for (size_t i = 0; i < students.size(); i++)
	{
		students[i]->removedFromCourse(this);
	}
	while (students.size() != 0)
	{
		students.pop_back();
	}
}

Student::Student(const string& name)
{
	this->name = name;

}

const string& Student::getName() const
{
	return this->name;
}

bool Student::addCourse(Course* curr)
{
	for (size_t i = 0; i < courses.size(); i++)
	{
		if (curr == courses[i])
		{
			return false;
		}
	}
	courses.push_back(curr);
	return true;
}

void Student::removedFromCourse(Course* curr)
{
	for(size_t i = 0; i < courses.size(); i++)
	{
		if (curr == courses[i])
		{
			courses[i] = courses[courses.size() - 1];
		}
	}
	courses.pop_back();
}

Registrar::Registrar() {}

bool Registrar::addCourse(const string& curr)
{
	if (this->findCourse(curr) < courses.size())
	{
		return false;
	}
	else
	{
		courses.push_back(new Course(curr));
		return true;
	}
}

bool Registrar::addStudent(const string& stu)
{
	if (this->findStudent(stu) < students.size())
	{
		return false;
	}
	else
	{
		students.push_back(new Student(stu));
		return true;
	}
}

bool Registrar::enrollStudentInCourse(const string& studentName, const string& courseName)
{
	size_t studentIdx = findStudent(studentName);
	size_t courseIdx = findCourse(courseName);
	if (studentIdx > students.size() || courseIdx > courses.size())
	{
		cout << "student doesn't exist";
		return false;
	}
	students[studentIdx]->addCourse(courses[courseIdx]);
	courses[courseIdx]->addStudent(students[studentIdx]);
	return true;

}

bool Registrar::cancelCourse(const string& courseName)
{
	size_t courseIdx = findCourse(courseName);
	if(courseIdx > courses.size())
		return false;
	courses[courseIdx]->removeStudentsFromCourse();
	courses[courseIdx] = courses[courses.size() - 1];
	courses.pop_back();
	return true;
}

void Registrar::purge()
{
	for (size_t i = 0; i < students.size(); i++)
	{
		delete students[i];
	}
	while (students.size() != 0)
	{
		students.pop_back();
	}
	for (size_t i = 0; i < courses.size(); i++)
	{
		delete courses[i];
	}
	while (courses.size() != 0)
	{
		courses.pop_back();
	}
}

size_t Registrar::findStudent(const string& stu) const
{
	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i]->getName() == stu)
		{
			return i;
		}
	}
	return SIZE_MAX;
}

size_t Registrar::findCourse(const string& curr) const
{
	for (size_t i = 0; i < courses.size(); i++)
	{
		if (courses[i]->getName() == curr)
		{
			return i;
		}
	}
	return SIZE_MAX;
}
