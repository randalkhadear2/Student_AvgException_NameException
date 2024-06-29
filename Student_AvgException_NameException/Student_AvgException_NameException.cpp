// Student_AvgException_NameException.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>

using namespace std;


class AvgException : public exception {
public:
	const char* what() const throw() {
		return "can not enter the avg less than 0!! ";
	}
};

class NameException : public exception {
public:
	const char* what() const throw() {
		return "Name should be  15 characters  or less";
	}
};


class Student {
	int avg;
	string name;
public:
	Student() {
		avg = 0;
		name = "";
	}
	Student(int a, string n) {
		if (avg <= -1) {
			throw AvgException();
		}

		if (name.length() > 15) {
			throw NameException();
		}

	}
	string get_name() {
		return name;
	}
	int get_avg() {
		return avg;
	}

	void set_name(string n) {
		name = n;
	}
	void set_avg(int i) {
		avg = i;
	}
};
int main()
{

	try {
		Student s1(-1, "rand");

	}
	catch (exception* e) { // what
		cout << e->what() << endl;
	}


	try {
		Student s1(1, "randjsjsjjsnsjsjsjsjs");

	}
	catch (exception* e) { // what
		cout << e->what() << endl;
	}



}
