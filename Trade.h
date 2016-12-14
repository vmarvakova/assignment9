#ifndef TRADE_H
#define TRADE_H

#include <iterator>

// TODO: Your code goes here


template<typename M>

int bestProfit(const M& bPrice, const M& ePrice){
    
    int maxP = 0;
    int maxSecond = 0;
    
    //  int formula = *prev(ePrice,1) - *bPrice;
    if(*bPrice == *prev(ePrice,1)){
        
        return maxP;
        
    }
    else {
        
        if(*prev(ePrice,1) - *bPrice <= maxP){
            
            return bestProfit(next(bPrice,1),ePrice);
        }
        else{
            maxSecond = bestProfit(bPrice,prev(ePrice,1));
            maxP = *prev(ePrice,1) - *bPrice;
            
            if(maxSecond>maxP){
                
                maxP = maxSecond;
            }
            
            return maxP;
        }
        
    }
    
    
}




#endif