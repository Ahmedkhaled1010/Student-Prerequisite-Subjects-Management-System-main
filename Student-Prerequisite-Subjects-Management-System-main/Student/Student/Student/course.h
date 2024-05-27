#pragma once
#include<iostream>
#include"ArrList.cpp"
using namespace std;
class course
{
public:
	string Name;
	int code;
	int max_stu;
	int hours;
	ArrList<string>* pre_required ;
	course();
	
};

