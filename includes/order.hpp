#ifndef ORDER_HPP
#define ORDER_HPP

#include <cstdlib>
#include <ctime>
#include <string>

enum class OrderSide { BUY, SELL };
enum class OrderType { LIMIT, MARKET };

class Order {
    public:
        Order(OrderSide os, OrderType ot, std::string asset, 
            float price, size_t number_of_shares, time_t order_time);
        std::string GetAsset();
        float GetPrice();
        size_t GetNumberOfShares();
        time_t GetOrderTime();

    private:
        OrderSide order_side_;
        OrderType order_type_;
        std::string asset_;
        float price_; // only for limit orders
        size_t number_of_shares_;
        time_t order_time_;

};

#endif
