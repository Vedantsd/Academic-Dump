// Code for round robin (RR) scheduling algorithm in C++

#include <iostream>
using namespace std;

class Process {
    public:
        int pid; 
        int bt;  
        int wt; 
        int arrival; 
        int tat; 
        int rt;  

        Process(int id, int burst, int arrivalTime) {
            pid = id;
            bt = burst;
            wt = 0;
            arrival = arrivalTime;
            tat = 0;
            rt = burst;
        }
};

int main() {
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;

    Process* p[100];

    for (int i = 0; i < n; i++) {
        int bt, arrival;
        cout << "Enter burst time and arrival time for process " << i + 1 << ": ";
        cin >> bt >> arrival;
        p[i] = new Process(i + 1, bt, arrival);
    }

    cout << "Enter time quantum: ";
    cin >> quantum;

    int t = 0; 
    bool done;

    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (p[i]->rt > 0) {
                done = false; 
                if (p[i]->rt > quantum) {
                    t += quantum;
                    p[i]->rt -= quantum;
                } else {
                    t += p[i]->rt;
                    p[i]->wt = t - p[i]->bt - p[i]->arrival;
                    p[i]->rt = 0;
                }
            }
        }
    } while (!done);

    for (int i = 0; i < n; i++) {
        p[i]->tat = p[i]->bt + p[i]->wt;
    }

    cout << "\nProcess\tBT\tAT\tWT\tTA\n";
    for (int i = 0; i < n; i++) {
        cout << p[i]->pid << "\t" << p[i]->bt << "\t" << p[i]->arrival << "\t" << p[i]->wt << "\t" << p[i]->tat << endl;
    }
}