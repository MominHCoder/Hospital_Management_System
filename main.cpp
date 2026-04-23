#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


// Doctor and Treatment Class by Momin

class Doctor {
private:

    int doctorID;
    string doctorName;
    string doctorSpeciality;
    int experience;

public: //  constructor, it is called when an object of a class is created to initialize its data members
    Doctor() {
        doctorID = 0;
        experience = 0;
        doctorName = "";
        doctorSpeciality = "";
    }

// class getters

int get_doctorID() {return doctorID;}
string get_doctorName() {return doctorName;}
string get_doctorSpeciality() {return doctorSpeciality;}
int get_experience() {return experience;}

// class setters

void set_doctorID(int id) {doctorID = id;}
void set_doctorName(string n) {doctorName = n;}
void set_doctorSpeciality(string s) {doctorSpeciality = s;}
void set_experience(int e) {experience = e;}

};

class Treatment {
private:
    int patientID;
    string description; // details of our treatment
    double cost;
    bool paid; // this will be true if the bill is paid

public:
    Treatment() {
        patientID = 0;
        cost = 0.0;
        paid = false;
        description = "";
    }

    // getter of the class

    int get_patientID() {return patientID;}
    string get_description() {return description;}
    double get_cost() {return cost;}
    bool isPaid() {return paid;}


    // setter of the class

    void set_patientID(int id) {patientID = id;}
    void set_description(string d) {description = d;}
    void set_cost(double c) {cost = c;}
    void set_paid(bool p) {paid = p;}



};


// test case for checking of above classes will remove later

int main() {
     Doctor d;
     d.set_doctorID(201);
     d.set_doctorName("Dr.Moin Akhtar");
     d.set_doctorSpeciality("Neurosurgeon");
     d.set_experience(10);

     cout<<"== Doctor Results =="<<endl;
     cout<<"ID: "<<d.get_doctorID()<<endl;
     cout<<"Name: "<<d.get_doctorName()<<endl;
     cout<<"Speciality: "<<d.get_doctorSpeciality()<<endl;
     cout<<"Experience: "<<d.get_experience()<<" years "<<endl;


     Treatment t;
     t.set_patientID(101);
     t.set_description("Aneurysm Checkup");
     t.set_cost(1000);
     t.set_paid(true);

     cout<<"== Treatment Results =="<<endl;
     cout<<"ID: "<<t.get_patientID()<<endl;
     cout<<"Description: "<<t.get_description()<<endl;
     cout<<"Cost: "<<t.get_cost()<<endl;
     cout<<"Paid: "<<(t.isPaid() ? "Yes" : "No")<<endl;
}

