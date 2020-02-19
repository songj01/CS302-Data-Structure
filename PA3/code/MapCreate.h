/**
@file MapCreate.h
@author Song Jiang
@date Mar 4,2018
*/



#ifndef MAPCREATE_H
#define MAPCREATE_H

#include<iostream>
#include <string>
#include "LinkedStack.h"
#include <fstream>


const static int Max=40;

///Create Vexode struct

struct VexNode{
     std::string cityVexName; ///< the name of city
     City *head; ///< head pointer
           };


/** 1st,read information about Vexties and egde ciyies from files;
  * 2nd, Create the graghic model via adjacency list;
  * 3rd, Create graphic by inputting data;
  * 4th, Search the flight from origin city to destination city by DFS.
  * 5th, Check and print the search result.
  */
class MapCreate
{
  public:
        /// Ctor function
        MapCreate();
	///Read City information from file as Vex.
   	void readCityVex(); 
	///Read flight information from file as Edge.
   	void readFlightInfo();
	///Create Graghic via adjacency list.
        void createMap(std::string &fromCity, std::string &toCity );
	///Compute the position of city in Vex array.
        int PosLocate(std::string & aCity);
	///Input vex and edge information to create graghic.
        void createMapData( );
	///Display graghic by adjacnency list.
	void displayMap( );
        ///Set the sum of cities.
        void setCitySum(int &citySum);
        ///Get the sum of cities.
	int getCitySum( ) const;
        ///Mark the visitied cities.
        bool markVisited(int i);
        ///Initialize the visit status of cities.
        void unvisitAll( );
        ///Get next city which will be visited.
        int getNextCity(int topCityNum);
        ///Travsal and search the map and check if the destination can will found. 
        bool isPath( std::string aCity, std::string bCity);
        ///Display the search result.
        void Result(std::string aCity, std::string bCity);
private:

	std::pair  <std::string, std::string> flightLine[Max]; ///< Declare the flightiLine.
	VexNode vexCity[Max]; ///< Declare the vex City array.
        int citySum,flightSum; ///< Declare the citySum, fLIGHTSum.
        int Visited[Max]; ///Declare the vistied cities array.
};


#endif // MAPCREATE_H
