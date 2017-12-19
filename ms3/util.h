#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

void trimSpace(std::string& field);
void csvprint(std::vector<std::vector<std::string>> csvData);
void csvRead(std::string filename, char delim, std::vector< std::vector<std::string> > &csv);
bool validateItem(const std::string& ck);
bool validSequenceNumber(std::string& t);
bool validSlots(std::string& t);
bool validCustomerName(const std::string& t);
bool validProductName(const std::string& t);