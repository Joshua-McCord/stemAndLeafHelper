// stemAndLeafHelper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>

void print_vector(std::map<int,std::vector<int>> arg);
void calculate_data(std::vector<int> data);

int main()
{   
    
    std::map<int,std::vector<int>> plot;
    std::string input = "";
    std::vector<int> data;
    std::cout << "Hello! Please enter your numbers seperated by spaces > ";
    std::getline(std::cin, input, '\n');
    for (size_t i = 0; i < input.size(); i++)
    {
        std::string temp = "";
        size_t j = i;
        while (input[j] != ' ' && j < input.size())
        {
            temp.append(std::string(1, input[j]));
            j++;
        }
        i = j;
        int currNum = stoi(temp);
        data.push_back(currNum);
        int roundedNum = (currNum / 10) * 10;
        plot[roundedNum/10].push_back(currNum % 10);
    }
    print_vector(plot);
    calculate_data(data);
    return 1;
}

void print_vector(std::map<int, std::vector<int>> arg)
{   
    std::vector<int>::iterator value;
    for (std::map<int, std::vector<int>>::iterator it = arg.begin(); it != arg.end(); ++it)
    {
            std::cout << it->first << "\t";
            for (value = it->second.begin(); value != it->second.end(); value++)
            {
                if (value == std::prev(it->second.end()))
                {
                    std::cout << *value;
                }
                else
                {
                    std::cout << *value << ", ";
                }
            }
            std::cout << "\n";
    }
}
void calculate_data(std::vector<int> data)
{
    int sum = 0;
    for (std::vector<int>::iterator it = data.begin(); it != data.end; it++)
    {
        sum += *it;
    }
    float mean = sum / data.size();
}

