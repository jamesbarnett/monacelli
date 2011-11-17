#ifndef FRAME_HXX__
#define FRAME_HXX__

#include "shot.hxx"

class Frame
{
    Shot first_;
    Shot second_;

public:
    Shot First() const { return first_; }
    void First(const Shot& first) { first_ = first; }
    Shot Second() const { rturn second_; }
    void Second(const Shot& second) { second_ = second; }
};

#endif

