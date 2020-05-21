#include <iostream>
#include <windows.h>
main()
{

/**BACKSPACING IN CONSOLE          &    PUTTING  DELAY*/

    std::cout<<"Loading---";
int a=0;
    while(a<10)
    {
        Sleep(400);
        std::cout<<"\b"<<"\\";

        Sleep(400);
        std::cout<<"\b"<<"|";

        Sleep(400);
        std::cout<<"\b"<<"/";
        a++;
    }

}
