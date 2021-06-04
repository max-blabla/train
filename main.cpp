#include <iostream>
#include"Mainclass.hpp"
#include<string>
using namespace std;
int cur=3;
string new_train(int n){
    string ret;
    ret+="add_train ";
    ret+="-c ";

    //ID
    ret+=std::to_string(n);
    //ret+="Train_ID "
    ret+=' ';
    ret+="-c ";
    n=99;
    ret+=std::to_string(n);
    ret+=' ';
    ret+="-c ";
    ret+="100 ";
    string tmp;
    //地点
    ret+="-c ";


    for(int i=1;i<=n-1;i++){
        ret+=std::to_string(i);
        ret+='|';
    }
    ret+=std::to_string(n);
    ret+=' ';
    //价格
    ret+="-c ";


    for(int i=1;i<=n-2;i++){
        ret+=std::to_string(i);
        ret+='|';
    }
    ret+=std::to_string(n-1);
    ret+=' ';
    //
    ret+="-c ";

    ret+="23:57";
    ret+=' ';
    ret+="-c ";


    //旅行时间
    for(int i=1;i<=n-2;i++){
        ret+=std::to_string(i);
        ret+='|';
    }
    ret+=std::to_string(n-1);
    ret+=' ';
    ret+="-c ";

    //停靠时间
    for(int i=1;i<=n-3;i++){
        ret+=std::to_string(i);
        ret+='|';
    }
    ret+=std::to_string(n-2);
    ret+=' ';
    ret+="-c ";

    //
    ret+="06-30|07-02";
    ret+=' ';
    ret+="-c ";

    ret+='A';
    return ret;
}
void Query_Ticket(){
    std::ofstream os;
    os.open("out.txt");
    Backend::Main test;
    Backend::Cmd_Que * cmdQue=new Backend::Cmd_Que;
    for(int i=0;i<10000;i++) {
        // std::cout<<i<<"\n";
        string todo = new_train(i);
        Backend::process(cmdQue, todo);
        test.OP(cmdQue, os);
        cmdQue->clear();
        cur++;
        // cur++;
    }
    for(int i=0;i<10000;i++){
        //std::cout<<'i'<<'\n';
        string todo="release_train -c ";
        todo+=to_string(i);
        Backend::process(cmdQue,todo);
        test.OP(cmdQue,os);
        cmdQue->clear();
    }
    for(int i=0;i<1000000;i++) {
        // std::cout<<i<<"\n";
        string todo = "query_ticket -s 4 -t 6";
        todo+=" -d ";
        todo+="07-01";
        todo+=" -p price";
        Backend::process(cmdQue, todo);
        test.OP(cmdQue, os);
        cmdQue->clear();
    }
    delete cmdQue;
    os.close();
}
void Add_Train(){
    Backend::Main test;
    Backend::Cmd_Que * cmdQue=new Backend::Cmd_Que;
    for(int i=0;i<100;i++) {
        //std::cout<<i<<"\n";
        string todo = new_train(i);
        Backend::process(cmdQue, todo);
        test.OP(cmdQue, std::cout);
        cmdQue->clear();
        //cur++;
    }
    for(int i=0;i<100;i++) {
        //std::cout<<i<<"\n";
        string todo = new_train(i);
        Backend::process(cmdQue, todo);
        test.OP(cmdQue, std::cout);
        cmdQue->clear();
    }
    delete cmdQue;
}
void Release_Train(){
    Backend::Main test;
    Backend::Cmd_Que * cmdQue=new Backend::Cmd_Que;
    for(int i=0;i<100;i++) {
        // std::cout<<i<<"\n";
        string todo = new_train(i);
        Backend::process(cmdQue, todo);
        test.OP(cmdQue, std::cout);
        cmdQue->clear();
        // cur++;
    }
    for(int i=0;i<100;i++){
        string todo="release_train -c ";
        todo+=to_string(i);
        Backend::process(cmdQue, todo);
        test.OP(cmdQue, std::cout);
        cmdQue->clear();
    }
    for(int i=100;i<200;i++){
        string todo="release_train -c ";
        todo+=to_string(i);
        Backend::process(cmdQue, todo);
        test.OP(cmdQue, std::cout);
        cmdQue->clear();
    }
    delete cmdQue;
};
void Delete_Train(){
    Backend::Main test;
    Backend::Cmd_Que * cmdQue=new Backend::Cmd_Que;
    for(int i=0;i<100;i++) {
        // std::cout<<i<<"\n";
        string todo = new_train(i);
        Backend::process(cmdQue, todo);
        test.OP(cmdQue, std::cout);
        cmdQue->clear();
        // cur++;
    }
    std::cout<<"-------------"<<'\n';
    /* for(int i=0;i<100;i++) {
         // std::cout<<i<<"\n";
         string todo = new_train(i);
         Backend::process(cmdQue, todo);
         test.OP(cmdQue, std::cout);
         cmdQue->clear();
         // cur++;
     }*/
    for(int i=0;i<100;i++){
        string todo="delete_train -c ";
        todo+=to_string(i);
        Backend::process(cmdQue,todo);
        test.OP(cmdQue,std::cout);
        cmdQue->clear();
    }
    for(int i=0;i<100;i++) {
        // std::cout<<i<<"\n";
        string todo = new_train(i);
        Backend::process(cmdQue, todo);
        test.OP(cmdQue, std::cout);
        cmdQue->clear();
        // cur++;
    }
    delete cmdQue;
}
void Query_Train(){
    Backend::Main test;
    Backend::Cmd_Que * cmdQue=new Backend::Cmd_Que;
    for(int i=0;i<1000;i++) {
        // std::cout<<i<<"\n";
        string todo = new_train(i);
        Backend::process(cmdQue, todo);
        test.OP(cmdQue, std::cout);
        cmdQue->clear();
        cur++;
        // cur++;
    }
    std::cout<<"-----------------"<<'\n';
/*    for(int i=0;i<100;i++) {
        // std::cout<<i<<"\n";
        string todo = "query_train -c ";
        todo+=std::to_string(i);
        todo+=" -d ";
        todo+="06-30";
        Backend::process(cmdQue, todo);
        test.OP(cmdQue, std::cout);
        cmdQue->clear();
    }*/
    std::cout<<"-----------------"<<'\n';
//    std::cout<<"-----------------"<<'\n';
    for(int i=0;i<1000;i++){
        string todo="release_train -c ";
        todo+=to_string(i);
        Backend::process(cmdQue,todo);
        test.OP(cmdQue,std::cout);
        cmdQue->clear();
    }
/*    std::cout<<"-----------------"<<'\n';
    for(int i=0;i<10;i++){
        string todo="delete_train -c ";
        todo+=to_string(i);
        Backend::process(cmdQue,todo);
        test.OP(cmdQue,std::cout);
        cmdQue->clear();
    }*/
/*    std::cout<<"-----------------"<<'\n';
    for(int i=4;i<=100;i++){
        string todo="delete_train -c ";
        todo+=to_string(i);
        Backend::process(cmdQue,todo);
        test.OP(cmdQue,std::cout);
        cmdQue->clear();
    }*/
    std::cout<<"-----------------"<<'\n';
    for(int i=0;i<1000;i++) {
        // std::cout<<i<<"\n";
        string todo = "query_train -c ";
        todo+=std::to_string(i);
        todo+=" -d ";
        todo+="06-30";
        Backend::process(cmdQue, todo);
        test.OP(cmdQue, std::cout);
        cmdQue->clear();
    }
}
void Buy_Ticket(){
    Backend::Main test;
    Backend::Cmd_Que * cmd=new Backend::Cmd_Que;
    std::string init;
    std::string str[10000];
    init="add_user cur root root root root@root.root 10";
    Backend::process(cmd,init);
    test.OP(cmd,std::cout);
    cmd->clear();
    std::string log="login root root";
    Backend::process(cmd,log);
    test.OP(cmd,std::cout);
   /* for(int i=0;i<100;i++){
        //   std::cout<<'\n';
        str[i]="add_user root ";
        std::string sub;
        sub=std::to_string(i);
        for(int j=0;j<4;j++) str[i]+=sub,str[i]+=' ';
        str[i]+=sub;
        std::cout<<str[i]<<'\n';
        // delete cmd;
        process(cmd,str[i]);
        test.OP(cmd,std::cout);
        std::cout<<'?'<<'\n';
        cmd->clear();
    }*/
   /* for(int i=0;i<100;i++) {
        // std::cout<<i<<"\n";
        string todo = new_train(i);
        Backend::process(cmd, todo);
        test.OP(cmd, std::cout);
        cmd->clear();
        //cur++;
        // cur++;
    }
    std::cout<<"-----------------"<<'\n';
    for(int i=0;i<100;i++){
        string todo="release_train -c ";
        todo+=to_string(i);
        Backend::process(cmd,todo);
        test.OP(cmd,std::cout);
        cmd->clear();
    }
    std::cout<<"-----------------"<<'\n';
    string todo="query_order -c root";
    Backend::process(cmd,todo);
    test.OP(cmd,std::cout);
    cmd->clear();*/
   for(int i=0;i<=0;i++){
        string todo="buy_ticket -u root ";
        todo+="-i ";
        todo+=to_string(i);
        todo+=" -d 07-01";
        todo+=" -n 56";
        todo+=" -f 1";
        todo+=" -t 4";
        Backend::process(cmd,todo);
        test.OP(cmd,std::cout);
        cmd->clear();
        todo = "query_ticket -s 1 -t 4";
        todo+=" -d ";
        todo+="07-01";
        todo+=" -p price";
        Backend::process(cmd, todo);
        test.OP(cmd, std::cout);
        cmd->clear();
    }
    delete cmd;
}

int main(){
    //Add_Train();
    //Release_Train();
    //Delete_Train();
    //Query_Train();
   // Query_Ticket();
   //Test_1();
   //Buy_Ticket();
   std::ifstream  is;
   std::ofstream os;
   int now=time(0);
   is.open("in.txt");
   os.open("my.txt");
   for(int i=0;i<10;i++) {
       Backend::Main OP;
       //其中第一个参数为输入流，第二个参数为输出流
       OP.Run(is, os);
   }
   int now2=time(0);
   std::cout<<now2-now<<'\n';
    is.close();
    os.close();
    return 0;
}