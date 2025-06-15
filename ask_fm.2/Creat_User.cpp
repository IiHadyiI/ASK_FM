#include "Create_User.h"
#include "Ask_sys.cpp"
#include <iostream>
using namespace :: std;
Creat_User::Creat_User(){
}
Creat_User*Creat_User::get_instance(){
    if (create==nullptr)
    {
        create=new Creat_User();
    }
    return create;
}
void Creat_User::sign_up(){
    string firstName,secName,user_name,password,gender;
        bool allow_anonymous;
        string path = "projectFiles/Users/users.txt";
        cout << "Enter first name:";
        cin >> std::ws;
        getline(cin,firstName);
        cout << "Enter sec name:";
        getline(cin,secName);
        cout << "Enter UserNmae:";
        getline(cin,user_name);
        cout << "Enter Password:";
        getline(cin,password);
        cout << "Enter your gender:";
        getline(cin,gender);
        cout << "Allow anonymous question?: (0 or 1) ";
        cin >> allow_anonymous;
        user_count++;
        User U = User(firstName,secName,user_name,gender,password,allow_anonymous,user_count);
        users.insert({user_count,U});
        write_user(U,path);
}
void Creat_User ::write_user(User& U,string file_path){
    
    ofstream myFile;
    myFile.open(file_path,ios::out|ios::app);

    myFile << U.get_id() << " " << U.get_firstName() << " " 
    << U.get_secName() << " " << U.get_gender() << " "
    << U.get_user_name() << " " << U.get_password() << " "
    << U.get_anon() << "\n";

    cout << "--> Recoord is added to file\n";

    System_reload*sys=System_reload::get_instance();
    sys->reload_sys();    
}
Creat_User*Creat_User::create=nullptr;