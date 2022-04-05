#include <iostream>
#include "calander.h"

int main()
{
	std::cout<<"Enter date:";
	Calander date{};
	std::cin>>date;
	if (date.valid())
	{
		std::cout<<'\n';
		date.print();
		std::cout<<'\n';
	}
	else
		std::cerr<<"\033[31m"<<"Given date is not valid\n"<<"\033[0m";
	return 0;
}
