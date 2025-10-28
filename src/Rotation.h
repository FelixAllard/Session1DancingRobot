//
// Created by xilef on 10/27/2025.
//

#ifndef SESSION1DANCINGROBOT_ROTATION_H
#define SESSION1DANCINGROBOT_ROTATION_H


extern unsigned long timeSincePreviousTick;
extern unsigned long totalTimeBetweenTicks;
extern int numberOfTicksRequired;
extern int numberOfTicksSpent;

extern float rotationDegrees;
extern float currentRotation;

extern float currentAcceleration;
extern bool turningRight;
extern bool finishedMovement;

/// @brief This function is must be called before a movement to make sure it does what we want
/// @param degree How many degrees to turn, either positive for to the right and negative to the left
/// @param ticksRequired How many time do we need to call DoMovementIteration() for the full rotation to be achieved;
/// @author Felix
void InitializeMovement(float degree, int ticksRequired, float speed =0.5f);

/// This tells us if we finished tunrning
/// @return True if we finished turning and false if not
/// @author Felix
bool CheckIfMovementIsFinished();

/// Does one tick of the movment, must be called in a loop
/// @return True if we finished the whole movement
/// @author Felix
bool DoMovementIteration();

///Makes sure everything is reset before continuing, will be called by Initialize movement!
///@author Felix
void ReinitializeMovement();

/// Simple function for testing, might be useful later tho
/// @return Return the average time between the ticks
/// @author Felix
long GetAverageTimeBetweenTicks();
#endif //SESSION1DANCINGROBOT_ROTATION_H