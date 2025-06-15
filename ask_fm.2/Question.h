#ifndef Question_H_
#define Question_H_
#include <iostream>
#include <map>
using namespace :: std;
class Question{
    private:
        int id,thread;
        string Q,from,to,answer;
        bool isAnonymous,hasThread,isDeleted;
    public:
        ~Question();
        Question(string Q,string from,string to,int id,bool isAnonymous,int thread);
        void set_from(const string& from);
        string get_from();
        void set_to(const string& to);
        string get_to();
        void set_Q(const string& Q);
        string get_Q();
        void set_answer(const string& answer);
        string get_answer();
        void set_id(const int& id);
        int get_id();
        void set_anon(const bool& isAnonymous);
        bool get_anon();
        void set_thread(const int& thread);
        int get_thread();
        void set_is_thread(const bool& thread);
        bool get_is_thread();
        void is_deleted();
        bool get_deleted();
};

#endif