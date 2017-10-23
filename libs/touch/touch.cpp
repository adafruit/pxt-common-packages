#include "pxt.h"
#include "touch.h"

namespace pxt {
//%
TouchButton getTouchButton(int id) {
    auto cpid = DEVICE_ID_FIRST_TOUCHBUTTON + id;
    auto btn = (CapTouchButton*)lookupComponent(cpid);
    if (btn == NULL) {
        // 'new' will add it to component list
        btn = new CapTouchButton(*pxt::getPin(id));
        btn->id = cpid;
    }
    return btn;
}
}


namespace TouchButtonMethods {

/**
 * Manually define the threshold use to detect a touch event. Any sensed value equal to or greater than this value will be interpreted as a touch.
 * @param name button name
 * @param threshold minimum value to consider a touch eg:200
 */
//% blockId=touch_set_threshold block="button %button|set threshold %threshold"
//% blockNamespace=input
//% name.fieldEditor="gridpicker"
//% name.fieldOptions.width=220
//% name.fieldOptions.columns=4
//% group="More" weight=16 blockGap=8
void setThreshold(TouchButton button, int threshold) {
    button->setThreshold(max(0, min(1023, threshold)));
}

/**
 * Reads the current value registered with the button.
 * @param name button name
 */
//% blockId=touch_value block="button %button|value"
//% blockNamespace=input
//% name.fieldEditor="gridpicker"
//% name.fieldOptions.width=220
//% name.fieldOptions.columns=4
//% group="More" weight=49 blockGap=8
int value(TouchButton button) {
    return button->getValue();
}

}

namespace AnalogPinMethods {
    
/**
 * Get the cap-touch sensor for given pin (if available)
 */
//%
TouchButton touchButton(AnalogPin pin) {
    if (PA02 <= pin->name && pin->name <= PA07)
        ;
    else if (PB02 <= pin->name && pin->name <= PB09)
        ;
    else
        return NULL;
    return pxt::getTouchButton(pin->name);
}

}
