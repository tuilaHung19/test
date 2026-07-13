#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "../include/scheduler.h"

int main() {
    int n = 3;
    Process proc[3] = {{1, 24, 0}, {2, 3, 0}, {3, 3, 0}};
    
    // Đo thời gian chạy bằng clock()
    clock_t start = clock();
    run_round_robin(proc, n, 4);
    clock_t end = clock();
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000; // Đổi sang ms

    // Test thử xem kết quả logic có đúng không
    int passed = (proc[0].waiting_time == 6 && proc[1].waiting_time == 4) ? 1 : 0;

    // Ghi kết quả thô ra file result.json
    FILE *f = fopen("result.json", "w");
    if (f == NULL) return 1;
    
    fprintf(f, "{\n");
    fprintf(f, "  \"group_name\": \"Group_VGU_MOCK\",\n");
    fprintf(f, "  \"status\": \"%s\",\n", passed ? "PASSED" : "FAILED");
    fprintf(f, "  \"execution_time_ms\": %.2f,\n", time_taken);
    fprintf(f, "  \"memory_leak_bytes\": 0\n"); // Bạn có thể parse từ Valgrind sau
    fprintf(f, "}\n");
    fclose(f);

    return 0;
}
