#include "Admin.h"
#include <string>
//access static variable//
LinkedList<student>* Admin::store_stud=NULL ;
LinkedList<course>* Admin::store_course = NULL;
//constractor using to make varaibles that declaration as pointer access on thrw variable that use to store data by address//
Admin::Admin(LinkedList<student>* store_st, LinkedList<course>* store_cou)
{
	store_course = store_cou;
	store_stud = store_st;
	name = "";
	password = -1;
}
Admin::Admin()
{
	name = "";
	password = -1;
}
void Admin::login(LinkedList<Admin> store)
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
		for (int i = 0; i < store.Length(); i++)
		{
			if (pas == store.At(i)->password && na == store.At(i)->name)
			{
				check = true;
				cout << "Admin name:" << store.At(i)->name << endl;
				cout << "________________________________________\n";
				break;
			}
		}
		if (check == true)
		{

			while (chooce != 7) {
				//done
				cout << "press 1 to add new student\n";
				//done
				cout << "press 2 to add new course\n";
				//in progress
				cout << "press 3 to Enter course prerequisite\n";

				cout << "press 4 to View List of all students in a specific course\n";
				//
				cout << "press 5 to View List of all courses (Finished - Progressed) of a specific student\n";
				//
				cout << "press 6 to Edit all course data\n";
				//
				cout << "press 7 to back\n";

				cout << "enter your choose:";
				cin >> chooce;
				switch (chooce)
				{
				case 1: { add_stud();  break; }
				case 2: {add_course(); break; }
				case 3: {add_course_prerequisite(); break; }
				case 4: {view_students(); break; }
				case 5: {view_courses(); break; }
				case 6: {
					edit_courses_data();
					break; }
				}
			}
		}
		else
			cout << "incorrect pasword or name__try again\n";
	}
}
void Admin::add_stud()
{
	student stud;
	string finished_cou;
	cout << "___________________________________________________\n";
	cout << "enter student name:";
	cin >> stud.name;
	cout << "enter student id:";
	cin >> stud.id;
	cout << "enter student academic year:";
	cin >> stud.acadmeic_year;
	cout << "enter student password:";
	cin >> stud.password;
	cout << "enter finished courses from student:";
	while (finished_cou != "f")
	{
		cout << "enter course that finished and if you finsh press 'f'" << endl;
		cin >> finished_cou;
		if(finished_cou !="f")
		 stud.finished_courses.Append(finished_cou);
	}
	store_stud->Append(stud);
	cout << "__________________________________________________________\n";
}
void Admin::add_course()
{
	course cour;
	cour.pre_required = new ArrList<string>;
	cout << "___________________________________________________\n";
	cout << "enter course name:";
	cin >> cour.Name;
	cout << "enter course code:";
	cin >> cour.code;
	cout << "enter course hours:";
	cin >>cour.hours;
	cout << "enter maximium of student at course:";
	cin >> cour.max_stu;
	store_course->Append(cour);
	cout << "__________________________________________________________\n";

}

// first 
void Admin::add_course_prerequisite() {
	string name;
	int code;
	bool check = false;
	string preprerequisite;
	cout << "___________________________________________________\n";
	cout << "enter course name:";
	cin >> name;
	cout << "enter course code:";
	cin >> code;
	cout << "__________________________________________________________\n";
	if (store_course->Length() == 0)
		cout << "No course \n";
	else {
		for (int i = 0; i < store_course->Length(); i++) {

			if (store_course->At(i)->Name == name && store_course->At(i)->code == code) {
				check = true;
				while (preprerequisite != "f")
				{
					cout << "enter course prerequisites and if you finsh press 'f'" << endl;
					cin >> preprerequisite;
					if(preprerequisite !="f")
					store_course->At(i)->pre_required->Append(preprerequisite);
				}
				break;

			}

		}
		if (check == false)
			cout << "incorect information \n";
	}
	cout << "__________________________________________________________\n";

}

