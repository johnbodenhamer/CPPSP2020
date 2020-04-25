#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#include "PriorityQueue.h"
#include "Job.h"

const int SIZE = 15;
int getPriorityLevel(int lines);
int main() {
    string jobsFile = "Jobs.csv";
    string printActivity = "PrintActivity.csv";
    Job j;
    char action;
    PriorityQueue<Job> pq1(15);
    Job jobArr[SIZE];
    int i = 0;
    ifstream fileIn;
    string cStr;

    fileIn.open(jobsFile);
    cout << "------------------------------------------------------------\n"
         << "Records in the array prior to placing in the Priority Queue:\n"
         << "------------------------------------------------------------\n"
         << "Index\tLevel\tName\tLines\tKey" << endl;

    while(getline(fileIn, cStr, ','))
    {
        j.numLines = stoi(cStr);
        getline(fileIn, cStr, '\n');
        j.jobName = cStr.substr(0, cStr.length() -1);
        j.level = getPriorityLevel(j.numLines);
        j.key = (100000 * j.level) - j.numLines;
        jobArr[i] = j;
        cout << i << "\t\t" << jobArr[i] << endl;
        pq1.enqueue(jobArr[i]);
        i++;
    }

    fileIn.close();
    PriorityQueue<Job> pq2(jobArr, i);
    PriorityQueue<Job> pq3(pq2);

    cout << "------------------------------------------------------------\n"
         << "The Jobs Priority Queue:\n"
         << "------------------------------------------------------------\n"
         << "Level\tName\tLines\tKey" << endl;

    while(pq1.dequeue(j))
    {
        cout << j << endl;
    }

    fileIn.open(printActivity);


    cout << "------------------------------------------------------------\n"
         << "Records processed from the print activity file:\n"
         << "------------------------------------------------------------\n"
         << "Action\tLevel\tName\tLines\tKey" << endl;

    while(getline(fileIn, cStr, ','))
    {
        action = cStr[0];
        getline(fileIn, cStr, ',');
        j.numLines = stoi(cStr);
        getline(fileIn, cStr, '\n');
        j.jobName = cStr.substr(0, cStr.length() -1);

        if(action == 'E')
        {
            j.level = getPriorityLevel(j.numLines);
            j.key = (100000 * j.level) - j.numLines;
            pq2.enqueue(j);
            cout << "Enqueue\t";
        } else
        {
            pq2.dequeue(j);
            cout << "Dequeue\t";
        }
        cout << j << endl;
    }


    fileIn.close();

    cout << "------------------------------------------------------------\n"
         << "The Jobs Priority Queue:\n"
         << "------------------------------------------------------------\n"
         << "Level\tName\tLines\tKey" << endl;

    while(pq2.dequeue(j))
    {
        cout << j << endl;
    }

    cout << "------------------------------------------------------------\n"
         << "The copy constructor PQ:\n"
         << "------------------------------------------------------------\n"
         << "Level\tName\tLines\tKey" << endl;

    while(pq3.dequeue(j))
    {
        cout << j << endl;
    }


    return 0;
}

int getPriorityLevel(int lines)
{
    int priorityLevel = 0;

    if (lines >= 0 && lines <= 10000)
    {
        priorityLevel = 15;
    }
    else if (lines >= 10001 && lines <= 50000)
    {
        priorityLevel = 10;
    } else
    {
        priorityLevel = 1;
    }

    return priorityLevel;
}