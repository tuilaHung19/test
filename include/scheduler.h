#ifndef SCHEDULER_H
#define SCHEDULER_H

typedef struct {
    int pid;
    int burst_time;
    int waiting_time;
} Process;

// Hàm bắt buộc sinh viên phải cài đặt đúng tên
void run_round_robin(Process proc[], int n, int quantum);

#endif
