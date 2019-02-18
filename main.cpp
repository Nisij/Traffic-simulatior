#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
    pid_t pid;
    vector <string> old_plate;
    vector <string> old_direction;
    vector <int> old_time;
    
    vector <string> new_plate;
    vector <string> new_direction;
    vector <int> new_time;
    
    int max, count;
    string p, dir, direction;
    int t;
