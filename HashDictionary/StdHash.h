#pragma once
#include "Hash.h"
#include <functional>

class StdHash : public Hash
{
	virtual size_t Hasher(const std::string& key) override
	{
		return std::hash<std::string>{}(key) % SIZE;
	}

	virtual bool Find(const std::string& key) override
	{
		size_t index = Hasher(key);
		auto it = m_Bucket.find(index);
		if (it != m_Bucket.end())
		{
			const auto& Chaining = it->second;
			auto vecIt = std::find(Chaining.begin(), Chaining.end(), key);
			if (vecIt != Chaining.end())
			{
				std::cout << "Found in STD Hash table.";
				return true;
			}
		}

		std::cout << "Not found in STD Hash table.";
		return false;
	}
};