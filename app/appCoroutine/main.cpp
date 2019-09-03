#include <iostream>
#include "../../lib/coroutine/Coroutine.h"
#include <cstdio>
#include <ucontext.h>

using namespace std;

static ucontext_t g_ctx[3];
int g_product_sn = 0;
int g_available_num = 0;
static int MAX_PRODUCT = 10;
int coroutine_index = 0;

void yield_cpu() {
    //int other_coroutine_index = random();
    //swapcontext(&g_ctx[coroutine_index], &g_ctx[other_coroutine_index]);

}

void coroutine_sleep() {
}

static void consume() {
    while (true) {
        //coroutine_sleep = 1;
        --g_available_num;
        cout << "=====consume:" << g_product_sn << std::endl;
        if (g_product_sn > MAX_PRODUCT) {
            return;
        }
        swapcontext(&g_ctx[1], &g_ctx[2]);
    }
}

static void produce() {
    while (true) {
        //coroutine_sleep = 2;
        ++g_product_sn;
        ++g_available_num;

        cout << "=====produce new:" << g_product_sn << std::endl;
        swapcontext(&g_ctx[2], &g_ctx[1]);
    }
}


int main(int argc, char* argv[]) {
    cout << "=====app begin" << std::endl;
    char stack1[8192]; getcontext(&g_ctx[1]);
    g_ctx[1].uc_stack.ss_sp = stack1;
    g_ctx[1].uc_stack.ss_size = sizeof(stack1);
    g_ctx[1].uc_link = &g_ctx[0];
    makecontext(&g_ctx[1], consume, 0);

    char stack2[8192];
    getcontext(&g_ctx[2]);
    g_ctx[2].uc_stack.ss_sp = stack2;
    g_ctx[2].uc_stack.ss_size = sizeof(stack2);
    g_ctx[2].uc_link = &g_ctx[1];
    makecontext(&g_ctx[2], produce, 0);

    //for (int i = 0; i < MAX_PRODUCT; ++i)
        swapcontext(&g_ctx[0], &g_ctx[2]);
    cout << "=====app end" << std::endl;
    return 0;
}
