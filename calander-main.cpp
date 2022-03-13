#include <iostream>
#include "calander.h"

int main()
{
	std::cout<<"Enter date:";
	int date_temp[3]{};
	char temp{};
	std::cin>>date_temp[0]>>temp>>date_temp[1]>>temp>>date_temp[2];
	const Calander date{date_temp[0],date_temp[1],date_temp[2]};
	if (date.valid())
	{
		std::cout<<'\n';
		date.print();
	}
	else
		std::cerr<<"\033[31m"<<"Given date is not valid\n"<<"\033[0m";
	return 0;
}
