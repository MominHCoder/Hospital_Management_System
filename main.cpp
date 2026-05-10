#include <iostream>
#include <string>
#include <fstream>
using namespace std;


// Helper Functions by Huzaifa and Momin
bool isNumber(string s){
    if(s.empty()){
        return false;
    }
    for(int i = 0; i < s.length(); i++){
        if(!isdigit(s[i])){
            return false;
        }
    }
    return true;
}


// Splits a line by '#' delimiter and stores each part in the parts[] array
// Returns the number of parts found
// Example: "101#Ali Raza#25#Male" to parts[0]="101", parts[1]="Ali Raza", etc.
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

void display() {
    cout << "Doctor ID  : " << doctorID << endl;
    cout << "Name       : " << doctorName << endl;
    cout << "Specialty  : " << doctorSpecialty<< endl;
    cout << "Experience : " << experience << " years" << endl;
    cout << "------------------------" << endl;
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

    void display() {
        cout << "Patient ID  : " << patientID   << endl;
        cout << "Description : " << description << endl;
        cout << "Cost : " << cost        << endl;

        //we use ternary operator
        cout << "Paid : " << (paid ? "Yes" : "No") << endl;
        cout << "------------------------" << endl;
    }

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
        name = "";
        age = 0;
        gender = "";
        contact = "";
        balance = 0.0;
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
        else cout << "Invalid Patient ID" << endl;
    }
    void setName(string n) {
        if (!n.empty()) name = n;
        else cout << "Name cannot be empty" << endl;
    }
    void setAge(int a) {
        if (a > 0 && a < 120) age = a;
        else cout << "Invalid Age" << endl;
    }
    void setGender(string g) {
        if (g == "Male" || g == "Female") {
            gender = g;
        }
        else {
            cout << "Invalid Gender (use Male or Female)" << endl;
        }
    }
    void setContact(string c) {
        if (c.length() == 11) {
            for (int i = 0; i < (int)c.length(); i++) {
                if (!isdigit(c[i])) {
                    cout << "Contact must contain digits only" << endl;
                    return;
                }
            }
            contact = c;
        } else {
            cout << "Invalid Contact Number (must be 11 digits)" << endl;
        }
    }
    void setBalance(double b) {
        if (b >= 0) balance = b;
        else cout << "Balance cannot be negative" << endl;
    }

    int getPatientId() const { 
        return patientId; 
    }
    string getName() const { 
        return name;      
    }
    int getAge() const { 
        return age;        
    }
    string getGender() const { 
        return gender;     
    }
    string getContact() const { 
        return contact;    
    }
    double getBalance()  const { 
        return balance;    
    }

    void display() const {
        cout << "Patient ID : " << patientId << endl;
        cout << "Name : " << name<< endl;
        cout << "Age : " << age << endl;
        cout << "Gender : " << gender<< endl;
        cout << "Contact : " << contact << endl;
        cout << "Balance : " << balance << endl;
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
        else cout << "Invalid Patient ID" << endl;
    }
    void setDoctorId(int id) {
        if (id > 0) doctorId = id;
        else cout << "Invalid Doctor ID" << endl;
    }
    void setDate(string d) {
        if (d.length() > 0 && d.length() <= 11) {
            for (int i = 0; i < (int)d.length(); i++)
                date[i] = d[i];
            date[d.length()] = '\0';
        } else {
            cout << "Invalid Date" << endl;
        }
    }
    void setTime(string t) {
        if (t.length() > 0 && t.length() <= 11) {
            for (int i = 0; i < (int)t.length(); i++)
                time[i] = t[i];
            time[t.length()] = '\0';
        } else {
            cout << "Invalid Time" << endl;
        }
    }

    int getPatientId() const { 
        return patientId;    
    }
    int getDoctorId()  const { 
        return doctorId;     
    }
    string getDate() const { 
        return string(date); 
    }
    string getTime() const { 
        return string(time); 
    }

    void display() const {
        cout << "Patient ID : " << patientId << endl;
        cout << "Doctor ID  : " << doctorId  << endl;
        cout << "Date       : " << date      << endl;
        cout << "Time       : " << time      << endl;
        cout << "------------------------"<<endl;
    }
};


bool isValidRecord(string fields[], int count, int requiredFields) {
    // check required number of fields exist
    if (count < requiredFields) return false;

    for (int i = 0; i < requiredFields; i++) {
        if (fields[i].empty()) return false;
    }

    return true;
}


// Clean Up Functions

// cleanDoctorsFile() by Momin

