#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream file;
    file.open("tempos.csv");

    file<<"bs,obs,ss,oss"<<endl;
    file<<"1,2,3,4"<<endl;

    file.close();
    
    return 0;
}