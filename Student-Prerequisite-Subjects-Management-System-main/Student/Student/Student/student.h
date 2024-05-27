#pragma once
#include<iostream>
#include"LinkedList.cpp"
#include"course.h"
using namespace std; 
class student
{
	static int posation;
public:
	string name ,acadmeic_year ;
	int id, password;
	//
	LinkedList<string> current_courses;
	//
	LinkedList<string> finished_courses;
	student();
	static void login(LinkedList<student>*);
	static void view_all_courses();
	static void edit_data();
	static void View_details_of_specific_course();
	static void view_his_courses();
	static void register_course();
};