void cleanDoctorsFile() {
    ifstream inFile("data/doctors.txt");
    ofstream tempFile("data/doctors_temp.txt");

    string line;
    int removed = 0; // for the remove count

    while(getline(inFile, line)){
        if(line.empty()){
            continue;
        }

        string fields[4];
        int count = splitLine(line, fields, 4);

        for(int i = 0; i < count; i++){
            fields[i] = trim(fields[i]);
        }

        // checking for the existence of all 4 fields
        if(!isValidRecord(fields, count, 4)){
            cout << "Removed incomplete Doctor Record: " << line << endl;
            removed++;
            continue;
        }

        // individual checks for each field

        if(!isNumber(fields[0])){
            cout << "Removed the invalid Doctor Id" << endl;
            removed++;
            continue;
        }

        if(fields[1].empty()){
            cout << "Removed the missing doctor name" << endl;
            removed++;
            continue;
        }

        if(fields[2].empty()){
            cout << "Removed the missing speciality" << endl;
            removed++;
            continue;
        }

        if(!isNumber(fields[3])){
            cout << "Removed the invalid experience" << endl;
            removed++;
            continue;
        }

        tempFile << line << endl;
    }

    inFile.close();
    tempFile.close();

    remove("data/doctors.txt");
    rename("data/doctors_temp.txt", "data/doctors.txt");

    cout << "Doctors file cleaned. Records removed: " << removed << endl;
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
        if(!isValidRecord(fields, count, 4)){
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

    remove("data/treatments.txt");
    rename("data/treatments_temp.txt", "data/treatments.txt");

    cout << "Treatments file cleaned. Records removed: " << removed << endl;
}

// duplicate function for cleaning of patients file

void removeDuplicateIDs() {
    ifstream inFile("data/patients.txt");

    int ids[500];
    int idCount = 0;
    int duplicateIDs[500];
    int dupCount = 0;

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;

        string fields[6];
        int count = splitLine(line, fields, 6);
        if (count < 1) continue;

        int id = toInt(trim(fields[0]));

        // Check if this ID already exists
        bool found = false;
        for (int i = 0; i < idCount; i++) {
            if (ids[i] == id) {
                found = true;
                break;
            }
        }

        if (found) {
            duplicateIDs[dupCount++] = id;
        } else {
            ids[idCount++] = id;
        }
    }
    inFile.close();

    if (dupCount == 0) {
        cout << "No duplicate IDs found in patients file." << endl;
        return;
    }

    inFile.open("data/patients.txt");
    ofstream tempFile("data/patients_temp.txt");

    while (getline(inFile, line)) {
        if (line.empty()) continue;

        string fields[6];
        int count = splitLine(line, fields, 6);
        if (count < 1) continue;

        int id = toInt(trim(fields[0]));

        bool isDuplicate = false;
        for (int i = 0; i < dupCount; i++) {
            if (duplicateIDs[i] == id) {
                isDuplicate = true;
                break;
            }
        }

        if (isDuplicate) {
            cout << "Removed duplicate ID " << id << ": " << line << endl;
        } else {
            tempFile << line << endl;
        }
    }

    inFile.close();
    tempFile.close();

    remove("data/patients.txt");
    rename("data/patients_temp.txt", "data/patients.txt");

    cout << "Duplicate IDs removed: " << dupCount << endl;
}

void cleanPatientsFile() {
    //removing duplicatess
    removeDuplicateIDs();

    ifstream inFile("data/patients.txt");
    ofstream tempFile("data/patients_temp.txt");

    string line;
    int removed = 0;

    while (getline(inFile, line)) {
        if (line.empty()) continue;

        string fields[6];
        int count = splitLine(line, fields, 6);

        for (int i = 0; i < count; i++) {
            fields[i] = trim(fields[i]);
        }

        // check fir 6 fields
        if(!isValidRecord(fields, count, 6)){
            cout << "Removed incomplete patient record: " << line << endl;
            removed++;
            continue;
        }

        if(!isNumber(fields[0])){
            cout << "Removed invalid ID: " << line << endl;
            removed++;
            continue;
        }

    
        if (!isNumber(fields[2])) {
            cout << "Removed invalid age: " << line << endl;
            removed++;
            continue;
        }

    
        if (fields[3] == "M") {
            fields[3] = "Male";
        } else if (fields[3] == "F") {
            fields[3] = "Female";
        }

        if (fields[4].empty()) {
            cout << "Removed missing contact: " << line << endl;
            removed++;
            continue;
        }

        // check phone has no alphabets
        bool validPhone = true;
        for (int i = 0; i < fields[4].length(); i++) {
            if (!isdigit(fields[4][i])) {
                validPhone = false;
                break;
            }
        }
        if (!validPhone) {
            cout << "Removed invalid phone (contains alphabets): " << line << endl;
            removed++;
            continue;
        }

        // check phone has exactly 11 digits
        if (fields[4].length() != 11) {
            cout << "Removed incomplete phone number: " << line << endl;
            removed++;
            continue;
        }

        // write to temp file with fixed gender
        tempFile << fields[0] << "#" << fields[1] << "#"<< fields[2] << "#" << fields[3] << "#"<< fields[4] << "#" << fields[5] << endl;
    }

    inFile.close();
    tempFile.close();

    remove("data/patients.txt");
    rename("data/patients_temp.txt", "data/patients.txt");

    cout << "Patients file cleaned. Records removed: " << removed << endl;
}

string fixDate(string date) {
    // Check if date is in YYYY-MM-DD format starts with 4 digit year
    // 2026-04-24 to 04-24-2026
    if (date.length() == 10 && date[4] == '-') {
        string year  = date.substr(0, 4);
        string month = date.substr(5, 2);
        string day   = date.substr(8, 2);
        return month + "-" + day + "-" + year;
    }
    return date;
}

