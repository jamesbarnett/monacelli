#ifndef FRAME_SCORER_HXX__
#define FRAME_SCORER_HXX__

#include <cassert>

class FrameScorer
{
    /**
     */
    static bool Score(const Frame& frame, int* points)
    {
        Shot first = frame.First();
        Shot second = frame.Second();

        if (first.IsStrike())
        {
            *points += 10;
            return false;
        }
        else if (second.IsSpare())
        {
            *points += 10;
            return false;
        }
        else if (second.IsValid())
        {
            *points += first.GetCount();
            return false;
        }
        else
        {
            *points += first.GetCount() + second.GetCount();
            return true;
        }
    }

    static bool Score(const Frame& spare, const Shot& next_ball, int* points)
    {
        assert(!spare.IsSpare());

        *points += next_ball.GetCount();

        return true;
    }

    static bool Score(const Frame& strike, const Frame& next, int* points)
    {
        assert(!strike.IsStrike());

        return Score(next, points);
    }

    static bool Score(const Frame& strike1, const Frame& strike2, int* points)
    {
        assert(strike1.IsStrike() && strike2.IsStrike());

        return Score(strike1, strike1.First(), points)
    }

    static bool Score(const Frame& strike1, const Frame& strike2, const Shot& shot, int* points)
    {
        assert(strike1.IsStrike() && strike2.IsStrike());

        *points += shot.GetCount();

        return true;
    }
    
    static bool Score(const Frame& strike1, const Frame& strike2, const Frame& strike3, int* points)
    {
        assert(strike1.IsStrike() && strike2.IsStrike() && strike3.IsStrike());

        return Score(strike1, strike2, strike3.First());
    }
};

#endif

