


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
