//
// Created by M.Ghelichkhani on 5/18/2025.
//

// exit_codes.h

#ifndef EXIT_CODES_H
#define EXIT_CODES_H

typedef enum {
    EXIT_OK                      = 0,    // اجرای موفقیت‌آمیز
    EXIT_GENERAL_ERROR           = 1,    // خطای کلی
    EXIT_MISUSE_BUILTIN          = 2,    // استفاده نادرست از built-in ها

    EXIT_CANNOT_EXECUTE          = 126,  // فایل اجرا شدنی نیست (Permission Denied)
    EXIT_COMMAND_NOT_FOUND       = 127,  // دستور وجود ندارد
    EXIT_INVALID_EXIT_ARG        = 128,  // مقدار نامعتبر برای exit()

    // سیگنال‌ها: 128 + شماره سیگنال
    EXIT_SIGNAL_HUP              = 129,  // SIGHUP - Hangup
    EXIT_SIGNAL_INT              = 130,  // SIGINT - Ctrl+C
    EXIT_SIGNAL_QUIT             = 131,  // SIGQUIT - Ctrl+\
    EXIT_SIGNAL_ILL              = 132,  // SIGILL - Illegal instruction
    EXIT_SIGNAL_TRAP             = 133,  // SIGTRAP
    EXIT_SIGNAL_ABORT            = 134,  // SIGABRT
    EXIT_SIGNAL_BUS              = 135,  // SIGBUS - حافظه نادرست
    EXIT_SIGNAL_FPE              = 136,  // SIGFPE - تقسیم بر صفر و...
    EXIT_SIGNAL_KILL             = 137,  // SIGKILL - kill -9
    EXIT_SIGNAL_USR1             = 138,  // SIGUSR1
    EXIT_SIGNAL_SEGV             = 139,  // SIGSEGV - segmentation fault
    EXIT_SIGNAL_USR2             = 140,  // SIGUSR2
    EXIT_SIGNAL_PIPE             = 141,  // SIGPIPE
    EXIT_SIGNAL_ALRM             = 142,  // SIGALRM - تایمر
    EXIT_SIGNAL_TERM             = 143,  // SIGTERM - پایان طبیعی

    EXIT_UNKNOWN                 = 255   // رزرو شده برای خطاهای نامشخص
} ExitCode;

#endif // EXIT_CODES_H
