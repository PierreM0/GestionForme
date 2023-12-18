#include "Formes/FormeSimple/Segment.h"
#include <algorithm>
#include <memory>

class SocketClient {
  static SocketClient *instance_;
  SocketClient() {}

public:
  SocketClient *instance() {
    if (instance_ == nullptr)
      instance_ = new SocketClient();
    return instance_;
  };
};

SocketClient *SocketClient::instance_ = nullptr;

int main(int argc, char *argv[]) {}
