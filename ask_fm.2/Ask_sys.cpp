#include "Ask_sys.h"
#include <iostream>
#include "System_reload.cpp"
using namespace :: std;
Ask_sys :: Ask_sys(){
}
Ask_sys* Ask_sys :: get_instance(){
    if(ask_sys==nullptr)
        ask_sys = new Ask_sys();
    return ask_sys;
}
void Ask_sys::ask_question(int user_id){
    string ques,to;
    int thread,to_id;
    int question_id=0;
    bool ask_anon,isAnonymous,isThread=false;
    ofstream oStream("projectFiles/Questions/questions/Q_count.txt",ios::out);
    cout << "Enter User_name or -1 to cancel: ";
    cin >> to;
    for(auto& user : users){
        if (user.second.get_user_name()==to)
        {
            to_id=user.second.get_id();
            if (users.at(to_id).get_anon())
            {
                cout << "Ask as anonymous? (0 or 1): ";
                cin >> ask_anon;
            }
            else
                cout << "Note: Anonymous questions are not allowed for this user! \n";
            cout << "1) For thread question enter question id \n";
            cout << "2) (-1) for new question \n";
            cin >> thread;
            if(thread!=-1){
                if (users.at(to_id).get_question_to_me(thread).get_Q()!=""){
                    cout << "no questoin with this id! \n";
                    return;
                }
                users.at(to_id).get_question_to_me(thread).set_thread(true);
            }
            cout << "Enter questoin text: ";
            std::cin >> std::ws;
            getline(cin,ques);
            Q_count++;
            oStream << Q_count;
            question_id=((question_id+user_id)*100+(to_id))*100+Q_count;
            Question Q = Question(ques,users.at(user_id).get_user_name(),to,question_id,ask_anon,thread);
            users.at(user_id).addQ_from_me(Q);
            users.at(to_id).addQ_to_me(Q);
            users.at(to_id).print_Qs_to_me();
            write_question(Q,users.at(user_id));
            return;
        }
    }
    cout << "no user with such id! \n";
}
void Ask_sys::write_question(Question& Q,User& U){
    ofstream oStream("projectFiles/Questions/questions/questions.txt",ios::out|ios::app);
    oStream << Q.get_Q() << "-" << Q.get_to() << "-" << Q.get_id() 
    << "-" << Q.get_anon() << "-" << Q.get_thread() << "\n";
    System_reload* sys = System_reload::get_instance();
    sys->reload_sys();
}
void Ask_sys::answer_question(int user_id){
    int question_id;
    string answer;
    users.at(user_id).print_Qs_to_me();
    cout << "Enter question id or -1 to cancel: ";
    cout << "Enter questoin id: ";
        
    cin >> question_id;
    if (users.at(user_id).get_question_to_me(question_id).get_id()==question_id)
    {
            cout << "Enter your answer: ";
            std::cin >> std::ws;
            getline(cin,answer);
            users.at(user_id).add_answer_to_question(answer,question_id);
            users.at(user_id).add_answer_from_question(answer,question_id);
            write_answer(answer,user_id,question_id);
            return;
    }
    cout << "No question with sutch id! \n";
    answer_question(user_id);
}
void Ask_sys:: write_answer(string answer,int user_id,int question_id){
    ofstream oStream("projectFiles/Questions/answers/answers.txt",ios::out|ios::app);
    oStream << answer << "-" << question_id << "\n";
    users.at(user_id).add_answer_to_question(answer,question_id);
    users.at(question_id/10000).add_answer_from_question(answer,question_id);
    System_reload* sys = System_reload::get_instance();
    sys->reload_sys();
}
void Ask_sys :: delete_question(int user_id){
        ofstream oStream("projectFiles/Questions/questions/deleted.txt",ios::out|ios::app);
        int question_id;
        users.at(user_id).print_Qs_from_me();
        cout << "Enter question id or (-1) to cancel: \n";
        cin >> question_id;
        if (question_id!=-1)
        {
            if (users.at(user_id).get_question_from_me(question_id).get_id()!=question_id)
            {
                cout << "No question with such id! \n";
                delete_question(user_id);
            }
            cout << "===Questoin is deleted!===\n";
            oStream << question_id << "\n";
        }
        System_reload*sys=System_reload::get_instance();
        sys->reload_sys();
    }
void Ask_sys:: print_users(){
    auto it = users.begin();
    int i = 0;
    while(it!=users.end())
    {
        cout<< "user-" << i+1 << " " << it->second.get_firstName() 
        << " " << it->second.get_secName() << "\n";
        i++;
        it++;
    }
}

int Ask_sys :: main_menu(){
    int choise = -1;
    while (choise==-1)
    {
        cout << "1-print questions to me\n";
        cout << "2-print questions from me\n";
        cout << "3-answer question \n";
        cout << "4-delete question \n";
        cout << "5-Ask question:\n";
        cout << "6-print all users.\n";
        cout << "8-sign out.\n";
        cin >> choise;
        if (choise<1||choise>8)
        {
            choise=-1;
        }
    }
    return choise;
}
void Ask_sys:: run(int user_id){
    int choise;
    while (true)
    {            
        choise=main_menu();
        if(choise==1)
        {
            users.at(user_id).print_Qs_to_me();
        }
        else if (choise==2)
        {
            users.at(user_id).print_Qs_from_me();
        }
        else if (choise==3)
        {
            answer_question(user_id);
        }
        else if (choise==4)
        {
            delete_question(user_id);
        }
            
        else if (choise==5)
        {
            ask_question(user_id);
        }
        else if (choise==6)
        {
            print_users();
        }
        else if (choise==8)
        {
            return;
        }
    }
}
Ask_sys* Ask_sys::ask_sys = nullptr;