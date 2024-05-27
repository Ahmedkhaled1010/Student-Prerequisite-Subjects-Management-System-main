#pragma once
#include<iostream>
#include"student.h"
using namespace std;
class Admin
{
	
public:

	static LinkedList<student> *store_stud;
	static LinkedList<course>* store_course;
	string name;
	int password;
	Admin(LinkedList<student>*, LinkedList<course>*);
	Admin();
	static void login(LinkedList<Admin>);
	static void add_stud();
	static void add_course();
	static void view_students();
	static void view_courses();
	static void edit_courses_data();
	

	static void add_course_prerequisite();

};

