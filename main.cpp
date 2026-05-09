#include <iostream>
#include <string>
#include <fstream>
using namespace std;



// Helper Functions by Huzaifa and Momin

bool isNumber(string s){
    if(s.empty()){
        return false;
    }

    for(int i = 0; i<s.length();i++){
        if(!isdigit(s[i])){
            return false;
        }
    }
    return true;
}

// Splits a line by '#' delimiter and stores each part in the parts[] array
// Returns the number of parts found
// Example: "101#Ali Raza#25#Male" → parts[0]="101", parts[1]="Ali Raza", etc.
int splitLine(string line, string parts[], int maxParts) {
    int count = 0;      
    string current = ""; 

    for (int i = 0; i < (int)line.length(); i++) {
        
        if (line[i] == '#') {
            
            if (count < maxParts) {
                parts[count] = current;
                count++;
            }
            current = ""; // reset for next part
        } 
        else {
            
            current += line[i];
        }
    }

    if (count < maxParts && !current.empty()) {
        parts[count] = current;
        count++;
    }

    return count;
}


string trim(string s) {
    int start = 0, end = (int)s.length() - 1;
    while (start <= end && s[start] == ' ') start++;
    while (end >= start && s[end] == ' ') end--;
    if (start > end) return "";
    return s.substr(start, end - start + 1);
}

// toInt() and toDouble() written by Huzaifa Modified by Momin

int toInt(string s) {
    if (s.empty()) return 0;
    int result = 0;
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) return 0;
        result = result * 10 + (s[i] - '0');
    }
    return result;
}

double toDouble(string s) {
    if (s.empty()) return 0.0;
    double result = 0.0;
    double decimal = 0.1;
    bool afterDot = false;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.') {
            afterDot = true;
        } 
        else if (isdigit(s[i])) {
            if (!afterDot) {
                result = result * 10 + (s[i] - '0');
            } else {
                result = result + (s[i] - '0') * decimal;
                decimal = decimal * 0.1;
            }
        } 
        else {
            return 0.0;
        }
    }
    return result;
}

int countLines(string filename) {
    ifstream f(filename.c_str());
    int count = 0;
    string line;
    while (getline(f, line))
        if (!line.empty()) count++;
    return count;
}



// Doctor and Treatment Class by Momin

class Doctor {
private:

    int doctorID;
    string doctorName;
    string doctorSpecialty;
    int experience;

public: //  constructor, it is called when an object of a class is created to initialize its data members
    Doctor() {
        doctorID = 0;
        experience = 0;
        doctorName = "";
        doctorSpecialty = "";
    }

// class getters

int get_doctorID() {
    return doctorID;
}
string get_doctorName() {
    return doctorName;
}
string get_doctorSpecialty() {
    return doctorSpecialty;
}
int get_experience() {
    return experience;
}

// class setters

void set_doctorID(int id) {
    doctorID = id;
}
void set_doctorName(string n) {
    doctorName = n;
}
void set_doctorSpecialty(string s) {
    doctorSpecialty = s;
}
void set_experience(int e) {
    experience = e;
}

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

    int get_patientID() {
        return patientID;
    }
    string get_description() {
        return description;
    }
    double get_cost() {
        return cost;
    }
    bool isPaid() {
        return paid;
    }


    // setter of the class

    void set_patientID(int id) {patientID = id;}
    void set_description(string d) {description = d;}
    void set_cost(double c) {cost = c;}
    void set_paid(bool p) {paid = p;}



};


//  Patient and Appointment Classes by Huzaifa
// ============================================================

class Patient {
private:
    int patientId;
    string name;
    int age;
    string gender;
    string contact;
    double balance;
public:
    Patient() {
        patientId = 0;
        name      = "";
        age       = 0;
        gender    = "";
        contact   = "";
        balance   = 0.0;
    }
    Patient(int id, string n, int a, string g, string c, double b) {
        setPatientId(id);
        setName(n);
        setAge(a);
        setGender(g);
        setContact(c);
        setBalance(b);
    }
    
    void setPatientId(int id) {
        if (id > 0) patientId = id;
        else cout << "Invalid Patient ID\n";
    }
    void setName(string n) {
        if (!n.empty()) name = n;
        else cout << "Name cannot be empty\n";
    }
    void setAge(int a) {
        if (a > 0 && a < 120) age = a;
        else cout << "Invalid Age\n";
    }
    void setGender(string g) {
        if (g == "Male" || g == "Female") gender = g;
        else cout << "Invalid Gender (use Male or Female)\n";
    }
    void setContact(string c) {
        if (c.length() == 11) {
            for (int i = 0; i < (int)c.length(); i++) {
                if (!isdigit(c[i])) {
                    cout << "Contact must contain digits only\n";
                    return;
                }
            }
            contact = c;
        } else {
            cout << "Invalid Contact Number (must be 11 digits)\n";
        }
    }
    void setBalance(double b) {
        if (b >= 0) balance = b;
        else cout << "Balance cannot be negative\n";
    }
    int    getPatientId() const { 
        return patientId;
    }
    string getName() const { 
        return name;      
    }
    int    getAge() const { 
        return age;        
    }
    string getGender() const { 
        return gender;     
    }
    string getContact() const { 
        return contact;    
    }
    double getBalance() const { 
        return balance;    
    }
    void display() const {
        cout << "Patient ID: " << patientId << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Contact: " << contact << endl;
        cout << "Balance: " << balance << endl;
        cout << "------------------------"<<endl;
    }
};

