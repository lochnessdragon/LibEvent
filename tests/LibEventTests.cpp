#include <iostream>
#include <string>
#include <LibEvent.h>

struct EventData {
  int x;
  std::string y;
  float z;
};

int LibEventPublishTest() {
  LibEvent::EventDispatcher<EventData> testDispatcher;

  std::string str2 = "";
  int x2 = 0;
  float z2 = 0;

  testDispatcher.subscribe([&str2, &x2, &z2](const EventData& data) {
    str2 = data.y;
    x2 = data.x;
    z2 = data.z;
    return true;
  });

  EventData eventData;
  eventData.x = 452;
  eventData.y = "Hello World!";
  eventData.z = 12.34f;

  testDispatcher.dispatch(eventData);

  int status = 0;

  if(x2 != eventData.x) {
    std::cout << "eventData.x != x2, test failed" << std::endl;
    status = 1;
  }
  if (str2 != eventData.y) {
    std::cout << "eventData.y != str2, test failed" << std::endl;
    status = 1;
  }
  if (z2 != eventData.z) {
    std::cout << "eventData.z != z2, test failed: eventData.z: " << eventData.z << " z2: " << z2 << std::endl;
    status = 1;
  }

  return status;
}

int main() {
  int status = LibEventPublishTest();

  if(status != 0) {
    std::cout << "Tests failed!" << std::endl;
  } else {
    std::cout << "Tests passed!" << std::endl;
  }

  return status;
}