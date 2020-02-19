#include "MapCreate.h"
#include "LinkedStack.h"
#include <iostream>
#include <fstream>
#include <string>

///Initialize Data via Ctor.
 MapCreate::MapCreate()
 {
     citySum = 0;
     flightSum = 0;
 }

///Set the citySum.
void MapCreate::setCitySum(int &citySum)
{
 	this->citySum = citySum;
}

///get the citySum.
int MapCreate::getCitySum( ) const
{
    return citySum;
}

/// Read Vex city from file.
void MapCreate::readCityVex( )
{
    std::string cityname;///< declare cityname
    std::ifstream cityNameFile;
    cityNameFile.open("cityFile.txt");///< open file
    while(getline(cityNameFile,cityname)){
        vexCity[citySum].cityVexName = cityname;///< assignment cityname to vexcity array
        vexCity[citySum].head = nullptr;
	citySum++;
    }
	setCitySum(citySum);///<assignment final cityname.
}
/// Read egde city from file.
void MapCreate::readFlightInfo( )
{
    std::string originCity, destinationCity;
    std::string str;
    std::ifstream flightInfoFile;
    flightInfoFile.open("flightFile.txt");
    while(getline(flightInfoFile, str))///< read file each line one time.
        {
           originCity = str.substr(0,(str.find(',')));///<find the position and get substr
           destinationCity = (str.substr((str.find(',')+2)));///< the others is second city name.
           flightLine[flightSum] = std::make_pair(originCity, destinationCity);///< make two cities into a pair.
	flightSum++;
    }

}




///locate the position according the name of city.
int MapCreate::PosLocate(std::string & aCity)
{ 
    for(int i = 0 ; i < citySum ; i++)
        if(vexCity[i].cityVexName == aCity)
        return i;
}


void MapCreate::createMap(std::string &fromCity, std::string &toCity)

{
   int i ,j;
   City *aCity = new City();
   i = PosLocate(fromCity);///< the position of fromcity is i.
   j = PosLocate(toCity);///< the position of fromcity is j.
   aCity -> pos = j;
   aCity -> subsquent = vexCity[i].head;
   vexCity[i].head = aCity;///< get the city name based on position.
}

///create map with data.
void MapCreate::createMapData( )
{
    for(int i = 0; i< flightSum; i++)
    {
        createMap(flightLine[i].first, flightLine[i].second);
    }
}

///display map with adjacency list type.
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

///mark the visited city, if the city was visited, Visited[] return true.
bool MapCreate:: markVisited( int i)
{
            Visited[i] = true;
   return true;

 }


///Initialize the status if visit: all of cities are not visited.
void MapCreate::unvisitAll( )
{
   std::ofstream flog("HPAir.log.txt",std::ofstream::out |std::ofstream::app);
   for(int i =0; i < citySum; i++)
        Visited[i] = 0;
flog<<"unvisitAll() is called."<<std::endl;
flog.close();
}

///get the next city of top city.
int MapCreate::getNextCity(int topCityNum )
{
    std::ofstream flog("HPAir.log.txt",std::ofstream::out |std::ofstream::app);
   

    	City * nextCity;
      	int nextCityNum =-1 ; ///initial next city does not exsit.
     	 nextCity = vexCity[topCityNum].head;
       if(nextCity != nullptr){
             while(Visited[nextCity->pos]== true )///while next city was visited.
             {
               nextCity = nextCity->subsquent; ///< go to the next city.
               if(nextCity==nullptr) return -1;
               }
                nextCityNum = nextCity->pos;
flog<<"getNextCity() is called.  "<< "nextCityNum: "<<nextCityNum<<std::endl;
flog.close();
         }
           return  nextCityNum;///< return the position of next city.
 flog.close();
}

/// Search the destination city.
bool MapCreate::isPath( std::string aCity, std::string bCity)
{
 std::ofstream flog("HPAir.log.txt",std::ofstream::out |std::ofstream::app);

	int i=0 ,j =0 ;
	int topCityNum = 0, nextCityNum =0;
	i = PosLocate(aCity);
	j = PosLocate(bCity);
	LinkedStack aStack;
	unvisitAll();
	aStack.push(i);
	markVisited(i);
	topCityNum = aStack.peek();///< topcity num is the top of stack.
flog<<"isPath() is called.  "<< "topCityNum: "<<topCityNum<<std::endl;
        while (!aStack.isEmpty() && (topCityNum != j)){
            nextCityNum = getNextCity(topCityNum);
            if (nextCityNum ==-1){ aStack.pop();}
            else{
                aStack.push(nextCityNum);
                markVisited(nextCityNum);
            }
        if (!aStack.isEmpty())
        topCityNum = aStack.peek();

    }
flog.close();
    return !aStack.isEmpty();

}


void MapCreate::Result(std::string aCity, std::string bCity)
{
    int i=0,j=0;

    i= PosLocate(aCity);
    j= PosLocate(bCity);

       if(i < 0|| i >= citySum){
            std::cout<< "Request is to fly from "<< aCity<<" to "<<bCity<<". "<<std::endl;
            std::cout<< "Sorry. HPAir does not serve "<< aCity<<". "<<std::endl;
            }
        else if(j < 0|| j >= citySum){
            std::cout<< "Request is to fly from "<< aCity<<" to "<<bCity<<". "<<std::endl;
            std::cout<< "Sorry. HPAir does not serve "<< bCity<<". "<<std::endl;
            }
          else if(j >= 0 && j < citySum){
            if(isPath(aCity,bCity)){
                std::cout<< "Request is to fly from "<< aCity<<" to "<<bCity<<". "<<std::endl;
                std::cout<< "HPAir flies from "<<aCity<<" to "<<bCity<<". "<<std::endl;
                }
             else{
                std::cout<< "Request is to fly from "<< aCity<<" to "<<bCity<<". "<<std::endl;
                std::cout<< "Sorry. HPAir does not fly from "<<aCity<<" to "<<bCity<< ". "<<std::endl;
                }

             }
}


