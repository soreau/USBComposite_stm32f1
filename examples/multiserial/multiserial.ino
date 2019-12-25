#include <USBComposite.h>

USBMultiSerial ms;

void setup() {
  ms.setNumberOfPorts(2);
  ms.begin();
}

void loop() {
  while(ms.ports[1].available()) {
    ms.ports[0].write(ms.ports[1].read());
  }
  while(ms.ports[0].available()) {
    ms.ports[1].write(ms.ports[0].read());
  } 
}
