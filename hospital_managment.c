#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define structures for patients and doctors
struct Patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    char diagnosis[100];
    float bill;
};

struct Doctor {
    int id;
    char name[50];
    char specialty[50];
    int available; // 1 for available, 0 for not available
};

// Function prototypes
void addPatient();
void viewPatients();
void dischargePatient();
void addDoctor();
void viewDoctors();
void markDoctorAvailability();

// Global variables
struct Patient patients[100];
int patientCount = 0;

struct Doctor doctors[50];
int doctorCount = 0;

int main() {
    int choice;
    char cont = 'y';

    do {
        system("clear"); // Clears the screen (macOS/Linux-specific)
        printf("\n--- Hospital Management System ---\n");
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Discharge Patient\n");
        printf("4. Add Doctor\n");
        printf("5. View Doctors\n");
        printf("6. Mark Doctor Availability\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                viewPatients();
                break;
            case 3:
                dischargePatient();
                break;
            case 4:
                addDoctor();
                break;
            case 5:
                viewDoctors();
                break;
            case 6:
                markDoctorAvailability();
                break;
            case 7:
                printf("\nThank you for using the Hospital Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }

        printf("\nDo you want to continue? [y/n]: ");
        scanf(" %c", &cont);
    } while (cont == 'y' || cont == 'Y');

    return 0;
}

// Function to add a new patient
void addPatient() {
    printf("\n--- Add Patient ---\n");
    struct Patient p;
    p.id = patientCount + 1;

    printf("Enter patient name: ");
    scanf(" %[^\n]%*c", p.name); // Read a string with spaces
    printf("Enter patient age: ");
    scanf("%d", &p.age);
    printf("Enter patient gender (Male/Female): ");
    scanf("%s", p.gender);
    printf("Enter diagnosis: ");
    scanf(" %[^\n]%*c", p.diagnosis);
    printf("Enter initial bill amount: ");
    scanf("%f", &p.bill);

    patients[patientCount++] = p;
    printf("\nPatient added successfully! Patient ID: %d\n", p.id);
}

// Function to view all patients
void viewPatients() {
    printf("\n--- View Patients ---\n");
    if (patientCount == 0) {
        printf("No patients registered.\n");
        return;
    }

    for (int i = 0; i < patientCount; i++) {
        struct Patient p = patients[i];
        printf("\nPatient ID: %d\n", p.id);
        printf("Name: %s\n", p.name);
        printf("Age: %d\n", p.age);
        printf("Gender: %s\n", p.gender);
        printf("Diagnosis: %s\n", p.diagnosis);
        printf("Bill: $%.2f\n", p.bill);
    }
}

// Function to discharge a patient
void dischargePatient() {
    printf("\n--- Discharge Patient ---\n");
    if (patientCount == 0) {
        printf("No patients to discharge.\n");
        return;
    }

    int id;
    printf("Enter Patient ID to discharge: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Patient with ID %d not found.\n", id);
        return;
    }

    printf("Patient %s discharged successfully!\n", patients[index].name);

    // Shift remaining patients up
    for (int i = index; i < patientCount - 1; i++) {
        patients[i] = patients[i + 1];
    }
    patientCount--;
}

// Function to add a new doctor
void addDoctor() {
    printf("\n--- Add Doctor ---\n");
    struct Doctor d;
    d.id = doctorCount + 1;

    printf("Enter doctor name: ");
    scanf(" %[^\n]%*c", d.name);
    printf("Enter specialty: ");
    scanf(" %[^\n]%*c", d.specialty);
    d.available = 1; // By default, the doctor is available

    doctors[doctorCount++] = d;
    printf("\nDoctor added successfully! Doctor ID: %d\n", d.id);
}

// Function to view all doctors
void viewDoctors() {
    printf("\n--- View Doctors ---\n");
    if (doctorCount == 0) {
        printf("No doctors registered.\n");
        return;
    }

    for (int i = 0; i < doctorCount; i++) {
        struct Doctor d = doctors[i];
        printf("\nDoctor ID: %d\n", d.id);
        printf("Name: %s\n", d.name);
        printf("Specialty: %s\n", d.specialty);
        printf("Availability: %s\n", d.available ? "Available" : "Not Available");
    }
}

// Function to mark doctor availability
void markDoctorAvailability() {
    printf("\n--- Mark Doctor Availability ---\n");
    if (doctorCount == 0) {
        printf("No doctors to update.\n");
        return;
    }

    int id, status;
    printf("Enter Doctor ID: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < doctorCount; i++) {
        if (doctors[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Doctor with ID %d not found.\n", id);
        return;
    }

    printf("Enter availability (1 for Available, 0 for Not Available): ");
    scanf("%d", &status);

    doctors[index].available = status;
    printf("Doctor %s's availability updated successfully!\n", doctors[index].name);
}
