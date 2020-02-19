#include "MapCreate_B.h"
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedQueue_B.h"

 MapCreate::MapCreate()
 {
     citySum = 0;
     flightSum = 0;
     Totalcost = 0;
     flightRouteSum =0;
 }

void MapCreate::setCitySum(int &citySum)
{
 	this->citySum = citySum;
}

int MapCreate::getCitySum( ) const
{
    return citySum;
}

void MapCreate::readCityVex( )
{
    std::string cityname;
    std::ifstream cityNameFile;
    cityNameFile.open("cityFile.txt");
    while(getline(cityNameFile,cityname)){
        vexCity[citySum].cityVexName = cityname;
        vexCity[citySum].head = nullptr;
	citySum++;
    }

   setCitySum(citySum);
}

void MapCreate::readFlightInfo( )
{
    std::string originCity, destinationCity;
    std::string str;
    std::ifstream flightInfoFile;
    flightInfoFile.open("flightFile.txt");
    while(getline(flightInfoFile, str))
        {
           originCity = str.substr(0,(str.find(',')));
           destinationCity = (str.substr((str.find(',')+2)));
           flightLine[flightSum] = std::make_pair(originCity, destinationCity);
	flightSum++;
    }

}





int MapCreate::PosLocate(std::string & aCity)
{    for(int i = 0 ; i < citySum ; i++)
        if(vexCity[i].cityVexName == aCity)
        return i;
}


void MapCreate::createMap(std::string &fromCity, std::string &toCity)

{
   int i ,j;
   City *aCity = new City();
   i = PosLocate(fromCity);
   j = PosLocate(toCity);
   aCity -> pos = j;
   aCity -> subsquent = vexCity[i].head;
   vexCity[i].head = aCity;
}


void MapCreate::createMapData( )
{
    for(int i = 0; i< flightSum; i++)
    {
        createMap(flightLine[i].first, flightLine[i].second);
    }
}


void MapCreate::displayMap()
{
    for (int i = 0; i < citySum; i++){
        City * tmpCity = vexCity[i].head;
        std::cout<<"\n Adjacency list of vertex "<<i<<std::endl<<vexCity[i].cityVexName;
        while (tmpCity){
            std::cout<<" -> "<<vexCity[tmpCity->pos].cityVexName;
            tmpCity = tmpCity->subsquent;
            }
        std::cout<<std::endl;
        }
 }


bool MapCreate:: markVisited( int i)
{
            Visited[i] = true;
   return true;

 }



void MapCreate::unvisitAll( )
{
   for(int i =0; i < citySum; i++)
        Visited[i] = 0;
}



bool MapCreate::isPath( std::string aCity, std::string bCity)
{

	int i=0 ,j =0;
	int topCityNum = 0;
	City * nextCity;
	LinkedQueue aQueue;
	i = PosLocate(aCity);
	j = PosLocate(bCity);
	unvisitAll();
	aQueue.enqueue(i);
	markVisited(i);
        while (!aQueue.isEmpty() && (topCityNum != j)){
                topCityNum = aQueue.peekFront();
		nextCity = vexCity[topCityNum].head;

	while (nextCity!=nullptr)
            {
                if(Visited[nextCity->pos] == false){
                aQueue.enqueue(nextCity->pos);
                markVisited(nextCity->pos);
                }

             else
                nextCity = nextCity->subsquent;
                }
	aQueue.dequeue();
         }
       if (aQueue.isEmpty())
           return aQueue.isEmpty();
       else
          while(!aQueue.isEmpty()){
          topCityNum = aQueue.peekFront();
          flightRoute[flightRouteSum] = topCityNum;
          flightRouteSum++;
          aQueue.dequeue();
         }


}






void MapCreate::Result(std::string aCity, std::string bCity)
{
    int i=0,j=0;

    i= PosLocate(aCity);
    j= PosLocate(bCity);

    std::ofstream outputfile("HPAir.out.txt");

       if(i < 0|| i >= citySum){
            outputfile<< "Request is to fly from "<< aCity<<" to "<<bCity<<". "<<std::endl;
            //outputfile<< "Request is to fly from "<< aCity<<" to "<<bCity<<". "<<std::endl;
            std::cout<< "Sorry. HPAir does not serve "<< aCity<<". "<<std::endl;
            }
        else if(j < 0|| j >= citySum){
            std::cout<< "Request is to fly from "<< aCity<<" to "<<bCity<<". "<<std::endl;
            std::cout<< "Sorry. HPAir does not serve "<< bCity<<". "<<std::endl;
            }
          else if(j >= 0 && j < citySum){
            if(isPath(aCity,bCity)){
                std::cout<< "Request is to fly from "<< aCity<<" to "<<bCity<<". "<<std::endl;

            for(int k =0; k< (flightRouteSum-1); k++){
                std::cout<< "HPAir flies from "<<vexCity[k].cityVexName<<" to "<<vexCity[k+1].cityVexName<<". "<<std::endl;

            }
                }
             else{
                std::cout<< "Request is to fly from "<< aCity<<" to "<<bCity<<". "<<std::endl;
                std::cout<< "Sorry. HPAir does not fly from "<<aCity<<" to "<<bCity<< ". "<<std::endl;
                }

             }


}










