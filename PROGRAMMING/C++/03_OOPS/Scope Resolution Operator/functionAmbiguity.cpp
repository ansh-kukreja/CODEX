#include<iostream>
using namespace std;

class SoboDilliGirl{
    public:
    void speak(){
        cout<<endl<<"Bhaiya chwenty ke momos dena.."<<endl<<endl;
    }
};

class PunjabiKudi{
    public:
    void speak(){
        cout<<endl<<"Ve meri kaali Activa da, ik din khad gya handle fadd ke, Paani Paani hogyi mai, pattu haan krvaunda ae adkee.."<<endl<<endl;
    }
};


class Kudi: public SoboDilliGirl, public PunjabiKudi{
    public:
};


int main(){
    Kudi parmeet;

    parmeet.PunjabiKudi::speak();
    parmeet.SoboDilliGirl::speak();
}