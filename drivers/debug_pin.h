
// Driver for the debug (timing) pin.

#ifndef BRAIDS_DRIVERS_DEBUG_PIN_H_
#define BRAIDS_DRIVERS_DEBUG_PIN_H_

#include <stm32f10x_conf.h>
#include "stmlib/stmlib.h"

namespace braids {

class DebugPin {
 public:
  DebugPin() { }
  ~DebugPin() { }
  
  void Init();
  void High();
  void Low();
  
 private:
  
  DISALLOW_COPY_AND_ASSIGN(DebugPin);
};

}  // namespace braids

#endif  // BRAIDS_DRIVERS_DEBUG_PIN_H_
