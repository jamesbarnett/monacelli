#ifndef SHOT_HXX__
#define SHOT_HXX__

class Shot
{
    short result_;

public:
    static const short ONE_PIN   = 0x0001;
    static const short TWO_PIN   = 0x0002;
    static const short THREE_PIN = 0x0004;
    static const short FOUR_PIN  = 0x0008;
    static const short FIVE_PIN  = 0x0010;
    static const short SIX_PIN   = 0x0020;
    static const short SEVEN_PIN = 0x0040;
    static const short EIGHT_PIN = 0x0080;
    static const short NINE_PIN  = 0x0100;
    static const short TEN_PIN   = 0x0200;
    static const short FOUL      = 0x0400;
    static const short MISS      = 0x0800;
    static const short SPARE     = 0x1000;
    static const short STRIKE    = 0x2000;
    static const short VALID     = 0x4000;

    bool IsFoul() const { return (FOUL & result_) != 0; }
    bool IsMiss() const { return (MISS & result_) != 0; }
    bool IsSpare() const { return (SPARE & result_) != 0; }
    bool IsStrike() const { return (STRIKE & result_) != 0; }
    bool IsValid() const { return (VALID & result_) != 0; }
    
    int GetCount() const 
    {
        if ((result_ & SPARE) != 0) return 10;
        else if ((result_ & STRIKE) != 0) return 10;
        else
        {
            int count = 0;

            for (int i = 0; i < 10; ++i)
            {
                if ((result_ & (1 << i)) != 0)
                    ++count;
            }

            return count;
        }
    }

    short Result() const { return result_; }
    void Result(short result) { result_ = result; } 
};

#endif

