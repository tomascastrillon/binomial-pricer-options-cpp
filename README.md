# High-Performance Binomial Options Pricer in C++

This project implements a binomial pricer for European options, including Delta hedging calculations, while strictly enforcing no-arbitrage conditions upon initialization.

To ensure ultra-low latency, the core engine avoids standard 2D structures (like nested vectors or ```std::map```). Instead, the binomial tree is mapped into a flattened 1D contiguous memory array ```std::vector<double>``` paired with an inline index solver. This architectural design minimizes pointer chasing and maximizes CPU cache hit rates during backward induction. Work in Progress.