string fixTime(string time) {
    // Check if time already has AM or PM by looking for 'A' or 'P'
    bool hasAMPM = false;
    for (int i = 0; i < time.length(); i++) {
        if (time[i] == 'A' || time[i] == 'P') {
            hasAMPM = true;
            break;
        }
    }

    if (hasAMPM) {
        return time;
    }
    string hourStr = "";
    string minStr  = "";
    bool colonFound = false;

    for (int i = 0; i < time.length(); i++) {
        if (time[i] == ':') {
            colonFound = true;
        } else if (!colonFound) {
            hourStr += time[i];
        } else {
            minStr += time[i];
        }
    }

    int hour = toInt(hourStr);

    // Determine AM or PM
    string period = "";
    if (hour >= 12) {
        period = "PM";
        if (hour > 12) hour = hour - 12;
    } else {
        period = "AM";
        if (hour == 0) hour = 12;
    }

    // Convert hour back to string manually
    string fixedHour = "";
    if (hour < 10) {
        fixedHour = "0";
        fixedHour += (char)('0' + hour);
    } else {
        fixedHour += (char)('0' + hour / 10);
        fixedHour += (char)('0' + hour % 10);
    }

    return fixedHour + ":" + minStr + " " + period;
}

void cleanAppointmentsFile() {
    ifstream inFile("data/appointments.txt");
    ofstream tempFile("data/appointments_temp.txt");

    string line;
    int removed = 0;
    int fixed   = 0;

    while (getline(inFile, line)) {
        if (line.empty()) continue;

        string fields[4];
        int count = splitLine(line, fields, 4);

        for (int i = 0; i < count; i++) {
            fields[i] = trim(fields[i]);
        }

        // Check all 4 fields exist
        if(!isValidRecord(fields, count, 4)){
            cout << "Removed incomplete appointment: " << line << endl;
            removed++;
            continue;
        }

        // Check patientId is a number
        if (!isNumber(fields[0])) {
            cout << "Removed invalid patient ID: " << line << endl;
            removed++;
            continue;
        }

        // Check doctorId is a number
        if (!isNumber(fields[1])) {
            cout << "Removed invalid doctor ID: " << line << endl;
            removed++;
            continue;
        }

        // Check date is not empty
        if (fields[2].empty()) {
            cout << "Removed missing date: " << line << endl;
            removed++;
            continue;
        }

        // Check time is not empty
        if (fields[3].empty()) {
            cout << "Removed missing time: " << line << endl;
            removed++;
            continue;
        }

        // Fix date format if needed
        string fixedDate = fixDate(fields[2]);
        if (fixedDate != fields[2]) {
            cout << "Fixed date: " << fields[2] << " -> " << fixedDate << endl;
            fixed++;
        }

        // Fix time format if needed
        string fixedTime = fixTime(fields[3]);
        if (fixedTime != fields[3]) {
            cout << "Fixed time: " << fields[3] << " -> " << fixedTime << endl;
            fixed++;
        }

        tempFile << fields[0] << "#"<< fields[1] << "#" << fixedDate  << "#" << fixedTime  << endl;
    }

    inFile.close();
    tempFile.close();

    remove("data/appointments.txt");
    rename("data/appointments_temp.txt", "data/appointments.txt");

    cout << "Appointments file cleaned. Records removed: " << removed
         << ", Records fixed: " << fixed << endl;
}

void cleanBillsFile() {
    ifstream inFile("data/bills.txt");
    ofstream tempFile("data/bills_temp.txt");

    string line;
    int removed = 0;

    while (getline(inFile, line)) {
        if (line.empty()) continue;

        string fields[3];
        int count = splitLine(line, fields, 3);

        for (int i = 0; i < count; i++) {
            fields[i] = trim(fields[i]);
        }

        // Check all 3 fields exist
        if(!isValidRecord(fields, count, 3)){
            cout << "Removed incomplete bill: " << line << endl;
            removed++;
            continue;
        }

        // Check patientId is a number
        if (!isNumber(fields[0])) {
            cout << "Removed invalid patient ID: " << line << endl;
            removed++;
            continue;
        }

        // Check amount is a number
        if (!isNumber(fields[1])) {
            cout << "Removed invalid amount: " << line << endl;
            removed++;
            continue;
        }

        // Check status is Paid or Unpaid
        if (fields[2] != "Paid" && fields[2] != "Unpaid") {
            cout << "Removed invalid status: " << line << endl;
            removed++;
            continue;
        }

        tempFile << line << endl;
    }

    inFile.close();
    tempFile.close();

    remove("data/bills.txt");
    rename("data/bills_temp.txt", "data/bills.txt");

    cout << "Bills file cleaned. Records removed: " << removed << endl;
}

void cleanFile() {
    cout << "========= Cleaning All Files =========" << endl;
    cleanPatientsFile();
    cleanDoctorsFile();
    cleanAppointmentsFile();
    cleanTreatmentsFile();
    cleanBillsFile();
    cout << "========= All Files Cleaned =========" << endl;
}


// LOAD FUNCTIONS (Loading of files)
// loadDoctors() and loadTreatments() written by Momin
// loadPatients() and loadAppointments() written by Huzaifa


// function for loading doctors.txt (file is already clean)
Doctor* loadDoctors(int &count) {
    ifstream file("data/doctors.txt");
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
        if(line.empty()) continue;

        string fields[4];
        int fieldCount = splitLine(line, fields, 4);

        doctors[i].set_doctorID(toInt(fields[0]));
        doctors[i].set_doctorName(fields[1]);
        doctors[i].set_doctorSpecialty(fields[2]);
        doctors[i].set_experience(toInt(fields[3]));
        i++;
    }

    file.close();
    return doctors;
}

Patient* loadPatients(int& total) {
    total = countLines("data/patients.txt");
    if (total == 0) { 
        cout << "No patients found."<<endl;
        return NULL; 
    }

    Patient* patients = new Patient[total];
    ifstream file("data/patients.txt");
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
    cout << "Loaded " << total << " patients."<<endl;
    return patients;
}

