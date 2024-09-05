#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;
bool isDuplicate(const std::string& rollNo, const std::string& filename) {
    std::ifstream csvFile("Book2.csv");
    std::string line;
    while (std::getline(csvFile, line)) {
        std::stringstream ss(line); 
        std::string firstColumn;
        if (std::getline(ss, firstColumn, ',')) {
            if (firstColumn == rollNo) {
                csvFile.close();
                return true;
            }
        }
    }
    csvFile.close();
    return false;
}
bool searchByRollNumber(const std::string& rollNo, const std::string& filename) {
    std::ifstream csvFile("Book2.csv");
    std::string line;
    while (std::getline(csvFile, line)) {
        std::stringstream ss(line); 
        std::string firstColumn;
        if (std::getline(ss, firstColumn, ',')) {
            if (firstColumn == rollNo) {
                std::cout << "Record found\n" << line << '\n';
                csvFile.close();
                return true;
            }
        }
    }

    std::cout << "Record not found for roll number: " << rollNo << '\n';
    csvFile.close();
    return false;
}
bool updateByRollNumber(const std::string& rollNo, const std::string& filename) {
    std::ifstream inputFile("Book2.csv");
    std::ofstream outputFile("temp.csv", std::ios::trunc);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files.\n";
        return false;
    }

    std::string line;
    bool found = false;

    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string firstColumn;
        if (std::getline(ss, firstColumn, ',')) {
            if (firstColumn == rollNo) {
                std::string newName, newRollNo, newAge,newMarks,newEmail,newContact;
                std::cout << "Enter new roll number: ";
                std::cin>>newRollNo;
                std::cout << "Enter new name: ";
                std::cin>>newName;
                std::cout << "Enter new age: ";
                std::cin>>newAge;
                std::cout << "Enter new Marks: ";
                std::cin>>newMarks;
                std::cout << "Enter new Email: ";
                std::cin>>newEmail;
                std::cout << "Enter new Contact: ";
                std::cin>>newContact;

                outputFile << newRollNo << "," << newName << "," << newAge <<","<<newMarks<<","<<newEmail<<","<<newContact<<'\n';
                found = true;
            } else {
                outputFile << line << '\n';
            }
        }
    }

    inputFile.close();
    outputFile.close();
    std::remove(filename.c_str());
    std::rename("temp.csv", filename.c_str());

    if (found) {
        std::cout << "Record with roll number " << rollNo << " updated.\n";
    } else {
        std::cout << "Record not found for roll number: " << rollNo << '\n';
    }

    return found;
}
bool deleteByRollNumber(const std::string& rollNo, const std::string& filename) {
    std::ifstream inputFile("Book2.csv");
    std::ofstream outputFile("temp.csv", std::ios::trunc);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files.\n";
        return false;
    }

    std::string line;
    bool found = false;

    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string firstColumn;
        if (std::getline(ss, firstColumn, ',')) {
            if (firstColumn != rollNo) {
                outputFile << line << '\n';
            } else {
                found = true;
            }
        }
    }

    inputFile.close();
    outputFile.close();
    std::remove(filename.c_str());
    std::rename("temp.csv", filename.c_str());

    if (found) {
        std::cout << "Record with roll number " << rollNo << " deleted.\n";
    } else {
        std::cout << "Record not found for roll number: " << rollNo << '\n';
    }

    return found;
}
void AddNewStudent(){
	std::string rollNo,name,email,contact;
	   double age,marks;
	
	 std::ofstream csvFile("Book2.csv",std::ios::app);
	    std::cout<<"Enter Roll No.:";
	    std::cin>>rollNo;
	    if (isDuplicate(rollNo, "Book2.csv")) {
        std::cout << "Roll number is already exists\n";
          return;
        }
	    std::cout<<"Enter Name:";
	    std::cin>>name;
	    std::cout<<"Enter Age:";
	    std::cin>>age;
	    std::cout<<"Enter Marks Out of 500:";
	    std::cin>>marks;
	    std::cout<<"Enter Email Id:";
	    std::cin>>email;
	    std::cout<<"Enter Contact Number:";
	    std::cin>>contact;
	    csvFile<<rollNo<<","<<name<<","<<age<<","<<marks<<","<<email<<","<<contact<<"\n";
		csvFile.close();
		std::cout<<"Student Details Added Successfully..."<<endl;
		return;
	} 

void displayAllRecords(const std::string& filename) {
	std::string rollNo,name,email,contact;
	   double age,marks;
    std::ifstream csvFile("Book2.csv");
    std::string line;
    while (std::getline(csvFile, line)) {
        std::cout << line << '\n';
    }

    csvFile.close();
}
void SearchStudent(){
	std::string rollNo;
    std::cout << "Enter roll number to search: ";
    std::cin>>rollNo;

    searchByRollNumber(rollNo, "Book2.csv");
	   	return;
}
void UpdateStudent(){
	std::string updateRollNo;
    std::cout << "Enter roll number to update: ";
    std::cin>>updateRollNo;

    updateByRollNumber(updateRollNo, "Book2.csv");
}
void Deletestudent(){
	std::string deleteRollNo;
    std::cout << "Enter roll number to delete: ";
    std::cin>>deleteRollNo;

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
