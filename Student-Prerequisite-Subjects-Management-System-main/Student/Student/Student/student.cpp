#include "student.h"
 #include "Admin.h"
int student::posation = -1;
student::student()
{
	name = "";
	id = password=-1;
}
 void student::login(LinkedList<student>* store)
{
	bool check = false;
	int chooce = 0;
	while (check == false)
	{
		cout << "____________________________________________________\n";
		int pas;
		string na;
		cout << "enter name:";
		cin >> na;
		cout << "enter pasword:";
		cin >> pas;
		cout << "__________________________________________________\n";
		for (int i = 0; i < store->Length(); i++)
		{
			if (pas == store->At(i)->password && na == store->At(i)->name)
			{
				posation = i;
				check = true;
				cout << "student name:" << store->At(i)->name << endl;
				cout << "student id:" << store->At(i)->id << endl;
				cout << "________________________________________\n";
				break;
			}
		}
		if (check == true)
		{

			while (chooce != 6) {
				cout << "press 1 to view list of all available course\n";
				cout << "press 2 to view details of a special course\n";
				cout << "press 3 to register for a course\n";
				cout << "press 4 to view all your course\n";
				cout << "press 5 to edit your data\n";
				cout << "press 6 to back\n";
				cout << "enter your choose:";
				cin >> chooce;
				switch (chooce)
				{
				case 1: { view_all_courses(); break; }
				case 2: {View_details_of_specific_course();  break; }
				case 3: {register_course();
					break; }
				case 4: {view_his_courses();
					break; }
				case 5: {edit_data();  break; }
				}
			}
		}
		else
			cout << "incorrect pasword or name__try again\n";
	}
}
 void student::view_all_courses()
 {
	 cout << "___________________________________________________\n";
	 if (Admin::store_course->Length() == 0)
		 cout << " No available course \n";
	 else {
		 cout << "All available courses : \n";
		 for (int i = 0; i < Admin::store_course->Length(); i++) {
			 cout <<i+1<< "-Name of course:" << Admin::store_course->At(i)->Name << '\n';
		 }
	 }
		 cout << "___________________________________________________\n";

 }
 void student::edit_data()
 {
	 cout << "________________________________________________________\n";
	 int chooce=0;
	 while (chooce!=4)
	 {
		 cout << "press 1 to change your Name\n";
		 cout << "press 2 to change your password\n";
		 cout << "press 3 to change your Academic year\n";
		 cout << "press 4 to back\n";
		 cout << "enter your chooce:";
		 cin >> chooce;
		 cout << "_______________________________________\n";
		 switch (chooce)
		 {
		 case 1: {cout << "enter Name:";
			 cin >> Admin::store_stud->At(posation)->name;
			 cout << "_____________________________________________\n";
			 break; };
		 case 2: {
			 cout << "enter pasword:";
			 cin >> Admin::store_stud->At(posation)->password;
			 cout << "_____________________________________________\n";
			 break; };
		 case 3: {
			 cout << "enter Acadmeic year:";
			 cin >> Admin::store_stud->At(posation)->acadmeic_year; 
			 cout << "_____________________________________________\n"; break; };
		 }
	 }
	 cout << "________________________________________________\n";
 }
 void student::View_details_of_specific_course()
 {
	 cout << "_______________________________________________\n";

	 if (Admin::store_course->Length() == 0)
		 cout << " No course ";
	 else
	 {
		 int chooce;
		 view_all_courses();
		 cout << "enter th nummber of course:";
		 cin >> chooce;
		 cout << "________________________________________________\n";
		 cout << "the details of course:\n";
		 cout << "Name:" << Admin::store_course->At(chooce - 1)->Name << endl;
		 cout << "Code:" << Admin::store_course->At(chooce - 1)->code << endl;
		 cout << "Hourse:" << Admin::store_course->At(chooce - 1)->hours << endl;
		 cout << "Maximum number of student:" << Admin::store_course->At(chooce - 1)->max_stu << endl;
		 cout << " list of pre-required courses: ";
		 if (Admin::store_course->At(chooce - 1)->pre_required->Length() == 0)
			 cout << "No pre_required";
		 else
		 {
			 for (int i = 0; i < Admin::store_course->At(chooce - 1)->pre_required->Length(); i++)
				 cout << Admin::store_course->At(chooce - 1)->pre_required->At(i) << "\t";
		 }
			
	 }
	 cout << "\n______________________________________________________\n";
 }
 void student::view_his_courses()
 {
	 cout << "_________________________________________\n";
	 cout << "the finished course is :\n";
	 if (Admin::store_stud->At(posation)->finished_courses.Length() != 0)
	 {
		 for (int i = 0; i < Admin::store_stud->At(posation)->finished_courses.Length(); i++)
		 {
			 cout << i + 1 << "-Name:" << *(Admin::store_stud->At(posation)->finished_courses.At(i)) << endl;
		 }
	 }
	 else
		 cout << "NO coursess\n";
	 cout << "______________________________________________________________\n";
	 cout << "the Courses in progress:\n";
	 if (Admin::store_stud->At(posation)->current_courses.Length() != 0)
	 {
		 for (int i = 0; i < Admin::store_stud->At(posation)->current_courses.Length(); i++)
			 cout << i + 1 << "-Name:" <<*( Admin::store_stud->At(posation)->current_courses.At(i)) << endl;
	 }
	 else
		 cout << "No courses\n";
	 cout << "__________________________________________________________\n";
 }
 void student::register_course()
 {
	 cout << "_____________________________________________\n";

	 if (Admin::store_course->Length() == 0)
		 cout << " No course \n";
	 else
	 {
		 int chooce;
		 bool check = false, regis = true;
		 course* cour;
		 view_all_courses();
		 cout << "enter the number of course:";
		 cin >> chooce;
		 cour = Admin::store_course->At(chooce - 1);
		 for (int i = 0; i < Admin::store_stud->At(posation)->finished_courses.Length(); i++)
		 {
			 if (*(Admin::store_stud->At(posation)->finished_courses.At(i)) == cour->Name)
			 {
				 cout << "you finished this course \n";
				 check = true;
				 regis = false;
				 break;
			 }
		 }
		 for (int i = 0; i < Admin::store_stud->At(posation)->current_courses.Length(); i++)
		 {
			 if (*(Admin::store_stud->At(posation)->current_courses.At(i)) == cour->Name)
			 {
				 cout << "you progress this course \n";
				 check = true;
				 regis = false;
				 break;
			 }
		 }
		 if (check == false)
		 {
			 for (int i = 0; i < cour->pre_required->Length(); i++)
			 {
				 if (regis == true)
				 {
					 if (Admin::store_stud->At(posation)->finished_courses.Length() == 0)
					 {
						 regis = false;
						 break;
					 }
					 else
					 {
						 for (int j = 0; j < Admin::store_stud->At(posation)->finished_courses.Length(); j++)
						 {
							 if (cour->pre_required->At(i) == *(Admin::store_stud->At(posation)->finished_courses.At(j)))
							 {
								 regis = true;
								 break;
							 }
							 else
								 regis = false;
						 }
					 }
				 }
				 else
					 break;
			 }
		 }
		 if (regis == true)
			 Admin::store_stud->At(posation)->current_courses.Append(cour->Name);
	 }
	 cout << "_______________________________________________________________________\n";
 }
