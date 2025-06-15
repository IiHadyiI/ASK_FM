#ifndef CREATE_USER_H_
#define CREATE_USER_H_
#include <iostream>
#include "System_reload.h"
using namespace :: std;
class Creat_User{
    private:
        Creat_User();
        static Creat_User*create;
    public:
        static Creat_User* get_instance();
        static void sign_up();
        static void write_user(User& U,string file_path);
};
#endif