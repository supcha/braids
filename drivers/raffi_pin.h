
// Driver for the debug (timing) pin.

#ifndef BRAIDS_DRIVERS_RAFFI_PIN_H_
#define BRAIDS_DRIVERS_RAFFI_PIN_H_

#include <stm32f10x_conf.h>
#include "stmlib/stmlib.h"

namespace braids {

class RaffiPin {
 public:
  RaffiPin() { }
  ~RaffiPin() { }
  
  void Init();
  void High();
  void Low();
  
 private:
  
  DISALLOW_COPY_AND_ASSIGN(RaffiPin);
};

}  // namespace braids

#endif  // BRAIDS_DRIVERS_RAFFI_PIN_H_
