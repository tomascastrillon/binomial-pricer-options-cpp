#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>

using namespace std;

class BinomialPricer{
    private:
        double strike;
        double up;
        double down;
        double interest;
        double price;
        int T;
        string type;

    void checkArbitrage(const double up,const double down,const double interest){

        double riskFreeRate = 1.0 + interest;
        if(riskFreeRate < down || riskFreeRate > up){
            throw std::invalid_argument("There can be no arbitrage");
        }
    }
    
    inline int getIndex(int t, int j) const{
        return(t * (t+1))/ 2+j;
    }

    public:
    void price(){
        int nodes = (T+1)*(T+2) / 2;
        double p = (1+interest - down) / (up - down);
        double q = 1-p;
        std::vector<double> prices(nodes);

        for(int t=0; t < T+1; t++){
            for(int j=0; j< t+1; j++){
                double node_price = price * pow(up,j) * pow(down,t-j);
                prices[getIndex(t,j)] = node_price;
            }
        }
    }


};