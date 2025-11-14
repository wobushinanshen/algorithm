#include<bits/stdc++.h>
using namespace std;
int n, m, k;

typedef pair<int, int> PII;
//这里是各种容器及其增删查改的操作
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	//	vector<int>a(5,20);
	//	for(int i:a)cout<<i<<" ";
	//	cout<<endl;
	//	
	//	vector<int>b{1, 2, 3, 4, 5};
	//	
	//	n=m=5;
	//	vector<vector<int>>mt(n,vector<int>(m,3));
	//	for(auto& v:mt)
	//	{
	//		for(auto& i:v)cout<<i<<" ";	
	//		cout<<endl;	
	//	}


	//vector<int>a;
	//n = 5;
	//for (int i = 0; i < n; i++)a.push_back(i);
	//for (int i : a)cout << i << " ";
	//cout << endl;

	//for (int i : a)
	//{
	//	cout << i << " ";
	//	if (i <= 3)a.push_back(10);
	//}
	//cout << endl;

	//a.assign(10, 1);
	//for (int i : a)cout << i << " ";
	//cout << endl;

	//a.resize(15,2);
	//for (int i : a)cout << i << " ";
	//cout << endl;


	//vector<int>v;
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << v.size() << " " << v.capacity() << endl;
	//	v.push_back(i);
	//}
	//v.reserve(20);
	//cout << v.capacity() << endl;

	//vector<int>v(100, 1);
	//v.resize(200, 2);
	//auto it = v.begin();
	//it += 155;
	//cout << *it << endl;
	//auto it = v.rbegin();
	//it += 155;
	//cout << *it << endl;

	//set<int>s;
	//for (int i = 0; i < 100; i++)s.insert(i);
	//auto it1 = s.begin();
	//it1 += 50;


	//stack<int>sta;
	//n = 5;
	//for (int i = 0; i < n; i++)sta.push(i);
	//while (sta.size())
	//{
	//	cout << sta.top() << " ";
	//	sta.pop();
	//}
	//cout << endl;

	//queue<int>q;
	//n = 5;
	//for (int i = 0; i < n; i++)q.push(i);
	//while (q.size())
	//{
	//	cout << q.front() << " ";
	//	q.pop();
	//}
	//cout << endl;


	//deque<int>dq;
	//dq.push_back(15);
	//dq.push_back(10);
	//dq.push_back(17);
	//dq.push_back(23);
	//dq.push_back(101);
	//cout<<dq[3]<<endl;
	//sort(dq.begin(), dq.end());
	//dq.begin();
	//while (dq.size())
	//{
	//	cout << dq.front() << " ";
	//	dq.pop_front();
	//}
	//cout << endl;


	//vector<string>ss;
	//ss.push_back("h");
	//ss.push_back("hh");
	//ss.push_back("chh");
	//ss.push_back("galaxy");
	//ss.push_back("visual");
	//ss.push_back("code");	
	//ss.back() += "forces";

	//sort(ss.begin(), ss.end());
	//for (string& s : ss)cout << s << endl;

	//string s("codeforces");
	//cout << s.substr(0, 4) << endl;

	//cout << s.find('o') << endl;

	//priority_queue<int>pq;
	//pq.push(99);
	//pq.push(13);
	//pq.push(27);
	//pq.push(1);
	//pq.push(105);
	//while (pq.size())
	//{
	//	cout << pq.top() << " ";
	//	pq.pop();
	//}
	//cout << endl;

	
	//struct cmp1 
	//{
	//	bool operator()(const PII& a, const PII& b) const//first小的先出队，first相同则second大的先出队
	//	{
	//		if (a.first == b.first)return a.second < b.second;
	//		return a.first > b.first;
	//	}
	//};
	//priority_queue<PII, vector<PII>, cmp1>pq;
	//auto cmp = [](PII a, PII b)->bool //first小的先出队，first相同则second大的先出队
	//{
	//	if (a.first == b.first)return a.second < b.second;
	//	return a.first > b.first;
	//};
	//priority_queue<PII, vector<PII>, function<bool(PII, PII)>>pq(cmp);
	//pq.push({ 1,3 });
	//pq.push({ 2,5 });
	//pq.push({ 9,6 });
	//pq.push({ 1,30 });
	//pq.push({ 1,5 });
	//while (pq.size())
	//{
	//	auto& [x, y] = pq.top();
	//	cout << x << " " << y << endl;
	//	pq.pop();
	//}

	//map<string, int>mp;
	//mp["hh"] = 3;
	//mp["galaxy"] = 5;
	//mp["gugg"] = 10;
	//mp["aha"] = 0;
	//mp["123"] = 1234;
	//cout << mp["galaxy"] << endl;
	//for (auto& [s, v] : mp)cout << s << " " << v << endl;

	//struct cmp1 
	//{
	//	bool operator()(const PII& a, const PII& b) const//first小的在前，first相同则second大的在前
	//	{
	//		if (a.first == b.first)return a.second > b.second;
	//		return a.first < b.first;
	//	}
	//};
	//set<PII, cmp1>s;

	//auto cmp = [](PII a, PII b)->bool //first小的在前，first相同则second大的在前
	//{
	//	if (a.first == b.first)return a.second > b.second;
	//	return a.first < b.first;
	//};
	//set<PII, function<bool(PII, PII)>>s(cmp);
	//s.insert({ 1,3 });
	//s.insert({ 2,5 });
	//s.insert({ 9,6 });
	//s.insert({ 1,30 });
	//s.insert({ 1,5 });
	//for (auto& [x, y] : s)cout << x << " " << y << endl;

	//auto mn = *s.begin();
	//auto mx = *(--s.end());
	////auto mx = *s.rbegin();
	//cout << mn.first << " " << mn.second << endl;
	//cout << mx.first << " " << mx.second << endl;
	//s.erase(--s.end());

	//vector<int>v{ 3, 1, 4, 1, 5, 9, 2, 6 };
	//nth_element(v.begin(), v.begin() + 3, v.end());
	//for (int i : v)cout << i << " ";
	//cout << endl;
	

	//vector<int>v{ 1,2,3,4,5 };
	//do
	//{
	//	for (int i : v)cout << i << " ";
	//	cout << endl;
	//} while (next_permutation(v.begin(), v.end()));

	//reverse(v.begin(), v.end());
	//for (int i : v)cout << i << " ";
	//cout << endl;


	//vector<PII> v = { {1, 3}, {2, 5}, {1, 5}, {1, 4}, {2, 3}, {3, 1},{2,30 } };
	//auto cmp = [](PII a, PII b)->bool //first小的在前，first相同则second大的在前
	//{
	//	if (a.first == b.first)return a.second > b.second;
	//	return a.first < b.first;
	//};
	//sort(v.begin(), v.end(), cmp);
	//for (auto& [x, y] : v)cout << x << " " << y << endl;
	//PII p = { 2,5 };
	//auto it1 = lower_bound(v.begin(), v.end(), p, cmp);
	//cout << it1->first << " " << it1->second << endl;
	//auto it2 = upper_bound(v.begin(), v.end(), p, cmp);
	//cout << it2->first << " " << it2->second << endl;
	
}