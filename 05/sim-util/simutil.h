//
// Created by sanguk on 13/06/2017.
//

#ifndef _SIM_UTIL_
#define _SIM_UTIL_

void insertCutomer(int arrivalTime, int serviceTime, LinkedQueue *pQueue);

void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue);

QueueNode *processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue);

QueueNode *processServiceNodeEnd(int currentTime, QueueNode *pServiceNode,
                                 int *pServiceUserCount, int *pTotalWaitTime);

void printSimCustomer(int currentTime, SimCustomer customer);

void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);

void printReport(LinkedQueue *pWaitQueue,
                 int serviceUserCount,
                 int totalWaitTime);

#endif