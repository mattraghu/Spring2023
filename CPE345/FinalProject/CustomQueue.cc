#include "CustomQueue.h"
#include "Job.h"

Define_Module(CustomQueue);

void CustomQueue::handleMessage(cMessage *msg)
{
    queueing::Job *job = check_and_cast<queueing::Job *>(msg);
    job->setTimestamp();

    // omnetpp::cPacket *encapsulatedMsg = job->getEncapsulatedPacket();

    // Get the difficulty parameter from the job message
    double jobDifficulty = job->par("difficulty");

    // check for container capacity
    if (capacity >= 0 && queue.getLength() >= capacity)
    {
        EV << "Queue full! Job dropped.\n";
        if (hasGUI())
            bubble("Dropped!");
        emit(droppedSignal, 1);
        delete msg;
        return;
    }

    int k = selectionStrategy->select();
    bool priorityEffected = par("priorityEffected");
    if (k < 0 || !queue.isEmpty())
    {
        // Prioritize job based on its difficulty
        if (priorityEffected && queue.front() != nullptr)
        {
            // Get the difficulty of the first job in the queue
            double topJobDifficulty = check_and_cast<queueing::Job *>(queue.front())->par("difficulty");

            // If the incoming job has higher difficulty, add it to the front of the queue
            if (jobDifficulty > topJobDifficulty)
            {
                queue.insertBefore(queue.front(), job);
                emit(queueLengthSignal, length());
                job->setQueueCount(job->getQueueCount() + 1);
                return;
            }
        }

        // Otherwise, add the job to the end of the queue
        queue.insert(job);
        emit(queueLengthSignal, length());
        job->setQueueCount(job->getQueueCount() + 1);
    }
    else
    {
        EV << "Sending job `" << job->getName() << "' to server[" << k << "]\n";
        // Just send it
        sendJob(job, k);
    }
}

// void CustomQueue::handleMessage(cMessage *msg)
// {
//     // PassiveQueue::handleMessage(msg);
//     queueing::Job *job = check_and_cast<queueing::Job *>(msg);
//     job->setTimestamp();

//     // check for container capacity
//     if (capacity >= 0 && queue.getLength() >= capacity)
//     {
//         EV << "Queue full! Job dropped.\n";
//         if (hasGUI())
//             bubble("Dropped!");
//         emit(droppedSignal, 1);
//         delete msg;
//         return;
//     }

//     int k = selectionStrategy->select();
//     if (k < 0)
//     {
//         // enqueue if no idle server found
//         queue.insert(job);
//         emit(queueLengthSignal, length());
//         job->setQueueCount(job->getQueueCount() + 1);
//     }
//     else if (length() == 0)
//     {
//         // send through without queueing
//         sendJob(job, k);
//     }
//     else
//         throw cRuntimeError("This should not happen. Queue is NOT empty and there is an IDLE server attached to us.");
// }