#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// 何回でもコネクション受付可能バージョン
int main() {
  int sock0;
  // TODO check about sockaddr_in struct
  struct sockaddr_in addr;
  struct sockaddr_in client;
  unsigned int len;
  int sock;
  int count = 0;
  char countStr[10];
  // create socket
  sock0 = socket(AF_INET, SOCK_STREAM, 0);

  // add socket settings
  addr.sin_family = AF_INET;
  addr.sin_port = htons(12345);
  addr.sin_addr.s_addr = INADDR_ANY;

  bind(sock0, (struct sockaddr *)&addr, sizeof(addr));
  // Make status waiting for connection
  listen(sock0, 5);
  printf("listen start");
  while (1) {
    char str1[10] = "hello";
    count++;
    // convert int to string
    sprintf(countStr, "%d", count);
    printf("connection. %d", count);
    // accept client connection
    len = sizeof(client);
    sock = accept(sock0, (struct sockaddr *)&client, &len);
    // send 5 chars
    write(sock, countStr, 5);
    // close tcp session
    close(sock);
  }

  // close listening socket
  close(sock0);
  return 0;
}