class Appointment {
private:
    int  patientId;
    int  doctorId;
    char date[12];
    char time[12];
public:
    Appointment() {
        patientId = 0;
        doctorId  = 0;
        date[0]   = '\0';
        time[0]   = '\0';
    }
    Appointment(int pid, int did, string d, string t) {
        setPatientId(pid);
        setDoctorId(did);
        setDate(d);
        setTime(t);
    }
    
    void setPatientId(int id) {
        if (id > 0) patientId = id;
        else cout << "Invalid Patient ID"<<endl;
    }
    void setDoctorId(int id) {
        if (id > 0) doctorId = id;
        else cout << "Invalid Doctor ID"<<endl;
    }
    void setDate(string d) {
        if (d.length() > 0 && d.length() <= 11) {
            for (int i = 0; i < (int)d.length(); i++)
                date[i] = d[i];
            date[d.length()] = '\0';
        } else {
            cout << "Invalid Date"<<endl;
        }
    }
    void setTime(string t) {
        if (t.length() > 0 && t.length() <= 11) {
            for (int i = 0; i < (int)t.length(); i++)
                time[i] = t[i];
            time[t.length()] = '\0';
        } else {
            cout << "Invalid Time"<<endl;
        }
    }
    int    getPatientId()const { 
        return patientId;    
    }
    int    getDoctorId() const { 
        return doctorId;     
    }
    string getDate() const { 
        return string(date); 
    }
    string getTime() const { 
        return string(time); 
    }
    void display() const {
        cout << "Patient ID: " << patientId << endl;
        cout << "Doctor ID: " << doctorId  << endl;
        cout << "Date: " << date << endl;
        cout << "Time: " << time << endl;
        cout << "------------------------"<<endl;
    }
};

// Clean Up Functions

// cleanDoctorsFile() by Momin


void cleanDoctorsFile() {
    ifstream inFile("doctors.txt");
    ofstream tempFile("doctors_temp.txt");

    string line;
    int removed = 0; // for the remove count

    while(getline(inFile, line)){
        if(line.empty()){
            continue;
        }

        string fields[4];
        int count = splitLine(line, fields, 4);

        for(int i = 0; i<count; i++){
            fields[i] = trim(fields[i]);
        }

        // checking for the existence of all 4 fields
        if(count < 4){
            cout<<"Removed! incomplete Doctor Record: "<<line<<endl;
            removed++;
            continue;
        }

        // individual checks for each field

        if(!isNumber(fields[0])){
            cout<<"Removed the invalid Doctor Id";
            removed++;
            continue;
        }

        if (fields[1].empty()){
            cout<<"Removed the missing speciality";
            removed++;
            continue;
        }

        if(!isNumber(fields[2])){
            cout<<"Removed the invalid experience";
            removed++;
            continue;
        }

        tempFile << line << endl;

    }

    inFile.close();
    tempFile.close();

    remove("doctors.txt");
    rename("doctors_temp.txt", "doctors.txt");

    cout<<"Doctors file cleaned. Records removed"<<removed<<endl;
}

void cleanTreatmentsFile() {
    ifstream inFile("data/treatments.txt");
    ofstream tempFile("data/treatments_temp.txt");

    string line;
    int removed = 0;

    while (getline(inFile, line)) {
        if (line.empty()){
            continue;
        }
        
        string fields[4];
        int count = splitLine(line, fields, 4);

        
        for (int i = 0; i < count; i++) {
            fields[i] = trim(fields[i]);
        }

        // Check all 4 fields exist
        if (count < 4) {
            cout << "Removed incomplete treatment: " << line << endl;
            removed++;
            continue;
        }

        // Check for individual existence
        if (!isNumber(fields[0])) {
            cout << "Removed invalid patient ID: " << line << endl;
            removed++;
            continue;
        }

        
        if (fields[1].empty()) {
            cout << "Removed missing description: " << line << endl;
            removed++;
            continue;
        }

        
        if (!isNumber(fields[2])) {
            cout << "Removed invalid cost: " << line << endl;
            removed++;
            continue;
        }

        
        if (fields[3] != "true" && fields[3] != "false") {
            cout << "Removed invalid paid status: " << line << endl;
            removed++;
            continue;
        }

        
        tempFile << line << endl;
    }

    inFile.close();
    tempFile.close();

    remove("treatments.txt");
    rename("treatments_temp.txt", "treatments.txt");

    cout << "Treatments file cleaned. Records removed: " << removed << endl;
}

