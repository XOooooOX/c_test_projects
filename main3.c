//
// Created by M.Ghelichkhani on 5/12/2025.
//

// kar ba socket

#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main3() {
    system("chcp 65001");

    WSADATA wsa;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("WSAStartup failed: %d\n", WSAGetLastError());
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        puts("خطا در ایجاد سوکت");
        WSACleanup();
        return 1;
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("142.250.180.14"); // آدرس IP برای google.com
    server.sin_family = AF_INET;
    server.sin_port = htons(80); // پورت HTTP

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        puts("خطا در اتصال");
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    char *request = "GET / HTTP/1.1\r\nHost: google.com\r\nConnection: close\r\n\r\n";
    if (send(sock, request, strlen(request), 0) < 0) {
        puts("خطا در ارسال درخواست");
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    char buffer[10000];
    int bytes_received;
    while ((bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}