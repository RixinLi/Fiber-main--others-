#ifndef __FIBER__H__
#define __FIBER__H__

#include <memory>
#include <ucontext.h>
#include <functional>

class Fiber{

public:
    typedef std::shared_ptr<Fiber> ptr;

    enum State{
        INIT, // 初始化
        HOLD, // 后台暂停
        EXEC, // 执行中
        TERM, // 结束
        READY, // 可执行
        EXECPT // 异常
    }



private:
    uint64_t m_id; // 协程ID
    ucontext_t m_ctx; // 协程上下文保存结构
    void* m_stack; // 协程的栈大小，这里打算使用虚拟内存分配
    uint32_t m_stackSize;
    State m_state;
    std::function<void()> m_cb; 
}

class FiberScheduler{

}



#endif