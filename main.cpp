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
        if (g == "Male" || g == "Female") gender = g;
        else cout << "Invalid Gender (use Male or Female)" << endl;
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
        cout << "Patient ID : " << patientId << "\n";
        cout << "Name : " << name<< "\n";
        cout << "Age : " << age << "\n";
        cout << "Gender : " << gender<< "\n";
        cout << "Contact : " << contact << "\n";
        cout << "Balance : " << balance << "\n";
        cout << "------------------------\n";
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

    int    getPatientId() const { return patientId;    }
    int    getDoctorId()  const { return doctorId;     }
    string getDate()      const { return string(date); }
    string getTime()      const { return string(time); }

    void display() const {
        cout << "Patient ID : " << patientId << "\n";
        cout << "Doctor ID  : " << doctorId  << "\n";
        cout << "Date       : " << date      << "\n";
        cout << "Time       : " << time      << "\n";
        cout << "------------------------\n";
    }
};


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
        if(count < 4){
            cout << "Removed! incomplete Doctor Record: " << line << endl;
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
    // Step 1: Remove duplicates first
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

        // Check all 6 fields exist
        if (count < 6) {
            cout << "Removed incomplete patient record: " << line << endl;
            removed++;
            continue;
        }

        // Check ID is not empty and is a number
        if (fields[0].empty() || !isNumber(fields[0])) {
            cout << "Removed invalid ID: " << line << endl;
            removed++;
            continue;
        }

        // Check name is not empty
        if (fields[1].empty()) {
            cout << "Removed missing name: " << line << endl;
            removed++;
            continue;
        }

        // Check age is a number
        if (!isNumber(fields[2])) {
            cout << "Removed invalid age: " << line << endl;
            removed++;
            continue;
        }

        // Fix gender M→Male, F→Female
        if (fields[3] == "M") {
            fields[3] = "Male";
        } else if (fields[3] == "F") {
            fields[3] = "Female";
        }

        // Check contact is not empty
        if (fields[4].empty()) {
            cout << "Removed missing contact: " << line << endl;
            removed++;
            continue;
        }

        // Check phone has no alphabets
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

        // Check phone has exactly 11 digits
        if (fields[4].length() != 11) {
            cout << "Removed incomplete phone number: " << line << endl;
            removed++;
            continue;
        }

        // Valid record — write to temp file with fixed gender
        tempFile << fields[0] << "#"
                 << fields[1] << "#"
                 << fields[2] << "#"
                 << fields[3] << "#"
                 << fields[4] << "#"
                 << fields[5] << endl;
    }

    inFile.close();
    tempFile.close();

    remove("data/patients.txt");
    rename("data/patients_temp.txt", "data/patients.txt");

    cout << "Patients file cleaned. Records removed: " << removed << endl;
}

