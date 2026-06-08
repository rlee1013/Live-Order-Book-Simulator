#include "order.hpp"

Order::Order(OrderSide os, 
             OrderType ot, 
             std::string asset, 
             float price, 
             size_t number_of_shares, 
             time_t order_time) 
    : order_side_(os)
    , order_type_(ot)
    , asset_(asset)
    , price_(price)
    , number_of_shares_(number_of_shares)
    , order_time_(order_time) 
{ }

OrderSide Order::GetSide() {
    return order_side_;
}

OrderType Order::GetType() {
    return order_type_;
}

std::string Order::GetAsset() {
    return asset_;
}

float Order::GetPrice() {
    return price_;
}

size_t Order::GetNumberOfShares() {
    return number_of_shares_;
}

time_t Order::GetOrderTime() {
    return order_time_;
}
