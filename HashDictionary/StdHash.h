#pragma once
#include "Hash.h"
#include <functional>

class StdHash : public Hash
{
private:
	std::unordered_map<std::string, std::string> m_Bucket;

public:
	virtual size_t Hasher(const std::string& key) override
	{
		return 0;
	}

	virtual void LoadDictionary(const std::set<std::string>& setAll)
	{
		m_Bucket.reserve(SIZE);
		for (const auto& word : setAll)
		{
			m_Bucket.insert({ word, word });
		}
	}

	virtual bool Find(const std::string& key) override
	{
		auto it = m_Bucket.find(key);
		if (it != m_Bucket.end())
		{
			std::cout << "Found in STD Hash table.";
			return true;
		}
		std::cout << "Not found in STD Hash table.";
		return false;
	}

	virtual void PrintIssue() override
	{
		int DataCount = 0;
		int DataTwoOver = 0;
		int ChainingMax = 0;

		for (size_t i = 0; i < m_Bucket.bucket_count(); ++i)
		{
			if (m_Bucket.bucket_size(i) > 0)
			{
				DataCount++;
				if (m_Bucket.bucket_size(i) > 1)
				{
					DataTwoOver++;
					if (ChainingMax < m_Bucket.bucket_size(i))
					{
						ChainingMax = m_Bucket.bucket_size(i);
					}
				}
			}
		}

		std::cout << "stdHash Issue" << std::endl;
		std::cout << "데이터가 있는 버킷 수            : " << DataCount << std::endl;
		std::cout << "데이터가 있는 버킷 / 총버킷        : " << (double)DataCount / m_Bucket.bucket_count() << '%' << std::endl;
		std::cout << "데이터가 2개 이상인 버킷 수        : " << DataTwoOver << std::endl;
		std::cout << "데이터가 가장 많은 버킷의 원소 갯수 : " << ChainingMax << std::endl;
		std::cout << "2개 이상인 버킷 / 데이터가 있는 버킷 : " << (double)DataTwoOver / DataCount << '%' << std::endl << std::endl;
	}
};