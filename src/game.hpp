#ifndef GAME_HXX__
#define GAME_HXX__

#include "frame.hxx"
#include "tenth_frame.hxx"

class Game
{
    Frame frames_[9];
    TenthFrame tenth_frame_;

public:
    Frame frame(int n) const { return frames_[n]; }
    void frame(int n, const Frame& f) { frames_[n] = f; }
    TenthFrame tenth_frame() const { return tenth_frame_; }
    void tenth_frame(const TenthFrame& f) { tenth_frame_ = f; }
};

#endif

