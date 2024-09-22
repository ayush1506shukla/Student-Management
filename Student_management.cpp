#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;
bool isDuplicate(const string& rollNo, const string& filename) {
    ifstream csvFile("Book2.csv");
    string line;
    while (getline(csvFile, line)) {
        stringstream ss(line); 
        string firstColumn;
        if (getline(ss, firstColumn, ',')) {
            if (firstColumn == rollNo) {
                csvFile.close();
                return true;
            }
        }
    }
    csvFile.close();
    return false;
}
bool searchByRollNumber(const string& rollNo, const string& filename) {
    ifstream csvFile("Book2.csv");
    string line;
    while (getline(csvFile, line)) {
        stringstream ss(line); 
        string firstColumn;
        if (getline(ss, firstColumn, ',')) {
            if (firstColumn == rollNo) {
                cout << "Record found\n" << line << '\n';
                csvFile.close();
                return true;
            }
        }
    }

    cout << "Record not found for roll number: " << rollNo << '\n';
    csvFile.close();
    return false;
}
bool updateByRollNumber(const string& rollNo, const string& filename) {
    ifstream inputFile("Book2.csv");
    ofstream outputFile("temp.csv", ios::trunc);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files.\n";
        return false;
    }

    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string firstColumn;
        if (getline(ss, firstColumn, ',')) {
            if (firstColumn == rollNo) {
                string newName, newRollNo, newAge,newMarks,newEmail,newContact;
                cout << "Enter new roll number: ";
                cin>>newRollNo;
                cout << "Enter new name: ";
                cin>>newName;
                cout << "Enter new age: ";
                cin>>newAge;
                cout << "Enter new Marks: ";
                cin>>newMarks;
                cout << "Enter new Email: ";
                cin>>newEmail;
                cout << "Enter new Contact: ";
                cin>>newContact;

                outputFile << newRollNo << "," << newName << "," << newAge <<","<<newMarks<<","<<newEmail<<","<<newContact<<'\n';
                found = true;
            } else {
                outputFile << line << '\n';
            }
        }
    }

    inputFile.close();
    outputFile.close();
    remove(filename.c_str());
    rename("temp.csv", filename.c_str());

    if (found) {
        cout << "Record with roll number " << rollNo << " updated.\n";
    } else {
        cout << "Record not found for roll number: " << rollNo << '\n';
    }

    return found;
}
bool deleteByRollNumber(const string& rollNo, const string& filename) {
    ifstream inputFile("Book2.csv");
    ofstream outputFile("temp.csv", ios::trunc);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files.\n";
        return false;
    }

    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string firstColumn;
        if (getline(ss, firstColumn, ',')) {
            if (firstColumn != rollNo) {
                outputFile << line << '\n';
            } else {
                found = true;
            }
        }
    }

    inputFile.close();
    outputFile.close();
    remove(filename.c_str());
    rename("temp.csv", filename.c_str());

    if (found) {
        cout << "Record with roll number " << rollNo << " deleted.\n";
    } else {
        cout << "Record not found for roll number: " << rollNo << '\n';
    }

    return found;
}
void AddNewStudent(){
	string rollNo,name,email,contact;
	   double age,marks;
	
	 ofstream csvFile("Book2.csv",ios::app);
	    cout<<"Enter Roll No.:";
	    cin>>rollNo;
	    if (isDuplicate(rollNo, "Book2.csv")) {
        cout << "Roll number is already exists\n";
          return;
        }
	    cout<<"Enter Name:";
	    cin>>name;
	    cout<<"Enter Age:";
	    cin>>age;
	    cout<<"Enter Marks Out of 500:";
	    cin>>marks;
	    cout<<"Enter Email Id:";
	    cin>>email;
	    cout<<"Enter Contact Number:";
	    cin>>contact;
	    csvFile<<rollNo<<","<<name<<","<<age<<","<<marks<<","<<email<<","<<contact<<"\n";
		csvFile.close();
		cout<<"Student Details Added Successfully..."<<endl;
		return;
	} 

void displayAllRecords(const string& filename) {
	string rollNo,name,email,contact;
	   double age,marks;
    ifstream csvFile("Book2.csv");
    string line;
    while (getline(csvFile, line)) {
        cout << line << '\n';
    }

    csvFile.close();
}
void SearchStudent(){
	string rollNo;
    cout << "Enter roll number to search: ";
    cin>>rollNo;

    searchByRollNumber(rollNo, "Book2.csv");
	   	return;
}
void UpdateStudent(){
	string updateRollNo;
    cout << "Enter roll number to update: ";
    cin>>updateRollNo;

    updateByRollNumber(updateRollNo, "Book2.csv");
}
void Deletestudent(){
	string deleteRollNo;
    cout << "Enter roll number to delete: ";
    cin>>deleteRollNo;

    deleteByRollNumber(deleteRollNo, "Book2.csv");
}
main(){  
	char op;
	do{
		int choice;
		cout<<"-------------------------------------------"<<endl;
		cout<<"        VIVA INSTITUTE OF TECHNOLOGY       "<<endl;
	    cout<<"             STUDENT MANAGEMENT            "<<endl;
	    cout<<"-------------------------------------------"<<endl;
	    cout<<"1.Registered New Student"<<endl;
	    cout<<"2.Display Registered Student"<<endl;
	    cout<<"3.Search Student"<<endl;
	    cout<<"4.Update Student Details"<<endl;
	    cout<<"5.Delete Student Details"<<endl;
	    cout<<"6.Exit"<<endl;
	    cout<<"-------------------------------------------"<<endl;
	    cout<<"Enter your choice:";
	    cin>>choice;
	    switch(choice){
		   case 1:AddNewStudent();break;
		   case 2:displayAllRecords("Book2.csv") ;break;
		   case 3:SearchStudent();break;
		   case 4:UpdateStudent();break;
		   case 5:Deletestudent();break;
		   case 6:exit(1);
		     default:cout<<"Invalid choice"<<endl;
	    }
	  cout<<"\nDo You Want to Continue[Yes/No]?:";
	  cin>>op;
    }while(op=='y'||op=='Y');
}
