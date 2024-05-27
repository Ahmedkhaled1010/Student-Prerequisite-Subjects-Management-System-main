#include<iostream>
#include"Admin.h"
using namespace std;
int main()
{
	//store the data of students//
	LinkedList<student>*store_stud=new LinkedList<student>;
	//store the data of admins//
	LinkedList<Admin>store_Admin;
	//store the data of courses//
	LinkedList<course>* store_course = new LinkedList<course>;
	//store one admin in varaible{stor_admin}//
	Admin admin(store_stud, store_course);
	admin.name = "mohamed";
	admin.password = 10;
	store_Admin.Append(admin);


	int choose=0;
	cout << "\t\t\tWelcome To Student Prerequisite Subjects Management System\n";
	
	while (choose!=3)
	{
		cout << "\t\t------------------------------------------------------------------\n";
		cout << "press 1 To Login As Student\n";
			cout << "press 2 To Login As Admin\n";
			cout << "press 3 To Exit\n";
			cout << "Enter your Choose:";
			cin >> choose;
			switch (choose)
			{
			case 1: {
				student::login(store_stud);
				break;
			}
			case 2: {
				Admin::login(store_Admin);
				break;
			}

		    }
	}
	
}