//
// Created by John on 4/14/2020.
//

#ifndef A03_PRIORITYQUEUE_JOB_H
#define A03_PRIORITYQUEUE_JOB_H

#include<iostream>
#include <string>
using namespace std;

struct Job
{
    int numLines;
    string jobName;
    int level;
    int key;

    bool operator > (const Job & data) const;
    bool operator <= (const Job & data) const;
    friend ostream & operator << (ostream & out, const Job & data);
};

bool Job :: operator > (const Job & data) const
{
    return (this -> key > data.key);
}

bool Job :: operator <= (const Job & data) const
{
    return (this -> key <= data.key);
}

ostream & operator << (ostream & out, const Job & data)
{
    out << data.level << "\t\t" << data.jobName << "\t" << data.numLines << "\t" << data.key;
    return out;
}

#endif //A03_PRIORITYQUEUE_JOB_H
