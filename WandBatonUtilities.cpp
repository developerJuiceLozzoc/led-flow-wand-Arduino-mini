#include "WandBatonUtilities.h"

// Correct definitions
CRGB ledCluster1[CLUSTER_1_COUNT];  // Ensure this matches the declaration exactly
CRGB ledCluster2[CLUSTER_2_COUNT];

void stateMachineForAnimationStateAndCurrentClicks(
	WandBatonAnimationState* state,
	uint32_t* clicks
) {

}

void inputReceivedIncrementState(
	WandBatonAnimationState* state
) {
	
}

void animatePGS() {
	// Define deep pink and gold color values
	CRGB deepPink = CRGB(255, 20, 147);
	CRGB gold = CRGB(255, 215, 0);
	ledCluster2[0] = deepPink;
	ledCluster2[1] = gold;
	ledCluster2[2] = deepPink;
			// Set colors for Cluster 1 (6 LEDs)
	ledCluster1[0] = deepPink;
	ledCluster1[1] = gold;
	ledCluster1[2] = deepPink;
	ledCluster1[3] = gold;
	ledCluster1[5] = deepPink;
	ledCluster1[4] = gold;
	FastLED.show();
}

void animatePGPP(long clicks) {
	// Define Poison Green and Deep Purple colors
CRGB poisonGreen = CRGB(64, 255, 0);  // Poison Green
CRGB deepPurple = CRGB(75, 0, 130);   // Deep Purple

// Calculate the interpolation factor with a sine wave, mapping it to 0-1
float interpolationFactor = (sin(millis() * 0.003) + 1) / 2.0;

// Interpolate between Poison Green and Deep Purple
CRGB blendedColor = blend(poisonGreen, deepPurple, interpolationFactor * 255);

// Set LED clusters to the interpolated color
fill_solid(ledCluster1, CLUSTER_1_COUNT, blendedColor);
fill_solid(ledCluster2, CLUSTER_2_COUNT, blendedColor);

// Adjust brightness with sine wave (optional if needed for a dimming effect)
uint8_t brightness = (sin(millis() * 0.001) + 1) * 127.5;
FastLED.setBrightness(brightness);

FastLED.show();

}

void animateSCP(long clicks) {

  // Calculate the brightness with a sine wave
  // Multiplying `millis()` by 0.001 controls the fade speed; adjust as needed
  uint8_t brightness = (sin(clicks * 0.003) + 1) * 127.5;


CRGB purple1 = CRGB(128, 0, 128);    // Purple 1
CRGB purple2 = CRGB(75, 0, 130);

fill_solid(ledCluster1, CLUSTER_1_COUNT, purple1);
fill_solid(ledCluster2, CLUSTER_2_COUNT, purple1);

FastLED.setBrightness(brightness);

  FastLED.show();
}

void animateRFSF(long clicks) {

}

void setPurpleColorForIndex(CRGB * color, int index){
	CRGB colors[] = {
		// Purple shades
		CRGB(128, 0, 128),   // Purple
		CRGB(147, 112, 219), // MediumPurple
		CRGB(138, 43, 226),  // BlueViolet
	};
	*color = colors[index];
}

void setPinkColorForIndex(CRGB * color, int index){
	CRGB colors[] = {
		// Pink shades
		CRGB(255, 182, 193), // LightPink
		CRGB(255, 105, 180), // HotPink
		CRGB(255, 20, 147),  // DeepPink

	};
	*color = colors[index];
}

void setGoldColorForIndex(CRGB * color, int index){
  
	CRGB colors[] = {
		// Purple shades
		CRGB(128, 0, 128),   // Purple
		CRGB(147, 112, 219), // MediumPurple
		CRGB(138, 43, 226),  // BlueViolet
	};
	*color = colors[index];
}

void setGreenColorForIndex(CRGB * color, int index){
	CRGB colors[] = {

		// Green shades
		CRGB(0, 255, 0),     // Lime
		CRGB(0, 128, 0),     // Green
		CRGB(34, 139, 34)    // ForestGreen
	};
	*color = colors[index];
}