Appointment* loadAppointments(int& total) {
    total = countLines("data/appointments.txt");
    if (total == 0) { 
        cout << "No appointments found."<<endl;
        return NULL;
    }
    Appointment* appointments = new Appointment[total];
    ifstream file("data/appointments.txt");
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
    cout << "Loaded " << total << " appointments."<<endl;
    return appointments;
}

Treatment* loadTreatments(int& total) {
    total = countLines("data/treatments.txt");
    if (total == 0) { 
        cout << "No treatments found."<<endl; 
        return NULL;
    }
   

    Treatment* treatments = new Treatment[total];
    ifstream file("data/treatments.txt");
    string line; int i = 0;

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        string parts[10];
        int count = splitLine(line, parts, 10);
        if (count < 4) {
            continue;
        }

        treatments[i].set_patientID(toInt(trim(parts[0])));
        treatments[i].set_description(trim(parts[1]));
        treatments[i].set_cost(toDouble(trim(parts[2])));
        treatments[i].set_paid(trim(parts[3]) == "true");
        i++;
    }
    file.close();
    total = i;
    cout << "Loaded " << total << " treatments."<<endl;
    return treatments;
}



//  PATIENT MANAGEMENT FUNCTIONS by Huzaifa

void savePatientsToFile(Patient* patients, int total) {
    ofstream file("data/patients.txt");
    for (int i = 0; i < total; i++) {
        file << patients[i].getPatientId() << "#"<< patients[i].getName()<< "#"<< patients[i].getAge() << "#"<< patients[i].getGender()<< "#" << patients[i].getContact() << "#"<< patients[i].getBalance()<< endl;
    }
    file.close();
}

void addPatient(Patient* &patients, int &total)
{
    int id, age;
    string name, gender, contact;
    double balance;

    cout << "Add New Patient"<<endl;
    cout << "Enter Patient ID          : ";
    cin >> id;
    cin.ignore();
    cout << "Enter Name                : ";
    getline(cin, name);
    cout << "Enter Age                 : ";
    cin >> age;
    cout << "Enter Gender (Male/Female): ";
    cin >> gender;
    cout << "Enter Contact             : ";
    cin >> contact;
    cout << "Enter Balance             : ";
    cin >> balance;

    // make a bigger array with one extra slot
    Patient* newArr = new Patient[total + 1];

    // copy existing patients into new array
    for (int i = 0; i < total; i++)
        newArr[i] = patients[i];

    // set the new patient at the last slot
    newArr[total].setPatientId(id);
    newArr[total].setName(name);
    newArr[total].setAge(age);
    newArr[total].setGender(gender);
    newArr[total].setContact(contact);
    newArr[total].setBalance(balance);

    delete[] patients;
    patients = newArr;
    total++;

    ofstream file("data/patients.txt", ios::app);
    file << id << "#" << name << "#" << age << "#"
         << gender << "#" << contact << "#" << balance << endl;
    file.close();

    cout << "Patient added successfully."<<endl;
}

void updatePatient(Patient* patients, int total) {
    int id;
    cout << "\n--- Update Patient ---"<<endl;
    cout << "Enter Patient ID to update: "; cin >> id;

    int found = -1;
    for (int i = 0; i < total; i++)
    {
        if (patients[i].getPatientId() == id)
        {
            found = i;
            break;
        }
    }

    if (found == -1) {
        cout << "Patient not found."<<endl;
        return;
    }

    cout << "Current details:"<<endl;
    patients[found].display();

    string name, gender, contact;
    int age;
    double balance;

    cin.ignore();
    cout << "Enter new Name    : ";
    getline(cin, name);
    cout << "Enter new Age     : ";
    cin >> age;
    cout << "Enter new Gender  : ";
    cin >> gender;
    cout << "Enter new Contact : ";
    cin >> contact;
    cout << "Enter new Balance : ";
    cin >> balance;

    patients[found].setName(name);
    patients[found].setAge(age);
    patients[found].setGender(gender);
    patients[found].setContact(contact);
    patients[found].setBalance(balance);

    // rewrite entire file with updated data
    ofstream file("data/patients.txt");
    for (int i = 0; i < total; i++) {
        file << patients[i].getPatientId() << "#"<< patients[i].getName() << "#"<< patients[i].getAge() << "#"<< patients[i].getGender() << "#"<< patients[i].getContact() << "#"<< patients[i].getBalance()   << endl;
    }
    file.close();

    cout << "Patient updated successfully."<<endl;
}

