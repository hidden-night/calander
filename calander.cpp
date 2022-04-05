#include <iostream>
#include "calander.h"

//return true if leap year
bool Calander::leap_year(const int& year) const
{
	if (year%400==0)
		return true;
	else if (year%100==0)
		return false;
	else if (year%4==0)
		return true;
	else
		return false;
}

//calculate odd days
int Calander::odd_days()
{
	int years{m_date[2]%400-1};
	int odd_days{(years/4-years/100)*2+(years-(years/4-years/100))};
	for (int months{1};months<m_date[1];months++)
	{
		odd_days+=n_months[months-1];
		if (months==2 && leap_year(m_date[2]))
			odd_days+=1;
	}
	odd_days+=1;
	return odd_days%7;
}

//check if given date is real
bool Calander::check_date()
{
	if (m_date[2]<1 || m_date[1]<1 || m_date[1]>12 || m_date[0]<1)
		return false;
	else if ((m_date[1]==2 && leap_year(m_date[2]) && m_date[0]>29) || (m_date[1]==2 && !leap_year(m_date[2]) && m_date[0]>28))
		return false;
	else if ((m_date[1]==4 || m_date[1]==6 || m_date[1]==9 || m_date[1]==11) && m_date[0]>30)
		return false;
	else if (m_date[0]>31)
		return false;
	else
		return true;
}

//constructor
Calander::Calander ()=default;

Calander::Calander (int day,int month,int year):m_date{day,month,year},m_odd_days{odd_days()},m_valid{check_date()}
{
}

//return true if date is real
bool Calander::valid() const
{
	return m_valid;
}

//print calander
void Calander::print() const
{
	int date{1};
	std::cout<<"\033[1;4m"<<"Su Mo Tu We Th Fr Sa"<<"\033[0m"<<'\n';
	for(int blank{};blank<m_odd_days;blank++)
		std::cout<<"   ";
	for (int i{m_odd_days};i<7;i++)
	{
		if (date==m_date[0])
			std::cout<<"\033[1;32m";
		if (i!=m_odd_days)
			std::cout<<"  "<<date;
		else
			std::cout<<" "<<date;
		if (date==m_date[0])
			std::cout<<"\033[0m";
		date++;
	}
	std::cout<<'\n';
	int month_days{};
	if (leap_year(m_date[2]) && m_date[1]==2)
		month_days=29;
	else
		month_days=n_months[m_date[1]-1];
	while (date<month_days+1)
	{
		int week{};
		while (date<month_days+1 && week<7)
		{
			if (week>0)
				std::cout<<" ";
			if (date==m_date[0])
				std::cout<<"\033[1;32m";
			if (date<10)
				std::cout<<" "<<date;
			else
				std::cout<<date;
			if (date==m_date[0])
				std::cout<<"\033[0m";
			date++;
			week++;
		}
		std::cout<<'\n';
	}
}

//overloaded input operator
std::istream& operator>>(std::istream& in,Calander& calander)
{
	char temp{};
	in>>calander.m_date[0]>>temp>>calander.m_date[1]>>temp>>calander.m_date[2];
	calander.m_odd_days=calander.odd_days();
	calander.m_valid=calander.check_date();
	return in;
}
