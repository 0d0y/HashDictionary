#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <set>

class Hash
{
protected:
	static const int SIZE = 195000;

public:
	virtual ~Hash() {}

	virtual size_t Hasher(const std::string& key) = 0;
	virtual bool Find(const std::string& key) = 0;
	virtual void LoadDictionary(const std::set<std::string>& setAll) = 0;
	virtual void PrintIssue() = 0;
};