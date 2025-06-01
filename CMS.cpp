#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

class contact
{
private:
	char fName[50], lName[50], address[50], email[50];
	string phNo;
	bool exitFlag=false;
	

public:
	bool isValidPhoneNumber(const string &phoneNumber)
	{
		// if (phoneNumber.length() != 10)
		// {
		// 	return false;
		// }
		for (char c : phoneNumber)
		{
			if (!isdigit(c))
			{
				return false;
			}
		}
		return true;
	}

	void createContact()
	{
		takephno();
		if(exitFlag== true)
		{
			getExitFlag();
		}
		else
		{
		cout << "Enter your first name: ";
		cin >> fName;
		cout << "Enter your last name: ";
		cin >> lName;
		// cout << "Enter Your Phone Number: ";
		// cin >> phNo;
		// if (isValidPhoneNumber(phNo))
		// {
		// 	cout << "Valid phone number entered: " << phNo << endl;
		// }
		// else
		// {
		// 	cout << "Invalid input. Please enter a 10-digit phone number without any alphabets." << endl;
		// 	 exitFlag = true;
		// }
		cout << "Enter Your Address: ";
		cin >> address;
		cout << "Enter Your Email: ";
		cin >> email;
		}
	}

	void takephno() {
        string phoneNumber;
        cout << "Enter a 10-digit phone number: ";
        cin >> phoneNumber;

        if (isValidPhoneNumber(phoneNumber)) {
            cout << "Valid phone number entered: " << phoneNumber << endl;
        } else {
            cout << "Invalid input. Please enter a 10-digit phone number without any alphabets." << endl;
            exitFlag = true; // Set the flag to indicate invalid input
        }
    }
	
	bool getExitFlag() {
        return exitFlag;
    }


	void showContact()
	{
		cout << "Name: " << fName << " " << lName << endl;
		cout << "Phone: " << phNo << endl;
		cout << "Address: " << address << endl;
		cout << "Email: " << email << endl;
	}

	int writeOnFile()
	{
		char ch;
		ofstream f1;
		f1.open("CMS.dat", ios::binary | ios::app);

		do
		{
			createContact();
			if(exitFlag==true)
			return 1;
			f1.write(reinterpret_cast<char *>(this), sizeof(*this));
			cout << "Do you have next data?(y/n)";
			cin >> ch;
		} while (ch == 'y');

		cout << "Contact has been Sucessfully Created...";
		f1.close();
	}

	void readFromFile()
	{
		ifstream f2;
		f2.open("CMS.dat", ios::binary);

		cout << "\n================================\n";
		cout << "        LIST OF CONTACTS";
		cout << "\n================================\n";

		while (!f2.eof())
		{
			if (f2.read(reinterpret_cast<char *>(this), sizeof(*this)))
			{
				showContact();
				cout << "\n================================\n";
			}
		}
		f2.close();
	}

	void searchOnFile()
	{
		ifstream f3;
		string phone;
		cout << "Enter phone no.: ";
		cin >> phone;
		f3.open("CMS.dat", ios::binary);

		while (!f3.eof())
		{
			if (f3.read(reinterpret_cast<char *>(this), sizeof(*this)))
			{
				if (phone == phNo)
				{
					showContact();
					return;
				}
			}
		}
		cout << "\n\n No record not found";
		f3.close();
	}

	void deleteFromFile()
	{
		string num;
		int flag = 0;
		ofstream f4;
		ifstream f5;

		f5.open("CMS.dat", ios::binary);
		f4.open("temp.dat", ios::binary);

		cout << "Enter phone no. to delete: ";
		cin >> num;

		while (!f5.eof())
		{
			if (f5.read(reinterpret_cast<char *>(this), sizeof(*this)))
			{
				if (phNo != num)
				{
					f4.write(reinterpret_cast<char *>(this), sizeof(*this));
				}
				else
					flag = 1;
			}
		}
		f5.close();
		f4.close();
		remove("CMS.dat");
		rename("temp.dat", "CMS.dat");

		flag == 1 ? cout << endl
						 << endl
						 << "\tContact Deleted..."
				  : cout << endl
						 << endl
						 << "\tContact Not Found...";
	}

	void editContact()
	{
		string num;
		fstream f6;

		cout << "Edit contact";
		cout << "\n===============================\n\n";
		cout << "Enter the phone number to be edit: ";
		cin >> num;

		f6.open("CMS.dat", ios::binary | ios::out | ios::in);

		while (!f6.eof())
		{
			if (f6.read(reinterpret_cast<char *>(this), sizeof(*this)))
			{
				if (phNo == num)
				{
					cout << "Enter new record\n";
					createContact();
					int pos = -1 * sizeof(*this);
					f6.seekp(pos, ios::cur);
					f6.write(reinterpret_cast<char *>(this), sizeof(*this));
					cout << endl
						 << endl
						 << "\t Contact Successfully Updated...";
					return;
				}
			}
		}
		cout << "\n\n No record not found";
		f6.close();
	}
};

int main()
{
	system("cls");
	system("Color 8F"); // "Color XY", X - backgroung color, Y - text color

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t * WELCOME TO CONTACT MANAGEMENT SYSTEM *";
	getch();

	while (1)
	{
		contact c1;
		int choice;

		system("cls");
		system("Color 03");

		cout << "\n\n\t\t\t\t\t\t\t\tCONTACT MANAGEMENT SYSTEM";
		cout << "\n\n\t\t\t\t\t\t\t\t      [MAIN MENU]";
		cout << "\n\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "\t\t\t\t\t\t\t\t[1]-> Add a new Contact\n";
		cout << "\t\t\t\t\t\t\t\t[2]-> List all Contacts\n";
		cout << "\t\t\t\t\t\t\t\t[3]-> Search for contact\n";
		cout << "\t\t\t\t\t\t\t\t[4]-> Delete a Contact\n";
		cout << "\t\t\t\t\t\t\t\t[5]-> Edit a Contact\n";
		cout << "\t\t\t\t\t\t\t\t[0]-> Exit";
		cout << "\n\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			c1.writeOnFile();
			if(c1.getExitFlag())
			{
				cout<<"Invalid input. Please enter a 10-digit phone number without any alphabets";
				break;	
			}

		case 2:
			system("cls");
			c1.readFromFile();
			break;

		case 3:
			system("cls");
			c1.searchOnFile();
			break;

		case 4:
			system("cls");
			c1.deleteFromFile();
			break;

		case 5:
			system("cls");
			c1.editContact();
			break;

		case 0:
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n||||||||||||| Thank you for using CMS :) |||||||||||||" << endl
				 << endl;
			exit(0);
			break;

		default:
			continue;
		}

		int opt;
		cout << "\n\n...:::Enter the Choice:::...\n[1] Main Menu\t\t[0] Exit\n";
		cin >> opt;

		switch (opt)
		{
		case 0:
			system("cls");
			cout << "\n\n\n||||||||||||| Thank you for using CMS :) |||||||||||||" << endl
				 << endl;
			exit(0);
			break;

		default:
			continue;
		}
	}

	return 0;
}
