

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
    string p, dir, direction, initial_direction;
    int t;
    
//INPUT FOR FIRST 2 LINES ----------------------------------------------------------
    cin >> direction;
    cin >> max;
    initial_direction = direction;

//Pushesh all input from the file to the vector "old"------------------------------------------------------
    while(cin >> p >> dir >> t){
        old_plate.push_back(p);
        old_direction.push_back(dir);
        old_time.push_back(t);
    }
    
    
//sorts the direction into order with respect to max car and direction -------------------------
//Copies from old to new vector in order --------------------------
    while (!old_direction.empty())
    {
        count = 0;
        for (int i=0 ; i<old_direction.size(); i++)
        {
            if(count == max)
            {
                break;
            }else if(old_direction[i] == direction)
            {
                new_plate.push_back(old_plate[i]);
                new_direction.push_back(old_direction[i]);
                new_time.push_back(old_time[i]);
                
                old_plate.erase(old_plate.begin()+i);
                old_direction.erase(old_direction.begin()+i);
                old_time.erase(old_time.begin()+i);
                
                count ++;
                i--;
                }
        }
        
        if(direction == "N"){
            direction = "E";
        }else if(direction == "E"){
            direction = "S";
        }else if(direction == "S"){
            direction = "W";
        }else {
            direction = "N";
        }
    }
    

    for (int i=0; i<new_direction.size() ; i++)
    {
         if(i == 0 || (initial_direction != new_direction[i]))
        {
            if(new_direction[i] == "E"){
                cout << "Current direction: Eastbound" << endl;
                initial_direction = new_direction[i];
            }else if(new_direction[i] == "N"){
                cout << "Current direction: Northbound" << endl;
                initial_direction = new_direction[i];
            }else if(new_direction[i] == "S"){
                cout << "Current direction: Southbound" << endl;
                initial_direction = new_direction[i];
            }else if (new_direction[i] == "W"){
                cout << "Current direction: Westbound" << endl;
                initial_direction = new_direction[i];
            }
        }

        if((pid = fork())==0)
        {
            if(new_direction[i] == "E"){
                cout << "Car " << new_plate[i] << " is using the intersection for " << new_time[i] << " sec(s)." << endl;
            }else if(new_direction[i] == "N"){
                cout << "Car " << new_plate[i] << " is using the intersection for " << new_time[i] << " sec(s)." << endl;
            }else if(new_direction[i] == "S"){
                cout << "Car " << new_plate[i] << " is using the intersection for " << new_time[i] << " sec(s)." << endl;
            }else if (new_direction[i] == "W"){
                cout << "Car " << new_plate[i] << " is using the intersection for " << new_time[i] << " sec(s)." << endl;
            }

            sleep(new_time[i]);
            
            break;
        }else{
            for( int j=0 ; j<new_direction.size() ; j++){
                wait(NULL);
            }
        }
    }
    return 0;
}






