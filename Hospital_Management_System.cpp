#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
    string gender;

public:
    Person(const string& n, int a, const string& g) : name(n), age(a), gender(g) {}

    virtual void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age << ", Gender: " << gender << endl;
    }
};

class Patient : public Person {
private:
    int patientID;

public:
    Patient(const string& n, int a, const string& g, int id) : Person(n, a, g), patientID(id) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << endl;
    }
};

class Doctor : public Person {
private:
    string specialization;

public:
    Doctor(const string& n, int a, const string& g, const string& s) : Person(n, a, g), specialization(s) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Specialization: " << specialization << endl;
    }
};

// Similar classes for Nurse, Staff, etc.

class Hospital {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    // other staff lists

public:
    void addPatient(const Patient& p) {
        patients.push_back(p);
    }

    void addDoctor(const Doctor& d) {
        doctors.push_back(d);
    }

    // functions to search, display, and manage data for patients, doctors, etc.
};

int main() {
    Patient p1("John Doe", 35, "Male", 1001);
    Doctor d1("Dr. Smith", 45, "Female", "Cardiology");

    Hospital hospital;
    hospital.addPatient(p1);
    hospital.addDoctor(d1);

    // Perform operations like displaying patient records, adding new staff, etc.

    return 0;
}
