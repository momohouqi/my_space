#ifndef LIB_COROUTINE
#define LIB_COROUTINE
#include <string>
#include <vector>
#include <ucontext.h>

struct FuncUnit {
    typedef std::string (*Func)(std::string);

    FuncUnit() {
        const int Stack_Size = 8196;
        m_stack = new char[Stack_Size]();
        getcontext(&m_ctx);
        m_ctx.uc_stack.ss_sp = m_stack;
        m_ctx.uc_stack.ss_size = Stack_Size;
        m_ctx.uc_link = &m_ctx;
    }
    ~FuncUnit() {
        delete [] m_stack;
    }

    char *m_stack;
    ucontext_t m_ctx;
    Func m_fun;
    std::vector<std::string> m_args;
};

/*
class Coroutine {
    public:
        Coroutine() {}
        void add_fun1(FuncUnit fun) {}
        void run() {
            for (std::vector<Func>::iterator it = m_funcs.begin(); it != m_funcs.end(); ++it) {
                it->run()
            }
        }
    private:
        std::vector<Func> m_funcs;
};
*/

#endif // LIB_COROUTINE
