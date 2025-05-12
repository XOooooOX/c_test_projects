//#include <winsock2.h>
//#include <ws2tcpip.h>
//#include <windows.h>
////#include <openssl/ssl.h>
////#include <openssl/err.h>
//#include <stdio.h>
//
//#pragma comment(lib, "ws2_32.lib") // فقط برای MSVC
//
//int main4() {
//    WSADATA wsa;
//    WSAStartup(MAKEWORD(2, 2), &wsa);
//
//    // 1. آدرس IP سرور (یا از getaddrinfo استفاده کن)
//    const char *hostname = "www.google.com";
//    const int port = 443;
//
//    struct hostent *host = gethostbyname(hostname);
//    if (!host) {
//        printf("خطا در یافتن آدرس IP\n");
//        return 1;
//    }
//
//    struct sockaddr_in server_addr = {0};
//    server_addr.sin_family = AF_INET;
//    server_addr.sin_port = htons(port);
//    server_addr.sin_addr = *(struct in_addr*)host->h_addr;
//
//    // 2. ساخت سوکت TCP
//    int sock = socket(AF_INET, SOCK_STREAM, 0);
//    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
//        printf("خطا در اتصال TCP\n");
//        return 1;
//    }
//
//    // 3. راه‌اندازی OpenSSL
//    SSL_load_error_strings();
//    OpenSSL_add_ssl_algorithms();
//
//    const SSL_METHOD *method = TLS_client_method();
//    SSL_CTX *ctx = SSL_CTX_new(method);
//    if (!ctx) {
//        printf("خطا در ساخت context\n");
//        return 1;
//    }
//
//    SSL *ssl = SSL_new(ctx);
//    SSL_set_fd(ssl, sock);
//
//    if (SSL_connect(ssl) <= 0) {
//        printf("خطا در handshake TLS\n");
//        ERR_print_errors_fp(stderr);
//        return 1;
//    }
//
//    // 4. ارسال درخواست HTTPS
//    const char *request = "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n";
//    SSL_write(ssl, request, strlen(request));
//
//    // 5. دریافت پاسخ
//    char buffer[4096];
//    int bytes;
//    while ((bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1)) > 0) {
//        buffer[bytes] = '\0';
//        printf("%s", buffer);
//    }
//
//    // 6. پاک‌سازی
//    SSL_free(ssl);
//    closesocket(sock);
//    SSL_CTX_free(ctx);
//    EVP_cleanup();
//    WSACleanup();
//
//    return 0;
//}