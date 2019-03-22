// PatientFees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Surgery;
class Pharmacy;

class PatientAccount {

	friend class Surgery;
	friend class Pharmacy;

	int totalCharges;
	int pricePerDay;
	int days;

public:

	PatientAccount() {

		totalCharges = 0;
		pricePerDay = 100;
		days = 0;

	}

	void updateDays(int input) {

		days = input;
		totalCharges += (pricePerDay*days);
	}

	void printCharges() {

		cout << totalCharges;
	}

	friend void updateCharges(PatientAccount &account) {};
	friend void updateChargesMeds(PatientAccount &account) {};


};
class Surgery {


	int herniaSCompleted;
	int rhinoplastySCompleted;
	int lasikSCompleted;
	int heartSCompleted;
	int brainSCompleted;

	int herniaSurgery;
	int rhinoplastySurgery;
	int lasikSurgery;
	int heartSurgery;
	int brainSurgery;

public:

	Surgery() {

		herniaSurgery = 5000;
		rhinoplastySurgery = 10000;
		lasikSurgery = 2000;
		heartSurgery = 20000;
		brainSurgery = 25000;

		herniaSCompleted = 0;
		rhinoplastySCompleted = 0;
		lasikSCompleted = 0;
		heartSCompleted = 0;
		brainSCompleted = 0;

	}

	void herniaCompleted() {

		herniaSCompleted = 1;

	} void rhinoPlastyCompleted() {

		++rhinoplastySCompleted;

	} void lasikCompleted() {

		++lasikSCompleted;

	} void heartSurgeryCompleted() {

		++heartSCompleted;

	} void brainSurgeryCompleted() {

		++brainSCompleted;

	} 

	void updateCharges(PatientAccount &account) {

		account.totalCharges += (herniaSurgery * herniaSCompleted) + (rhinoplastySurgery * rhinoplastySCompleted) + (lasikSurgery * lasikSCompleted)
			+ (heartSurgery * heartSCompleted) + (brainSurgery * brainSCompleted);
		
		
	}

};

class Pharmacy {

	int bloodPressureSold;
	int crohnsDiseaseSold;
	int painMedicationSold;
	int diabetesMedicationSold;
	int cholestrolMedicationSold;

	int bloodPressure;
	int crohnsDisease;
	int painMeds;
	int diabetesMedication;
	int cholestrolMedication;


public:


	Pharmacy() {

		bloodPressure = 200;
		crohnsDisease = 500;
		painMeds = 80;
		diabetesMedication = 4000;
		cholestrolMedication = 100;
		
		bloodPressureSold = 0;
		crohnsDiseaseSold = 0;
		painMedicationSold = 0;
		diabetesMedicationSold = 0;
		cholestrolMedicationSold = 0;
	}

	void bloodPressureMeds() {

		bloodPressureSold++;

	} void crohnsDiseaseMeds() {

		crohnsDiseaseSold++;

	} void painMedications() {

		painMedicationSold++;
		
	} void diabetesMeds() {

		diabetesMedicationSold++;

	} void cholestrolMeds() {

		cholestrolMedicationSold++;

	} void updateCharges(PatientAccount &account) {

		account.totalCharges += (bloodPressureSold * bloodPressure) + (crohnsDisease * crohnsDiseaseSold) + (painMedicationSold * painMeds)
		+ (diabetesMedicationSold * diabetesMedication) + (cholestrolMedication * cholestrolMedicationSold);
		
	}

	
};




int main()
{

	int surgery;
	int medication;
	int daysInHospital;

	PatientAccount patientOne;
	Surgery patientSurgery;
	Pharmacy patientMeds;
	

	cout << "Hello and welcome to the Dominick Hospital of Fast Recovery." << endl;
	cout << "Choose the number correlated to the surgery the patient received: " << endl;
	cout << "1. Hernia Surgery" << endl;
	cout << "2. Rhinoplasty" << endl;
	cout << "3. Lasik" << endl;
	cout << "4. Heart Surgery" << endl;
	cout << "5. Brain Surgery" << endl;
	cin >> surgery;

	switch (surgery) {
	
	case 1:
		patientSurgery.herniaCompleted();
		break;
	case 2:
		patientSurgery.rhinoPlastyCompleted();
		break;
	case 3:
		patientSurgery.lasikCompleted();
		break;
	case 4:
		patientSurgery.heartSurgeryCompleted();
		break;
	case 5:
		patientSurgery.brainSurgeryCompleted();
		break;
	}
	
	cout << "\nChoose the number correlated to the medication the patient received from our pharmacy: " << endl;
	cout << "1. Blood Pressure" << endl;
	cout << "2. Crohn's Disease" << endl;
	cout << "3. Pain Meds" << endl;
	cout << "4. Diabetes Medication" << endl;
	cout << "5. Cholestrol Medication" << endl;
	cin >> medication;

	switch (medication) {

	case 1:
		patientMeds.bloodPressureMeds();
		break;
	case 2:
		patientMeds.crohnsDiseaseMeds();
		break;
	case 3:
		patientMeds.painMedications();
		break;
	case 4:
		patientMeds.diabetesMeds();
		break;
	case 5:
		patientMeds.cholestrolMeds();
		break;
	}

	patientSurgery.updateCharges(patientOne);
	patientMeds.updateCharges(patientOne);

	cout << "\nEnter the number of days the patient stayed with us: " << endl;
	cin >> daysInHospital;
	patientOne.updateDays(daysInHospital);

	cout << "The patient is now checked out." << endl;
	cout << "Total Charges Due: $";
	patientOne.printCharges();
 
}

