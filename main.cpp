void savePatientsToFile(Patient* patients, int total) {
    ofstream file("patients.txt");
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

// ============================================================
//  PATIENT MANAGEMENT FUNCTIONS by Huzaifa
// ============================================================

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

    ofstream file("patients.txt", ios::app);
    file << id << "#" << name << "#" << age << "#"
         << gender << "#" << contact << "#" << balance << "\n";
    file.close();

    cout << "Patient added successfully.\n";
}


void updatePatient(Patient* patients, int total) {
    int id;
    cout << "\n--- Update Patient ---\n";
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
        cout << "Patient not found.\n";
        return;
    }

    cout << "Current details:\n";
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
    ofstream file("patients.txt");
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
    ofstream file("patients.txt");
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


// ============================================================
//  APPOINTMENT FUNCTIONS by Huzaifa
// ============================================================

void scheduleAppointment(Appointment* &appointments, int &total,
                          Patient* patients, int patientCount) {
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
    ofstream file("appointments.txt", ios::app);
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
    ofstream file("appointments.txt");
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


// ============================================================
//  SEARCH FUNCTIONS by Huzaifa
// ============================================================

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
