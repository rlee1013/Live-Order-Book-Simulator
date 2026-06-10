#include "matchengine.hpp"

void MatchEngine::ProcessOrder(Order& order) {
    OrderType order_type = order.GetType();
    
    if (order_type == OrderType::LIMIT) {
        // try to match with existing orders first
        Match(order); 
        
        // put remaining shares on book
        if (order.GetNumberOfShares() > 0) {
            order_book_.AddOrder(order);
        }
    } 
    else if (order_type == OrderType::MARKET) {
        // try to match
        Match(order);
        
        // 2. cancel all leftover shares (immediate-or-cancel)
        if (order.GetNumberOfShares() > 0) {
            // add to trade history
        }
    }
}

void MatchEngine::Match(Order& order) {
    
}
