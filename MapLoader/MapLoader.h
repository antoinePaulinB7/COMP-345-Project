#pragma once

#include "../Map/Map.h"
#include <fstream>

using namespace std;

struct MapLoader 
{


	MapLoader();
	MapLoader(const MapLoader&);
	~MapLoader();
	MapLoader& operator=(const MapLoader&);
	friend ostream& operator<<(std::ostream& strm, MapLoader& mapLoader);

	shared_ptr<Map> createMap(string fileName, string pathToDirectory = "");
};