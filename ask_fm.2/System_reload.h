#ifndef SYS_REL_H_
#define SYS_REL_H_
#include <iostream>
#include <fstream>
#include "Read.h"
#include "User.h"
using namespace :: std;
class System_reload{
    private:
        string firstName,secName,gender,userName,password,str,Ques_count="0";
        bool allow_anonymous;
        ifstream iStream(),q_count_stream();
        System_reload();
        static System_reload*sys_rel;
    public:
        ~System_reload();
        static System_reload*get_instance();
        static void free_instance();
        void reload_sys();
};
#endif