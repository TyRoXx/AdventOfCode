#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cassert>

using Machine = std::vector<int>;

Machine buildMachine(const std::string &input)
{
    std::istringstream iss(input);
    Machine machine;
    for (;;)
    {
        int cell;
        iss >> cell;
        if (!iss)
        {
            break;
        }
        char seperator;
        iss >> seperator;
        assert(seperator == ',');
        machine.emplace_back(cell);
    }

    return machine;
}

void run(Machine &machine)
{
    int instructionPointer = 0;
    for (;;)
    {
        int opCode = machine[instructionPointer];
        if (opCode == 99)
        {
            return;
        }
        int operatorOne = machine[instructionPointer + 1];
        int operatorTwo = machine[instructionPointer + 2];
        int target = machine[instructionPointer + 3];

        switch (opCode)
        {
        case 1:
            machine[target] = machine[operatorOne] + machine[operatorTwo];
            break;
        case 2:
            machine[target] = machine[operatorOne] * machine[operatorTwo];
            break;
        }
        instructionPointer += 4;
    }
}

void solve(const std::string &input)
{
    for (size_t t = 0; t < 99; t++)
        for (size_t j = 0; j < 99; j++)
        {
            Machine machine = buildMachine(input);
            machine[1] = t;
            machine[2] = j;
            run(machine);
            if (machine[0] == 19690720)
            {
                std::cout << t << "," << j;
            }
        }
}

int main()
{
    solve("1,12,2,3,1,1,2,3,1,3,4,3,1,5,0,3,2,1,10,19,1,6,19,23,1,10,23,27,2,27,13,31,1,31,6,35,2,6,35,39,1,39,5,43,1,6,43,47,2,6,47,51,1,51,5,55,2,55,9,59,1,6,59,63,1,9,63,67,1,67,10,71,2,9,71,75,1,6,75,79,1,5,79,83,2,83,10,87,1,87,5,91,1,91,9,95,1,6,95,99,2,99,10,103,1,103,5,107,2,107,6,111,1,111,5,115,1,9,115,119,2,119,10,123,1,6,123,127,2,13,127,131,1,131,6,135,1,135,10,139,1,13,139,143,1,143,13,147,1,5,147,151,1,151,2,155,1,155,5,0,99,2,0,14,0");
}