#include "MapCreate_B.h"

#include <iostream>
#include <fstream>


int main()
{

MapCreate Flightmap;
Flightmap.readCityVex( );
Flightmap.readFlightInfo( );
Flightmap.createMapData( );
//map.displayMap( );

std::ofstream outputfile("HPAir.out.txt");

std::string originCity[Max];
    std::string destinationCity[Max];
    std::string str;
    int sum = 0;
    std::ifstream rfFile;
    rfFile.open("BrequestFile.txt");
    while(getline(rfFile, str))
        {
           originCity[sum] = str.substr(0,(str.find(',')));
           destinationCity[sum] = (str.substr((str.find(',')+2)));
        sum++;
        }

for(int k =0; k < sum ;k++){

    //Flightmap.Result2(originCity[i],destinationCity[i]);
  int  i= Flightmap.PosLocate(originCity[k]);
   int  j= Flightmap.PosLocate(destinationCity[k]);

       if(i < 0|| i >= Flightmap.getCitySum()){
            outputfile<< "Request is to fly from "<< originCity[k]<<" to "<<destinationCity[k]<<". "<<std::endl;
            outputfile<< "Sorry. HPAir does not serve "<< originCity[k]<<". "<<std::endl;
            }
        else if(j < 0|| j >= Flightmap.getCitySum()){
            outputfile<< "Request is to fly from "<< originCity[k]<<" to "<<destinationCity[k]<<". "<<std::endl;
            outputfile<< "Sorry. HPAir does not serve "<< destinationCity[k]<<". "<<std::endl;
            }
          else if(j >= 0 && j < Flightmap.getCitySum()){
            if(Flightmap.isPath(originCity[k],destinationCity[k])){
                outputfile<< "Request is to fly from "<< originCity[k]<<" to "<<destinationCity[k]<<". "<<std::endl;
                outputfile<< "HPAir flies from "<<originCity[k]<<" to "<<destinationCity[k]<<". "<<std::endl;
                }
             else{
                outputfile<< "Request is to fly from "<< originCity[k]<<" to "<<destinationCity[k]<<". "<<std::endl;
                outputfile<< "Sorry. HPAir does not fly from "<<originCity[k]<<" to "<<destinationCity[k]<< ". "<<std::endl;
                }

             }
    //std::cout<<"\n"<<std::endl;
    //Flightmap.isPath2(originCity[0],destinationCity[0]);
}



//cout<<map.isPath(a, b);

//map.filghttest(aCity);
//map.printtest( );
//map.displayCityies( );
//cout<<aCity.getSubsquent()->getCityName()<<endl;
return 0;

}