void deletePatient(Patient* &patients, int &total) {
    int id;
    cout << "\n--- Delete Patient ---\n";
    cout << "Enter Patient ID to delete: "; cin >> id;

    int found = -1;
    for (int i = 0; i < total; i++) {
        if (patients[i].getPatientId() == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        cout << "Patient not found."<<endl;
        return;
    }

    // make a smaller array without that patient
    Patient* newArr = new Patient[total - 1];
    int j = 0;
    for (int i = 0; i < total; i++) {
        if (i == found) continue; // skiping deleted ones
        newArr[j++] = patients[i];
    }

    delete[] patients;
    patients = newArr;
    total--;

    // rewrite file without deleted patient
    ofstream file("data/patients.txt");
    for (int i = 0; i < total; i++) {
        file << patients[i].getPatientId() << "#"<< patients[i].getName()<< "#"<< patients[i].getAge() << "#"<< patients[i].getGender()<< "#"<< patients[i].getContact()<< "#" << patients[i].getBalance()   << endl;
    }
    file.close();

    cout << "Patient deleted successfully."<<endl;
}

void viewPatients(Patient* patients, int total) {
    cout << "\n--- All Patients ---\n";
    if (total == 0) {
        cout << "No patients found."<<endl;
        return;
    }
    for (int i = 0; i < total; i++)
        patients[i].display();
}



//  APPOINTMENT FUNCTIONS by Huzaifa

void scheduleAppointment(Appointment* &appointments, int &total, Patient* patients, int patientCount) {
    int pid, did;
    string date, timeSlot;  // renamed from time to avoid conflict
    double cost;

    cout << "\n--- Schedule Appointment ---\n";
    cout << "Enter Patient ID           : ";
    cin >> pid;
    cout << "Enter Doctor ID  : ";
    cin >> did;
    cin.ignore();
    cout << "Enter Date (MM-DD-YYYY)    : ";
    getline(cin, date);
    cout << "Enter Time (e.g. 10:00 AM) : ";
    getline(cin, timeSlot);
    cout << "Enter Appointment Cost     : ";
    cin >> cost;

    // find patient
    int found = -1;
    for (int i = 0; i < patientCount; i++)
    {
        if (patients[i].getPatientId() == pid)
        {
            found = i;
            break;
        }
    }

    if (found == -1) {
        cout << "Patient not found."<<endl;
        return;
    }

    // check balance
    if (patients[found].getBalance() < cost)
    {
        cout << "Insufficient balance. Appointment denied."<<endl;
        cout << "Balance: " << patients[found].getBalance()<< " | Cost: " << cost << endl;
        return;
    }

    // deduct cost
    patients[found].setBalance(patients[found].getBalance() - cost);

    // add to appointments array
    Appointment* newArr = new Appointment[total + 1];
    for (int i = 0; i < total; i++){
        newArr[i] = appointments[i];
    }
    newArr[total].setPatientId(pid);
    newArr[total].setDoctorId(did);
    newArr[total].setDate(date);
    newArr[total].setTime(timeSlot);

    delete[] appointments;
    appointments = newArr;
    total++;

    // save appointment to file
    ofstream file("data/appointments.txt", ios::app);
    file << pid << "#" << did << "#" << date << "#" << timeSlot << endl;
    file.close();

    cout << "Appointment scheduled successfully."<<endl;
    cout << "Remaining balance: " << patients[found].getBalance() << endl;

    // save updated patient balance to file
    savePatientsToFile(patients, patientCount);
}

void cancelAppointment(Appointment* &appointments, int &total) {
    int pid;
    cout << "\n--- Cancel Appointment ---\n";
    cout << "Enter Patient ID to cancel appointment: ";
    cin >> pid;

    int found = -1;
    for (int i = 0; i < total; i++) {
        if (appointments[i].getPatientId() == pid) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        cout << "Appointment not found."<<endl;
        return;
    }

    cout << "Cancelling:"<<endl;
    appointments[found].display();

    // make smaller array without that appointment
    Appointment* newArr = new Appointment[total - 1];
    int j = 0;
    for (int i = 0; i < total; i++) {
        if (i == found) continue;
        newArr[j++] = appointments[i];
    }

    delete[] appointments;
    appointments = newArr;
    total--;

    // rewrite too file
    ofstream file("data/appointments.txt");
    for (int i = 0; i < total; i++) {
        file << appointments[i].getPatientId() << "#" << appointments[i].getDoctorId() << "#"<< appointments[i].getDate() << "#"<< appointments[i].getTime() << endl;
    }
    file.close();

    cout << "Appointment cancelled successfully."<<endl;
}

void viewAppointments(Appointment* appointments, int total) {
    cout << "\n--- All Appointments ---\n";
    if (total == 0) {
        cout << "No appointments found"<<endl;
        return;
    }
    for (int i = 0; i < total; i++)
        appointments[i].display();
}


//  SEARCH FUNCTIONS by Huzaifa


void searchPatientsByID(Patient* patients, int total) {
    int id;
    cout << "\n--- Search Patient by ID ---\n";
    cout << "Enter Patient ID: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < total; i++) {
        if (patients[i].getPatientId() == id) {
            patients[i].display();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "No patient found with ID " << id << endl;
}

void searchPatientsByName(Patient* patients, int total) {
    string name;
    cout << "\n--- Search Patient by Name ---\n";
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);

    bool found = false;
    for (int i = 0; i < total; i++) {
        if (patients[i].getName() == name) {
            patients[i].display();
            found = true;
        }
    }

    if (!found)
        cout << "No patient found with name " << name << endl;
}

void searchDoctorBySpecialty(Doctor* doctors, int total) {
    string specialty;
    cout << "\n--- Search Doctor by Specialty ---\n";
    cin.ignore();
    cout << "Enter Specialty: "; getline(cin, specialty);

    bool found = false;
    for (int i = 0; i < total; i++) {
        if (doctors[i].get_doctorSpecialty() == specialty) {
            doctors[i].display();
            found = true;
        }
    }

    if (!found)
        cout << "No doctor found with specialty " << specialty << endl;
}

void viewDoctors(Doctor* doctors, int total) {
    cout << "\n--- All Doctors ---\n";
    if (total == 0) {
        cout << "No doctors found."<<endl;
        return;
    }
    for (int i = 0; i < total; i++)
        doctors[i].display();
}

void addDoctor(Doctor* &doctors, int &total) {
    int id, experience;
    string name, specialty;

    cout << "\n--- Add New Doctor ---\n";
    cout << "Enter Doctor ID      : ";
    cin >> id;
    cin.ignore();
    cout << "Enter Name : ";
    getline(cin, name);
    cout << "Enter Specialty : ";
    getline(cin, specialty);
    cout << "Enter Experience (years): ";
    cin >> experience;

    
    Doctor* newArr = new Doctor[total + 1];

   
    for (int i = 0; i < total; i++){
        newArr[i] = doctors[i];
    }
    
    newArr[total].set_doctorID(id);
    newArr[total].set_doctorName(name);
    newArr[total].set_doctorSpecialty(specialty);
    newArr[total].set_experience(experience);

    delete[] doctors;
    doctors = newArr;
    total++;

    ofstream file("data/doctors.txt", ios::app);
    file << id << "#" << name << "#" << specialty << "#" << experience << endl;
    file.close();

    cout << "Doctor added successfully."<<endl;
}

void updateDoctor(Doctor* doctors, int total) {
    int id;
    cout << "\n--- Update Doctor ---\n";
    cout << "Enter Doctor ID to update: "; cin >> id;

    int found = -1;
    for (int i = 0; i < total; i++) {
        if (doctors[i].get_doctorID() == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        cout << "Doctor not found."<<endl;
        return;
    }

    cout << "Current details:"<<endl;
    doctors[found].display();

    string name, specialty;
    int experience;

    cin.ignore();
    cout << "Enter new Name : ";
    getline(cin, name);
    cout << "Enter new Specialty : ";
    getline(cin, specialty);
    cout << "Enter new Experience : ";
    cin >> experience;

    doctors[found].set_doctorName(name);
    doctors[found].set_doctorSpecialty(specialty);
    doctors[found].set_experience(experience);

    ofstream file("data/doctors.txt");
    for (int i = 0; i < total; i++) {
        file << doctors[i].get_doctorID() << "#"<< doctors[i].get_doctorName() << "#"<< doctors[i].get_doctorSpecialty() << "#" << doctors[i].get_experience() << "\n";
    }
    file.close();

    cout << "Doctor updated successfully."<<endl;
}

void deleteDoctor(Doctor* &doctors, int &total) {
    int id;
    cout << "\n--- Delete Doctor ---\n";
    cout << "Enter Doctor ID to delete: "; cin >> id;

    int found = -1;
    for (int i = 0; i < total; i++) {
        if (doctors[i].get_doctorID() == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        cout << "Doctor not found."<<endl;
        return;
    }

    // makeING small array without that doctor
    Doctor* newArr = new Doctor[total - 1];
    int j = 0;
    for (int i = 0; i < total; i++) {
        if (i == found){
            continue;
        }
        newArr[j++] = doctors[i];
    }

    delete[] doctors;
    doctors = newArr;
    total--;

   
    ofstream file("data/doctors.txt");
    for (int i = 0; i < total; i++) {
        file << doctors[i].get_doctorID() << "#" << doctors[i].get_doctorName() << "#" << doctors[i].get_doctorSpecialty() << "#"<< doctors[i].get_experience() << endl;
    }
    file.close();

    cout << "Doctor deleted successfully."<<endl;
}

void sortDoctorsByExperience(Doctor* doctors, int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (doctors[j].get_experience() < doctors[j + 1].get_experience()) {
                // swap
                Doctor temp = doctors[j];
                doctors[j] = doctors[j + 1];
                doctors[j + 1] = temp;
            }
        }
    }
    cout<<endl;
    cout << "--- Doctors Sorted by Experience ---"<<endl;
    for (int i = 0; i < total; i++)
        doctors[i].display();
}

void viewTreatmentsByDoctor(Doctor* doctors, int docTotal, Appointment* appointments, int appTotal, Treatment* treatments, int treatTotal) {
    int id;
    cout<<endl;
    cout << "--- View Treatments by Doctor ---"<<endl;
    cout << "Enter Doctor ID: "; cin >> id;

    
    bool doc_Found = false;
    for (int i = 0; i < docTotal; i++) {
        if (doctors[i].get_doctorID() == id) {
            cout << "Doctor: " << doctors[i].get_doctorName() << endl;
            doc_Found = true;
            break;
        }
    }

    if (!doc_Found) {
        cout << "Doctor not found."<<endl;
        return;
    }

   
    bool anyFound = false;
    for (int i = 0; i < appTotal; i++) {
        if (appointments[i].getDoctorId() == id) {
            int pid = appointments[i].getPatientId();

            
            for (int j = 0; j < treatTotal; j++) {
                if (treatments[j].get_patientID() == pid) {
                    treatments[j].display();
                    anyFound = true;
                }
            }
        }
    }

    if (!anyFound)
        cout << "No treatments found for this doctor."<<endl;
}

void addTreatment(Treatment* &treatments, int &total){
    int id;
    string description;
    double cost;

    cout<<endl;
    cout<<"--- Add Treatment --- "<<endl;
    cout<<"Enter Patient ID: ";
    cin>>id;

    cin.ignore();

    cout<<"Enter Description: ";
    getline(cin, description);

    cout<<"Enter the cost: ";
    cin>>cost;

    Treatment* new_arr = new Treatment[total + 1];
    for(int i=0;i<total;i++){
        new_arr[i] = treatments[i];
    }

    new_arr[total].set_patientID(id);
    new_arr[total].set_description(description);
    new_arr[total].set_cost(cost);
    new_arr[total].set_paid(false);

    delete[] treatments;
    treatments = new_arr;
    total++;

    ofstream tfile("data/treatments.txt", ios::app);
    tfile<<id<<"#"<<description<<"#"<<cost<<"#"<<"false"<<endl;
    tfile.close();

    cout<<"Treatments are added successfully"<<endl;

}

void viewTreatments(Treatment* treatments, int total) {
    cout<<endl;
    cout << "--- All Treatments --- "<<endl;
    if (total == 0) {
        cout << "No treatments found."<<endl;
        return;
    }
    for (int i = 0; i < total; i++)
        treatments[i].display();
}

void updatePayment(Treatment* treatments, int treatTotal) {
    int id;
    cout<<endl;
    cout << "--- Update Payment Status ---"<<endl;
    cout << "Enter Patient ID: "; cin >> id;

    // find treatment for this patient
    bool found = false;
    for (int i = 0; i < treatTotal; i++) {
        if (treatments[i].get_patientID() == id) {
            treatments[i].set_paid(true);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No treatment found for Patient ID " << id << endl;
        return;
    }

    // update bills.txt — find the line with this patient ID and mark as Paid
    ifstream inFile("data/bills.txt");
    ofstream tempFile("data/bills_temp.txt");

    string line;
    bool updated = false;

    while (getline(inFile, line)) {
        if (line.empty()) continue;

        string fields[3];
        int count = splitLine(line, fields, 3);

        if (count >= 3 && toInt(trim(fields[0])) == id) {
            // write this record with Paid status
            tempFile << fields[0] << "#" << fields[1] << "#Paid"<<endl;
            updated = true;
            cout << "Payment marked as Paid for Patient ID " << id << endl;
        } else {
            tempFile << line << endl;
        }
    }

    inFile.close();
    tempFile.close();

    remove("data/bills.txt");
    rename("data/bills_temp.txt", "data/bills.txt");

    if (!updated)
        cout << "No bill found for Patient ID " << id << endl;
}

void generateBill(Treatment* treatments, int treatTotal,
                  Patient* patients, int patientTotal) {
    int id;

    cout<<endl;
    cout << "--- Generate Bill --- "<<endl;
    cout << "Enter Patient ID: "; cin >> id;

    // findinf name
    string patientName = "Unknown";
    for (int i = 0; i < patientTotal; i++) {
        if (patients[i].getPatientId() == id) {
            patientName = patients[i].getName();
            break;
        }
    }

    cout<<endl;
    cout << "========== BILL ========"<<endl;
    cout << "Patient ID: " << id << endl;
    cout << "Patient Name: " << patientName << endl;
    cout << "--------------------------"<<endl;

    double totalCost = 0;
    bool found = false;
    string status;

    for (int i = 0; i < treatTotal; i++) {
        if (treatments[i].get_patientID() == id) {
            cout << "Treatment: " << treatments[i].get_description() << endl;
            cout << "Cost: " << treatments[i].get_cost() << endl;
            
        if (treatments[i].isPaid()) {
            status = "Paid";
        } else {
            status = "Unpaid";
        }
        cout << "Status: " << status << endl;
        cout << "--------------------------"<<endl;
        totalCost += treatments[i].get_cost();
        found = true;
        }
    }

    if (!found) {
        cout << "No treatments found for this patient"<<endl;
        return;
    }

    cout << "Total Cost   : " << totalCost << endl;
    cout << "=========================="<<endl;
}

bool login() {
    string employeeID = "123";
    string password = "pass123";

    string enteredID, enteredPassword;
    int attempts = 0;

    while (attempts < 3) {
        cout << "=========================================" << endl;
        cout << "        HOSPITAL MANAGEMENT SYSTEM       " << endl;
        cout << "=========================================" << endl;
        cout << "Enter Employee ID: "; cin >> enteredID;
        cout << "Enter Password   : "; cin >> enteredPassword;

        if (enteredID == employeeID && enteredPassword == password) {
            cout<<endl;
            cout << "Login Successful! Welcome!"<<endl;
            return true;
        } else {
            attempts++;
            
            cout << "Invalid ID or Password. Attempts remaining: " << 3 - attempts << endl;
        }
    }

    cout << "Too many failed attempts. Exiting"<<endl;
    return false;
}

void searchDoctorByID(Doctor* doctors, int total) {
    int id;
    cout<<endl;
    cout << "--- Search Doctor by ID ---"<<endl;
    cout << "Enter Doctor ID: "; cin >> id;

    bool found = false;
    for (int i = 0; i < total; i++) {
        if (doctors[i].get_doctorID() == id) {
            doctors[i].display();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "No doctor found with ID " << id << endl;
}

int main(){
    if (!login()) return 0;

    cleanFile();

    int docTotal = 0, treatTotal = 0, patTotal = 0, appTotal = 0;

    Doctor* doctors = loadDoctors(docTotal);
    Treatment* treatments  = loadTreatments(treatTotal);
    Patient* patients = loadPatients(patTotal);
    Appointment* appointments = loadAppointments(appTotal);

    int choice = 0;
    while (choice != 6) {
        cout<<endl;
        cout << "=========================================" << endl;
        cout << "        HOSPITAL MANAGEMENT SYSTEM       " << endl;
        cout << "=========================================" << endl;
        cout << "1. Patient Management"     << endl;
        cout << "2. Doctor Management"      << endl;
        cout << "3. Appointment Management" << endl;
        cout << "4. Treatment & Billing"    << endl;
        cout << "5. Search / Reports"       << endl;
        cout << "6. Exit"                   << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int subChoice;
            cout<<endl;
            cout << "--- Patient Management ---"<<endl;
            cout << "1. Add Patient"<<endl;
            cout << "2. Update Patient"<<endl;
            cout << "3. Delete Patient"<<endl;
            cout << "4. View All Patients"<<endl;
            cout << "Enter choice: ";
            cin >> subChoice;

            if      (subChoice == 1) {
                addPatient(patients, patTotal);
            }
            else if (subChoice == 2) {
                updatePatient(patients, patTotal);
            }
            else if (subChoice == 3) {
                deletePatient(patients, patTotal);
            }
            else if (subChoice == 4) {
                viewPatients(patients, patTotal);
            }
            else {
                cout << "Invalid choice."<<endl;
            }

        } else if (choice == 2) {
            int subChoice;
            cout<<endl;
            cout << "--- Doctor Management ---"<<endl;
            cout << "1. Add Doctor"<<endl;
            cout << "2. Update Doctor"<<endl;
            cout << "3. Delete Doctor"<<endl;
            cout << "4. View All Doctors"<<endl;
            cout << "5. Sort Doctors by Experience"<<endl;
            cout << "Enter choice: ";
            cin >> subChoice;

            if (subChoice == 1) {
                addDoctor(doctors, docTotal);
            }
            else if (subChoice == 2) {
                updateDoctor(doctors, docTotal);
            }
            else if (subChoice == 3) {
                deleteDoctor(doctors, docTotal);
            }
            else if (subChoice == 4) {
                viewDoctors(doctors, docTotal);
            }
            else if (subChoice == 5) {
                sortDoctorsByExperience(doctors, docTotal);
            }
            else {
                cout << "Invalid choice."<<endl;
            }

        } else if (choice == 3) {
            int subChoice;
            cout<<endl;
            cout << "--- Appointment Management ---"<<endl;
            cout << "1. Schedule Appointment"<<endl;
            cout << "2. Cancel Appointment"<<endl;
            cout << "3. View All Appointments"<<endl;
            cout << "Enter choice: ";
            cin >> subChoice;

            if (subChoice == 1) {
                scheduleAppointment(appointments, appTotal, patients, patTotal);
            }
            else if (subChoice == 2) {
                cancelAppointment(appointments, appTotal);
            }
            else if (subChoice == 3) {
                viewAppointments(appointments, appTotal);
            }
            else {
                cout << "Invalid choice"<<endl;
            }

        } else if (choice == 4) {
            int subChoice;
            cout<<endl;
            cout << " --- Treatment & Billing ---"<<endl;
            cout << "1. Add Treatment"<<endl;
            cout << "2. View Treatments"<<endl;
            cout << "3. Update Payment Status"<<endl;
            cout << "4. Generate Bill"<<endl;
            cout << "5. View Treatments by Doctor"<<endl;
            cout << "Enter choice: ";
            cin >> subChoice;

            if (subChoice == 1) {
                addTreatment(treatments, treatTotal);
            }
            else if (subChoice == 2) {
                viewTreatments(treatments, treatTotal);
            }
            else if (subChoice == 3) {
                updatePayment(treatments, treatTotal);
            }
            else if (subChoice == 4) {
                generateBill(treatments, treatTotal, patients, patTotal);
            }
            else if (subChoice == 5) {
                viewTreatmentsByDoctor(doctors, docTotal, appointments, appTotal, treatments, treatTotal);
            }
            else {
                cout << "Invalid choice."<<endl;
            }

        } else if (choice == 5) {
            int subChoice;
            cout<<endl;
            cout << "--- Search / Reports ---"<<endl;
            cout << "1. Search Patient by ID"<<endl;
            cout << "2. Search Patient by Name"<<endl;
            cout << "3. Search Doctor by ID"<<endl;
            cout << "4. Search Doctor by Specialty"<<endl;
            cout << "5. View Treatments by Doctor"<<endl;
            cout << "6. Sort Doctors by Experience"<<endl;
            cout << "Enter choice: ";
            cin >> subChoice;

            if (subChoice == 1) {
                searchPatientsByID(patients, patTotal);
            }
            else if (subChoice == 2) {
                searchPatientsByName(patients, patTotal);
            }
            else if (subChoice == 3) {
                searchDoctorByID(doctors, docTotal);
            }
            else if (subChoice == 4) {
                searchDoctorBySpecialty(doctors, docTotal);
            }
            else if (subChoice == 5) {
                viewTreatmentsByDoctor(doctors, docTotal, appointments, appTotal, treatments, treatTotal);
            }
            else if (subChoice == 6) {
                sortDoctorsByExperience(doctors, docTotal);
            }
            else {
                cout << "Invalid choice."<<endl;
            }

        } else if (choice == 6) {
            cout << "Exiting... Goodbye!"<<endl;
        } else {
            cout << "Invalid choice. Try again."<<endl;
        }
    }

    
    delete[] doctors;
    delete[] treatments;
    delete[] patients;
    delete[] appointments;

    return 0;
}