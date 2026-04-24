#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// ============================================================
//  HELPER FUNCTIONS
// ============================================================

int splitLine(string line, string parts[], int maxParts) {
    int count = 0;
    string token = "";
    for (int i = 0; i < (int)line.length(); i++) {
        if (line[i] == '#') {
            if (count < maxParts) parts[count++] = token;
            token = "";
        } else {
            token += line[i];
        }
    }
    if (count < maxParts) parts[count++] = token;
    return count;
}

string trim(string s) {
    int start = 0, end = (int)s.length() - 1;
    while (start <= end && s[start] == ' ') start++;
    while (end >= start && s[end]   == ' ') end--;
    if (start > end) return "";
    return s.substr(start, end - start + 1);
}

// replaces stoi — works on all compilers including Dev-C++
int toInt(string s) {
    int val = 0;
    stringstream ss(s);
    ss >> val;
    return val;
}

// replaces stod
double toDouble(string s) {
    double val = 0.0;
    stringstream ss(s);
    ss >> val;
    return val;
}

int countLines(string filename) {
    ifstream f(filename.c_str());
    int count = 0;
    string line;
    while (getline(f, line))
        if (!line.empty()) count++;
    return count;
}


// ============================================================
//  PATIENT CLASS
// ============================================================
class Patient {
private:
    int    patientId;
    string name;
    int    age;
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

    ~Patient() {}

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

    int    getPatientId() const { return patientId; }
    string getName()      const { return name;      }
    int    getAge()       const { return age;        }
    string getGender()    const { return gender;     }
    string getContact()   const { return contact;    }
    double getBalance()   const { return balance;    }

    void display() const {
        cout << "Patient ID : " << patientId << "\n";
        cout << "Name       : " << name      << "\n";
        cout << "Age        : " << age       << "\n";
        cout << "Gender     : " << gender    << "\n";
        cout << "Contact    : " << contact   << "\n";
        cout << "Balance    : " << balance   << "\n";
        cout << "------------------------\n";
    }
};


// ============================================================
//  APPOINTMENT CLASS
// ============================================================
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

    ~Appointment() {}

    void setPatientId(int id) {
        if (id > 0) patientId = id;
        else cout << "Invalid Patient ID\n";
    }
    void setDoctorId(int id) {
        if (id > 0) doctorId = id;
        else cout << "Invalid Doctor ID\n";
    }
    void setDate(string d) {
        if (d.length() > 0 && d.length() <= 11) {
            for (int i = 0; i < (int)d.length(); i++)
                date[i] = d[i];
            date[d.length()] = '\0';
        } else {
            cout << "Invalid Date\n";
        }
    }
    void setTime(string t) {
        if (t.length() > 0 && t.length() <= 11) {
            for (int i = 0; i < (int)t.length(); i++)
                time[i] = t[i];
            time[t.length()] = '\0';
        } else {
            cout << "Invalid Time\n";
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


// ============================================================
//  DOCTOR CLASS
// ============================================================
class Doctor {
private:
    int    doctorID;
    string doctorName;
    string doctorSpecialty;
    int    experience;

public:
    Doctor() {
        doctorID        = 0;
        experience      = 0;
        doctorName      = "";
        doctorSpecialty = "";
    }

    int    get_doctorID()        const { return doctorID;        }
    string get_doctorName()      const { return doctorName;      }
    string get_doctorSpecialty() const { return doctorSpecialty; }
    int    get_experience()      const { return experience;      }

    void set_doctorID(int id)          { doctorID = id;       }
    void set_doctorName(string n)      { doctorName = n;      }
    void set_doctorSpecialty(string s) { doctorSpecialty = s; }
    void set_experience(int e)         { experience = e;      }

    void display() const {
        cout << "Doctor ID  : " << doctorID        << "\n";
        cout << "Name       : " << doctorName      << "\n";
        cout << "Specialty  : " << doctorSpecialty << "\n";
        cout << "Experience : " << experience      << " years\n";
        cout << "------------------------\n";
    }
};


// ============================================================
//  TREATMENT CLASS
// ============================================================
class Treatment {
private:
    int    patientID;
    string description;
    double cost;
    bool   paid;

public:
    Treatment() {
        patientID   = 0;
        cost        = 0.0;
        paid        = false;
        description = "";
    }

    int    get_patientID()   const { return patientID;   }
    string get_description() const { return description; }
    double get_cost()        const { return cost;        }
    bool   isPaid()          const { return paid;        }

    void set_patientID(int id)     { patientID = id;   }
    void set_description(string d) { description = d;  }
    void set_cost(double c)        { cost = c;         }
    void set_paid(bool p)          { paid = p;         }

    void display() const {
        cout << "Patient ID  : " << patientID              << "\n";
        cout << "Description : " << description            << "\n";
        cout << "Cost        : " << cost                   << "\n";
        cout << "Paid        : " << (paid ? "Yes" : "No")  << "\n";
        cout << "------------------------\n";
    }
};


// ============================================================
//  LOAD PATIENTS
// ============================================================
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


// ============================================================
//  LOAD APPOINTMENTS
// ============================================================
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


// ============================================================
//  LOAD DOCTORS
// ============================================================
Doctor* loadDoctors(int& total) {
    total = countLines("doctors.txt");
    if (total == 0) { cout << "No doctors found.\n"; return NULL; }

    Doctor* doctors = new Doctor[total];
    ifstream file("doctors.txt");
    string line; int i = 0;

    while (getline(file, line)) {
        if (line.empty()) continue;
        string parts[10];
        int count = splitLine(line, parts, 10);
        if (count < 4) continue;

        doctors[i].set_doctorID(toInt(trim(parts[0])));
        doctors[i].set_doctorName(trim(parts[1]));
        doctors[i].set_doctorSpecialty(trim(parts[2]));
        doctors[i].set_experience(toInt(trim(parts[3])));
        i++;
    }
    file.close();
    total = i;
    cout << "Loaded " << total << " doctors.\n";
    return doctors;
}


// ============================================================
//  LOAD TREATMENTS
// ============================================================
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


// ============================================================
//  MAIN
// ============================================================
int main() {
    int patientCount   = 0;
    int appointCount   = 0;
    int doctorCount    = 0;
    int treatmentCount = 0;

    Patient*     patients     = loadPatients(patientCount);
    Appointment* appointments = loadAppointments(appointCount);
    Doctor*      doctors      = loadDoctors(doctorCount);
    Treatment*   treatments   = loadTreatments(treatmentCount);

    cout << "\n===== PATIENTS =====\n";
    for (int i = 0; i < 1; i++) //rep with 1 patientCount
        patients[i].display();

    cout << "\n===== APPOINTMENTS =====\n";
    for (int i = 0; i < ; i++)//appointCount replaced with 1
        appointments[i].display();

    cout << "\n===== DOCTORS =====\n";
    for (int i = 0; i < doctorCount; i++)
        doctors[i].display();

    cout << "\n===== TREATMENTS =====\n";
    for (int i = 0; i < treatmentCount; i++)
        treatments[i].display();

    delete[] patients;
    delete[] appointments;
    delete[] doctors;
    delete[] treatments;

    return 0;
}
