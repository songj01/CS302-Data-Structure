#ifndef TELLERS_H
#define TELLERS_H

class Tellers{
    public:
        Tellers(){ tellerAvailable = true;}
        void setTellerAvailable(bool const &a){tellerAvailable = a;}
        bool getTellerAvailable( )const {return tellerAvailable;}

    private:
        bool tellerAvailable;
       // int idleTime;
};

#endif // TELLERS_H
