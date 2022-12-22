#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>
#include <regex>

#define MAX_LINES 300000

using namespace std;

//"D:\work\_DOCS\Notes\46460\46460_techlog.txt"
//zka - TechnologySelectCRTDS.cpp ([....]): Aborted

//D:\work\_DOCS\Logs\ZPD06591\ZPD06591.txt


vector<string> DataType;
string str_to_find = "zka - TechnologySelectCRTDS.cpp [0-9]+: Aborted";
//string str_to_find = "transparent mode";
string template_for_search = "zka - TechnologySelectCRTDS.cpp (): Aborted";

void search_template_in_file(ifstream &f_in, vector<string> &data,
                             ofstream &f_out, string &search_str);
void load_data(string &arr_of_lines, int arr_of_lines_size);
int main() {

    string search_str, file_in_path, file_out_path;

    cout<<"Input the file name with path : ";
    cin>>file_in_path;

//    cout<<"Output file name : ";
//    cin>>file_out_path;

//    cout<<"Input a string for search : ";
//    cin>>search_str;

    search_str = str_to_find;

    ifstream file_in;
    ofstream file_out;
    file_in.open(file_in_path, ios::in);
    file_out.open(file_out_path, ios::out);




    search_template_in_file(file_in, DataType, file_out, search_str);

//    if (regex_match ("softwareTesting", regex("(soft)(.*)") ))
//      cout << "string:literal => matched\n";



    return 0;
}

void search_template_in_file(ifstream &f_in, vector<string> &data,
                             ofstream &f_out, string &str_search)
{
    int i=0;
    string str_line, arr_of_lines[MAX_LINES];

    while(!f_in.eof()) {
        getline(f_in, str_line);
        arr_of_lines[i]=str_line;
        i++;
    }
    for (int counter = 0; counter < MAX_LINES; counter++){
        size_t found = arr_of_lines[counter].find(str_search);
        if(found != string::npos){
            data.push_back(arr_of_lines[counter]);
            cout<<arr_of_lines[counter]<<endl;
        }
    }

//    for(auto j:data){
//        f_out<<j<<endl;
//        cout<<j<<endl;
//    }
}
//void load_data(string &arr_of_lines, int arr_of_lines_size){
//    int i=0;
//    string str_line, arr_of_lines[MAX_LINES];
//
//    while(!f_in.eof()) {
//        getline(f_in, str_line);
//        arr_of_lines[i]=str_line;
//        i++;
//    }
//}
