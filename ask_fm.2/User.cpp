#include "User.h"
#include <iostream>
#include "Question.cpp"
using namespace::std;
User::User(string firstName,string secName,string user_name
        ,string gender,string password,bool anonymous,int id) :
            firstName(firstName),
            secName(secName),
            user_name(user_name),
            gender(gender),
            password(password),
            anonymous(anonymous),
            id(id),
            myQ_count(0),
            recQ_count(0)
        {
        }
User::~User(){
}
void User::set_firstName(const string& firstName){
    this->firstName=firstName;
}
string User::get_firstName(){
    return firstName;
}
void User::set_secName(const string& secName){
    this->secName=secName;
}
string User::get_secName(){
    return secName;
}
void User::set_userName(const string& user_name){
    this->user_name=user_name;
}
string User::get_user_name(){
    return user_name;
}
void User::set_gender(const string& gender){
    this->gender=gender;
}
string User::get_gender(){
    return gender;
}
void User::set_id(const int& id){
    this->id=id;
}
int User::get_id(){
    return id;
}
void User::set_password(const string& password){
    this->password=password;
}
string User::get_password(){
    return password;
}
void User::set_myQ_count(const int& myQ_count){
    this->myQ_count=myQ_count;
}
int User::get_myQ_count(){
    return myQ_count;
}
void User::set_recQ_count(const int& recQ_count){
    this->recQ_count=recQ_count;
}
int User::get_recQ_count(){
    return recQ_count;
}
void User::set_anon(const bool& anonymous){
    this->anonymous=anonymous;
}
int User::get_anon(){
    return anonymous;
}
map<int,Question> User::get_questions_from_me(){
    return questions_from_me;
}
map<int,Question> User::get_questions_to_me(){
    return questions_to_me;
}
Question User::get_question_from_me(const int& id){
    if(questions_from_me.find(id)==questions_from_me.end())
        return Question("","","",0,0,0);
    return questions_from_me.at(id);
}
Question User::get_question_to_me(const int& id){
    if(questions_to_me.find(id)==questions_from_me.end())
        return Question("","","",0,0,0);
    return questions_to_me.at(id);
}
void User::add_answer_to_question(const string& answer,const int& Q_id){
    if(questions_to_me.find(Q_id)==questions_to_me.end())
        return;
    questions_to_me.at(Q_id).set_answer(answer);
    print_Qs_to_me();
}
void User::add_answer_from_question(const string& answer,const int& Q_id){
    if(questions_from_me.find(Q_id)==questions_from_me.end())
        return;
    questions_from_me.at(Q_id).set_answer(answer);
}
void User::delete_question_from(const int& Q_id){
    questions_from_me.at(Q_id).is_deleted();
}
void User::delete_question_to(const int& Q_id){
    questions_to_me.at(Q_id).is_deleted();
}
void User::addQ_to_me(Question& q){
    questions_to_me.insert({q.get_id(),q});
    recQ_count++;
}
void User::print_Qs_to_me(){
    for (auto& Q:questions_to_me)
    {
        if (Q.second.get_deleted())
            continue;                
        if (Q.second.get_thread()==-1)
        {                
            cout << "Question Id (" << Q.second.get_id() << ")";
            if(Q.second.get_anon())
            {
                cout << "----> Question: " << Q.second.get_Q() << "   Answer: " << Q.second.get_answer()
                << "\n";
            }
            else
                cout << "from user {" << Q.second.get_from() << "} ----> Question: " 
                << Q.second.get_Q() << "   Answer: " << Q.second.get_answer() << "\n";
        }
        for(auto& Q2:questions_to_me){
            if (Q2.second.get_deleted())
                continue;
            if (Q2.second.get_thread()==Q.second.get_id())
            {
                cout << "         Thread:";
                cout << "Question Id (" << Q2.second.get_id() << ")";
                if(Q2.second.get_anon())
                {
                    cout << "----> Question: " << Q2.second.get_Q() 
                    << "   Answer: " << Q2.second.get_answer() << "\n";
                }
                else
                    cout << "from user {" << Q2.second.get_from() << "} ----> Question: " 
                    << Q2.second.get_Q() << "   Answer: " << Q2.second.get_answer() << "\n";
            }
        }
    }
}
void User::addQ_from_me(Question q){
    questions_from_me.insert({q.get_id(),q});
    myQ_count++;
}
void User::print_Qs_from_me(){
    for (auto& Q:questions_from_me)
    {
        if (Q.second.get_deleted()){

            continue;
        }
        cout << "Question Id (" << Q.second.get_id() << ") to user {" << Q.second.get_to() 
        << "} ----> Question: " << Q.second.get_Q() << "   Answer: " << Q.second.get_answer() << "\n";
    }
}
