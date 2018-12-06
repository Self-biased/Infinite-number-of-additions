#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<int> num_one, num_two;
	vector<char> char_one,char_two;
	string number;

	//num_one赋值
	cin >> number;
	for (auto temp : number)
		char_one.push_back(temp); //基于for的范围循环，push——back函数将字符串每个字符赋值数组

	auto char_count = char_one.size();//获取数组长度

	//num_two赋值
	cin >> number;
	for (auto temp : number)
		char_two.push_back(temp); //基于for的范围循环，push——back函数将字符串每个字符赋值数组

	char_count = char_one.size() > char_two.size() ? char_one.size() : char_two.size();//获取数组长度

	//正式赋值
	for (int i = 0; i < char_count; i++)
	{
		num_one.push_back(0);//循环赋值为0
		num_two.push_back(0);
	}

	for (int i = 0; char_one.size() > i; i++)//因为字符转数字会多49，我们便把插入数字数组的元素-48
		num_one[char_count - i - 1] += char_one[char_one.size() - i - 1] - 48;

	for (int i = 0; char_two.size() > i; i++)
		num_two[char_count - i - 1] += char_two[char_two.size() - i - 1] - 48;
	//至此，复制完毕，下面开始运算

	auto number_max = num_one.size() > num_two.size() ? num_one.size() : num_two.size(); //返回长度长的数值

	vector<int> result(number_max + 1, 0);

	for (int i = 1; i < number_max + 1; i++) //循环赋值
	{
		auto temp = number_max - i;
		result[temp] += num_one[temp] + num_two[temp];
		if (result[i - 1] >= 10)
		{
			result[i - 1] - 10;
			result[i] + 1;
		}
	}

	//打印结果
	if (result[0] != 0)
		cout << result[0];
	for (int i = 1; i < number_max; i++)
		cout << result[i];
	cout << endl;

	system("pause");
}
