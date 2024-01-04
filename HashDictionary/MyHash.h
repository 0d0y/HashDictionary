#pragma once
#include "Hash.h"
#include <array>
#include <list>

class MyHash : public Hash
{
private:
	std::array<std::list<std::string>, SIZE> m_Bucket;

public:
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

	virtual void LoadDictionary(const std::set<std::string>& setAll) override
	{
		for (const auto& word : setAll)
		{
			size_t index = Hasher(word);
			m_Bucket[index].push_back(word);
		}
	}

	virtual bool Find(const std::string& key) override
	{
		size_t index = Hasher(key);
		const auto& list = m_Bucket[index];
		const auto& listIt = std::find(list.begin(), list.end(), key);

		if (listIt != list.end())
		{
			std::cout << "Found in My Hash table.";
			return true;
		}

		std::cout << "Not found in My Hash table.";
		return false;

		//size_t index = Hasher(key);
		//const auto& list = m_Bucket[index];

		//for (const auto& node : list)
		//{
		//	if (node == key)
		//	{
		//		std::cout << "Found in My Hash table.";
		//		return true;
		//	}
		//}

		//std::cout << "Not found in My Hash table.";
		//return false;
	}

	virtual void PrintIssue() override
	{
		int DataCount = 0;
		int DataTwoOver = 0;
		int ChaningMax = 0;
		for (int i = 0; i < SIZE; i++)
		{
			if (m_Bucket[i].size() != 0)
			{
				DataCount++;
				if (m_Bucket[i].size() > 1)
				{
					DataTwoOver++;
					if (ChaningMax < m_Bucket[i].size())
					{
						ChaningMax = m_Bucket[i].size();
					}
				}
			}
		}

		std::cout << "myHash Issue" << std::endl;
		std::cout << "데이터가 있는 버킷 수			: " << DataCount << std::endl;
		std::cout << "데이터가 있는 버킷 / 총버킷		: " << (double)DataCount / SIZE << '%' << std::endl;
		std::cout << "데이터가 2개 이상인 버킷 수		: " << DataTwoOver << std::endl;
		std::cout << "데이터가 가장 많은 버킷의 원소 갯수	: " << ChaningMax << std::endl;
		std::cout << "2개 이상인 버킷 / 데이터가 있는 버킷	: " << (double)DataTwoOver / DataCount << '%' << std::endl << std::endl;
	}

};