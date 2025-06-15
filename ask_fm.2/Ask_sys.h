#ifndef ASK_SYS_H_
#define ASK_SYS_H_
#include <iostream>
#include "System_reload.h"
using namespace :: std;
class Ask_sys{
    private:
        Ask_sys();
        static Ask_sys* ask_sys;
    public:
        static Ask_sys* get_instance();
        void ask_question(int user_id);
        void write_question(Question& Q,User& U);
        void answer_question(int user_id);
        void write_answer(string answer,int user_id,int question_id);
        void delete_question(int user_id);
        void print_users(); 
        void run(int user_id);   
        int main_menu();
};
#endif
