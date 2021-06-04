#include <iostream>
#include"Mainclass.hpp"
#include<string>
using namespace std;
int main(){
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);
    Backend::Main OP;
//    其中第一个参数为输入流，第二个参数为输出流
    OP.Run(std::cin,std::cout);
    return 0;
//    Query_Ticket();
}
