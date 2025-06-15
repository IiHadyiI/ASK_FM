#include "Question.h"
#include <istream>
using namespace :: std;
Question ::Question(string Q,string from,string to,int id,bool isAnonymous,int thread):
    Q(Q),
    from(from),
    to(to),
    id(id),
    isAnonymous(isAnonymous),
    thread(thread),
    answer("")
{
}
Question::~Question(){
}
void Question ::set_Q(const string& Q){
    this->Q=Q;
}
string Question ::get_Q(){
    return Q;
}
void Question ::set_answer(const string& answer){
    this->answer=answer;
}
string Question ::get_answer(){
    return answer;
}
void Question ::set_from(const string& from){
    this->from=from;
}
string Question ::get_from(){
    return from;
}
void Question ::set_to(const string& to){
    this->to=to;
}
string Question ::get_to(){
    return to;
}
void Question ::set_id(const int& id){
    this->id=id;
}
int Question ::get_id(){
    return id;
}
void Question ::set_thread(const int& thread){
    this->thread=thread;
}
int Question ::get_thread(){
    return thread;
}
void Question ::set_is_thread(const bool& is_thread){
    this->hasThread=is_thread;
}
bool Question ::get_is_thread(){
    return hasThread;
}
void Question :: set_anon(const bool& isAnonymous){
    this->isAnonymous=isAnonymous;
}
bool Question :: get_anon(){
    return isAnonymous;
}
void Question :: is_deleted(){
    isDeleted=true;
}
bool Question :: get_deleted(){
    return isDeleted;
}