#include <iostream>
#include <thread>
#include <vector>
#include <windows.h>
bool doLoading=1;
bool printLog=0;

void loading(){
    std::cout<<"Loading---";

    while(doLoading)
    {
        Sleep(400);
        if(!doLoading)
            break;                      ///As might be possible after entering loop cond changed so
        std::cout<<"\b"<<"\\";

        Sleep(400);
        if(!doLoading)
            break;
        std::cout<<"\b"<<"|";

        Sleep(400);
        if(!doLoading)
            break;
        std::cout<<"\b"<<"/";
    }
}

void completed(){
    std::cout<<"\b\b\b\b\b\b\b\b\b\b";
    std::cout<<"--Loaded--\n"<<"Thanks for waiting\n";

}
void log(){
std::vector<std::string>logging;
std::string temp;

    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

    while(doLoading)
    {
        getline(std::cin, temp);
        logging.push_back(temp);
    }

    while(!printLog)
    {
    }
        for(int i=0;i<logging.size();i++)
        std::cout<<logging[i]<<"\n";

}
main()
{
    int timer;
    std::cout<<"How much should it wait(in seconds)\n";
    std::cin>>timer;
    std::thread t1(loading);
    std::thread t2(log);
    Sleep(timer*1000);
    doLoading=0;
    t1.join();
    completed();

    std::cout<<"Press Enter to display what you wrote during Loading\n";
    printLog=1;
    t2.join();
///will not work with gcc minGW as they dont support threads, use another compiler
}

