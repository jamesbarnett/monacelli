#ifndef TENTH_FRAME_HXX__
#define TENTH_FRAME_HXX__

#include "frame.hxx"

class TenthFrame : public Frame
{
    Shot third_;

public:
    Shot Third() const { return third_; }
    void Third(const Shot& third) { third_ = third; }
};

#endif