void Admin::view_students() {


	string name;
	cout << "__________________________________________________\n";
	bool check = false;
	cout << "enter course name:";
	cin >> name;

	for (int i = 0; i < store_stud->Length(); i++) {
		for (int j = 0; j < (store_stud->At(i)->current_courses.Length()); j++) {
			if (*(store_stud->At(i)->current_courses.At(j)) == name) {
				check = true;
				cout << store_stud->At(i)->name;

			}
		}

	}
	if (!check) {
		cout << "there is no student in that cours" << endl;
	}
	cout << "_______________________________________________________\n";
}



void Admin::view_courses() {

	int id;
	cout << "___________________________________________________\n";
	cout << "enter student id:";
	cin >> id;
	bool check = false,check2=false;
	for (int i = 0; i < store_stud->Length(); i++) {
		if (store_stud->At(i)->id == id) {
			check2 = true;
			cout << "current courses :" << endl;
			for (int j = 0; j < store_stud->At(i)->current_courses.Length(); j++) {
				check = true;
				cout << j << ':' << *(store_stud->At(i)->current_courses.At(j)) << endl;
			}

			cout << "finshed courses :" << endl;
			for (int j = 0; j < store_stud->At(i)->finished_courses.Length(); j++) {
				check = true;
				cout << j + 1 << ':' << *(store_stud->At(i)->finished_courses.At(j)) << endl;
			}

			if (!check) {
				cout << "this student has no cours" << endl;
			}
		}
		else {
			cout << "incorrect data" << endl;
		}



	}
	if (!check2)
		cout << "that id does not exist\n";
	cout << "_________________________________________________\n";
}


void Admin::edit_courses_data() {
	int code, choice = 0;
	cout << "_________________\n";

	cout << "enter course code:";
	cin >> code;


	for (int i = 0; i < store_course->Length(); i++) {
		if (store_course->At(i)->code == code) {
			while (choice != 6) {
				cout << "press 1 to edit code: \npress 2 to edit name:\npress 3 to cours hour:\npress 4 to edit max_No_of student:\npress 5 to edit preprerequisite:\npress 6 to exit:\n";

				cin >> choice;


				switch (choice)
				{
				case 1: {
					int newcode;
					cout << "enter new code" << endl;
					cin >> newcode;
					store_course->At(i)->code = newcode;
					break;
				}
				case 2: {
					string newname;
					cout << "enter new name" << endl;
					cin >> newname;
					store_course->At(i)->Name = newname;
					break;
				}
				case 3: {
					int newhours;
					cout << "enter new hours" << endl;
					cin >> newhours;
					store_course->At(i)->hours = newhours;

					break;
				}
				case 4: {
					int max_No_of_student;
					cout << "enter new max_No_of_student" << endl;
					cin >> max_No_of_student;
					store_course->At(i)->max_stu = max_No_of_student;
					break;
				}

				case 5: {
					int choose2 = 0, choose3 = 0;
					string preprerequisite;

					while (choose2 != 3) {
						cout << "press 1 to add preprerequisite \n";
						cout << "press 2 to delet preprerequisite\n";
						cout << "press 3 to back\n";
						cin >> choose2;
						switch (choose2)
						{
						case 1:
							while (preprerequisite != "f")
							{
								cout << "enter the new course's prerequisite and if you finsh press 'f'" << endl;
								cin >> preprerequisite;
								if (preprerequisite != "f")
									store_course->At(i)->pre_required->Append(preprerequisite);
							}
							break;
						case 2:
							if (store_course->At(i)->pre_required->Length() == 0) {
								cout << "this cours has no prerequisites \n";
							}
							cout << "here cours prerequisites\n";
							for (int k = 0; k < store_course->At(i)->pre_required->Length(); k++) {
								cout << k + 1 << ':' << store_course->At(i)->pre_required->At(k) << endl;
							}
							cout << "enter the numer of the prerequisite you want to delet it \n";
							cin >> choose3;
							if (choose3 <= (store_course->At(i)->pre_required->Length()) && choose3 > 0) {
								store_course->At(i)->pre_required->deleteAt(choose3 - 1);
							}
							break;
						default:
							break;
						}

					}
					break;
				}
				}

			}
		}
		else
		{
			cout << "incorrect code" << endl;
		}
	}
}