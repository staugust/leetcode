/* 
 * string match problem
 * https://www.hackerrank.com/challenges/determining-dna-health/problem
 */

#include <string>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;


using namespace std;
#include <string>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

vector<string> split_string(string);
class ACNode
{
public:
	int val;
	char data;
	bool is_ending_char;   // 是否结束字符
	int length;            // 当前节点为结束字符时记录模式串长度
	ACNode *fail;          // 失败指针
	ACNode *children[26];  // 字符集只包含 a-z 这 26 个字符

	ACNode(char ch)
	{
		val = 0;
		data = ch;
		is_ending_char = false;
		length = -1;
		fail = NULL;
		for (int i = 0; i < 26; i++)
			children[i] = NULL;
	}
};

class AC
{
private:

	ACNode *root;

public:

	// 构造函数，根节点存储无意义字符 '/'
	AC()
	{
		root = new ACNode('/');
	}

	// 向 Trie 树中添加一个字符串
	void insert_string(const string & str, int val)
	{
		ACNode *cur = root;
		for (unsigned int i = 0; i < str.size(); i++)
		{
			int index = int(str[i] - 'a');
			if (cur->children[index] == NULL)
			{
				ACNode *temp = new ACNode(str[i]);
				cur->children[index] = temp;
			}
			cur = cur->children[index];
		}
		cur->is_ending_char = true;
		cur->length = str.size();
		cur->val += val;
	}

	// 构建失败指针
	void build_failure_pointer()
	{
		queue<ACNode *> AC_queue;
		AC_queue.push(root);

		while (!AC_queue.empty())
		{
			ACNode *p = AC_queue.front();
			AC_queue.pop();
			for (int i = 0; i < 26; i++)
			{
				ACNode *pc = p->children[i];

				if (pc == NULL) continue;
				if (p == root) pc->fail = root;
				else
				{
					ACNode *q = p->fail;
					while (q != NULL)
					{
						ACNode *qc = q->children[pc->data - 'a'];
						if (qc != NULL)
						{
							pc->fail = qc;
							break;
						}
						q = q->fail;
					}

					if (q == NULL) pc->fail = root;
				}
				AC_queue.push(pc);
			}
		}
	}

	// 在 AC 自动机中匹配字符串
	void match_string(const std::string & str, uint64_t & total)
	{
		ACNode *p = root;
		for (unsigned int i = 0; i < str.size(); i++)
		{
			int index = int(str[i] - 'a');
			while (p->children[index] == NULL && p != root)
			{
				p = p->fail;
			}
			p = p->children[index];

			if (p == NULL) p = root; // 没有可匹配的，从根节点开始重新匹配
			ACNode *temp = p;
			while (temp != root)
			{
				if (temp->is_ending_char == true)
				{
					total += temp->val;
				}
				temp = temp->fail;
			}
		}
	}
};



int main_dna()
{
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string genes_temp_temp;
	getline(cin, genes_temp_temp);

	vector<string> genes_temp = split_string(genes_temp_temp);

	vector<string> genes(n);

	for (int i = 0; i < n; i++) {
		string genes_item = genes_temp[i];

		genes[i] = genes_item;
	}

	string health_temp_temp;
	getline(cin, health_temp_temp);

	vector<string> health_temp = split_string(health_temp_temp);

	vector<int> health(n);

	for (int i = 0; i < n; i++) {
		int health_item = stoi(health_temp[i]);

		health[i] = health_item;
	}

	int s;
	cin >> s;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	uint64_t mn = 0x3f3f3f3f3f3f3f3fULL;
	uint64_t mx = 0;

	for (int s_itr = 0; s_itr < s; s_itr++) {
		string firstLastd_temp;
		getline(cin, firstLastd_temp);

		vector<string> firstLastd = split_string(firstLastd_temp);

		int first = stoi(firstLastd[0]);

		int last = stoi(firstLastd[1]);

		string d = firstLastd[2];
		std::map<string, int> mp;
		AC test;
		for (int i = first; i <= last; i++) {
			test.insert_string(genes[i], health[i]);
		}
		test.build_failure_pointer();
		unsigned long long th = 0;
		test.match_string(d, th);
		mx = mx > th ? mx : th;
		mn = mn > th ? th : mn;
	}

	printf("%llu %llu\n", mn, mx);

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
