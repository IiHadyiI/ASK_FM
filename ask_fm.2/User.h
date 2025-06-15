#ifndef USER_H_
#define USER_H_
#include "Question.h"
#include<iostream>
#include<map>
using namespace :: std;
class User{
    private:
        int id,myQ_count,recQ_count;
        string firstName,secName,user_name,gender,password;
        map<int,Question> questions_to_me;
        map<int,Question> questions_from_me;
        bool anonymous;
        
    public:
        ~User();
        User(string firstName,string secName,string user_name
        ,string gender,string password,bool anonymous,int id);
        void set_firstName(const string& firstName);
        string get_firstName();
        void set_secName(const string& secName);
        string get_secName();
        void set_userName(const string& user_name);
        string get_user_name();
        void set_password(const string& password);
        string get_password();
        void set_gender(const string& gender);
        string get_gender();
        void set_id(const int& id);
        int get_id();
        void set_myQ_count(const int& myQcount);
        int get_myQ_count();
        void set_recQ_count(const int& recQ_count);
        int get_recQ_count();
        void set_anon(const bool& anonymous);
        int get_anon();
        map<int,Question> get_questions_from_me();
        map<int,Question> get_questions_to_me();
        Question get_question_from_me(const int& id);
        Question get_question_to_me(const int& id);
        void add_answer_to_question(const string& answer,const int& Q_id);
        void add_answer_from_question(const string& answer,const int& Q_id);
        void delete_question_from(const int& Q_id);
        void delete_question_to(const int& Q_id);
        void addQ_to_me(Question& Q);
        void print_Qs_to_me();
        void addQ_from_me(Question Q);
        void print_Qs_from_me();
};
map<int,User>users;
#endif