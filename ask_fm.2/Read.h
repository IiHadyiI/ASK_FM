#ifndef Read_H_
#define Read_H_
#include <iostream>
#include <fstream>
#include "User.h"
using namespace :: std;
class Read{
    private:
        string Q_count,to,questionText,from,deleted_Qs,Ques_id,isAnon,isThread,questions_path,deleted_path;
        ifstream from_iStream(),deleted_stream();
        string answer,question_id;
        int user_id_1,user_id_2;
        string path;
        ifstream iStream();
        Read();
        static Read*read;
    public:
        ~Read();
        static Read* get_instance();
        void read_answer();
        void read_question();
};
#endif