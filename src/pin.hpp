#ifndef PIN_HXX__
#define PIN_HXX__

template <short N>
class Pin
{
    short n_ = N;

public:
    short value() const { return 1 << (N - 1); }
    short pin() const { return n_; }
};

class OnePin : public Pin<1> {};
class TwoPin : public Pin<2> {};
class ThreePin : public Pin<3> {};
class FourPin : public Pin<4> {};
class FivePin : public Pin<5> {};
class SixPin : public Pin<6> {};
class SevenPin : public Pin<7> {};
class EightPin : public Pin<8> {};
class NinePin : public Pin<9> {};
class TenPin : public Pin<10> {};

#endif

