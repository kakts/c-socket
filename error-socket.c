#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <errno.h>

int main() {
  int sock;

  // 1: address family: AF_INET(IPv4)
  // 2: socket types: SOCK_STREAM(tcp)
  // 3: protocol
  sock = socket(3000, 4000, 0);
  if (sock < 0) {
    perror("socket failed \n");
    printf("%d", errno);
    return 1;
  }

  return 0;
}
