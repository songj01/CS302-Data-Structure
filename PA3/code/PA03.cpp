#include "MapCreate.h"
#include "LinkedStack.h"
#include <iostream>
#include <fstream>


int main()
{

MapCreate Flightmap; ///< create object.
Flightmap.readCityVex( ); ///< read vexcities.
Flightmap.readFlightInfo( );///< read flight information.
Flightmap.createMapData( ); ///< create map data.

std::ofstream outputfile("HPAir.out.txt");///<Declare and open the output file.

    std::string originCity[Max];  ///<Delclare the origincity array.
    std::string destinationCity[Max]; ///< Delclare the destination city array.
    std::string str; ///< Declare str and use it to store each line data.
    int sum = 0; ///<Declare the sum of request flights.
    std::ifstream rfFile; ///<Declare object rfFile.
    rfFile.open("requestFile.txt");///< Open the file.
    while(getline(rfFile, str))
        {
           originCity[sum] = str.substr(0,(str.find(',')));///<read the data before comma.
           destinationCity[sum] = (str.substr((str.find(',')+2)));///<read the data after comma.
        sum++;
        }
   rfFile.close();///<Close the file.
///Output the result to file based on the different conditions.
for(int k =0; k < sum ;k++){
  int  i= Flightmap.PosLocate(originCity[k]);
   int  j= Flightmap.PosLocate(destinationCity[k]);

       if(i < 0|| i >= Flightmap.getCitySum()){     ///< condition 1: the origin city requested is beyond the serve cities.
            outputfile<< "Request is to fly from "<< originCity[k]<<" to "<<destinationCity[k]<<". "<<std::endl;
            outputfile<< "Sorry. HPAir does not serve "<< originCity[k]<<". "<<std::endl;
            }
        else if(j < 0|| j >= Flightmap.getCitySum()){  ///< condition 1: the destination city requested is beyond the serve cities.
            outputfile<< "Request is to fly from "<< originCity[k]<<" to "<<destinationCity[k]<<". "<<std::endl;
            outputfile<< "Sorry. HPAir does not serve "<< destinationCity[k]<<". "<<std::endl;
            }
          else if(j >= 0 && j < Flightmap.getCitySum()){ ///< condition 3: the the cities requested is in serve cities..
            if(Flightmap.isPath(originCity[k],destinationCity[k])){ ///< condition :flight is ok;
                outputfile<< "Request is to fly from "<< originCity[k]<<" to "<<destinationCity[k]<<". "<<std::endl;
                outputfile<< "HPAir flies from "<<originCity[k]<<" to "<<destinationCity[k]<<". "<<std::endl;
                }
             else{
                outputfile<< "Request is to fly from "<< originCity[k]<<" to "<<destinationCity[k]<<". "<<std::endl;
                outputfile<< "Sorry. HPAir does not fly from "<<originCity[k]<<" to "<<destinationCity[k]<< ". "<<std::endl;
                }

             }
}


outputfile.close();
return 0;

}
