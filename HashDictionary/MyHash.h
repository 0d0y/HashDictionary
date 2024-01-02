#pragma once
#include "Hash.h"

class MyHash : public Hash
{
	virtual size_t Hasher(const std::string& key) override
	{
		unsigned long long keySum = 0;

		for (int i = 0; i < key.length(); i++)
		{
			int digit = 1;
			for (int j = 0; j < i; j++)
			{
				digit *= 10;
			}
			keySum += (key[i] * digit);
		}

		return ((keySum * 1299821) % SIZE);
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
				std::cout << "Found in My Hash table.";
				return true;
			}
		}

		std::cout << "Not found in My Hash table.";
		return false;
	}

};