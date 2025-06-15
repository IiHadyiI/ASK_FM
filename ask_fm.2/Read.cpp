#include "Read.h"
#include <iostream>
#include <map>
using namespace :: std;
Read::~Read(){
}
Read :: Read () {
}
Read* Read::get_instance(){
    if (read==nullptr)
        read=new Read();
    return read;    
}
void Read::read_answer(){
    string answer,question_id;
    int user_id_1,user_id_2;
    string path = "projectFiles/Questions/answers/answers.txt";
    ifstream iStream(path,ios::in);
    while (getline(iStream,answer,'-'))
    {
        getline(iStream,question_id);
        user_id_1=stoi(question_id)/10000;
        user_id_2=(stoi(question_id)/100)%100;
        users.at(user_id_1).add_answer_from_question(answer,stoi(question_id));
        users.at(user_id_2).add_answer_to_question(answer,stoi(question_id));
    }
}
void Read :: read_question(){
    string Q_count,to,questionText,from,deleted_Qs,Ques_id,isAnon,isThread;
    ifstream from_iStream("projectFiles/Questions/questions/questions.txt",ios::in);
    ifstream deleted_stream("projectFiles/Questions/questions/deleted.txt",ios::in);
    while (getline(from_iStream,questionText,'-'))
    {
        getline(from_iStream,to,'-');
        getline(from_iStream,Ques_id,'-');
        getline(from_iStream,isAnon,'-');
        getline(from_iStream,isThread);
        Question Q = Question(questionText,users.at(stoi(Ques_id)/10000).get_user_name(),to,stoi(Ques_id),stoi(isAnon),stoi(isThread));
        users.at(stoi(Ques_id)/10000).addQ_from_me(Q);
        users.at((stoi(Ques_id)/100)%100).addQ_to_me(Q);
    }
    while (getline(deleted_stream,deleted_Qs))
    {
        for(auto& user:users){
            for(auto question:user.second.get_questions_from_me()){
                if (question.second.get_id()==stoi(deleted_Qs))
                {
                    user.second.delete_question_from(stoi(deleted_Qs));
                    users.at((stoi(deleted_Qs)/100)%100).delete_question_to(stoi(deleted_Qs));
                }
            }
        }
    }  
}
Read* Read::read=nullptr;