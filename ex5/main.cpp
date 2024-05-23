
#include <iostream>
#include <fstream>
using namespace std;

class myString{
    private:
        string m_str;
    public:
        myString(string s){
            m_str=s;
        }
};

class ReadClass{
    public:
    void showClass(){
        ifstream in;
        in.open("main.cpp");
        string line ;
        int Count = 0;
        
        string a[10];
        int i=0;
        
        
       
        
        while (getline(in, line)) {
             if (line.find("class ") != string::npos)
             {
                  if (line.find("{") != string::npos){
                 Count+=1;
                 a[i]=line;
                 i+=1;}
             }
        }
        cout<<Count<<" class in main.cpp"<<endl;
        for(int j=0;j<i;j++){
           
            cout<<a[j]<<endl;
        }
        
        in.close();
    }
    
};

int main()
{
    ReadClass rfile;
    rfile.showClass();

    return 0;
}