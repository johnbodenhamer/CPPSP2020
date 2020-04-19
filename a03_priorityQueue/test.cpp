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
    PriorityQueue<Job> pq(15);

    Job jobArr[SIZE];
    int i = 0;
    bool done = false;
    ifstream fileIn;

    string cStr;

    fileIn.open(jobsFile);
    cout << "------------------------------------------------------------\n"
         << "Records in the array prior to placing in the Priority Queue:\n"
         << "------------------------------------------------------------\n"
         << "Index\tLevel\tName\tLines\tKey" << endl;

    do
    {
      getline(fileIn, cStr, ',');
      if(!fileIn)
      {
        done = true;
        break;
      }
      j.numLines = stoi(cStr);
      getline(fileIn, cStr, '\r');
      j.jobName = cStr;
      j.level = getPriorityLevel(j.numLines);
      j.key = (100000 * j.level) - j.numLines;
      jobArr[i] = j;
      cout << i << "\t\t" << jobArr[i] << endl;
      i++;
    }
    while (!done);

    fileIn.close();
    PriorityQueue<Job> priorityQueue(jobArr, SIZE);

    cout << "------------------------------------------------------------\n"
         << "The Jobs Priority Queue:\n"
         << "------------------------------------------------------------\n"
         << "Level\tName\tLines\tKey" << endl;

    while(priorityQueue.dequeue(j))
    {
        cout << j;
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
    else if (lines >= 10001 && lines <= 500000)
    {
        priorityLevel = 10;
    } else
    {
        priorityLevel = 1;
    }

    return priorityLevel;
}
