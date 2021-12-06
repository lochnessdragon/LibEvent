# LibEvent
A simple and small (header only) event library for c++

## Usage
Simply include the header `LibEvent.h` in your project.

Example:

```
#include <LibEvent.h>
#include <iostream>

struct ConsoleInputEventData {
  std::string input;
}

bool onConsoleEvent(const ConsoleInputEventData& data) {
  std::cout << "You inputed: " << data.input << std::endl;
}

int main() {
  LibEvent::EventDispatcher<ConsoleInputEventData> consoleEvent;
  
  consoleEvent.subscribe(onConsoleEvent);
  
  ConsoleInputEventData eventData;
  
  std::getline(std::cin, eventData.input);
  
  consoleEvent.publish(eventData);
  
  return 0;
}
```