// duplicate function for cleaning of patients file

void removeDuplicateIDs(){
    ifstream inFile("patients.txt");

    int total = countLines("patients.txt");

    int ids[500];
    int idCount = 0;
    int duplicateIDs[500];
    int dupCount = 0;

    string line;
    while (getline(inFile, line)){
        
    }
}


// LOAD FUNCTIONS (Loading of files)
// loadDoctors() and loadTreatments() written by Momin
// loadPatients() and loadAppointments() written by Huzaifa


// function for loading doctors.txt (file is already clean)
Doctor* loadDoctors(int &count) {
    ifstream file("doctors.txt");
    count = 0;

    string line;
    while(getline(file, line)){
        if(!line.empty()){
            count++;
        } 
    }

    // memory alocation using pointers

    Doctor* doctors = new Doctor[count];

    file.clear();
    file.seekg(0);

    int i = 0;
    while(getline(file, line)) {
        if(line.empty()) {
            continue;
        }
        int pos= 0;
        string token;
        string fields[4];
        int fieldIndex = 0;

        for(int j = 0; j<=line.length(); j++){
            if(j == line.length() || line[j] == '#'){
                fields[fieldIndex++] = line.substr(pos, j - pos);
                pos = j + 1;
            }
        }

        doctors[i].set_doctorID(stoi(fields[0]));
        doctors[i].set_doctorName(fields[1]);
        doctors[i].set_doctorSpecialty(fields[2]);
        doctors[i].set_experience(stoi(fields[3]));
        i++;
    }

    file.close();
    return doctors;

}

Patient* loadPatients(int& total) {
    total = countLines("patients.txt");
    if (total == 0) { cout << "No patients found.\n"; return NULL; }

    Patient* patients = new Patient[total];
    ifstream file("patients.txt");
    string line; int i = 0;

    while (getline(file, line)) {
        if (line.empty()) continue;
        string parts[10];
        int count = splitLine(line, parts, 10);
        if (count < 6) continue;

        patients[i].setPatientId(toInt(trim(parts[0])));
        patients[i].setName(trim(parts[1]));
        patients[i].setAge(toInt(trim(parts[2])));
        patients[i].setGender(trim(parts[3]));
        patients[i].setContact(trim(parts[4]));
        patients[i].setBalance(toDouble(trim(parts[5])));
        i++;
    }
    file.close();
    total = i;
    cout << "Loaded " << total << " patients.\n";
    return patients;
}

Appointment* loadAppointments(int& total) {
    total = countLines("appointments.txt");
    if (total == 0) { cout << "No appointments found.\n"; return NULL; }

    Appointment* appointments = new Appointment[total];
    ifstream file("appointments.txt");
    string line; int i = 0;

    while (getline(file, line)) {
        if (line.empty()) continue;
        string parts[10];
        int count = splitLine(line, parts, 10);
        if (count < 4) continue;

        appointments[i].setPatientId(toInt(trim(parts[0])));
        appointments[i].setDoctorId(toInt(trim(parts[1])));
        appointments[i].setDate(trim(parts[2]));
        appointments[i].setTime(trim(parts[3]));
        i++;
    }
    file.close();
    total = i;
    cout << "Loaded " << total << " appointments.\n";
    return appointments;
}

Treatment* loadTreatments(int& total) {
    total = countLines("treatments.txt");
    if (total == 0) { cout << "No treatments found.\n"; return NULL; }

    Treatment* treatments = new Treatment[total];
    ifstream file("treatments.txt");
    string line; int i = 0;

    while (getline(file, line)) {
        if (line.empty()) continue;
        string parts[10];
        int count = splitLine(line, parts, 10);
        if (count < 4) continue;

        treatments[i].set_patientID(toInt(trim(parts[0])));
        treatments[i].set_description(trim(parts[1]));
        treatments[i].set_cost(toDouble(trim(parts[2])));
        treatments[i].set_paid(trim(parts[3]) == "true");
        i++;
    }
    file.close();
    total = i;
    cout << "Loaded " << total << " treatments.\n";
    return treatments;
}





// test case for checking of above classes will remove later

int main() {
     Doctor d;
     d.set_doctorID(201);
     d.set_doctorName("Dr.Moin Akhtar");
     d.set_doctorSpecialty("Neurosurgeon");
     d.set_experience(10);

     cout<<"== Doctor Results =="<<endl;
     cout<<"ID: "<<d.get_doctorID()<<endl;
     cout<<"Name: "<<d.get_doctorName()<<endl;
     cout<<"Speciality: "<<d.get_doctorSpecialty()<<endl;
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

     // test cases ran succesfully for now 23-4-26 11:22PM
}

