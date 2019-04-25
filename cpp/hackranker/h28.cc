/*
 * https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};


void levelOrder(Node * root) {
	queue<Node *> stk;
	stk.push(root);
	while (!stk.empty()) {
		Node * n = stk.front();
		stk.pop();
		if (n != nullptr) {
			cout << n->data << " ";
			stk.push(n->left);
			stk.push(n->right);
		}
	}
	cout << endl;
}

//int main() {
//	Node * root = new Node(1);
//	root->right = new Node(2);
//	root->right->right = new Node(5);
//	root->right->right->left = new Node(3);
//	root->right->right->right = new Node(6);
//	root->right->right->left->right = new Node(4);
//	levelOrder(root);
//	return 0;
//}

struct SinglyLinkedListNode{
	int data;
	SinglyLinkedListNode* next;
};

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
	if (head1 == nullptr) {
		return head2;
	}
	if (head2 == nullptr) {
		return head1;
	}
	SinglyLinkedListNode * lst = nullptr;
	SinglyLinkedListNode* h1 = head1;
	SinglyLinkedListNode* h2 = head2;
	if (head1->data < head2->data) {
		lst = head1;
		h1 = head1->next;
	}
	else {
		lst = head2;
		h2 = head2->next;
	}
	SinglyLinkedListNode * cur = lst;
	while (h1 != nullptr && h2 != nullptr) {
		if (h1->data < h2->data) {
			cur->next = h1;
			h1 = h1->next;
		}
		else {
			cur->next = h2;
			h2 = h2->next;
		}
		cur = cur->next;
	}
	if (h1 != nullptr) {
		cur->next = h1;
	}
	else {
		cur->next = h2;
	}
	return lst;
}

int getNode(SinglyLinkedListNode* head, int positionFromTail) {
	int len = 0;
	auto p = head;
	while (p) {
		len += 1;
		p = p->next;
	}
	p = head;
	positionFromTail = len - positionFromTail-1;
	while (positionFromTail--) {
		p = p->next;
	}
	return p->data;
}

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
	auto lst = head;
	auto cur = head;
	while (head) {
		if (head->data != cur->data) {
			cur->next = head;
			cur = cur->next;
		}
		head = head->next;
	}
	cur->next = nullptr;
	return lst;
}

bool has_cycle(SinglyLinkedListNode* head) {
	if (head == nullptr) {
		return false;
	}
	auto p1 = head;
	auto p2 = head->next;
	while (p1 && p2) {
		if (p1 == p2) {
			return true;
		}
		p1 = p1->next;
		p2 = p2->next;
		if (p2 == nullptr) {
			return false;
		}
		p2 = p2->next;
	}
	return false;
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
	auto p1 = head1;
	auto p2 = head2;
	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
		if (p1 == nullptr) {
			p1 = head1;
		}
		if (p2 == nullptr) {
			p2 = head2;
		}
	}
	return p1->data;
}


//For your reference:

struct DoublyLinkedListNode {
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;
};

//
//DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
//	if (head == nullptr) {
//		DoublyLinkedListNode * node = new DoublyLinkedListNode(data);
//		node->data = data;
//		return node;
//	}
//
//	if (head->data >= data) {
//		DoublyLinkedListNode * node = new DoublyLinkedListNode(data);
//		node->next = head;
//		return node;
//	}
//
//	auto p = head;
//	DoublyLinkedListNode*  last = nullptr;
//	while (p) {
//		if (p->data <= data && (p->next == nullptr || p->next->data > data)) {
//			DoublyLinkedListNode * node = new DoublyLinkedListNode(data);
//			node->next = p->next;
//			node->prev = p;
//			p->next = node;
//			if (node->next) {
//				node->next->prev = node;
//			}
//			return head;
//		}
//		p = p->next;
//	}
//	return head;
//}

DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
	auto p = head;
	while (p) {
		auto tmp = p->next;
		p->next = p->prev;
		p->prev = tmp;
		if (tmp == nullptr) {
			return p;
		}
	}
}


string biggerIsGreater(string w) {
	vector<char> vec;
	int i = w.size() - 2;
	for (; i >= 0; i--) {
		vec.push_back(w[i + 1]);
		if (w[i] < w[i + 1]) {
			char c = w[i];
			string res = w.substr(0, i);
			for (int i =0; i < vec.size(); i++) {
				if (vec[i] > c) {
					char tmp = vec[i];
					vec[i] = c;
					c = tmp;
					break;
				}
			}
			res += c;
			for (int i = 0; i <vec.size(); i++) {
				res += vec[i];
			}

			return res;
		}
	}
	return "no answer";
}


int chocolateFeast(int n, int c, int m) {
	int cnt = n / c;
	int w = cnt;
	while (w >= m) {
		cnt += w / m;
		auto k = w / m + w % m;
		w = k;
	}
	return cnt;
}

int workbook(int n, int k, vector<int> arr) {
	int p = 0;
	int cnt = 0;
	for (auto qs : arr) {
		for (int q = 1; q <= qs; q++) {
			if (q == (p + (q + k -1) / k)) {
				cnt += 1;
			}
		}
		p += (qs + k - 1) / k;
	}
	return cnt;
}


int fairRations(vector<int> B) {
	vector<int> idx;
	for (int i = 0; i < B.size(); i++) {
		if (B[i] & 1) {
			idx.push_back(i);
		}
	}
	if (idx.size() & 1) {
		return -1;
	}
	int cnt = 0;
	for (int i = 0; i < idx.size(); i += 2) {
		cnt += (idx[i + 1] - idx[i]) * 2;
	}
	return cnt;
}

string gridSearch(vector<string> G, vector<string> P) {
	int r = 0, c = 0;
	int pr = P.size(), pc = P[0].size();
	while (r < G.size() && c < G[0].size()) {
		int ct = G[r].find(P[0], c);
		if (ct != std::string::npos) {
			c = ct;
			bool isSame = true;
			for (int it = 1; it < P.size(); it++) {
				if (G[r + it].compare(ct, P[it].size(), P[it]) != 0) {
					isSame = false;
					break;
				}
			}
			if (isSame) {
				return "YES";
			}
		}
		else {
			r += 1;
			c = 0;
		}
	}
	return "NO";
}

string happyLadybugs(string b) {
	map<char, int> mp;
	for (int i = 0; i < b.size(); i++) {
		mp[b[i]] += 1;
	}
	for (auto pr : mp) {
		if (pr.second == 1 && pr.first != '_') {
			return "NO";
		}
	}
	if (mp.find('_') == mp.end()) {
		int c = 1;
		for (int i = 1; i < b.size(); i++) {
			if (b[i] == b[i - 1]) {
				c++;
			}
			else {
				if (c == 1) {
					return "NO";
				}
				else {
					c = 1;
				}
			}
		}
		if (c == 1) {
			return "NO";
		}
	}	
	return "YES";
}


struct Plus {
	int i, j;
	int k;
	Plus(int x, int y, int len):i(x),j(y), k(len) {
	}
};

int maxProduct(const Plus & p1, const Plus & p2) {
	if (p1.i == p2.i || p1.j == p2.j) {
		int total = (p1.i == p2.i) ? (p2.j - p1.j - 1): (p2.i - p1.i - 1);
		int p1k = p1.k;
		int p2k = p2.k;
		int mx = 1;
		while (p1k >= 0) {
			p2k = p2.k < (total - p1k) ? p2.k : (total - p1k);
			mx = mx > (4 * p1k + 1) * (4 * p2k + 1) ? mx : (4 * p1k + 1) * (4 * p2k + 1);			
			p1k -= 1;
		}
		return mx;
	}
	int mx = 1;
	int p1x = p1.k;
	while (p1x >= 0) {
		int p2x = p2.k;
		if (p1x > abs(p2.j - p1.j) - 1) {
			p2x = p2x < abs(p2.i - p1.i) - 1 ? p2x : abs(p2.i - p1.i) - 1;
		}
		if (p1x > abs(p2.i - p1.i) - 1) {
			p2x = p2x < abs(p2.j - p1.j) - 1 ? p2x : abs(p2.j - p1.j) - 1;
		}
		mx = mx > (4 * p1x + 1) * (4 * p2x + 1) ? mx : (4 * p1x + 1) * (4 * p2x + 1);
		p1x -= 1;
	}
	return mx;
}

int twoPluses(vector<string> grid) {
	vector<Plus> pls;
	int r = grid.size(), c = grid[0].size();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int k = 0;
			while (  (i - k) >= 0 && (i + k) < r && (j -k)>=0 && (j + k) < c 
				&& grid[i-k][j] == 'G' && grid[i+k][j] == 'G' && grid[i][j-k] == 'G' && grid[i][j+k] == 'G'
				) {
				k++;
			}
			if (k > 0) {
				pls.push_back(Plus(i, j, k - 1));
			}
		}
	}

	int mx = 0;
	for (int i = 0; i < pls.size(); i++) {
		for (int j = i + 1; j < pls.size(); j++) {
			mx = mx > maxProduct(pls[i], pls[j]) ? mx : maxProduct(pls[i], pls[j]);
		}
	}
	return mx;
}

string larrysArray(vector<int> A) {
	long total = 0;
	for (int i = 0; i < A.size(); i++) {
		for (int j = i + 1; j < A.size(); j++) {
			if (A[i] > A[j]) {
				total += 1;
			}
		}
	}
	if (total % 2 == 0) {
		return "YES";
	}
	return "NO";
}

void almostSorted(vector<int> arr) {
	vector<int> idx;
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] < arr[i - 1]) {
			idx.push_back(i);
		}
	}
	if (idx.size() == 0) {
		cout << "yes" << endl;
		return;
	}
	if (idx.size() == 1) {
		int l = idx[0] - 1;
		int r = idx[0];
		if (l - 1 >= 0 && arr[l - 1] > arr[r]) {
			cout << "no" << endl;
			return;
		}
		if (r + 1 < arr.size() && arr[r + 1] < arr[l]) {
			cout << "no" << endl;
			return;
		}
		cout << "yes" << endl;
		cout << "swap " << l + 1 << " " << r + 1 << endl;
		return;
	}

	if (idx.size() == 2) {
		//using swap
		int l = idx[0] - 1;
		int r = idx[1];
		if (l - 1 >= 0 && arr[l - 1] > arr[r]) {
			cout << "no" << endl;
			return;
		}
		if (l + 1 < arr.size() && arr[l + 1] < arr[r]) {
			cout << "no" << endl;
			return;
		}
		if (r - 1 >= 0 && arr[r - 1] > arr[l]) {
			cout << "no" << endl;
			return;
		}
		if (r + 1 < arr.size() && arr[r + 1] < arr[l]) {
			cout << "no" << endl;
			return;
		}
		cout << "yes" << endl;
		cout << "swap " << l+1 << " " << r + 1 << endl;
		return;
	}

	//using reverse
	int t = idx[0];
	for (int j = 1; j < idx.size(); j++) {
		if (idx[j] != t + 1) {
			cout << "no" << endl;
			return;
		}
		t += 1;
	}
	int l = idx[0] - 1;
	int r = idx[idx.size() - 1];
	if (l - 1 >= 0 && arr[r] < arr[l - 1]) {
		cout << "no" << endl;
		return;
	}
	if (r + 1 < arr.size() && arr[l] > arr[r + 1]) {
		cout << "no" << endl;
		return;
	}
	cout << "yes" << endl;
	cout << "reverse " << l + 1 << " " << r + 1 << endl;
}


vector<string> bigSorting(vector<string> unsorted) {

	std::sort(unsorted.begin(), unsorted.end(), []( string  s1,  string s2) {
	if (s1.size() == s2.size()) {
			return s1.compare(s2) < 0;
	}
		return s1.size() < s2.size();
	});
	return unsorted;
}

void insertionSort1(int n, vector<int> arr) {
	auto printVector = [](const vector<int> & vec) {
		for (auto k : vec) {
			std::cout << k << " ";
		}
		std::cout << endl;
	};

	int value = arr[arr.size() - 1];
	int j = arr.size() - 2;
	for (; j >= 0; j--) {
		if (arr[j] > value) {
			arr[j + 1] = arr[j];
			printVector(arr);
		}
		else {
			break;
		}
	}
	arr[j + 1] = value;
	printVector(arr);
}


void insertionSort2(int n, vector<int> arr) {
	auto printVector = [](const vector<int> & vec) {
		for (auto k : vec) {
			std::cout << k << " ";
		}
		std::cout << endl;
	};

	for (int j = 1; j < arr.size(); j++) {
		int idx = j - 1;
		int value = arr[j];
		for (; idx >= 0; idx--) {
			if (arr[idx] > value) {
				arr[idx + 1] = arr[idx];
			}
			else {
				break;
			}
		}
		
		arr[idx + 1] = value;
		printVector(arr);
		
	}
}


void insertionSort(int N, int arr[]) {
	int i, j;
	int value;
	for (i = 1; i < N; i++)
	{
		value = arr[i];
		j = i - 1;
		while (j >= 0 && value < arr[j])
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = value;
	}
	for (j = 0; j < N; j++)
	{
		printf("%d", arr[j]);
		printf(" ");
	}
}


int runningTime(vector<int> arr) {
	int i, j;
	int value;
	int cnt = 0;
	for (i = 1; i < arr.size(); i++)
	{
		value = arr[i];
		j = i - 1;
		while (j >= 0 && value < arr[j])
		{
			cnt += 1;
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		if (arr[j + 1] != value) {
			arr[j + 1] = value;
		}
	}
	return cnt;
}

string superReducedString(string s) {
	if (s.size() == 0) {
		return "Empty String";
	}
	int idx = -1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1]) {
			idx = i;
			break;
		}
	}
	if (idx != -1) {
		return superReducedString(
			s.substr(0, idx - 1) + (idx + 1 < s.size() ? s.substr(idx + 1, s.size() - idx - 1) : "")
		);
	}
	return s;
}


int minimumNumber(int n, string password) {
	// Return the minimum number of characters to make the password strong
	std::string numbers = "0123456789";
	std::string lower_case = "abcdefghijklmnopqrstuvwxyz";
	std::string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string special_characters = "!@#$%^&*()-+";
	auto p = [](const std::string & str) {
		std::set<char> st;
		for (auto c : str) {
			st.insert(c);
		}
		return st;
	};
	auto sn = p(numbers);
	auto sl = p(lower_case);
	auto su = p(upper_case);
	auto ss = p(special_characters);
	bool bn = false;
	bool bl = false;
	bool bu = false;
	bool bs = false;
	for (auto k : password) {
		if (sn.count(k) > 0) {
			bn = true;
		}
		else if (sl.count(k) > 0) {
			bl = true;
		}
		else if (su.count(k) > 0) {
			bu = true;
		}
		else if (ss.count(k) > 0) {
			bs = true;
		}
	}

	int cnt = 0;
	if (!bn) {
		cnt += 1;
	}
	if (!bl) {
		cnt += 1;
	}
	if (!bu) {
		cnt += 1;
	}
	if (!bs) {
		cnt += 1;
	}
	if (password.size() >= 6) {
		return cnt;
	}
	return cnt > (6 - password.size()) ? cnt : (6 - password.size());
}

int alternate(string s) {
	int mx = 0;
	std::set<char> processed;
	for (int i = 0; i < s.size() -1; i++) {
		char F = s[i];
		if (processed.count(F) > 0) {
			continue;
		}
		std::set<char> sec;
		for (int j = i + 1; j < s.size(); j++) {
			if (s[j] == s[i]) {
				processed.insert(s[j]);
				break;
			}
			if (processed.count(s[j]) > 0) {
				continue;
			};
			if (sec.count(s[j]) > 0) {
				continue;
			}
			char S = s[j];
			int cnt = 2;
			bool invalid = false;
			for (int k = j + 1; k < s.size(); k++) {
				if (s[k] == F) {
					if (cnt % 2 == 0) {
						cnt += 1;
					}
					else {
						invalid = true;
						break;
					}
				}
				if (s[k] == S) {
					if (cnt % 2 == 1) {
						cnt += 1;
					}
					else {
						invalid = true;
						break;
					}
				}
			}
			if (!invalid) {
				mx = mx > cnt ? mx : cnt;
			}
			sec.insert(s[j]);
		}
		processed.insert(F);
	}
	return mx;
}

string caesarCipher(string s, int k) {
	string res = "";
	for (auto c : s) {
		if (c >= 'a' && c <= 'z') 
			c = (c - 'a' + k) % 26 + 'a';
		if (c >= 'A' && c <= 'Z')
			c = (c - 'A' + k) % 26 + 'A';
		res += c;
	}
	return res;
}

vector<string> weightedUniformStrings(string s, vector<int> queries) {
	std::set<int> ws;
	int w = 0;
	for (int i = 1; i < s.size(); i++) {
		if (i == 0) {
			w = s[0] - 'a' + 1;
			ws.insert(w);
		}
		else {
			if (s[i] != s[i - 1]) {
				w = 0;
			}
			w += s[i] - 'a' + 1;
			ws.insert(w);
		}
	}
	vector<string> vec;
	for (auto k : queries) {
		if (ws.count(k) > 0) {
			vec.push_back("Yes");
		}
		else {
			vec.push_back("No");
		}
	}
	return vec;
}

int gemstones(vector<string> arr) {
	vector<bool> res(26, true);
	for (auto str : arr) {
		vector<bool> tmp(26,false);
		for (auto c : str) {
			tmp[c - 'a'] = true;
		}
		for (int i = 0; i < 26; i++) {
			res[i] = res[i] && tmp[i];
		}
	}
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (res[i]) {
			cnt += 1;
		}
	}
	return cnt;
}

int beautifulBinaryString(string b) {
	map<std::string, int> mp;
	for (auto p : mp) {
		
	}


	int cnt = 0;
	int idx = b.find("010", 0);
	while (idx != -1) {
		cnt += 1;
		idx = b.find("010", idx + 3);
	}
	return cnt;
}

std::string next(const std::string & str) {
	std::string s = str;
	bool carrier = false;
	int i = str.size() - 1;
	while (i >= 0 && s[i] == '9') {
		s[i] = '0';
		i--;
	}
	if (i == -1) {
		s = "1" + s;
	}
	else {
		s[i] = s[i] + 1;
	}
	return s;
}
void separateNumbers(string s) {
	for (int i = 1; i <= s.size() / 2; i++) {
		int idx = i;
		auto initStr = s.substr(0, i);
		if (initStr.size() > 1 && initStr[0] == '0') {
			continue;
		}
		auto nxt = next(initStr);
		int isEqual = 0;
		while (idx < s.size()) {
			isEqual = s.substr(idx, nxt.size()).compare(nxt);
			if (isEqual != 0) {
				break;
			}
			idx += nxt.size();
			nxt = next(nxt);
		}
		if (idx == s.size()) {
			printf("YES %s\n", initStr.data());
			return;
		}
	}
	printf("NO\n");
}



int main_h28() {

	std::cout << gemstones({ 
		"abcdde",
		"baccd",
		"eeabg", }) 
		<< std::endl;
	weightedUniformStrings("abccddde", { 6 });
	alternate("tlymrvjcylhqifsqtyyzfaugtibkkghfhyzxqbsizkjguqlqwwetyofqihtpkmpdlgthfybfhhmjerjdkybwppwrdapirukcshkpngayrdruanjtziknnwxmsjpnuswllymhkmztsrcwwzmlbcoakswwffveobbvzinkhnmvwqhpfednhsuzmffaebi");

	std::cout << superReducedString("baab") << std::endl;


	vector<int> vint = {
		 2,1,3,1,2
	};
	runningTime(vint);

	vector<string> vec = {
"BBGBGGGGGBBGGBB",
"BBGBGGGGGBBGGBB",
"GGGGGGGGGGGGGGG",
"GGGGGGGGGGGGGGG",
"BBGBGGGGGBBGGBB",
"BBGBGGGGGBBGGBB",
"BBGBGGGGGBBGGBB",
"GGGGGGGGGGGGGGG",
"BBGBGGGGGBBGGBB",
"BBGBGGGGGBBGGBB",
"BBGBGGGGGBBGGBB",
"BBGBGGGGGBBGGBB",
"BBGBGGGGGBBGGBB",
"BBGBGGGGGBBGGBB",
"GGGGGGGGGGGGGGG",
	};

	int k = twoPluses(vec);
	std::cout << k << std::endl;

	return 0;
}


