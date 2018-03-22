/*
  ==============================================================================

    FlexSliderComponent.h
    Created: 25 Oct 2017 2:43:45pm
    Author:  George Dean

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class FlexSlider    : public Slider, public FlexItem
{
public:
	FlexSlider(String name, int width = 75, int height = 50) :
		Slider(name),
		FlexItem(width, height)
    {
		associatedComponent = this;
    }


    ~FlexSlider()
    {
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FlexSlider)
};
