/*
  ==============================================================================

    EffectButtonContainerComponent.h
    Created: 19 Oct 2017 11:17:41pm
    Author:  George Dean

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "EffectBase.h"

//==============================================================================
/*
*/
class EffectButtonContainerComponent    : public Component, public FlexBox, public ButtonListener, public EffectBase
{
public:
    EffectButtonContainerComponent(int width, int height):
		m_width(width),
		m_height(height)
    {
        // In your constructor, you should add any child components, and
        // initialise any special settings that your component needs.

		// Add buttons
		m_buttonLPF = new EffectButtonComponent(EffectType::LowPassFilter, "LPF");
		m_buttonHPF = new EffectButtonComponent(EffectType::HighPassFilter, "HPF");
		m_buttonDelay = new EffectButtonComponent(EffectType::Delay, "Delay");

		// Make visible
		addAndMakeVisible(m_buttonLPF);
		addAndMakeVisible(m_buttonHPF);
		addAndMakeVisible(m_buttonDelay);

		//Add to flexbox
		items.add(m_buttonLPF->withMargin(3));
		items.add(m_buttonHPF->withMargin(3));
		items.add(m_buttonDelay->withMargin(3));

        // Set up flexbox
	    flexDirection = Direction::row;
	    flexWrap = Wrap::wrap;
	    justifyContent = JustifyContent::center;
	    alignItems = AlignItems::center;
	    alignContent = AlignContent::center;

    }

    ~EffectButtonContainerComponent()
    {
    }

    void paint (Graphics& g) override
    {
        /* This demo code just fills the component's background and
           draws some placeholder text to get you started.

           You should replace everything in this method with your own
           drawing code..
        */

        g.fillAll (Colours::lightslategrey);   // clear the background

        g.setColour (Colours::grey);
        g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

        g.setColour (Colours::white);
        g.setFont (14.0f);
        g.drawText ("EffectButtonContainerComponent", getLocalBounds(),
                    Justification::centred, true);   // draw some placeholder text
    }

    void resized() override
    {
        // This method is where you should set the bounds of any child
        // components that your component contains..

		auto bounds = getLocalBounds();
		performLayout(bounds);

    }

	void buttonClicked(Button* button) override
	{
		//if (button == m_buttonLPF)
		//{
		//	m_buttonLPF->setActive(true);
		//}
		//else if (button == m_buttonHPF)
		//{
		//	m_buttonLPF->setActive(true);
		//}
		//else if (button = m_buttonDelay)
		//{
		//	m_buttonDelay->setActive(true);
		//}
	}

private:
	int m_width, m_height;
	typedef ScopedPointer<EffectButtonComponent> FlexButtonPtr;
	FlexButtonPtr m_buttonLPF, m_buttonHPF, m_buttonDelay;
	EffectType m_currentEffect;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EffectButtonContainerComponent)
};
