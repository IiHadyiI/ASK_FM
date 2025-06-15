#include <iostream>
#include "System_reload.h"
using namespace :: std;
class Login{
    private:
        Login(){
        };
        static Login* log;
    public:
        static Login* get_instance(){
            if (log==nullptr)
            {
                log=new Login();
            }
            return log;
        }
        int login(){
            string userName;
            string password;
            cout << "Enter userName: \n";
            cin >> userName;
            cout << "Enter password: \n";
            cin >> password;
            for (auto user : users)
            {
                if (user.second.get_user_name()==userName&&user.second.get_password()==password)
                {
                    cout << "Welcome " << user.second.get_firstName() 
                    << " " << user.second.get_secName() << "\n";
                    users.at(2).print_Qs_to_me();
                    return user.second.get_id();
                }
            }
            return 0;
        }
};
Login* Login::log=nullptr;