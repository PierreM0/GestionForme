#ifndef CLIENT_TCP_H
#define CLIENT_TCP_H
#include "../../Formes/FormeSimple/Cercle.h"
#include "../../Formes/FormeSimple/Polygone.h"
#include "../../Formes/FormeSimple/Segment.h"
#include "../../Formes/FormeSimple/Triangle.h"
#include "../InterfaceGraphique.h"
#include "ClientTCPException.h"

#include <arpa/inet.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits>
#include <netdb.h>
#include <netinet/in.h>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

class ClientTcp : public InterfaceGraphique {
  int sock;
  static ClientTcp *client;

  /**
   * initialise un socket pour l'addresse addr et le port port
   * */
  ClientTcp(const char *addr, short port) {

    int sock;
    int addr_fam = AF_INET;      // IPV4;
    int sock_type = SOCK_STREAM; // TCP connect mode
    int proto = IPPROTO_TCP;
    sock = socket(addr_fam, sock_type, proto);

    if (sock == -1) {
      throw ClientTCPException("Socket invalide");
    }
    cout << "Socket validé !" << endl;

    const char *serv_addr = addr;
    short servport = port;

    sockaddr_in sock_addr;
    sock_addr.sin_family = addr_fam;
    sock_addr.sin_addr.s_addr = inet_addr(serv_addr);
    sock_addr.sin_port = htons(servport);

    int r = connect(sock, (sockaddr *)&sock_addr, sizeof(sockaddr));
    if (r != 0) {
      throw ClientTCPException("Impossible de se connecter");
    }

    cout << "Client connecté!" << endl;

    this->sock = sock;
  }

public:
  /**
   * methode de sigleton pour acceder à l'élément statique
   */
  static ClientTcp getClient() {
    if (client == nullptr) {
      client = new ClientTcp("127.0.0.1", 12345);
    }
    return *client;
  }

  void dessiner(const Segment &forme) const override {
    ostringstream s;
    s << "line;";
    s << forme.a.x << ";" << forme.a.y << ";";
    s << forme.b.x << ";" << forme.b.y << ";";
    s << forme.color.getContent() << "\r\n";

    int r = send(sock, s.str().c_str(), s.str().size(), 0);
    if (r == -1) {
      throw ClientTCPException("Envoit de la requete impossible");
    }
  }
  void dessiner(const Polygone &forme) const override {
    ostringstream s;
    s << "polygon;";
    s << forme.points.size() << ";";
    for (Point2D p : forme.points)
      s << p.x << ";" << p.y << ";";
    s << forme.color.getContent() << ";";
    s << "true\r\n";

    int r = send(sock, s.str().c_str(), s.str().size(), 0);
    if (r == -1) {
      throw ClientTCPException("Envoit de la requete impossible");
    }
  }
  void dessiner(const Cercle &forme) const override {
    ostringstream s;
    s << "circle;";
    s << forme.c.x << ";" << forme.c.y << ";";
    s << forme.rayon << ";";
    s << forme.color.getContent() << ";";
    s << "true\r\n";

    int r = send(sock, s.str().c_str(), s.str().size(), 0);
    if (r == -1) {
      throw ClientTCPException("Envoit de la requete impossible");
    }
  };
  void dessiner(const Triangle &forme) const override {
    ostringstream s;
    s << "polygon;3;";
    s << forme.a.x << ";" << forme.a.y << ";";
    s << forme.b.x << ";" << forme.b.y << ";";
    s << forme.c.x << ";" << forme.c.y << ";";
    s << forme.color.getContent() << ";";
    s << "true\r\n";

    int r = send(sock, s.str().c_str(), s.str().size(), 0);
    if (r == -1) {
      throw ClientTCPException("Envoit de la requete impossible");
    }
  }
  void nettoyer() const override {
    string s = "clear\r\n";
    int r = send(sock, s.c_str(), s.size(), 0);
    if (r == -1) {
      throw ClientTCPException("Envoit de la requete impossible");
    }
  };
  void definirZoneMonde(const Point2D &p1, const Point2D &p2) const override {
    ostringstream s;
    s << "worldzone;" << p1.x << ";" << p1.y << ";" << p2.x << ";" << p2.y
      << "\r\n";

    int r = send(sock, s.str().c_str(), s.str().size(), 0);
    if (r == -1) {
      throw ClientTCPException("Envoit de la requete impossible");
    }
  };

  void fermer() {
      close(sock);
  }
};

#endif // !CLIENT_TCP_H
