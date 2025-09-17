#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


class Octonaut {
	/*
	
	A constructor to initialize all attributes
	printProfile() — prints a detailed profile of the Octonaut, including their likes, dislikes, and conditions in a readable format
	addLike(string) and addDislike(string) to add to those lists
	hasCondition(string) — returns true if the Octonaut has the specified condition
	*/


	public:
		//constructor
		Octonaut(string name, string species, string ethnicity, string job, vector<string> conditions, vector<string> siblings) {
			this->name = name;
			this->species = species;
			this->ethnicity = ethnicity;
			this->job = job;
			this->conditions = conditions;
			this->siblings = siblings;

		}
		//name
		void setName(string inName) {
			name = inName;
		}
		string getName() {
			return name;
		}

		//species
		void setSpecies(string inSpecies) {
			species = inSpecies;
		}
		string getSpecies() {
			return species;
		}

		//ethnicity
		void setEthnicity(string inEthnicity) {
			ethnicity = inEthnicity;
		}
		string getEthnicity() {
			return ethnicity;
		}

		//job
		void setJob(string inJob) {
			job = inJob;
		}
		string getJob() {
			return job;
		}

		//conditions
		void setCondition(string condition) {
			conditions.push_back(condition);
		}
		vector<string> getConditions() {
			return conditions;
		}

		//siblings
		void setSibling(string sibling) {
			siblings.push_back(sibling);
		}
		vector<string> getSiblings() {
			return siblings;
		}
	private:
		string name;
		string species;
		string ethnicity;
		string job;
		vector<string> conditions;
		vector<string> siblings;
};
vector<Octonaut> crew;

//add entry
void addEntry() {
	string name;
	string species;
	string ethnicity;
	string job;
	vector<string> conditions;
	vector<string> siblings;

	int num;
	string temp;

	cout << "enter a name: ";
	getline(cin, name);

	cout << "enter a species: ";
	getline(cin, species);
	
	cout << "enter an ethnicity: ";
	getline(cin, ethnicity);

	cout << "enter a job: ";
	getline(cin, job);

	cout << "how many conditions? ";
	cin >> num;
	cin.ignore();
	for (int i = 0; i < num; ++i) {
		cout << "Enter a condition: ";
		getline(cin, temp);
		conditions.push_back(temp);
	}

	cout << "how many siblings? ";
	cin >> num;
	cin.ignore();
	for (int i = 0; i < num; ++i) {
		cout << "Enter a sibling: ";
		getline(cin, temp);
		siblings.push_back(temp);
	}

	Octonaut newOctonaut(name, species, ethnicity, job, conditions, siblings);
	crew.push_back(newOctonaut);
}

//edit entry
void editEntry(Octonaut& entry) {
	int toEdit;
	cout << "What aspect would you like to edit?" << endl << "1: name" << endl << "2: species" << endl << "3: ethnicity" << endl << "4: job" << endl << "5: conditions" << endl << "6: siblings" << endl;
	cin >> toEdit;
	cin.ignore();
	string newVar;
	
	switch (toEdit) {
		case 1: //name
			cout << "Enter new name :";
			getline (cin, newVar);
			entry.setName(newVar);
			break;
		case 2: //species
			cout << "Enter new species :";
			getline (cin, newVar);
			entry.setSpecies(newVar);
			break;
		case 3: //ethnicity
			cout << "Enter new ethnicity :";
			getline (cin, newVar);
			entry.setEthnicity(newVar);
			break;
		case 4: //job
			cout << "Enter new job :";
			getline (cin, newVar);
			entry.setJob(newVar);
			break;
		case 5: //conditions
			cout << "Enter new condition to be added to the list :";
			getline (cin, newVar);
			entry.setCondition(newVar);
			break;
		case 6: //siblings
			cout << "Enter new sibling to be added to the list :";
			getline (cin, newVar);
			entry.setSibling(newVar);
			break;
	}
}

//print one entry
void printEntry(Octonaut& entry) {
	cout << "-----------------------------------------------------------" << endl;
	
	cout << left << setw(15) << "Name" << setw(15) << "Species" << setw(15) << "Ethnicity" << setw(15) << "Job" << setw(30) << "Conditions" << setw(30) << "Siblings" << endl;
    cout << left << setw(15) << "----" << setw(15) << "-------" << setw(15) << "---------" << setw(15) << "---" << setw(30) << "----------" << setw(30) << "--------" << endl; 
	
	/*
	cout << "| " << entry.getName() << endl;
	cout << "| " << entry.getSpecies() << endl;
	cout << "| " << entry.getEthnicity() << endl;
	cout << "| " << entry.getJob() << endl;

	//conditions
	for (const auto& condition : entry.getConditions()) {
		cout << "| " << condition << " | ";
	}
	cout << endl;

	//siblings
	for (const auto& sibling : entry.getSiblings()) {
		cout << "| " << sibling << " | ";
	}
	cout << endl;

	cout << "-----------------------------------------------------------" << endl;
	*/
}

int main() {
	int choice;
	int toEdit;
	
	cout << "What would you like to do?" << endl << "1: add entry" << endl << "2: edit entry" << endl << "3: print one entry" << endl << "4: print whole list" << endl << "5: quit" << endl;
	cin >> choice;
	cin.ignore();
	
	while (choice != 5) {
		switch (choice) {
			case 1:
				addEntry();
				break;
			case 2:
				cout << "Which entry would you like to edit?" << endl;
				for (int i = 0; i < crew.size(); ++i) {
					cout << i << " : " << crew.at(i).getName() << endl;
				}
				cout << "Enter the number: ";
				cin >> toEdit;
				cin.ignore();

				editEntry(crew.at(toEdit));
				break;
			case 3:
				cout << "Which entry would you like to print?" << endl;
				for (int i = 0; i < crew.size(); ++i) {
					cout << i << " : " << crew.at(i).getName() << endl;
				}
				cout << "Enter the number: ";
				cin >> toEdit;
				cin.ignore();

				printEntry(crew.at(toEdit));
				break;
			case 4:
				for (int i = 0; i < crew.size(); ++i) {
					printEntry(crew.at(i));
					cout << endl;
				}
		}
		cout << "What would you like to do?" << endl << "1: add entry" << endl << "2: edit entry" << endl << "3: print one entry" << endl << "4: print whole list" << endl << "5: quit" << endl;
		cin >> choice;
		cin.ignore();
	}
	
	
	return 0;
}