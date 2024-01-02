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

		std::cout << "�����Ͱ� �ִ� ��Ŷ ��            : " << DataCount << std::endl;
		std::cout << "�����Ͱ� �ִ� ��Ŷ / �ѹ�Ŷ        : " << (double)DataCount / SIZE << '%' << std::endl;
		std::cout << "�����Ͱ� 2�� �̻��� ��Ŷ ��        : " << DataTwoOver << std::endl;
		std::cout << "�����Ͱ� ���� ���� ��Ŷ�� ���� ���� : " << ChainingMax << std::endl;
		std::cout << "2�� �̻��� ��Ŷ / �����Ͱ� �ִ� ��Ŷ : " << (double)DataTwoOver / DataCount << '%' << std::endl << std::endl;
	}

};