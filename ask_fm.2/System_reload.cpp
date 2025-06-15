#include "System_reload.h"
#include <iostream>
#include <sstream>
#include "User.cpp"
#include "Read.cpp"
using namespace :: std;
#define FILE_PATH "projectFiles/Users/users.txt"
System_reload::System_reload(){
}
System_reload::~System_reload(){
}
System_reload* System_reload::get_instance(){
    if (sys_rel==nullptr){
        sys_rel=new System_reload();
    }
    return sys_rel;    
}
int user_count=0;
int Q_count=0;
void System_reload::reload_sys(){
    ifstream iStream(FILE_PATH,ios::in);
    ifstream q_count_stream("projectFiles/Questions/questions/Q_count.txt",ios::in);
    if(getline(q_count_stream,Ques_count))
        Q_count = stoi(Ques_count);
    while (getline(iStream,str))
    { 
        user_count++;
        istringstream iss(str);
        iss >> user_count >> firstName >> secName >> gender >> userName >> password >> allow_anonymous;
        User U = User(firstName,secName,userName,gender,password,allow_anonymous,user_count);
        users.insert({U.get_id(),U});
    }
    Read* R = Read::get_instance();
    R->read_question();
    // R->read_answer();
}
void System_reload :: free_instance(){
    if (sys_rel!=nullptr)
    {
        cout << "free instance \n";
        delete sys_rel;
        sys_rel=nullptr;
    }
    else 
        cout << "Already freed! \n";    
}
System_reload* System_reload :: sys_rel=nullptr;