//TP 2018/2019: ZSR 3, Zadatak 22
#include <iostream>
#include <string>
#include <algorithm>

int main ()
{
    std::string s = "     mirza diiinko mirza    ";
    std::cout<<s<<std::endl;
    std::copy_if(s.begin(),s.end(),s.begin(),[](char c){if(c != ' ') return true; return false;});
    std::cout<<s;
	return 0;
}