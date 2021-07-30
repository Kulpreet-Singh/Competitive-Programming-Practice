#include <iostream>
#include <cstdlib>
#include <vector>

const int size = 10;

struct Job
{
    int deadline;
	int profit;
	int position;
};

void Swap(Job& a, Job& b)
{
	Job temp = a;
	a = b;
	b = temp;
}

int Partition(Job arr[], int first, int last)
{
	int lastnum = arr[last].profit;
	int i = first - 1;

	for (int j = first; j < last; ++j)
	{
		if (arr[j].profit > lastnum)
		{
			i++;
			Swap(arr[i], arr[j]);
		}
	}
	Swap(arr[i + 1], arr[last]);

	return (i + 1);
}

void QuickSort(Job arr[], int first, int last)
{
	if (first < last)
	{
		int piv = Partition(arr, first, last);
		QuickSort(arr, first, piv-1);
		QuickSort(arr, piv + 1, last);
	}
}

void JobScheduling(Job arr[])
{
	bool flag;
	int netProfit = 0;
	std::vector<Job> jobs;
	jobs.push_back(Job());
	jobs[0].deadline = arr[0].deadline;
	jobs[0].profit = arr[0].profit;
	jobs[0].position = arr[0].position;

	netProfit += jobs[0].profit;

	int k = 1;

	for (int i = 1; i < size; ++i)
	{
		flag = true;
		for (int j = i-1; j >= 0; --j)
		{
			if (arr[i].deadline == jobs[j].deadline)
			{
				flag = false;
			}
		}
		if (flag)
		{
			jobs.push_back(Job());
			jobs[k].deadline = arr[i].deadline;
			jobs[k].profit = arr[i].profit;
			jobs[k].position = arr[i].position;
			netProfit += jobs[k].profit;
			++k;
		}
	}

	std::cout << "Net Profit made from jobs after scheduling = " << netProfit << std::endl;
}

int main()
{
    Job arr[size];

    for (int i = 0; i < size; ++i)
    {
        arr[i].deadline = std::rand() % 9 + 1;
        arr[i].profit = std::rand() % 1000;
        arr[i].position = i;
    }

	std::cout<<"deadline \t profit \t position"<<std::endl;
	for (int i = 0; i < size; ++i)
    {
        std::cout<<arr[i].deadline <<"\t\t" << arr[i].profit << "\t\t" <<arr[i].position<<std::endl;
    }
	QuickSort(arr, 0, size - 1);
	std::cout<<"deadline \t profit \t position"<<std::endl;
	for (int i = 0; i < size; ++i)
    {
        std::cout<<arr[i].deadline <<"\t\t" << arr[i].profit << "\t\t" <<arr[i].position<<std::endl;
    }
	JobScheduling(arr);

	return 0;
}
