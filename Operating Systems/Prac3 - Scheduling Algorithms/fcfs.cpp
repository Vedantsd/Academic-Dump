#include <iostream>
using namespace std;

class Process {
    public:
        int pid; 
        int bt;  
        int wt;  
        int tat; 

        Process(int id, int burst) {
            pid = id;
            bt = burst;
            wt = 0;
            tat = 0;
        }
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process* p[100];

    for (int i = 0; i < n; i++) {
        int bt;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> bt;
        p[i] = new Process(i + 1, bt);
    }

    p[0]->wt = 0;

    for (int i = 1; i < n; i++) {
        p[i]->wt = p[i - 1]->wt + p[i - 1]->bt;
    }

    for (int i = 0; i < n; i++) {
        p[i]->tat = p[i]->wt + p[i]->bt;
    }

    cout << "\nProcess\tBT\tWT\tTA\n";
    for (int i = 0; i < n; i++) {
        cout << p[i]->pid << "\t" << p[i]->bt << "\t" << p[i]->wt << "\t" << p[i]->tat << endl;
    }
}