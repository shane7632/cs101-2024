/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

class Engine{
  private:
    int m_EngineCapacity;
    int m_Horsepower;
    bool m_EngineRunning;
  public:
    Engine(int EngineCapacity=2000,int Horsepower=200){
        m_EngineCapacity=EngineCapacity;
        m_Horsepower=Horsepower;
        m_EngineRunning=false;
    }
    bool EngineStart(){
        m_EngineRunning=true;
        return true;
    };
    bool EngineStop(){
        m_EngineRunning=false;
        return true;
    };
    bool get_EngineStatus(){
        return m_EngineRunning;
    }
};

class Fueltank{
  private:
    int m_FueltankCapacity;
    int m_Gas_grade;
    
  public:
  Fueltank(int FueltankCapacity=3000,int Gas=98){
      m_FueltankCapacity=FueltankCapacity;
      m_Gas_grade=Gas;
  }
    int fuel_up(int v,int gas){
        if(v>m_FueltankCapacity){cout<<"Error FueltankCapacity:"<<m_FueltankCapacity<<" but fuel up:"<<v<<endl;}
        if(gas!=m_Gas_grade){cout<<"Error Gas_grade:"<<gas<<" Correct Gas_grade:"<<m_Gas_grade<<endl;}
        if(gas==m_Gas_grade){cout<<"fuel_up: "<<v<<" Gas_grade: "<<gas<<endl;}
        return v;
    };
    int set_Gas_grade(int Gas_grade){
        m_Gas_grade=Gas_grade;
        return m_Gas_grade;
    }
    int get_Gas_grade()
    {
        return m_Gas_grade;
    };
};

class Car{
    
    private:
        Engine m_Engine;
        Fueltank m_Fueltank;
        int m_MaxSeating;
        int m_price;
        int m_base;
        string m_brand;
        string m_model;
        int m_year;
      
    public:
        Car(string x,string y,int z,int s){
            m_brand=x;
            Fueltank();
          
        }
       
       string get_brand(){
           return m_brand;
       }
      
        
        bool get_EngineStatus(){
            return m_Engine.get_EngineStatus();
        }
       
       int get_Gas_grade(){
           return  m_Fueltank.get_Gas_grade();
       }
       int set_Gas_grade(int gas=98){
           cout<<"set Gas_grade:"<<gas<<endl;
             m_Fueltank.set_Gas_grade(gas);
            return gas;
       }
       int fuel_up(int v,int gas=98){
           m_Fueltank.fuel_up(v,gas);
           return gas;
       }
        
};

class AUDI_Car:public Car{
    public:
        AUDI_Car(string y,int z,int s):Car("Audi",y,z,s){
            cout<<"Constructing AUDI_Car\n";
        }
};


int main()
{
    AUDI_Car car_2("A1",2021,2);
    cout<<car_2.get_brand()<<"Gas_grade="<<car_2.get_Gas_grade()<<endl;
    car_2.set_Gas_grade(95);
   cout<<car_2.get_brand()<<": Gas_grade="<<car_2.get_Gas_grade()<<endl;
    car_2.fuel_up(3000000,98);

    return 0;
}