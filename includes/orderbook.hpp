#ifndef ORDERBOOK_HPP
#define ORDERBOOK_HPP

#include "order.hpp"

#include <cstdlib>
#include <queue>

struct CompareBuyOrder {
    bool operator()(Order& o1, Order& o2) {
        if (o1.GetPrice() != o2.GetPrice()) {
            return o1.GetPrice() < o2.GetPrice();
        }
        if (o1.GetOrderTime() != o2.GetOrderTime()) {
            return o1.GetOrderTime() > o2.GetOrderTime();
        }
        return o1.GetNumberOfShares() < o2.GetNumberOfShares();
    }
};

struct CompareSellOrder {
    bool operator()(Order& o1, Order& o2) {
        if (o1.GetPrice() != o2.GetPrice()) {
            return o1.GetPrice() > o2.GetPrice();
        }
        if (o1.GetOrderTime() != o2.GetOrderTime()) {
            return o1.GetOrderTime() > o2.GetOrderTime();
        }
        return o1.GetNumberOfShares() < o2.GetNumberOfShares();
    }
};

class Orderbook {
    public:
        Orderbook() = default;
        void AddOrder(Order& order);
        void RemoveTopBid();
        void RemoveTopSell();
        bool HasBids();
        bool HasSells();
        const Order& GetBestBid();
        const Order& GetBestSell();
        float GetBidAskSpread();
        size_t GetBestBidVolume();
        size_t GetBestSellVolume();

    private:    
        std::priority_queue<Order, std::vector<Order>, CompareBuyOrder> buy_side_;
        std::priority_queue<Order, std::vector<Order>, CompareSellOrder> sell_side_;

};

#endif
