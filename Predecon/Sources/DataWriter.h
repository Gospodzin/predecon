#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "Point.h"
#include <chrono>
#include <map>
#include "Cluster.h"
#include "Subspace.h"

class DataWriter
{
public:
	DataWriter(std::string filePath);
	~DataWriter();
	void write(std::string str);
	static std::string write(std::vector<Point>* data);
	static std::string write(std::vector<Point>* data, std::vector<std::vector<int>>& prefDims);
	static std::string write(const std::map<Subspace, std::vector<Cluster*> >& clustersBySubspace);
	static std::string write(const Subspace& subspace);
	static std::string write(const std::map<CId, int>& sizeByCId);
	static std::string write(const double& duration);
	static std::string write(const std::map<Subspace, std::map<CId, int> >& clusterSizesBySubspace);
	void writeClusterIds(std::vector<Point>* data);
	void writeGraph(std::vector<Point>* data);
private:
	std::ofstream file;
};
