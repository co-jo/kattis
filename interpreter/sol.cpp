#include <iostream>
#include <vector>
#include <cmath>

#define magic 1000

using namespace std;

int execute (int index, vector<int> &memory, vector<int> &registers) {

    int instruction = memory[index];

    int op = instruction/100;
    int reg = (instruction % 100)/10;
    int arg = (instruction % 10);

    if (op == 1) return -1;
    else if (op == 2) registers[reg] = arg;
    else if (op == 3) registers[reg] = (registers[reg] + arg) % magic;
    else if (op == 4) registers[reg] = (registers[reg] * arg) % magic;
    else if (op == 5) registers[reg] = registers[arg];
    else if (op == 6) registers[reg] = (registers[reg] + registers[arg]) % magic;
    else if (op == 7) registers[reg] = (registers[reg]* registers[arg]) % magic;
    else if (op == 8) registers[reg] = memory[registers[arg]];
    else if (op == 9) memory[registers[arg]] = registers[reg];
    else if (op == 0 && registers[arg]) return registers[reg];

    return index + 1;
}

int main() {

    vector<int> memory(1000, 0);
    vector<int> registers(10, 0);

    int value, operations = 0, instruction = 0;
    for (int i = 0; cin >> value; i++) {
        memory[i] = value;
    }

    do {
        instruction = execute(instruction, memory, registers);
        operations += 1;
    } while(instruction != -1);

    cout << operations << endl;

    return 0;
}
