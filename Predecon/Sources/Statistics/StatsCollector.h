#pragma once
#include "Clustering/Point.h"

class StatsCollector
{
public:
	StatsCollector();
	~StatsCollector();
	void collect(std::vector<Point>& data);
	std::vector<int> stats;
	void write(std::string fileName, double time);
};
