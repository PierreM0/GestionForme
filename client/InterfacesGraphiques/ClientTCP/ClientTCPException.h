#ifndef CLIENT_TCP_EXCEPTION_H
#define CLIENT_TCP_EXCEPTION_H

#include <string>
class ClientTCPException {
public:
  std::string val;
  ClientTCPException(std::string val) : val(val) {}
};

#endif // !CLIENT_TCP_EXCEPTION_H
