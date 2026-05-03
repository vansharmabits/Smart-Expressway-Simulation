#pragma once
#include "GraphTypes.h"
#include "DSU.h"
#include "BloomFilter.h"
#include "Fenwick.h"

class Expressway {
    int n;
    vector<string> city;
    vector<vector<Edge>> adj;

public:
    bool loadFromFile(string filename);
    void addRoad(string u, string v, int d, int t, int c);

    tuple<int,int,int,int,vector<string>> shortestPath(string, string, char);
    bool hasFuelArbitrage(vector<double>&);
    pair<int, vector<tuple<string,string,int>>> getMST();

    void passVehicle(string, string);
    bool checkVehicleSeen(string);

    int citiesInRange(int L, int R);
    void printAllCities();
};