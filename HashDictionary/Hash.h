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
	std::unordered_map<size_t, std::vector<std::string>> m_Bucket;

public:
	virtual ~Hash() {}

	virtual size_t Hasher(const std::string& key) = 0;
	virtual bool Find(const std::string& key) = 0;

	void LoadDictionary(const std::set<std::string>& setAll)
	{
		for (const auto& word : setAll)
		{
			int index = Hasher(word);
			m_Bucket[index].push_back(word);
		}
	}

	void PrintIssue()
	{
		int DataCount = 0;
		int DataTwoOver = 0;
		int ChainingMax = 0;

		for (int i = 0; i < SIZE; i++)
		{
			if (!m_Bucket[i].empty())
			{
				DataCount++;

				if (m_Bucket[i].size() > 1)
				{
					DataTwoOver++;

					if (ChainingMax < m_Bucket[i].size())
					{
						ChainingMax = m_Bucket[i].size();
					}
				}
			}
		}

		std::cout << "데이터가 있는 버킷 수            : " << DataCount << std::endl;
		std::cout << "데이터가 있는 버킷 / 총버킷        : " << (double)DataCount / SIZE << '%' << std::endl;
		std::cout << "데이터가 2개 이상인 버킷 수        : " << DataTwoOver << std::endl;
		std::cout << "데이터가 가장 많은 버킷의 원소 갯수 : " << ChainingMax << std::endl;
		std::cout << "2개 이상인 버킷 / 데이터가 있는 버킷 : " << (double)DataTwoOver / DataCount << '%' << std::endl << std::endl;
	}

};