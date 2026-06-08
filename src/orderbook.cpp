#include "orderbook.hpp"

void Orderbook::AddOrder(Order& order) { // only for limit orders (check in matching engine)
    if (order.GetSide() == OrderSide::BUY) {
        buy_side_.push(order);
    } else {
        sell_side_.push(order);
    }
}

void Orderbook::RemoveTopBid() { 
    buy_side_.pop();
}

void Orderbook::RemoveTopSell() { 
    sell_side_.pop();
}

bool Orderbook::HasBids() { 
    return !buy_side_.empty();
}

bool Orderbook::HasSells() { 
    return !sell_side_.empty();
}

const Order& Orderbook::GetBestBid() { 
    return buy_side_.top();
}

const Order& Orderbook::GetBestSell() { 
    return sell_side_.top();
}

float Orderbook::GetBidAskSpread() {
    if (!HasBids() || !HasSells()) {
        return 0;
    }
    Order best_bid = GetBestBid();
    Order best_sell = GetBestSell();
    return best_sell.GetPrice() - best_bid.GetPrice();
}

size_t Orderbook::GetBestBidVolume() {
    if (!HasBids()) {
        return 0;
    }
    Order best_bid = GetBestBid();
    return best_bid.GetNumberOfShares();
}

size_t Orderbook::GetBestSellVolume() {
    if (!HasSells()) {
        return 0;
    }
    Order best_sell = GetBestSell();
    return best_sell.GetNumberOfShares();
}
