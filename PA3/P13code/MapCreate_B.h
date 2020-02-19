#ifndef MAPCREATE_H
#define MAPCREATE_H

#include<iostream>
#include <string>
#include "LinkedQueue_B.h"


const static int Max=40;

struct VexNode{
     std::string cityVexName;
     City *head;
           };

class MapCreate
{
  public:
        MapCreate();
   	void readCityVex();
   	void readFlightInfo();
        void createMap(std::string &fromCity, std::string &toCity );
        int PosLocate(std::string & aCity);
        void createMapData( );
	void displayMap( );
        void setCitySum(int &citySum);
	int getCitySum( ) const;
        bool markVisited(int i);
        void unvisitAll( );
        void displayFlightMap( );
        int getNextCity(int topCityNum);

        bool isPath( std::string aCity, std::string bCity);
        void Result(std::string aCity, std::string bCity);
private:

	std::pair  <std::string, std::string> flightLine[Max];
	VexNode vexCity[Max];
        int citySum,flightSum;
        int Visited[Max];
        int price[Max];///<added parameter
        int flightnumber[Max];///<added parameter
        int flightRoute[Max];///<added parameter
        int Totalcost;///<added parameter
        int flightRouteSum;///<added parameter
};


#endif // MAPCREATE_H