string fixDate(string date) {
    // Check if date is in YYYY-MM-DD format (starts with 4 digit year)
    // Example: 2026-04-24 → 04-24-2026
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
        return time; // already correct
    }

    // Extract hour and minutes
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
        if (count < 4) {
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

        tempFile << fields[0] << "#"
                 << fields[1] << "#"
                 << fixedDate  << "#"
                 << fixedTime  << endl;
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
        if (count < 3) {
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
    if (total == 0) { cout << "No patients found.\n"; return NULL; }

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
    cout << "Loaded " << total << " patients.\n";
    return patients;
}

Appointment* loadAppointments(int& total) {
    total = countLines("data/appointments.txt");
    if (total == 0) { cout << "No appointments found.\n"; return NULL; }

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
    cout << "Loaded " << total << " appointments.\n";
    return appointments;
}

Treatment* loadTreatments(int& total) {
    total = countLines("data/treatments.txt");
    if (total == 0) { cout << "No treatments found.\n"; return NULL; }

    Treatment* treatments = new Treatment[total];
    ifstream file("data/treatments.txt");
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



//  PATIENT MANAGEMENT FUNCTIONS by Huzaifa

void savePatientsToFile(Patient* patients, int total) {
    ofstream file("data/patients.txt");
    for (int i = 0; i < total; i++) {
        file << patients[i].getPatientId() << "#"
             << patients[i].getName()      << "#"
             << patients[i].getAge()       << "#"
             << patients[i].getGender()    << "#"
             << patients[i].getContact()   << "#"
             << patients[i].getBalance()   << "\n";
    }
    file.close();
}

void addPatient(Patient* &patients, int &total)
{
    int id, age;
    string name, gender, contact;
    double balance;

    cout << "Add New Patient\n";
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

    cout << "Patient added successfully.\n";
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
        file << patients[i].getPatientId() << "#"
             << patients[i].getName()      << "#"
             << patients[i].getAge()       << "#"
             << patients[i].getGender()    << "#"
             << patients[i].getContact()   << "#"
             << patients[i].getBalance()   << "\n";
    }
    file.close();

    cout << "Patient updated successfully.\n";
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
        cout << "Patient not found.\n";
        return;
    }

    // make a smaller array without that patient
    Patient* newArr = new Patient[total - 1];
    int j = 0;
    for (int i = 0; i < total; i++) {
        if (i == found) continue; // skip the deleted one
        newArr[j++] = patients[i];
    }

    delete[] patients;
    patients = newArr;
    total--;

    // rewrite file without deleted patient
    ofstream file("data/patients.txt");
    for (int i = 0; i < total; i++) {
        file << patients[i].getPatientId() << "#"
             << patients[i].getName()      << "#"
             << patients[i].getAge()       << "#"
             << patients[i].getGender()    << "#"
             << patients[i].getContact()   << "#"
             << patients[i].getBalance()   << "\n";
    }
    file.close();

    cout << "Patient deleted successfully.\n";
}

void viewPatients(Patient* patients, int total) {
    cout << "\n--- All Patients ---\n";
    if (total == 0) {
        cout << "No patients found.\n";
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
    cout << "Enter Doctor ID            : ";
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
        cout << "Patient not found.\n";
        return;
    }

    // check balance
    if (patients[found].getBalance() < cost)
    {
        cout << "Insufficient balance. Appointment denied.\n";
        cout << "Balance: " << patients[found].getBalance()
             << " | Cost: " << cost << "\n";
        return;
    }

    // deduct cost
    patients[found].setBalance(patients[found].getBalance() - cost);

    // add to appointments array
    Appointment* newArr = new Appointment[total + 1];
    for (int i = 0; i < total; i++)
        newArr[i] = appointments[i];

    newArr[total].setPatientId(pid);
    newArr[total].setDoctorId(did);
    newArr[total].setDate(date);
    newArr[total].setTime(timeSlot);

    delete[] appointments;
    appointments = newArr;
    total++;

    // save appointment to file
    ofstream file("data/appointments.txt", ios::app);
    file << pid << "#" << did << "#" << date << "#" << timeSlot << "\n";
    file.close();

    cout << "Appointment scheduled successfully.\n";
    cout << "Remaining balance: " << patients[found].getBalance() << "\n";

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
        cout << "Appointment not found.\n";
        return;
    }

    cout << "Cancelling:\n";
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

    // rewrite file
    ofstream file("data/appointments.txt");
    for (int i = 0; i < total; i++) {
        file << appointments[i].getPatientId() << "#"
             << appointments[i].getDoctorId()  << "#"
             << appointments[i].getDate()      << "#"
             << appointments[i].getTime()      << "\n";
    }
    file.close();

    cout << "Appointment cancelled successfully.\n";
}

void viewAppointments(Appointment* appointments, int total) {
    cout << "\n--- All Appointments ---\n";
    if (total == 0) {
        cout << "No appointments found.\n";
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
        cout << "No patient found with ID " << id << "\n";
}

void searchPatientsByName(Patient* patients, int total) {
    string name;
    cout << "\n--- Search Patient by Name ---\n";
    cin.ignore();
    cout << "Enter Name: "; getline(cin, name);

    bool found = false;
    for (int i = 0; i < total; i++) {
        if (patients[i].getName() == name) {
            patients[i].display();
            found = true;
        }
    }

    if (!found)
        cout << "No patient found with name " << name << "\n";
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
        cout << "No doctor found with specialty " << specialty << "\n";
}


int main() {
    return 0;
}