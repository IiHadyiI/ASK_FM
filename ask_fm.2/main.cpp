#include <iostream>
#include <map>
#include "Login.cpp"
#include "Creat_User.cpp"
void menu_0(){
    int choise=-1;
    while (true)
    {
        
        cout << "Menu:\n";
        cout << "   1-login\n";
        cout << "   2-sign up\n";
        cin >> choise;
        if (choise==1)
        {
            Login* log=Login::get_instance();
            int validate = log->login();
            Ask_sys* ask_sys=Ask_sys::get_instance();
            if(validate==0){
                cout << "Wrong user-name or password! \n";
                continue;
            }
            ask_sys->run(validate);
            choise=-1;
        }
        else if (choise==2)
        {
            Creat_User* create=Creat_User::get_instance();
            create->sign_up();
        }
        else
            choise=-1;
    }
}
int main(){
    System_reload*sys=System_reload::get_instance();
    sys->reload_sys();
    menu_0();
}