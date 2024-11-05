#ifndef MY_HELPER_H
#define MY_HELPER_H
#include <stdint.h>  // for uint32_t and other fixed-width integer types
#include <math.h>
#include <FastLED.h>

#define CLUSTER_1_COUNT 6
#define CLUSTER_2_COUNT 3
#define PI 3.14159265358979323846

extern CRGB ledCluster1[CLUSTER_1_COUNT];        // Create an array of LEDs
extern CRGB ledCluster2[CLUSTER_2_COUNT];        // Create an array of LEDs

enum class WandBatonAnimationState {
    None, 
    SinColorPurple,
    RapidFlashSlowFade,
    PurpleGreenPingPong,
    PinkAndGoldSexy
};

void stateMachineForAnimationStateAndCurrentClicks(
	WandBatonAnimationState* state,
	uint32_t* clicks
);

void inputReceivedIncrementState(
	WandBatonAnimationState* state
);


void animatePGS();

void animatePGPP(long clicks);
void animateSCP(long clicks);
void animateRFSF(long clicks);



/*
If there are X colors, thatn we shall pass a color by reference and set it to the value locationed at colors[index], assumiong index < X
*/
void setPurpleColorForIndex(uint16_t * color, int index);
void setPinkColorForIndex(uint16_t * color, int index);
void setGoldColorForIndex(uint16_t * color, int index);
void setGreenColorForIndex(uint16_t * color, int index);



#endif
