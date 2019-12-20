//对于一个排好序的线性表，计算不重复数的数目
#include<iostream>
#include<vector>

class SolutionOne
{
	//要求是相邻的都不能重复
public:
	int RemoveDuplicates(std::vector<int>& nums)
	{
		if (nums.empty())
			return 0;
		int index = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] != nums[index - 1])
				nums[index++] = nums[i];
		}
		return index;
	}
};

class SolutionTwo
{
	//要求可以有两个重复数
public:
	int RemoveDuplicatesTwo(std::vector<int>& nums)
	{
		if (nums.size() <= 2)
			return nums.size();
		int index = 2;
		for (int i = 2; i < nums.size(); i++)
		{
			if (nums[i] != nums[index - 2])
				nums[index++] = nums[i];
		}
		return index;
	}
};

void main()
{
	int a[6] = { 1,2,2,3,3,4 };
	std::vector<int> nums;
	nums.insert(nums.begin(), a, a+7);
	SolutionOne sol;
	std::cout << sol.RemoveDuplicates(nums) << std::endl;
	std::cout << a[0] << std::endl;

	int b[8] = { 1,1,1,2,3,4,4,4 };
	std::vector<int> numsTwo;
	numsTwo.insert(numsTwo.begin(), b, b + 9);
	SolutionTwo solTwo;
	std::cout << solTwo.RemoveDuplicatesTwo(numsTwo) << std::endl;
}