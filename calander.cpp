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
	int days{};
	for (int year{dec_31_1950+1};year<m_date[2];year++)
	{
		if (leap_year(year))
			days+=2;
		else
			days+=1;
	}
	for (int month{1};month<m_date[1];month++)
	{
		if (leap_year(m_date[2]))
			days+=l_months[month-1];
		else
			days+=n_months[month-1];
	}
	days+=1;
	return days%7;
}

//check if given date is real
bool Calander::check_date()
{
	if (m_date[2]<1951 || m_date[1]<1 || m_date[1]>12)
		return false;
	else if (m_date[1]==2 && leap_year(m_date[2]) && m_date[0]>29)
		return false;
	else if (m_date[1]==2 && !leap_year(m_date[2]) && m_date[0]>28)
		return false;
	else if ((m_date[1]==1 || m_date[1]==3 || m_date[1]==5 || m_date[1]==7 || m_date[1]==8 || m_date[1]==10 || m_date[2]==12) && m_date[0]>31)
		return false;
	else if (m_date[0]>30)
		return false;
	else
		return true;
}

//default constructor
Calander::Calander (int day=1,int month=1,int year=1):m_date{day,month,year},m_odd_days{odd_days()},m_valid{check_date()}
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
	std::cout<<"Su Mo Tu We Th Fr Sa\n";
	for(int blank{};blank<m_odd_days;blank++)
		std::cout<<"   ";
	for (int i{m_odd_days};i<7;i++)
	{
		if (date==m_date[0])
			std::cout<<"\033[32m";
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
	if (leap_year(m_date[2]))
		month_days=l_months[m_date[1]-1];
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
				std::cout<<"\033[32m";
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
