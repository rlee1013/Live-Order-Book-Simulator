#ifndef MATCHENGINE_HPP
#define MATCHENGINE_HPP

#include "orderbook.hpp"
#include "tradehistory.hpp"

class MatchEngine {
    public:
        void ProcessOrder(Order& order);
        void Match(Order& order);

    private:
        Orderbook order_book_;
};

#endif
