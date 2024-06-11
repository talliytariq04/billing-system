#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<conio.h>	

using namespace std;
struct Login {
	string username; string password;
};

float newreciept();//Function prototype
float seereciept();//Function prototype
void deleterecord();//Function prototype
float priceofitem(int a, float b);//Function prototype
int menu();//Function prototype
void login();//Function prototype

void main()
{
	login();//Login function call
}

void login()
{
	Login y;
	Login username;
	Login password;
	char x;
	cout << "Enter Username and Password to continue\n";//Asks user to input username
	cout << "Username: ";
	cin >> y.username;//User enters username
	cout << "Enter Password : ";//Asks user to input password
	cin >> y.password;//Use enters password
	if (y.username == "project" && y.password == "cp123")
	{
		system("cls");
		menu();//Menu fuction is called
	}
	else
	{
		cout << "\nInvalid information provided!\n";
		cout << "Do you want to try again? \nPress Y for yes and N for no : ";//Asks user if he/she wants to continue
		cin >> x;//User enters option
		if (x == 'y' || x == 'Y')
		{
			system("cls");
		}
		else
		{
			exit(0);
		}
	}
	_getch();
}

int menu()
{
	char ch;
	do
	{
		cout << "Super Mart Billing" << endl << endl;
		cout << "Press Following options to proceed \nPress 1 to start new reciept \nPress 2 to see existing reciept \nPress 3 to delete a record \nPress 4 to return to login menu \nPress 5 to exit" << endl;//Ask users to enter option for to perform following tasks
		int option;
		cout << "Option : ";
		cin >> option;//User enters required option
		switch (option)
		{
		case(1):
			system("cls");
			newreciept();//New reciept function is called
			break;
		case(2):
			system("cls");
			seereciept();//See reciept function is called
			break;
		case(3):
			system("cls");
			deleterecord();//Delete record function is called
			break;
		case(4):
			system("cls");
			main();//Menu function is called
			break;
		case(5):
			exit(0);
			break;
		default:
			system("cls");
			cout << "Wrong Selection" << endl;
		}
		cout << endl << "Do you want to perform another task? \nPress Y for yes and N for no : ";//Ask user if he/she wants to continue with other tasks
		cin >> ch;//User enters his/her choice
		system("cls");
	} while (ch != 'n' || ch != 'N');
	return 0;
}


float newreciept()
{
	fstream file;
	char x = 'y';
	file.open("Reciept.txt", ios::out);
	string item_name;
	int quantity;
	float price, iprice, total_price = 0;
	while (x != 'n')
	{
		cout << "Enter Item name : ";
		cin >> item_name;
		file << "Item : " << item_name;
		cout << endl;
		cout << "Quantity : ";
		cin >> quantity;
		file << "         " << "Quantity : " << quantity;
		cout << endl;
		cout << "Enter price per UNIT/Kg : ";
		cin >> price;
		file << "         " << "Price : " << price;
		iprice = priceofitem(quantity, price);
		total_price = total_price + iprice;
		cout << "\nNext Item Y for yes and N for no : ";
		cin >> x;
		file << "\n";
		if (x == 'n')
			file << "                                            " << "Total Price : " << total_price;
		else
			continue;
	}
	file.close();
	return 0;
}

float seereciept()
{
	fstream file1;
	string line;
	file1.open("Reciept.txt", ios::in);
	if (file1.is_open())
	{
		while (getline(file1, line))
		{
			cout << line << '\n';
		}
		file1.close();
	}
	else
		cout << "Unable to open file" << endl;
	return 0;
}

void deleterecord()
{
	ofstream file2;
	string s = " ";
	file2.open("Reciept.txt");
	file2 << s;
	cout << "Record Has Been Deleted " << endl;
	file2.close();
}

float priceofitem(int a, float b)
{
	float result;
	result = a * b;
	return result;
}