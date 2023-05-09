#include "CustomQueue.h"
#include "Job.h"

Define_Module(CustomQueue);

void CustomQueue::handleMessage(cMessage *msg)
{
    PassiveQueue::handleMessage(msg);
    // Job *job = check_and_cast<Job *>(msg);
    // delete msg;
    // job->setTimestamp();

    // // check for container capacity
    // if (capacity >= 0 && queue.getLength() >= capacity)
    // {
    //     EV << "Queue full! Job dropped.\n";
    //     if (queueing::hasGUI())
    //         bubble("Dropped!");
    //     emit(droppedSignal, 1);
    //     delete msg;
    //     return;
    // }

    // int k = selectionStrategy->select();
    // if (k < 0)
    // {
    //     // enqueue if no idle server found
    //     queue.insert(job);
    //     emit(queueLengthSignal, length());
    //     job->setQueueCount(job->getQueueCount() + 1);
    // }
    // else if (length() == 0)
    // {
    //     // send through without queueing
    //     sendJob(job, k);
    // }
    // else
    //     throw cRuntimeError("This should not happen. Queue is NOT empty and there is an IDLE server attached to us.");
}