#ifndef CRTP_COUNTER_HPP
#define CRTP_COUNTER_HPP

template <typename Derived>
class counted {
private:
    static inline int count_ = 0;
public:
    counted() { ++count_; }
    counted(const counted&) { ++count_; }
    counted(counted&&) noexcept { ++count_; }
    virtual ~counted() { --count_; }

    static int alive() { return count_; }
};

#endif