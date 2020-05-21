#include<iostream>
#include<regex>

main()
{
    std::string newOne,str,strF,strR;
/**FIND AND REPLACE*/
    std::cout<<"Enter String\n";
    getline(std::cin,str);

    std::cout<<"Find And Replace >\nFind : ";
    getline(std::cin,strF);

    std::cout<<"Replace with : ";
    getline(std::cin,strR);

std::regex exp1(strF,std::regex_constants::icase);
    newOne=std::regex_replace(str,exp1,strR);

    std::cout<<"Final Word : "<<newOne<<"\n";


}
