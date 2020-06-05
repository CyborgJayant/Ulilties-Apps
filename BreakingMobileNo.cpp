#include <iostream>
#include <regex>

main()
{
    /**
    9878177227
    91 9878177227
    987-817-7227
    (987)(817)(7227)
    (91)(987)(817)(7227)
    +919878177227
    +(91) (987)-(817) (7227)
    */
   std::regex mobileNoValidator("[\\.+(]*(\\d{0,3})[ ()-]*(\\d{3})[ ()-]*(\\d{3})[ ()-]*(\\d{4})[ )]*");


    std::string number;
    std::cout<<"Examples :\t9878177227\n91 9878177227\n987-817-7227\n(987)(817)(7227)\n(91)(987)(817)(7227)\n+919878177227\n+(91) (987)-(817) (7227)\n\n";
    std::cout<<"Enter Mobile Number\n";
    std::getline(std::cin,number);

    std::smatch groups;
    std::regex_search(number,groups,mobileNoValidator);

    std::cout<<"Your Mobile Number is: "<<groups.str(1)<<groups.str(2)<<groups.str(3)<<groups.str(4)<<"\n";
    std::cout<<"Country Code is: "<<groups.str(1)<<"\n";
    std::cout<<"State Code is: "<<groups.str(2)<<"\n";
    std::cout<<"Area Code is: "<<groups.str(3)<<"\n";
    std::cout<<"Subscriber Code is: "<<groups.str(4)<<"\n";


}
