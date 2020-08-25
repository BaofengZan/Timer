#pragma once
#include <chrono>
#define  CPU_ONLY

enum class Mode
{
    CPU = 0,
    GPU = 1,
    NO_GPU = 2
};
namespace Timer {

    class Timer {
    public:
        Timer();
        virtual ~Timer();
        virtual void Start();
        virtual void Stop();
        virtual float MilliSeconds();
        virtual float MicroSeconds();
        virtual float Seconds();

        inline bool initted() { return initted_; }
        inline bool running() { return running_; }
        inline bool has_run_at_least_once() { return has_run_at_least_once_; }

    protected:
        void Init();

        bool initted_;
        bool running_;
        bool has_run_at_least_once_;
#ifndef CPU_ONLY
        cudaEvent_t start_gpu_;
        cudaEvent_t stop_gpu_;
#endif
        std::chrono::time_point<std::chrono::steady_clock> start_cpu_;
        std::chrono::time_point<std::chrono::steady_clock> stop_cpu_;

        float elapsed_milliseconds_;
        float elapsed_microseconds_;
        Mode mode;
    };

    class CPUTimer : public Timer {
    public:
        explicit CPUTimer();
        virtual ~CPUTimer() {}
        virtual void Start();
        virtual void Stop();
        virtual float MilliSeconds();
        virtual float MicroSeconds();
    };

} 

